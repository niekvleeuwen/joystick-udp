/* 
    Author: Niek van Leeuwen
    Date:   13-11-2019
*/
#include "main.h"
#include "udp.h"

int main(){
    // set up socket
    if(connect() < 0){
        // error message will be given in the connect() function
        exit(-1);
    }

    // set up input
    inputdevice = open("/dev/input/js0", O_RDONLY);
 
    if(inputdevice < 0){
        printf("There was a problem with the reading of the input\n");
        exit(-1);
    }
        
    // event loop
    while(true){
        read(inputdevice, &e, sizeof(e)); //the only problem here is that read() is blocking
 
        if(e.type == JS_EVENT_BUTTON || e.type == JS_EVENT_AXIS){
            if( e.type == JS_EVENT_BUTTON ){
                printf( "button#%d value:%d\n", (int) e.number, e.value );
            }
            else{ 
                printf( "axis#%d value:%d\n", (int) e.number, e.value );
                if(e.number == 0){
                    sensordata.potiy_return = e.value;
                }else if(e.number == 1){
                    sensordata.potix_return = e.value;
                }
                send_packet(sensordata);
            }
        }else{
            printf( "Initializing...\n" );
        }
    }
 
    return 0;
}