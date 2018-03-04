# Rocket Ignition
The Rocket Ignition system is a custom printed circuit board to handle the sequential launch of up to 5 smoke rockets from an rc plan. On ground, the system prevents accidental launch of the smoke rockets with some security features, such as an RC release switch and a hard wired dip switch. 
Once in the air, the pilot will release the power relais by triggering an rc switch (ch2) and then, whenver he wants to launch a smoke rocket, by triggering the realease switch (ch1). The system will open the approriate relais, making sure all security checks are passed beforehand. 

## Requirements
A printed circuit board (pcb) with the correct version is required. 
- main_pcb_xx.cpp is the main arduino programm for pcb version xx. 
- two RC channels: trigger for rocket launcher (ch1), release switch (ch2)

Feel free to contact us for the newest custom built pcb. 
Also, we can preconfigure a pcb and the lastet version of the pcb for you. Feel free to contact us. 

## Usage
Download or clone this repository to your Arduino IDE of choice. We developed the code with PlatformIO on VScode. 
Upload the correct main_...cpp file to the Arduino. Make sure to upload the correct code required for the pcb version. 

## How to use the Rocket Ignition board
... 


