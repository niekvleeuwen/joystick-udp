#include "input.h"

Input::Input(UDP *_udp){
    udp = _udp;
}

bool Input::setupInput(){
    // set up input
    inputDevice = open("/dev/input/js0", O_NONBLOCK);
 
    if(inputDevice < 0){
        perror("There was a problem with the reading of the input");
        return false;
    }
    return true;
}

bool Input::readJoystick(){
    // event loopz
    while(true){
        if(read(inputDevice, &event, sizeof(event)) > -1){
            if(event.type == JOYSTICK_EVENT_BUTTON || event.type == JOYSTICK_EVENT_AXIS){
                if(event.type == JOYSTICK_EVENT_BUTTON ){
                    joystickData.button0 = false;
                    joystickData.button1 = false;
                    joystickData.button2 = false;
                    joystickData.button3 = false;
                    joystickData.button4 = false;
                    joystickData.button5 = false;
                    joystickData.button6 = false;
                    joystickData.button7 = false;
                    if(event.value == 1){
                        if(event.number == 0){
                            joystickData.button0 = true;
                        }else if(event.number == 1){
                            joystickData.button1 = true;
                        }else if(event.number == 2){
                            joystickData.button2 = true;
                        }else if(event.number == 3){
                            joystickData.button3 = true;
                        }else if(event.number == 4){
                            joystickData.button4 = true;
                        }else if(event.number == 5){
                            joystickData.button5 = true;
                        }else if(event.number == 6){
                            joystickData.button6 = true;
                        }else if(event.number == 7){
                            joystickData.button7 = true;
                        }
                    }
                    printf("=======\nButton 0: %d\n", joystickData.button0);
                }
                else{
                    if(event.number == 0){
                        joystickData.yAxis = event.value / 4; 
                    }else if(event.number == 1){
                        joystickData.xAxis = event.value / 4;
                    }else if(event.number == 2){
                        joystickData.zAxis = event.value / 4;
                    }
                    printf( "Axis %d - value:%d\n", (int) event.number, event.value );
                }
            }else{
                printf( "Initializing...\n" );
            }
        }
        sleep(0.1);
        udp->sendPacket(joystickData);
    }
}