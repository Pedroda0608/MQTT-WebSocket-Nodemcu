# MQTT-WebSocket-Nodemcu
En este repositorio encuentras los ficheros necesarios para la comunicacion mediante MQTT entre una web y una placa NodeMCU.

En <a href="https://github.com/Pedroda0608/MQTT-WebSocket-Nodemcu/tree/master/Web%20mqtt-websocket">Web mqtt-websocket</a> se alojan todos los ficheros de la Web, mdiante el servicio "Web Socket" mediante Javascript(mqttws31.js) este realiza la llamada a MQTT a traves del puero 9001.

Antes de ejecutar, debes modificar los datos de tu servidor MQTT, usuario y contraseña.

En <a href="https://github.com/Pedroda0608/MQTT-WebSocket-Nodemcu/tree/master/NodeMCU_MQTT-WebSocket">NodeMCU_MQTT-WebSocket</a> encontraras el fichero "ino" para cargar en tu placa NodeMCU mediante el IDE de Arduino, antes debes modificar todos los datos referentes a la conexion WiFi y MQTT.

El fichero <a href="https://github.com/Pedroda0608/MQTT-WebSocket-Nodemcu/blob/master/mqtt_esp8266_9001_LED.fzz">mqtt_esp8266_9001_LED.fzz</a> describe el esquema de conexiones para el proyecto.
