# Read me

The folowing example request time from server to client, wiht nanomsg. 
To test server and client with ipc. Type the following commands in this paths. Open two terminals, one for server and other for client.

#### 1. Go to 
execpath = SensorProyect/build/main-exec
#### 2. Exec 
#### Server 
```console
tonix@desk:~$<execpath> ./sensor server

```
#### Client

```console
tonix@desk:~$<execpath> ./sensor client Sensor Temp
tonix@desk:~$<execpath> ./sensor client Sensor Hum
tonix@desk:~$<execpath> ./sensor client Time <timestamp> <Temp/Hum>
```
posible commands
        //COMANDS FROM CLIENT TO SERVER

        //"Sensor Temp" --> returns last taken temperature
        //"Sensor Hum" --> returns last taken humidty
        //"Sensor Both"--> returns last boths
        //"Time <timestamp> <sensor type>" --> return sensor output in that time
#### 3. Expected output
SERVER: RECEIVED DATE REQUEST

SERVER: SENDING DATE Wed Apr 22 22:13:26 2020