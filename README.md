****DISCLAIMERS****
THIS IS AN EXPERIMENTAL ELECTRONICS PROJECT.
 THIS IS NOT A MEDICAL DEVICE.
 THIS PROJECT DOES NOT DIAGNOSE OR TREAT ANY MEDICAL CONDITIONS.
 THIS PROJECT IS FOR EDUCATIONAL AND HOBBY PURPOSES ONLY.
 DO NOT USE IF YOU HAVE IMPLANTED MEDICAL DEVICES.
 ONLY OPERATE DEVICE FROM BATTERY POWER WHILE ELECTRODES ARE ATTACHED.

****USE AT YOUR OWN RISK****


**Simple EMG Control**
This is a simple EMG based on/off control sysytem using the ‎B0CJ7FMSP4 EMG board available on Amazon. 
This project uses C++ firmware to filter EMG signals and covert them to a clean digital trigger for
muscle based actuation of LEDs and Servos. **IMPORTANT** The use of an external power supply is HIGHLY 
reccomended for servo use.


**Hardware**
-‎B0CJ7FMSP4 EMG board and electrodes
-Adruino Uno 
-LED (any color)
-220 Ohm resistor x2
-Jumper Wires 
-Breadboard
-Button
-Sg90 servo (optional)
-9v battery x2
-9v battery clips x2
-3D printed battery enclosure (optional but reccomended)


**Arduino Uno Pinout**
- EMG Module → A0          
- Status LED  → 13          
- Push Button → 7           
- Finger Servo → 10          
- Thumb Servo → 11          


**EMG Module Pinout**
- VCC → 5V
- GND → GND
- OUT → A0


**9v Power Pack Pinout**
-Positive 9v line → Positive 9v on EMG board
- Negaive 9v line → Negative 9v on EMG Board
- Ground → Ground
  

**LED Pinout**
- Pin 13 → LED anode (+)
- LED cathode (–) → 220 Ohm resistor → GND


**Push Button Pinout** 
- One side → Pin 7 AND 220 Ohm resitor → GND
- Other side → GND
  

  **Servo Pinout**
  Both servos:
  - Red → 5V (external supply recommended)
  - Brown/Black → GND
  - Signal → Pin 10 (Finger) / Pin 11 (Thumb)
