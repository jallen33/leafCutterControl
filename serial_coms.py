import serial
import time
import struct

port_file = '/dev/tty.usbserial-AC012VDW' # serial port of the serial device
baud = 57600

port = serial.Serial(port=port_file, baudrate=baud)

def receiveData():
    """
    function that receives 4 bytes and concatenate and output an integer
    """
    tmp = bytearray(4)
    tmp[0] = ord(port.read())
    tmp[1] = ord(port.read())
    tmp[2] = ord(port.read())
    tmp[3] = ord(port.read())

    val = struct.unpack(">i",tmp)

    print(val[0])

while True:
    a = port.read()

    while a != b'!': # start bit
        print(a)

    a = port.read() # second start bit
    while a != b'$':
        print(a)

    print("Pitch: ")
    receiveData() 
    print("Roll:")
    receiveData()
    print("Weight in grams:")
    receiveData()

    print()
    print()

    time.sleep(0.01)
