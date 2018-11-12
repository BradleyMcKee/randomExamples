import serial #THIS IMPORTS THE SERIAL TO SEE IF WE CAN SEE THE SERIAL PORT OF THE USB
from dronekit import connect
import time
#Dronekit is used to see the values we use to set the LEDs


ser = serial.Serial('/dev/ttyS2',dsrdtr = True, rtscts = True) #serial of the device used (teensy)
ser.baudrate = 19200 #Baudrate of teensy communication to drone
#selected baudrate is a communication band between the
ser.open() #Opens the port for communication
ser.setRTS(True) #allows the teensy to receive data

#connects to the 3DR Solo
vehicle = connect("udpout:127.0.0.1:14560", wait_ready=True)
print " GPS: %s" % vehicle.location.global_frame
altitude = vehicle.location.global_frame.alt
batterylvl = vehicle.battery.level
batteryvoltage = vehicle.battery.voltage


while altitude != 0 and batterylvl > 50:
	if altitude < 4: #display red LED if less than 4 ft.
		#red led to pinout
		print "RED LED ON"
		ser.write(0) #sends 0 to the serial for the teensy to take in
	elif altitude <= 8:
		#yellow led to pinout
		print "YELLOW LED ON"
		ser.write(1) #sends 1 to the serial for pin 1 on teensy to take in
	else:
		#green led to pinout
		print "GREEN LED ON"
		ser.write(2) #sends 2 to the serial...
	altitude = vehicle.location.global_frame.alt  #updates altitude in while loop
print "BATTERY LEVEL TOO LOW PLEASE LAND"
print "altitude: %s" % vehicle.location.global_frame.alt

ser.close()
vehicle.close()
time.sleep(2)
