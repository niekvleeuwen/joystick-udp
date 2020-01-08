#ifndef INPUT_H
#define INPUT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include "sensordata.h"
#include "udp.h"

class Input{
	public:
        Input(UDP *_udp);
        bool setupInput();
        bool readJoystick();

	private:
        #define JOYSTICK_EVENT_BUTTON         0x01    // button pressed/released
        #define JOYSTICK_EVENT_AXIS           0x02    // joystick moved 
        #define JOYSTICK_EVENT_INIT           0x80    // initial state of device 

        struct joystickEvent {
                unsigned int time;      // event timestamp in milliseconds
                short value;            // value
                unsigned char type;     // event type
                unsigned char number;   // axis/button number
        };
        struct joystickEvent event;
        SENSOR_DATA sensorData;
        int inputDevice;
        UDP *udp;
};

#endif // INPUT_H