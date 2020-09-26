#!/usr/bin/env python3

import os
import sys

if not os.getegid() == 0:
    sys.exit('Script must be run as root')


from time import sleep
from pyA20.gpio import gpio
from pyA20.gpio import port

led1 = port.PA20
led2 = port.PA10
led3 = port.PA9
led4 = port.PA8
led5 = port.PA7
led6 = port.PA19

gpio.init()
gpio.setcfg(led1, gpio.OUTPUT)
gpio.setcfg(led2, gpio.OUTPUT)
gpio.setcfg(led3, gpio.OUTPUT)
gpio.setcfg(led4, gpio.OUTPUT)
gpio.setcfg(led5, gpio.OUTPUT)
gpio.setcfg(led6, gpio.OUTPUT)

try:
    print ("Press CTRL+C to exit")
    while True:
        gpio.output(led1, 1)
        sleep(0.3)
        gpio.output(led1, 0)
        gpio.output(led2, 1)
        sleep(0.3)
        gpio.output(led2, 0)
        gpio.output(led3, 1)
        sleep(0.3)
        gpio.output(led3, 0)
        gpio.output(led4, 1)
        sleep(0.3)
        gpio.output(led4, 0)
        gpio.output(led5, 1)
        sleep(0.3)
        gpio.output(led5, 0)
        gpio.output(led6, 1)
        sleep(0.3)
        gpio.output(led6, 0)
except KeyboardInterrupt:
    print ("Goodbye.")
