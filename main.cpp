#include "main.h"

int main(){
    int inputdevice = open("/dev/input/js0", O_RDONLY);
 
    if(inputdevice < 0){
        printf( "There was a problem with the reading of the\n" );
        exit(1);
    }
        
    // event loop
    while(true){
        read( inputdevice, &e, sizeof(e) );
 
        //printf( "%d %d %d %d\n", e.time, e.value, e.type, e.number );
 
        if(e.type == JS_EVENT_BUTTON || e.type == JS_EVENT_AXIS){
            if( e.type == JS_EVENT_BUTTON ){
                printf( "button#%d value:%d\n", (int) e.number, e.value );
            }
            else{ 
                printf( "axis#%d value:%d\n", (int) e.number, e.value );
            }
        }else{
            printf( "Initializing...\n" );
        }
    }
 
    return 0;
}