#include "input.cpp"
#include "udp.cpp"

int main(){
    int port = 7755;
    std::string ipAddress = "192.168.100.10";
    UDP *udp = new UDP(port, ipAddress);
    Input *input = new Input(udp);

    // setup the input and if succesful read the input
    if(input->setupInput()){
        input->readJoystick();
    }
 
    return 0;
}