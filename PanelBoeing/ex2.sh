# Flightberry PI configuration
# 
# Wiringpi (GPIO)

#pin (0)17 (ISR)
gpio mode 0 in
gpio mode 0 up
gpio edge 0 falling
gpio export 17 in


#pin (1)18 (ISR)
gpio mode 1 in
gpio mode 1 up
gpio edge 1 falling
gpio export 18 in

#pin (2)27 (ISR)
gpio mode 2 in
gpio mode 2 up
gpio edge 2 falling
gpio export 27 in

#pin (3)22 (ISR)
gpio mode 3 in
gpio mode 3 up
gpio edge 3 falling
gpio export 22 in

#load i2c kernel module
#gpio load i2c

#export the pins
#gpio export 17 in
#gpio export 18 in
#gpio export 27 in
#gpio export 22 in
 
