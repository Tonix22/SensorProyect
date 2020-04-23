# Read me

The folowing example request time from server to client, wiht nanomsg. 
To test server and client with ipc. Type the following commands in this paths. Open two terminals, one for server and other for client.

#### 1. Go to 
execpath = SensorProyect/build/main-exec
#### 2. Exec 
#### Server 
```console
tonix@desk:~$<execpath> ./sensor server ipc:///tmp/reqrep.ipc

```
#### Client

```console
tonix@desk:~$<execpath> ./sensor client ipc:///tmp/reqrep.ipc

```
#### 3. Expected output
SERVER: RECEIVED DATE REQUEST

SERVER: SENDING DATE Wed Apr 22 22:13:26 2020