# Sensor-based-Finger-Protection-Mechanism-for-Sewing-Machines
Built a capacitive sensor circuit using copper strips mounted on presser foot of sewing machine to prevent accidents due to needle penetration into the finger

OPERATION:

As soon as the human touch is sensed on the electrode mounted on the presser foot a capacitor is formed, MPR121 feds the signal to the Arduino, which is the microcontroller used in the circuit , through I2C communication protocol. Microcontroller then activates the relay from normally closed (NC) to normally open (NO) contact , thus stopping the motor suddenly and saving the the finger from injury .
However , when the finger is removed , MPR121 again feds the signal to the Arduino that, now there is no human touch. Therefore, Microcontroller, again changes the state from NO(normally open) to NC(Normally closed) contact between between the hall effect sensor’s output terminal and the driver. So, signal is again established from the hall effect sensor’s output terminal to the driver. And motor perfom the normal operation in accordance with the operator paddle movement. The system remains in normal state until again the presser foot is touched.
The relay and microcontroller circuitry is powered via 5V DC supply. The microcontroller power ups the capacitive sensor circuitry. As a future scope of the project motor driver’s supply can be used to power up the circuitry. So, there is no need for the separate 5V DC supply. Also, the whole circuitry can be enclosed in the motor driver’s box . Thus , making it more compact

CIRCUITRY:

A capacitive sensor circuit has been designed for preventing accidental finger injury from needle.
12 channel capacitive sensor board MPR121 is used in the project , one of its channel is connected to electrode mounted on the presser foot of the sewing machine, which are nothing but thin copper strips for detecting the human touch. The electrode can any conductive material (https://www.adafruit.com/categories/190) and act as the one of the plate of the capacitor ,other plate being the human body .
The speed of the sewing machine motor is manually controlled by the operator through a paddle. The paddle is connected to magnet mechanically ,facing a hall effect sensor. The whole arrangement consisting of magnet and the Hall Effect sensor circuitry is enclosed in the box. Whenever the operator moves the paddle up and down , the magnetic field across the hall effect sensor varies. The output of the sensor is fed to the motor’s driver ,which accordingly decreases and increases the speed of motor.
If there is no signal from the hall effect sensor to the motor’s driver , the motor stops suddenly .
A relay is connected to make or break the contact between the hall effect sensor’s output terminal and the driver. In case the contact breaks the driver gets no signal from hall effect sensor, and the motor stops suddenly , even if the paddle is pressed down by the operator to increase the speed.

Note: Fixed Parameters programmed in projection for electrode copper strip: 
1) fixed current – 20uA 
2) fixed amount of time(i.e sampling time)- 10ms

![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
