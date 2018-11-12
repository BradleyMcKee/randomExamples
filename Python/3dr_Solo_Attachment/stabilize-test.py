#establish communications with mavlink and Ground Control Station
from dronekit import connect, VehicleMode, LocationGlobalRelative
from pymavlink import mavutil
import time

import argparse
parser = argparse.ArgumentParser(description='launch the drone through mavlink')
parser.add_argument('--connect', default='127.0.0.1:14550')
args = parser.parse_args()
print 'TEST AUTO TAKEOFF AND LANDING FEATURE'
# Connect to the Quad
print 'Connecting to ODU Quadcopter on: %s' % args.connect
vehicle = connect(args.connect, baud=57600, wait_ready=True)

# Function to arm and then takeoff to a user specified altitude
def arm_and_takeoff(aTargetAltitude):

  print "Basic pre-flight check"
  # Don't let the user try to arm until autopilot is ready
  while not vehicle.is_armable:
    print " Waiting for vehicle to initialize..."
    time.sleep(1)

  print " motors"
  # Copter should arm in GUIDED mode
  vehicle.mode    = VehicleMode("GUIDED")
  vehicle.armed   = True

  while not vehicle.armed:
    print " Waiting for arming..."
    time.sleep(1)

  print "Taking off!"
  vehicle.simple_takeoff(aTargetAltitude) # Take off to target altitude

  # Check that vehicle has reached takeoff altitude
  while True:
    print " Altitude: ", vehicle.location.global_relative_frame.alt
    #Break and return from function just below target altitude.
    if vehicle.location.global_relative_frame.alt>=aTargetAltitude*0.95:
      print "Reached target altitude"
      break
    time.sleep(1)

# Initialize the takeoff sequence to 8m
arm_and_takeoff(8)
print("stablized take off successful")

# Hover for 30 seconds
time.sleep(30)

print("Hover test complete, attempting to land")
vehicle.mode = VehicleMode("LAND")

# Close vehicle object
vehicle.close()
