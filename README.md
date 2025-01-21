# ESP-32 Motor Controller

This code creates a bridge between the ESP-32 microcontroller and a ROS program running on a host computer such as a Raspberry Pi. This repo is a fork of the fork of the original code! The original README's can be found in the main repo directory.


## Components Used

- ESP-32
- X Motor Drivers


## Functionality

The main functionality provided is to receive motor speed requests over a serial connection, and provide encoder feedback.
The original code has provisions for other features - e.g. read/write of digital/analog pins, servo control, but I've never used them.

The main commands to know are

- `e` - Motor responds with current encoder counts for each motor
- `r` - Reset encoder values
- `o <PWM1> <PWM2>` - Set the raw PWM speed of each motor (-255 to 255)
- `m <Spd1> <Spd2>` - Set the closed-loop speed of each motor in *counts per loop* (Default loop rate is 30, so `(counts per sec)/30`
- `p <Kp> <Kd> <Ki> <Ko>` - Update the PID parameters