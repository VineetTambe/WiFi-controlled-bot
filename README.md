# WiFi-controlled-bot
In this project I have used a NodeMCU to connect to my phone and send data via my phone to the node MCU.
Then tghe data is serially transmitted to an arduino nano which has the logic to drive an L293D motor driver.

The reason for such piggybacking of the ESP8266 based NodeMcu on the Arduino nano are the power issues faced due when the motor deiver code is dumped on the NodeMcu. 
The NodeMcu has poor current sorcing capabilities and hence had to be givven the 5V input from arduino and only worked fine when the data was serially transmitted to the arduino.
