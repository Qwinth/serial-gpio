import serial
import time

class GPIO:
    HIGH = 1
    LOW = 0
    OUTPUT = 1
    INPUT = 0
    INPUT_PULLUP = 2
    LED_BUILTIN = 13
    
    def __init__(self, port):
        self.ser = serial.Serial(port)
        time.sleep(0.05)
    
    def pinMode(self, pin, mode):
        self.ser.write(f"pm,{pin},{mode}".encode())
        time.sleep(0.05)

    
    def digitalWrite(self, pin, value, t = 0.03):
        self.ser.write(f"dw,{pin},{value}".encode())
        time.sleep(t)

    def digitalRead(self, pin):
        self.ser.write(f"dr,{pin}".encode())
        time.sleep(0.05)
        return int(self.ser.readline())

    def analogWrite(self, pin, value, t = 0.03):
        self.ser.write(f"aw,{pin},{value}".encode())
        time.sleep(t)

    def analogRead(self, pin):
        self.ser.write(f"ar,{pin}".encode())
        time.sleep(0.05)
        return int(self.ser.readline().decode())
    
    def close(self):
        self.ser.close()