# IoT_MQTT_Node-RED_example
IoT example with Raspberry Pi and Arduino using MQTT and Node-RED

This is a very simple IoT example using Arduino UNO for digital input and output.
The control program is running on a Raspberry Pi 3 B+ using Node-RED.
Communication between RPi and Arduino is with MQTT using the Mosquitto MQTT broker
installed on the RPi.

## Installation
### Arduino
This test setup is using an Arduino UNO and an Ethernet shield (https://www.arduino.cc/). 
Connected to the Arduino is a LED and a switch as described in the schematic in the figures directory.

It is assumed that the Arduino development environment is installed.
This example was tested with the Arduino Windows IDE (https://www.arduino.cc/en/Guide/Windows)
and the Arduino Linux IDE (https://www.arduino.cc/en/Guide/Linux).

Install Arduino PubSubClient MQTT Client using Library Manager the in Arduino IDE.

Download "ArdMQTTio.ino" from the source directory and open it in the Arduino development environment.
The address to the Mosquitto broker (i.e. the IP address of the RPi) must be updated to the correct value.
Then upload the code to the Arduino UNO and the program will be started.

### Raspberry Pi
Install the Mosquitto MQTT broker (http://mosquitto.org/) on Raspberry Pi using the following steps:
* $ wget http://repo.mosquitto.org/debian/mosquitto-repo.gpg.key
* $ sudo apt-key add mosquitto-repo.gpg.key
* $ cd /etc/apt/sources.list.d/
* $ sudo wget http://repo.mosquitto.org/debian/mosquitto-stretch.list
* $ sudo apt-get update
* $ sudo apt-get install mosquitto mosquitto-clients
Check that the Mosquitto MQTT broker is running:
* sudo service mosquitto status

Node-RED (https://nodered.org/) is pre-installed on Rasbian. 
The run-time environment can be launched under ‘Menu/Programming/Node-RED’.

Install the npm package manager.
* $ sudo apt-get install npm

Launch a web browser, either locally at the RPi: http://localhost:1880 or at: http://192.168.1.162:1880 
(192.168.1.162 is the RPi IP address in my setup).
  
Then install the Dashboard package (https://github.com/node-red/node-red-dashboard)
using "Manage palette" in the menu (search fornode-red-dashboard).
Then stop and re-start Node-RED.

Download the file "Node-RED_MQTT.txt" from the source directory and copy the content to the clipboard.
In the Node-RED web page open the Import menu item and get the code from the clipboard.

In the figures directory there is a screenshot file showing the blocks of the Node-RED program.

The address to the Mosquitto broker (i.e. the IP address of the RPi) must be updated to the correct value 
by changing the server address in the mqtt block (double click on one of the mqtt blocks to edit).

## Run the example
Click on "Deploy" in the Node-RED web page and the Node-RED program will run.
Test the user interface by launching a web browser, either locally at the RPi: http://localhost:1880/ui or at: http://192.168.1.162:1880/ui 
(192.168.1.162 is the RPi IP address in my setup).

In the figures directory there is a screenshot file showing the user interface.

## More information
https://github.com/ifding/iot/blob/master/mqtt/mqtt-raspberry-pi-arduino.md
