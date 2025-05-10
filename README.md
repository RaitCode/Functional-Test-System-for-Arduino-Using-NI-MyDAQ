# Functional-Test-System-for-Arduino-Using-NI-MyDAQ  
Arduino board testing  

**Project Overview**  

This project implements a comprehensive functional validation system for Arduino boards using NI myDAQ hardware and LabVIEW software. It demonstrates my ability to integrate an Arduino board with NI MyDAQ hardware, automated through LabVIEW, to perform sequential electronic validation tests of Arduino Microcontroller board. The goal is to verify the hardware integrity and capabilities of an Arduino microcontroller board.

It showcases a complete and realistic test sequence involving:  

•	Power Rail Integrity Testing (5V and 3.3V)  
•	Digital I/O Communication and Response Time Measurement  
•	PWM Signal Generation and Monitoring  
•	Serial Communication Validation  

All communication between LabVIEW, NI MyDAQ, and Arduino was successfully achieved, overcoming multiple hardware and software challenges.  

**Project Description**  
The system automatically performs the following tests in sequence:  

 &nbsp;*1. Power Integrity Test (5V and 3.3V Rails)*  
    &nbsp;&nbsp;&nbsp;&nbsp;o	5V Rail Test:  
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	The Arduino’s 5V rail is measured using NI MyDAQ Analog Input AI0.  
    &nbsp;&nbsp;&nbsp;&nbsp;o	3.3V Rail Test:  
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	The Arduino’s 3.3V rail is measured using NI MyDAQ Analog Input AI1.  
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	A 5V relay module is used to connect/disconnect the 3.3V line:  
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	The 3.3V line is connected to the Normally Open (NO) contact of the relay.  
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	During the 3.3V rail test, Arduino closes the relay (writing HIGH to the relay control).  
     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	After the 3.3V rail test, Arduino opens the relay (writing LOW) to disconnect the 3.3V rail, freeing AI1 for the PWM tests.  
 &nbsp;&nbsp;&nbsp;&nbsp;o	Noise Reduction:  
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	A capacitor was connected across the AI1 positive and negative terminals of NI myDAQ to stabilize readings during analog measurements.  

  &nbsp;*2.	Digital I/O Test*  
   &nbsp;&nbsp;&nbsp;&nbsp;o	LabVIEW (via NI MyDAQ) sends a digital pulse to the Arduino.  
   &nbsp;&nbsp;&nbsp;&nbsp;o	Arduino detects the incoming pulse and sends a return pulse back to MyDAQ.  
   &nbsp;&nbsp;&nbsp;&nbsp;o	The response time between sending and receiving the pulse is measured.  
   &nbsp;&nbsp;&nbsp;&nbsp;o	Arduino’s onboard LED provides a visual confirmation during this test.  

  &nbsp;*3. PWM Signal Testing*  
   &nbsp;&nbsp;&nbsp;&nbsp;o	Arduino generates PWM signals with duty cycles of:  
     &nbsp;&nbsp;&nbsp;&nbsp;	30%  
     &nbsp;&nbsp;&nbsp;&nbsp;	60%  
     &nbsp;&nbsp;&nbsp;&nbsp;	90%  
   &nbsp;&nbsp;&nbsp;&nbsp;o	These PWM signals are monitored through NI MyDAQ Analog Input AI1 (after the 3.3V rail is disconnected).  

  &nbsp;*4.	Serial Communication Test*  
   &nbsp;&nbsp;&nbsp;&nbsp;o	LabVIEW sends a 19-character string via serial communication to Arduino.  
   &nbsp;&nbsp;&nbsp;&nbsp;o	Arduino reads and echoes the string back to confirm serial communication reliability.  


**LabVIEW Design Techniques**  
 The LabVIEW program integrates several advanced programming techniques to ensure maintainability, modularity, and scalability:  
 &nbsp;&nbsp;&nbsp;&nbsp;•Event-Driven State Machine (EDSM) architecture.  
 &nbsp;&nbsp;&nbsp;&nbsp;•Use of SubVIs for modular code structure.  
 &nbsp;&nbsp;&nbsp;&nbsp;•Queues for efficient inter-process communication.  
 &nbsp;&nbsp;&nbsp;&nbsp;•Type Definitions (TypeDefs) to ensure consistent data types across the application.  
 These techniques demonstrate solid software engineering practices and ensure the test system is responsive and easy to extend.  

**Hardware Used**  
  •	Arduino Uno  
  •	NI MyDAQ  
  •	Jumper wires  
  •	5V Relay Module (for rail switching)  
  •	Capacitor (across AI1 terminals to improve analog signal stability)  
  •	Laptop running LabVIEW 2019 or later  
  
**Software Used**  
•	LabVIEW and NI MAX (for test automation and NI MyDAQ control)  
•	Arduino IDE (for firmware development)  

**Key Challenges Overcome**  
  •	Shared Analog Channel Management:  
  Designed a switching system using a relay to allow AI1 to serve both the 3.3V rail measurement and PWM capture without conflict.  
  •	Reliable Serial Communication Handling:  
  Ensured that serial transmission and echo were properly synchronized without disrupting the test flow.  
  •	Precise Digital I/O Response Measurement:  
  Implemented a mechanism to accurately measure response times between Arduino and LabVIEW.  
  •	State Machine Logic:  
  Built a robust Labview state machine to correctly sequence the tests and synchronize LabVIEW triggers and readings with Arduino.  
  •	Hardware Integration:  
  Successfully interfaced NI MyDAQ's analog and digital capabilities with Arduino's logic and voltage levels.  
  •	Noise Minimization:  
  Added a capacitor across AI1 terminals to reduce measurement noise during analog readings.  

**📹 Video Demonstration**  
Hardware Setup:  
Watch the project in action: https://drive.google.com/file/d/1TPXvxHDBPi6YRtS_AMUW9Qr9W78vY-Af/view?usp=sharing

