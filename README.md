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

Download from the source directory and open it in the Arduino development environment.
Then upload the code to the Arduino and it will be started.

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

Node-RED is pre-installed on Rasbian. The run-time environment can be launched under ‘Menu/Programming/Node-RED’.

Install the npm package manager.
* $ sudo apt-get install npm

Launch a web browser; either locally at localhost:1880 or at (RPi IP address):1880.
  
Then install the Dashboard package (https://github.com/node-red/node-red-dashboard)
using "Manage palette" in the menu (search fornode-red-dashboard).
Then stop and re-start Node-RED.
