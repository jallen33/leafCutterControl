import serial
import time
import struct

port_file = '/dev/tty.usbserial-AC012VDW'
baud = 57600

port = serial.Serial(port=port_file, baudrate=baud)

def receiveData():
    tmp = bytearray(4)
    tmp[0] = ord(port.read())
    tmp[1] = ord(port.read())
    tmp[2] = ord(port.read())
    tmp[3] = ord(port.read())

    val = struct.unpack(">i",tmp)

    print(val[0])

while True:
    a = port.read()

    while a != b'!':
        print(a)

    a = port.read()
    while a != b'$':
        print(a)

    print("Pitch: ")
    receiveData()
    print("Roll:")
    receiveData()
    print("Weight:")
    receiveData()

    print()
    print()

    time.sleep(0.01)
