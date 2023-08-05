<a name="br1"></a> 

*ECE 203 Final Project - Report*

*Shivam Kak & Maxwell Lin | Spring 2023*

*Table of Contents*

*#*

*Introduction*

*Materials*

*Design*

*3*

*4*

*5*

*6*

*7*

*8*

*9*

*Findings*

*Code*

*Gallery*

*Goals for Future*



<a name="br2"></a> 

*Introduction*

*Explanation of concept*

Have you ever wanted to optimize the sleep you get at night? From service staff working

night shifts to doctors staffing the emergency room to athletes on professional training cycles,

many people in society only have a limited window of time in which they can get the sleep they

need for the night.

*What if there was a way to guarantee restful sleep during this window of time?*

Sleep therapists recommend waking from sleep after completion of a REM cycle, which

is the latter half of the general sleep cycle. A full sleep cycle typically lasts from 90-110 minutes,

with an approximate breakdown of the length of each phase provided in the diagram below.

(Originally from the Sleep Foundation, found at <https://www.sleepfoundation.org/stages-of-sleep>)

Standard alarms work for this purpose in theory; in practice an alarm may wake you up

midway through a REM cycle, which results in grogginess upon awakening. Our final project,

the REM Clock, proposes a solution to this issue by designing a novel product that wakes up

users after the completion of a REM cycle as opposed to a fixed alarm time. Users still set an

alarm time, but they also input a desired quantity of REM cycles. If they have completed their

indicated REM cycles before their set alarm time, the alarm will sound early, at that precise time

when the cycle is completed. (For example, John sets an alarm for 8:00 AM with REMcount = 2.

If he finishes 2 REM cycles at 7:45 AM, the alarm wakes him up early, and he may feel more

energized than if he had woken up at 8:00 AM). The REM Clock is implemented primarily with

a heart rate monitor and a programmable Arduino Uno. This will be elaborated further in the

Materials section.



<a name="br3"></a> 

*Materials*

*Guide of components needed to recreate project*

● Buzzer:

○

[Buzzer,](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[3-24V](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Electronic](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Buzzer](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Alarm](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Sounder](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Continuous](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Tone](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Buzzer](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[85](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[to](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[95dB](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Door](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Buzzer](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[w/](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)

[100mm](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Cable](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[ ](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)[Length](https://www.amazon.com/Akozon-Buzzer-Electronic-Continuous-Length/dp/B07H84SF83)

● Heart Rate Sensor:

○

[PulseSensor.com](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[The](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Real](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[&](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Original](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Pulse](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Sensor](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Plug-in](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[for](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Your](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[ ](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)[Project.](https://www.amazon.com/PulseSensor-com-Original-Pulse-Sensor-project/dp/B01CPP4QM0/ref=asc_df_B01CPP4QM0/?tag=hyprod-20&linkCode=df0&hvadid=508977605709&hvpos=&hvnetw=g&hvrand=13319966699797284837&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-1362130091700&psc=1)

● LCD Display:

○

[HiLetgo](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[2pcs](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[HD44780](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[1602](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[LCD](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[Display](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[Module](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[DC](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[5V](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[16x2](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[Character](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[LCM](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[Blue](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[Blacklight](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[ ](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)[New](https://www.amazon.com/HiLetgo-Display-Backlight-Controller-Character/dp/B00HJ6AFW6/ref=asc_df_B00HJ6AFW6/?tag=hyprod-20&linkCode=df0&hvadid=312322349988&hvpos=&hvnetw=g&hvrand=12854924166094942605&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003941&hvtargid=pla-585256965018&psc=1)

● Arduino Uno

● Breadboard

● Male to Male connecting wires

● 2 9V batteries and holders

The basic materials needed are really just the heart rate sensor and the Arduino Uno. An

improvement of this project may consider manufacturing the heart rate monitor into a ring, with

chips linked in the future development section.



<a name="br4"></a> 

*Design*

*Following walk through of how to set-up with Arduino Uno*

We used the following reference materials when constructing our circuit

[*https://www.instructables.com/ZazHRM-a-Bluetooth-Heart-Rate-Monitoring-System-fo/*](https://www.instructables.com/ZazHRM-a-Bluetooth-Heart-Rate-Monitoring-System-fo/)



<a name="br5"></a> 

To design the algorithm, we implemented the following pseudo code:

a. Record heart rate data via pulseSensor.getBeatsPerMinute(); store as int

b. Update the alarm time accordingly:

i.

To approximate the time of REM cycle completion, the goal is to first

approximate deep sleep completion (easily marked as the sleep phase in

which lowest heart rate likely occurs). To find lowest heart rate in cycle:

1\. Store initial heart rate in a champion int variable. Compare current

heart rate with next heart rate (after delay(20)). If next is lower,

store nextHeartRate as the new champion. Store the time at which

this champion heart rate occurs in a Chronos DateTime object.

2\. Wait till no instance of lower heart rate has occurred in a period of

20 minutes. This suggests that heart rate has stopped decreasing

and deep sleep phase may be over

3\. Set Chronos DateTime object for REM Cycle completion for 50

minutes after the time set for the champion heart rate. This

approximates the time from the end of deep sleep to the end of

REM sleep.

ii.

Implement a functionality so that the REM Clock will never wake

someone up after their set alarm time, only before this time if they have

completed their REM Cycle:

1\. Instantiate a Chronos DateTime object in setup() with user input

for the time they want to set alarm for

2\. Check if the target time set for REM cycle completion in Step b.i.3

above is set after the Chronos DateTime object inputted by the user

a. If so, override the target REM time using boolean to switch

conditions, and set the alarm for the user-inputted time

b. If not, and the amount of user-inputted REM cycles was

completed, maintain REM target time

c. If not, and more REM cycles remain, program will keep

running till the total count of REM cycles matches the

desired amount inputted by user



<a name="br6"></a> 

*Findings*

*Progress log of what works and what needs improvement*

In the end, we were able to get the project working to our specifications. The Arduino program

correctly detects the end of a period of deep sleep, updates the REM cycle accordingly, and

updates the alarm time accordingly. The buzzer is functional (and quite loud) and will serve as a

proper alarm. Images of the completed circuit and LCD display setup are shown in the gallery

section.

The LCD pins {D4, D5, D6, D7, E, RS}are connected to ports {2, 3, 4, 5, 11, 12} of the

Arduino, respectively. V0 of the LCD is connected to a voltage divider on the board with a 1kΩ

and 4kΩ resistor, yielding a voltage of 1V for optimal contrast on the LCD. The buzzer is

connected to port 6. The heart rate monitor is connected to A0. All remaining VSS and VDD for

each component are connected to the ground and 5V ports of the Arduino as applicable.

Getting all the parts to work correctly was quite difficult and took up the majority of our lab

time. Both of our initial heart rate chips were faulty, as well as one of our two LCD displays.



<a name="br7"></a> 

*Code*

*.ino file also attached separately in zip file submission*

*// set-up low-level interrupts for most acurate BPM math.*

*#define USE\_ARDUINO\_INTERRUPTS true*

*// include the library code:*

*#include <LiquidCrystal.h>*

*#include <PulseSensorPlayground.h>*

*#include <TimeLib.h>*

*#include <Chronos.h>*

*// initialize the library by associating any needed LCD interface pin with the arduino*

*pin number it is connected to*

*const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;*

*LiquidCrystal lcd(rs, en, d4, d5, d6, d7);*

*// creates an instance of the PulseSensorPlayground object called "pulseSensor"*

*PulseSensorPlayground pulseSensor;*

*const int PulseWire = 0;*

*0*

*// pulseSensor PURPLE WIRE connected to ANALOG PIN*

*const int LED = LED\_BUILTIN;*

*int Threshold = 550;*

*example sketch)*

*// the on-board Arduino LED*

*// heartbeat signal threshold (borrowed from*

*int minHeartRate = 1000;*

*approximate deep sleep phase (NREM3)*

*bool alarmSound = false;*

*bool alarmSet = false;*

*int currentREM = 0;*

*// log the lowest heart rate in sleep cycle to*

*// set true when alarm rings*

*// true when end of REM cycle has been calculated/*

*// count # of current REM cycles*

*bool forceStop = false;*

*time*

*// true when targetTime exceeds user input alarm*

*const int targetREM = 3;*

*// take desired # of user REM cycles as input (set*

*to 3 for now, will develop further after creating user interface/app)*

*int myBPM;*

*// global bpm variable*

*Chronos::DateTime candidateTime;*

*occurs in a 20 min period*

*// candidate time at which minimum heart rate*

*// predicted time for end of REM Cycle, based on*

*Chronos::DateTime alarmTime;*

*conditions of candidateTime*



<a name="br8"></a> 

*Chronos::DateTime forceStopTime;*

*// latest time at which the user wants to wake up*

*(i.e. a normal alarm at 8:00 AM). for now, hard-coded. In the future, will allow user*

*to enter input via app*

*void setup() {*

*// Sets serial monitor*

*Serial.begin(9600);*

*// Sets LCD object*

*lcd.begin(16, 2);*

*// Sets time to now (year, month, date, hour, sec, ms)*

*Chronos::DateTime::setTime(2023, 05, 9, 05, 30, 00);*

*// Configure the PulseSensor object, by assigning our variables to it.*

*pulseSensor.analogInput(PulseWire);*

*pulseSensor.blinkOnPulse(LED);*

*pulseSensor.setThreshold(Threshold);*

*// Double-check the "pulseSensor" object was created and "began" seeing a signal.*

*if (pulseSensor.begin()) {*

*Serial.println("We created a pulseSensor Object !"); //This prints one time at*

*Arduino power-up, or on Arduino reset.*

*}*

*// set candidate time to now time*

*candidateTime = Chronos::DateTime::now();*

*// hard-coded for now, will eventually let user input alarm time via app*

*// (year, month, day, hour, second, ms)*

*forceStopTime = Chronos::DateTime(2023, 5, 9, 5, 40, 00);*

*}*

*void updateAlarmTime() {*

*// if alarm time is already set, do nothing*

*if (!alarmSet) {*

*// if 20 minutes has elapsed since the previous min heartrate, a deep sleep period*

*should be over*

*if (Chronos::DateTime::now() > candidateTime + Chronos::Span::Minutes(20)) {*

*currentREM++;*



<a name="br9"></a> 

*// if projected end of REM is past forceStopTime, set alarm to forceStopTime*

*if (Chronos::DateTime::now() + Chronos::Span::Minutes(50) > forceStopTime) {*

*alarmTime = forceStopTime;*

*alarmSet = true;*

*// otherwise if we've reached the target REM cycles then set alarm to end of REM*

*} else if (currentREM == targetREM) {*

*alarmTime = Chronos::DateTime::now() + Chronos::Span::Minutes(50);*

*alarmSet = true;*

*}*

*candidateTime += Chronos::Span::Minutes(70);*

*} else if (myBPM < minHeartRate) {*

*candidateTime = Chronos::DateTime::now();*

*}*

*//jank solution for restarting min champion after REM cycle*

*if (candidateTime == Chronos::DateTime::now()) {*

*minHeartRate = myBPM;*

*}*

*}*

*}*

*void loop() {*

*if (pulseSensor.sawStartOfBeat()) {*

*myBPM = pulseSensor.getBeatsPerMinute();*

*updateAlarmTime();*

*}*

*//wellness stat display*

*lcd.clear();*

*lcd.setCursor(0,0);*

*lcd.print("HR: ");*

*lcd.print(myBPM);*

*lcd.setCursor(0,1);*

*lcd.print("REM: ");*

*lcd.print(currentREM);*

*//row 2, Clock display*

*lcd.setCursor(8,0);*

*lcd.print("T: ");*

*lcd.print(Chronos::DateTime::now().hour());*

*lcd.print(":");*

*lcd.print(Chronos::DateTime::now().minute());*



<a name="br10"></a> 

*lcd.setCursor(8,1);*

*lcd.print("E: ");*

*if (!alarmSet) {*

*lcd.print("N/A");*

*} else {*

*lcd.print(alarmTime.hour());*

*lcd.print(":");*

*lcd.print(alarmTime.minute());*

*}*

*if (alarmSet) {*

*analogWrite(6,127);*

*} else {*

*analogWrite(6,0);*

*}*

*delay(20);*



<a name="br11"></a> 

*Gallery*

*Images of the project at final stage and intermediary steps*

*HR: Displays the heart rate of the user*

*REM: Displays the current REM cycle the user is in*

*T: Displays current time*

*E: Displays the alarm time, or N/A if it has not been calculated yet*

*Top-down view of the breadboard*



<a name="br12"></a> 

*REMclock in use*



<a name="br13"></a> 

*Goals for Future Development*

*Improving the functionality of the REM Clock*

Currently, it remains to be seen whether or not this algorithm/setup is effective in identifying the

completion of REM sleep cycles. Identifying this would require thorough experimentation and

refinement including the use of volunteers in a sleep lab who would wear the device over night.

Moreover, the end goal would be to make this into a minimally invasive product that can be

worn easily by users, such as a ring:

(DALL-E generated artwork)

To accomplish this end, we would need to use entirely different components, including a smaller

heart rate monitor and a smaller microprocessor chip. Along with integrating charging port

functionality, all components would ideally be connected via a printed circuit board and placed

within a 3D printed ring model from a CAD software.

On the software side, the ring would be supplemented by an app that is a conventional

iOS/Android app with the alarm features specified in this document. Cross-compatibility with

Apple watches and Fitbits would be a very promising feature.

Please reach out if you have any comments or feedback on the viability of this product and if you

think it is worth developing/researching further. Thank you for reviewing this project!

Best, Shivam and Maxwell

