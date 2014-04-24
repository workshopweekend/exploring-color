# Exploring Color

An RGB LED works like a computer screen; it relies on how your eye detects color. Your eye has three types of color-sensitive cells (called *cones*). Each type is most sensitive to a particular color of light: red light, green light, and blue light. We perceive different relative proportions of those colors as different colors. For example, yellow light triggers the red- and green-sensitive cells in roughly equal amounts, and we perceive yellow light. That fact allows us to fake "yellow" by producing red and green in equal amounts. In this lab, we'll play with colors and explore this effect.

![chart-explains-all](color-chart.png)

An RGB LED, then, approximately lets us produce any color we want by varying the red, green, and blue channels individually. Let’s explore that.

1.  Start with the following circuit. Make sure to orient the LED correctly -- the flat side should be on the left as in the diagram below.

    ![just-the-led dim=400wL](img/just-the-led-please.png "Fritzing for RGB LED with sigle active channel") ![just-the-led-schematic dim=400wL](img/just-the-led-please-schematic.png "Schematic for RGB LED with sigle active channel")

2.  The LED should appear blue. The the end of the wire connected to the LED's resistor and move it between the red, green, and blue positions. Observe the LED's color change.

3.  Connect the red, green, and blue legs of the LED to pins 9, 10, and 11:

    ![legs-connected-to-pins dim=400wL](img/legs-connected-to-pins.png "Fritzing for RGB LED on pins 9, 10, 11") ![legs-connected-to-pins dim=400wL](img/legs-connected-to-pins-schematic.png "Schematic for RGB LED on pins 9, 10, 11")

4.  Write code to get these colors in this sequence: red, green, blue, red *and* green (should make yellow), green *and* blue (should make cyan), blue *and* red (should make magenta), and finally red, green, *and* blue (should make white).
    <%= sequence.ino =%>
5.  Notice that the mixed colors are not very accurate -- in fact, the proportions are pretty far off! How can you correct this?

6.  You can adjust brightness of an LED (and an LED channel) using `analogWrite` instead of `digitalWrite`. `analogWrite` blinks very quickly (faster than you can perceive) and can adjust brightness by sending specially timed pulses. This type of pulse pattern is called Pulse Width Modulation (PWM); only the pins marked with `~` support PWM.

    Modify the sequence code to reduce the brightness of the blue channel wherever it is used. The [`analogWrite` reference](http://arduino.cc/en/Reference/AnalogWrite) (and specifically the included example code) may be helpful.

7.  Uploading new code to see a new color is tedious. Insteas, use a potentiometer to control the brightness of each color. Connect your two potentiometers to analog pins A0 and A1. Borrow a third potentiometer and connect it to analog pin A2:

    ![three-potentiometers dim=400wL](img/three-potentiometers.png "Fritzing for RGB LED and three potentiometers") ![three-potentiometers dim=400wL](img/three-potentiometers-schematic.png "Schematic for RGB LED and three potentiometers")

8.  Use analogRead on pins A0, A1, and A2, respectively, to set the value for analogWrite on redPin, greenPin, and bluePin:
    <%= analogRead_to_analogWrite.ino =%>
9.  Turn the LED off by turning all pots to 0.
* Experiment by turning the red and green pots to get a convincing orange color. (Likely to be full red and a little green.)
* Adjust the pots to get as close to white as you can.
* Use Serial.println to inspect the analogWrite values for red, green, and blue that produce white. We'll set these values as the maximum value for each channel.
* Write a setAdjustedColor function that uses map to convert the 0..1023 range of each analogInput to the 0..max for each channel.
* Use setAdjustedColor to set the LED's color based on the three pot values. Verify that the LED is white when the three pots are all the way on.
* Setting the red, green, and blue components is common, but not always the most useful way to think about color. Sometimes you want to pick a hue and keep it as bright and saturated as possible. That's what the Hue-Saturation-Brightness (HSB) color representation does.
* Use setHSBColor (provided) to control the hue, saturation, and brightness of the LED using the three potentiometers connected to pins A0, A1, A2.

Challenges:
* Use random() or another algorithm to slowly cycle through colors.
* Connect a button to a digital input pin. 
  * Modify the code so that the color of the LED doesn't change when the pots are rotated, but only when the button is pressed.
  * Instead of changing the color with the pots, increase the hue whenever the button is pressed, keeping full brightness and saturation. 
  * Instead of using a button, try the capsense library and a piece of copper foil. (You might use this in a lamp that changes color by touch.)
