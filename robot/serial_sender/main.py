import serial
import time
import json

arduino = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=15)

def write_read(x):
    x = "test"
    arduino.write(bytes(x, "utf-8"))
    arduino.flush()
    print(f"Server| {x}")
    data = arduino.readline()
    print(f"Robot | {data}")



move = "forward"
times = 5
speed = 500

data = json.dumps({"move" : move, "times" : times, "speed" : speed}) + "\n"
write_read(data)