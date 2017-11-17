

# home8-v0.6
<pre>
the Home8 is a Microchip MCU based SmartHome controler.

If you want to connect two deviced together or want to use OpenHub etc... a Linux board of some kind is needed. (eg NanoPI NEO)
The Board is used for a Network/LAN connection. As a protocol MQTT is used.


Parts
-Board MCU
-Firmwar for the PIC/MCU
-Software Linux | MQTT-UART bridge


Tested Linux Boards
  NanoPi Neo (LAN)
  NanoPi Due (WLAN)
  NanoPi Air (WLAN)
  (esp8266 in testing)(WLAN)


Is it stable?
  The the MCU firmware is very stable, but not perfect!
  The Linux-Mqtt software is NOT stable at the Moment.
  The ESP8266-Mqtt software is still in development.
  
Whats Next:
  UART-Bootloader for OTA Updates oft the MCU firmware.
  Simple RGBW-LED Controler-Board software is already in beta.
  Simple Temp. Senor for 
  
I will upload the code, when I have figured out the licensing(external Sources) and when the code is presentable.

license
  for external code/resources - please look it up your self (eclipse paho etc... )
  for my code please ask me - not decided yet (will be marked on top of every file)
<pre>
