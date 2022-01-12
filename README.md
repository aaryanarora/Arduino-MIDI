# Arduino-MIDI

MIDI keyboard made from push buttons using arduino.This project is done using arduino UNO and demo has been done on FL studio (DAW)

This MIDI keyboard has 8 buttons representing notes of a major scale (starting from C4) and can be transposed up and down using extra 2 buttons.
(There is also some info if you want to make proper MIDI with all the keys and knobs in the END)

Requirement for this particular project:-

1) ten push buttons
2) two 10k ohm resistors
3) Jumper wires
4) Arduino Mega or Uno (ATMEGA 328)

# DEMO video
https://drive.google.com/file/d/1CV16GmP1x8wY3V3esKLMSvlJt4v85bw8/view?usp=sharing

# Steps

1) Make the circuit connections either by reffering to the Circuit.png or from https://www.tinkercad.com/things/f6a69geZ6ee-arduino-midi/editel?sharecode=py_GTygFzcwvJVROEEDKGq8sP1jU2249GNyL0IIrgSc

2) After completing the circuit open the "MIDIarduinonomain" folder and then the ino file inside it.

3) Add the Stated library from the Manage libraries. If you want to change the number of buttons or the pin corresponding to them, you can change it from this part of the code (if you use pin 13 you need to uncomment the pin 13 code here and also define the index of that pin (for eg. we use pins 2,5,7,13 so index of pin 13 is 4)

<img width="642" alt="image" src="https://user-images.githubusercontent.com/62216774/149140977-b4658ace-72f5-46a1-bc54-396cf9ef41a2.png">

But if you are increasing the number of buttons you will also have to change the code here accordingly

<img width="399" alt="image" src="https://user-images.githubusercontent.com/62216774/149141251-44a24047-e821-4a26-a29b-8b6fd251528e.png">

4) The code initially is in DEBUG mode only to check if the circuit is working, so upload the code to arduino and go to the Serial monitor (from Tools) to see the outputs corresponding to the Push buttons. (It is only for the buttons corresponding to the notes , not the ones used for transpose).

<img width="608" alt="image" src="https://user-images.githubusercontent.com/62216774/149141964-5f77d378-cc8a-4260-98c0-93463621678b.png">

5) After checking the buttons change the "DEBUG" part at top by "ATMEGA328" so that it can now send Serial signal for the MIDI part.

<img width="356" alt="image" src="https://user-images.githubusercontent.com/62216774/149142233-a1a04ab5-347a-4396-b4db-70a84e12036a.png">

6) Now upload the updated code to the arduino.

7) We have to use a software "hairless-midiserial" to convert these Serial signals to MIDI signals so that computer can understand them. So open the "hairless-midiserial" folder and then run the exe file.

8) In the software select the Serial Port as the Arduino port and now u can see that it will start giving message according to the push button presses.

<img width="301" alt="image" src="https://user-images.githubusercontent.com/62216774/149142875-40a5805b-9dac-4709-96bd-20281db205f0.png">

9) Our MIDI Signal is ready but for FL studio to use it as MIDI we need a software which can act as a virtual MIDI input.For this run the "setuploopbe1.exe" file and install it. Now change the MIDI out at Hairless MIDI to be LoopBe Internal MIDI

<img width="302" alt="image" src="https://user-images.githubusercontent.com/62216774/149143272-77b64f15-93a3-4fa8-8caa-f4ed3a167088.png">

10) Open FL studio and from options go to MIDI settings. You will see LOOPBe Internal MIDI in the Input section. Press the enable button and you are ready to go.You can check it using FL keys or any other plugin.

<img width="483" alt="image" src="https://user-images.githubusercontent.com/62216774/149143738-55d9a438-6e18-4f52-8f84-39e872abbffa.png">

# EXTRA PART

If you want to make proper MIDI keyboard with every note and knobs then :-

Use the same connection as previous circuit but just add the number of buttons you want and potentiometers for knobs to the analog pins.

Instead of MIDIarduinomain Use the MIDiarduinoEXTRA file and open it.

Here along with buttons and their pins , you can also define the number of potentiometers and their corresponding ANALOG pins
<img width="548" alt="image" src="https://user-images.githubusercontent.com/62216774/149149475-70357792-d5bf-4850-b6f7-ec3cca9519c3.png">

No need to change any other thing in the code and in this one you can add as much buttons you can and they will correspond to the next notes without have to change the code like we had to do in the previous one.

Rest all the process are same and you will get your DIY MIDI Keyboard working.


