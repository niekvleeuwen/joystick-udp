#include "input.h"

Input::Input(UDP *_udp){
    udp = _udp;
}

bool Input::setupInput(){
    // set up input
    inputDevice = open("/dev/input/js0", O_RDONLY & O_NONBLOCK);
 
    if(inputDevice < 0){
        perror("There was a problem with the reading of the input");
        return false;
    }
    return true;
}

bool Input::readJoystick(){
    // event loop
    while(true){
        if(read(inputDevice, &event, sizeof(event)) > -1){
            if(event.type == JOYSTICK_EVENT_BUTTON || event.type == JOYSTICK_EVENT_AXIS){
                if(event.type == JOYSTICK_EVENT_BUTTON ){
                    printf( "Button %d - value:%d\n", (int) event.number, event.value );
                }
                else{ 
                    printf( "Axis: %d - value:%d\n", (int) event.number, event.value );
                    if(event.number == 0){
                        sensorData.potiy_return = event.value;
                    }else if(event.number == 1){
                        sensorData.potix_return = event.value;
                    }
                }
            }else{
                printf( "Initializing...\n" );
            }
        }
        udp->sendPacket(sensorData);
    }
}