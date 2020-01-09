#ifndef UDP_H
#define UDP_H

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string>

class UDP{
	public:
		UDP(int _port, std::string _ipAddress);
		int setupUDP();
		int sendPacket(JOYSTICK_DATA joystickData);
	private:
		int sock = 0; 
		int port;
		std::string ipAddress;
		struct sockaddr_in serv_addr; 
		char buffer[1024] = {0}; 
};

#endif // UDP_H