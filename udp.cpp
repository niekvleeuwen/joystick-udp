#include "udp.h"

UDP::UDP(int _port, std::string _ipAddress){
	port = _port;
    ipAddress = _ipAddress;
	setupUDP();
}   

// this function creates and connect a socket to the defined port and ip address
int UDP::setupUDP(){ 
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0){ 
		perror("Socket creation error"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(port); 
	
	// convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, ipAddress.c_str(), &serv_addr.sin_addr)<=0) { 
		perror("Invalid address/ Address not supported"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
		perror("Connection Failed"); 
		return -1; 
	} 

	return 0; 
} 

// this function sends the packet over the previously created socket
int UDP::sendPacket(SENSOR_DATA sensor_data){
    // check if a socket is connected
    if(sock > -1){
        if(send(sock , (void *)&sensor_data, sizeof(sensor_data),0) > -1){
            printf("Packet send!\n");
			return 0;
        }else{
			perror("Packet not send");
			return -1;
		}
    }else{
		//reconnect the socket
		printf("error");
		return this->setupUDP();
	}
}