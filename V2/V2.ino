// set-up low-level interrupts for most acurate BPM math.
#define USE_ARDUINO_INTERRUPTS true   


// include the library code:
#include <LiquidCrystal.h>
#include <PulseSensorPlayground.h>   
#include <TimeLib.h>
#include <Chronos.h>


// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// creates an instance of the PulseSensorPlayground object called "pulseSensor"
PulseSensorPlayground pulseSensor;  
const int PulseWire = 0;            // pulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;        // the on-board Arduino LED
int Threshold = 550;                // heartbeat signal threshold (borrowed from example sketch)


int minHeartRate = 1000;            // log the lowest heart rate in sleep cycle to approximate deep sleep phase (NREM3)
bool alarmSound = false;            // set true when alarm rings
bool alarmSet = false;              // true when end of REM cycle has been calculated/
int currentREM = 0;                 // count # of current REM cycles
bool forceStop = false;             // true when targetTime exceeds user input alarm time
const int targetREM = 3;            // take desired # of user REM cycles as input (set to 3 for now, will develop further after creating user interface/app)
int myBPM;                          // global bpm variable


Chronos::DateTime candidateTime;    // candidate time at which minimum heart rate occurs in a 20 min period
Chronos::DateTime alarmTime;        // predicted time for end of REM Cycle, based on conditions of candidateTime
Chronos::DateTime forceStopTime;    // latest time at which the user wants to wake up (i.e. a normal alarm at 8:00 AM). for now, hard-coded. In the future, will allow user to enter input via app






void setup() {
 // Sets serial monitor
 Serial.begin(9600);       


 // Sets LCD object
 lcd.begin(16, 2);


 // Sets time to now (year, month, date, hour, sec, ms)
 Chronos::DateTime::setTime(2023, 05, 9, 05, 30, 00);


 // Configure the PulseSensor object, by assigning our variables to it.
 pulseSensor.analogInput(PulseWire); 
 pulseSensor.blinkOnPulse(LED);     
 pulseSensor.setThreshold(Threshold); 


 // Double-check the "pulseSensor" object was created and "began" seeing a signal.
 if (pulseSensor.begin()) {
   Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset. 
 }


 // set candidate time to now time
 candidateTime = Chronos::DateTime::now();


 // hard-coded for now, will eventually let user input alarm time via app
 // (year, month, day, hour, second, ms)
 forceStopTime = Chronos::DateTime(2023, 5, 9, 5, 40, 00);
}


void updateAlarmTime() {
 // if alarm time is already set, do nothing
 if (!alarmSet) {
   // if 20 minutes has elapsed since the previous min heartrate, a deep sleep period should be over
   if (Chronos::DateTime::now() > candidateTime + Chronos::Span::Minutes(20)) {
     currentREM++;
     // if projected end of REM is past forceStopTime, set alarm to forceStopTime
     if (Chronos::DateTime::now() + Chronos::Span::Minutes(50) > forceStopTime) {
       alarmTime = forceStopTime;
       alarmSet = true;
     // otherwise if we've reached the target REM cycles then set alarm to end of REM
     } else if (currentREM == targetREM) {
       alarmTime = Chronos::DateTime::now() + Chronos::Span::Minutes(50);
       alarmSet = true;
     }
     candidateTime += Chronos::Span::Minutes(70);
   } else if (myBPM < minHeartRate) {
       candidateTime = Chronos::DateTime::now();
   }
   //jank solution for restarting min champion after REM cycle
   if (candidateTime == Chronos::DateTime::now()) {
     minHeartRate = myBPM;
   }
 }
}


void loop() {
 if (pulseSensor.sawStartOfBeat()) {       
   myBPM = pulseSensor.getBeatsPerMinute(); 
   updateAlarmTime();
 }


 //wellness stat display
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("HR: ");
 lcd.print(myBPM);
 lcd.setCursor(0,1);
 lcd.print("REM: ");
 lcd.print(currentREM);


 //row 2, Clock display
 lcd.setCursor(8,0);
 lcd.print("T: ");
 lcd.print(Chronos::DateTime::now().hour());
 lcd.print(":");
 lcd.print(Chronos::DateTime::now().minute());


 lcd.setCursor(8,1);
 lcd.print("E: ");
 if (!alarmSet) {
   lcd.print("N/A");
 } else {
   lcd.print(alarmTime.hour());
   lcd.print(":");
   lcd.print(alarmTime.minute());
 }


 if (alarmSet) {
   analogWrite(6,127);
 } else {
   analogWrite(6,0);
 }


 delay(20);      