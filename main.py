import serial
import time

ser=serial.Serial("COM7", 9600, timeout = 1)

print("Attendo eventi dal pulsante di Arduino")

file = open("./dati.csv", "a")

while True:
    linea = ser.readline().decode("utf-8").strip()

    if not linea:
        continue

    else:
        linea.startswith("EVENTO")
        timestamp=time.strftime("%H:%M:%S")
        print(f"Evento ricevuto alle {timestamp} - {linea}")

        file.write(f"{timestamp},{linea}\n") 
