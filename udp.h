/* 
    Author: Niek van Leeuwen
    Date:   13-11-2019
*/
#ifndef UDP_H
#define UDP_H

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>

#define PORT 7755
#define IP_ADDRESS "192.168.2.61"

int sock = 0, valread; 
struct sockaddr_in serv_addr; 
char buffer[1024] = {0}; 
    
// this function creates and connect a socket to the defined port and ip address
int connect() 
{ 
    sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0){ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, IP_ADDRESS, &serv_addr.sin_addr)<=0) { 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 

	return 0; 
} 

// this function sends the packet over the previously created socket
int send_packet(SENSOR_DATA sensordata){
    // check if a socket has been created
    if(sock > -1){
        int tmp = send(sock , (void *)&sensordata, sizeof(sensordata),0); 
        if(tmp > -1){
            printf("\nPacket send!\n");
        }
    }
    return -1;
}

#endif // UDP_H