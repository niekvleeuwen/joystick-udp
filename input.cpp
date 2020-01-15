#include "input.h"

Input::Input(UDP *_udp){
    udp = _udp;
}

bool Input::setupInput(){
    // set up input
    joystick1 = open("/dev/input/js0", O_NONBLOCK);
    joystick2 = open("/dev/input/js1", O_NONBLOCK);
 
    if(joystick1 < 0){
        perror("There was a problem with the reading of the input of Joystick 1");
        return false;
    }
    if(joystick2 < 0){
        perror("There was a problem with the reading of the input of Joystick 2");
        return false;
    }
    return true;
}

bool Input::readJoystick(){
    // event loopz
    while(true){
        if(readJoystick1() || readJoystick2()){
            udp->sendPacket(joystickData);
        }
        sleep(0.5);
    }
}

bool Input::readJoystick1(){
    if(read(joystick1, &event, sizeof(event)) > -1){
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
                printf("Joystick 1 --> Button %d: %d\n", event.number ,event.value);
            }
            else{
                if(event.number == 0){
                    joystickData.yAxis = event.value; 
                }else if(event.number == 1){
                    joystickData.xAxis = event.value;
                }else if(event.number == 2){
                    joystickData.gripperAxis = event.value;
                }
                printf( "Joystick 1 --> Axis %d: %d\n", (int) event.number, event.value );
            }
            return true;
        }else{
            printf( "Initializing joystick 1...\n" );
        }
    }
    return false;
}

bool Input::readJoystick2(){
    if(read(joystick2, &event, sizeof(event)) > -1){
        if(event.type == JOYSTICK_EVENT_AXIS){
            if(event.number == 0){
                joystickData.tiltAxis = event.value;
            }else if(event.number == 1){
                joystickData.zAxis = event.value;
            }
            printf( "Joystick 2 --> Axis %d: %d\n", (int) event.number, event.value );
            return true;
        }else{
            printf( "Initializing joystick 2...\n" );
        }
    }
    return false;
}
