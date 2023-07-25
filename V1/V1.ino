// Set-up low-level interrupts for most acurate BPM math.
#define USE_ARDUINO_INTERRUPTS true   
#define SERIAL_DEVICE     Serial


// include the library code:
#include <LiquidCrystal.h>
#include <PulseSensorPlayground.h>     
#include <TimeLib.h>
#include <Chronos.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int PulseWire = 0;     

// The on-board Arduino LED, close to PIN 13.
const int LED = LED_BUILTIN;     

// Determine which Signal to "count as a beat" and which to ignore.
// Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
// Otherwise leave the default "550" value.      
int Threshold = 550;           

// Creates an instance of the PulseSensorPlayground object called "pulseSensor"
PulseSensorPlayground pulseSensor;  

// Log the lowest heart rate in sleep cycle to approximate deep sleep phase (NREM3)
int minHeartRate = 1000;

// set true when alarm rings
bool setAlarm = false;

// true when end of REM cycle has been calculated
bool switchState = false;

// true when targetTime exceeds user input alarm time
bool forceStop = false;

// count # of current REM cycles
int currentREM = 0;

// take desired # of user REM cycles as input
// set to 3 for now, will develop further after creating user interface/app
int targetREM = 5;

// Used to fix bug with checkForceStop()
bool tempBool = false;

// candidate time at which minimum heart rate occurs in a 20 min period
Chronos::DateTime candidateTime;

// predicted time for end of REM Cycle, based on conditions of candidateTime
Chronos::DateTime targetTime;

// latest time at which the user wants to wake up (i.e. a normal alarm at 8:00 AM)
// for now, hard-coded. In the future, will allow user to enter input via app
Chronos::DateTime forceStopTime;

void setup() {

  // Sets serial monitor
  Serial.begin(9600);         

  // Sets LCD object
  lcd.begin(16, 2);

  // Sets clock object (year, month, date, hour, sec, ms)
  Chronos::DateTime::setTime(2023, 05, 05, 03, 04, 00);

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
   //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.blinkOnPulse(LED);      
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }

  // set candidate time to now time 
  // initiate entry into update conditional statement in findMinHeartRate()
  candidateTime = Chronos::DateTime::now();

  // hard-coded for now, will eventually let user input alarm time via app
  // (year, month, day, hour, second, ms)
    // Chronos::DateTime tempTimeObject(2019, 11, 1, 18, 05, 00);

  forceStopTime = Chronos::DateTime(2023, 5, 15, 8, 00, 00);
  targetTime = Chronos::DateTime(2023, 5, 20, 8, 00, 00);


}

void findMinHeartRate() {

//Only check sensor if REM cycle has not yet been calculated
if(!switchState){
  int myBPM = pulseSensor.getBeatsPerMinute();  

  if(myBPM < minHeartRate){

    Chronos::DateTime nowTime(Chronos::DateTime::now());
    Chronos::Span::Absolute diff = candidateTime - nowTime;

    if(diff <= Chronos::Span::Minutes(20)){
        
        minHeartRate = myBPM;
        candidateTime = Chronos::DateTime::now();
    }
    else{
      targetTime = candidateTime + Chronos::Span::Minutes(50);
      tempBool = true;

      //loop will not run after switch is turned off and target time is set
      switchState = !switchState;
    }

  }
}

}

// only iterates for first detected instance
void checkForceStop(){
  if((!forceStop) && tempBool){
    if(targetTime > forceStopTime){
      forceStop = true;
      targetTime = forceStopTime;
    }
  }
}

void loop() {

  Serial.println(forceStop);

  if (pulseSensor.sawStartOfBeat()) {         

    Serial.println(currentREM);

    Serial.print("Target Time: ");
    targetTime.printTo(SERIAL_DEVICE);
    // private helper methods
    findMinHeartRate();

    // increments remCount if targetTime is met
    // re-enter findMinHeartRate() by setting candidate and switch variables
    // switch == false condition so that enters only on first instance
    Chronos::DateTime nowTime(Chronos::DateTime::now());

      // nowTime.printTo(SERIAL_DEVICE); // dump to serial

    Chronos::Span::Absolute diff = targetTime - nowTime;
    if (switchState == false && diff <= Chronos::Span::Minutes(2)) {
      candidateTime = Chronos::DateTime::now();
      switchState = !switchState;

      // do not increment currentRem if targetTime was set to forceStopTime in checkForceStop()
      if(!forceStop){
      currentREM++;
      }



    }

    //checks if targetTime exceeds latest alarm bound
    //i.e. if user sets alarm for 8:00 AM, targetTime should not exceed 8:00 AM
    checkForceStop();

    // conditions to ring the alarm
    if(currentREM == targetREM){
      setAlarm = true;
    }

    if(forceStop && diff <= Chronos::Span::Seconds(10)){
      setAlarm = true;
    }

    // LCD display content
    int myBPM = pulseSensor.getBeatsPerMinute();  

    //wellness stat display
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HR: ");
    lcd.print(myBPM);
    lcd.setCursor(8,0);
    lcd.print("REM: ");
    lcd.print(currentREM);

    //row 2, Clock display
    lcd.setCursor(0,1);
    lcd.print("t:");

    lcd.print(nowTime.hour());
    lcd.print(".");
    lcd.print(nowTime.minute());
    lcd.print(".");
    lcd.print(nowTime.second());

    lcd.setCursor(9,1);
    lcd.print("E:");

    //only print targetTime estimate if it is finalized (last REM cycle)
    if(forceStop){
      lcd.print("NA");
    }
    else if(currentREM = targetREM - 1){
      lcd.print(diff.hours());
      lcd.print(".");
      lcd.print(diff.minutes());
      lcd.print(".");
      lcd.print(diff.seconds());
    }
    else{
      lcd.print("bruh");
    }

    if (setAlarm) {
      analogWrite(6,127);
    } else {
      analogWrite(6,0);
    }
  }

  delay(20);                    
}





