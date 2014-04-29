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

#pin (4)23 (ISR)
gpio mode 4 in
gpio mode 4 up
gpio edge 4 falling
gpio export 23 in

#pin (5)24 (ISR)
gpio mode 5 in
gpio mode 5 up
gpio edge 5 falling
gpio export 24 in

#pin (2)27 (ISR)
#gpio mode 2 in
#gpio mode 2 up
#gpio edge 2 falling
#gpio export 27 in

#pin (3)22 (ISR)
#gpio mode 3 in
#gpio mode 3 up
#gpio edge 3 falling
#gpio export 22 in

#load i2c kernel module
gpio load i2c

#export the pins
#gpio export 17 in
#gpio export 18 in
#gpio export 27 in
#gpio export 22 in
 
