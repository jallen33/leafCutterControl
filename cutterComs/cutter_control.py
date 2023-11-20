import serial
import time

port = serial.Serial(port='/dev/cu.usbserial-D306E157', baudrate=57600) # red XBee

# port = serial.Serial(port='/dev/cu.usbserial-A700ewHs', baudrate=57600) # yellow XBee

# port = serial.Serial(port='/dev/cu.usbmodem1301', baudrate=57600) # arduino

while True:
    print(
        "Close Gripper (g)\n"
        "Open Gripper(h)\n"
        "Close Gripper Slowly (j)\n"
        "Open Gripper Slowly (k)\n"                
        "Close Cutter (u)\n"
        "Open Cutter (i)\n"        
        "Open Cutter Slowly (p)\n"
        "Start Saw (c)\n"
        "Stop Saw (s)\n"       
        )

    i = input("Choose an Action: ")
    port.write(i.encode())
    time.sleep(.5)
    print(port.readline().decode('ascii'))
