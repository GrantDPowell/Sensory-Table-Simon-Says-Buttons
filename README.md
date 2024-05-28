# Light Up Piano Buttons Module for Space-Themed Sensory Table

## Project Overview
The Light Up Piano Buttons module is a part of the Space-Themed Sensory Table designed to aid adults with disabilities in managing overstimulation. This module provides an interactive and sensory-rich experience, focusing on auditory, visual, and tactile stimulation. Users can press the buttons to hear corresponding piano notes and see the buttons light up, creating a playful and engaging environment.

## Team Members
- Carter Bell
- Danae Wnuk
- Danielle Gardner
- Grant Powell

## Course/Instructor
- Course: ENME 1850
- Instructor: Cecelia Wigal
- Date: November 20, 2023

## Features
- **Interactive Buttons**: Ten colored buttons that light up and play corresponding piano notes when pressed.
- **Sound and Light Integration**: Each button is integrated with an LED and a speaker to provide both visual and auditory feedback.
- **User-Friendly Design**: The buttons are designed to be easily operable by users with varying degrees of physical ability.

## Components
- **Microcontroller**: Ele Goo Uno R3 Arduino with an AT Mega 328 chipset.
- **Buttons**: Ten colored push buttons with integrated LEDs.
- **Speaker**: 5V speaker for sound output.
- **Relays**: One relay per button to control the LED and sound.
- **Power Supply**: 12V power for LEDs and 5V power for the Arduino.

## Circuit Schematic
(![Circuit Schematic](https://github.com/OkimaSha/Sensory-Table-Simon-Says-Buttons/blob/main/Images/CircuitDiagram.png))

## Build Instructions

### Step 1: Table Through Cuts
1. Cut ten 2.25-inch holes through the table surface for the buttons.
2. Make 2.75-inch counter cuts from the bottom side of the table to create a lip for the button housing.

### Step 2: Installing the Buttons
1. Remove the switch and LED assembly from each button by twisting it counterclockwise.
2. Insert the threaded portion of the button through the table holes and secure with the washer and nut.
3. Reattach the switch and LED assembly to the button housing.

### Step 3: Wiring the Buttons (12V Connections)
1. Install the relays in a circular arrangement beneath the table, perpendicular to the button pins.
2. Connect the left-hand pin on each button to the ON terminal of the corresponding relay.
3. Create a +12V power rail connecting each relay's COM terminal.
4. Connect the ground pin on the LED assembly to the power rail.

### Step 4: Wiring the 5V Connections
1. Create a +5V power line connecting the relays to the Arduino's 5VCC port and the -5V line to the GND port.
2. Wire each relay's IN terminal to an Arduino IO pin and the remaining button pin.
3. Connect the speaker's positive terminal to an Arduino IO pin and the negative terminal to the GND port.

### Step 5: Programming the Arduino
1. Flash the Arduino with the provided source code.
2. The code sets each button's IO pin as INPUT and assigns a unique frequency to each button corresponding to a piano note.

### Step 6: Constructing the Compartment
1. Construct a wooden compartment to house the wiring, ensuring it fits beneath the table.
2. Router down every corner and edge, then seal and paint the wood black.

### Step 7: Final Assembly
1. Connect the speaker to the Arduino and place the compartment over the wiring buses.
2. Secure the compartment to the table using metal L brackets.

## Operation
- Pressing a button will light up the LED and play the corresponding piano note.
- The module is powered by a rechargeable battery, ensuring portability and ease of use.

## Source Code
The Arduino source code can be found in the [[GitHub repository](https://github.com/OkimaSha/LightButtonModuleSensoryTable/blob/main/Ard-R3-Code.ino).]

## Acknowledgements
- Ezra Reynolds for providing crucial information from Signal Centers.
- Benjamin Swords for assisting with the CNC machine operations.


