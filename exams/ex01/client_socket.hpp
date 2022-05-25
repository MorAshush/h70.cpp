#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP



class TCPClientSocket
{

public:  
/**
 * @brief constructor - opens a socket (and connects it to server)
 * @param server address to conncet client to
 */  
	ClientSocket(char* a_serverAddr);

/**
 * @brief sends a packet from client to server. (adds TCP header to the packet)
 * @param a ptr to message
 * @return 0 if sent successfully, or -1 if failed
 */ 
	int send(char* a_data);

/**
 * @brief recieve a packet from server to client.
 * @param a ptr to a buffer that recieves the message
 * @return 0 if recieved successfully, or -1 if failed
 */ 
	int recieve(char* m_buffer);

//	int get_socket();

private:
	int m_socket;
	char* m_serverAddr;
};



#endif //CLIENT_SOCKET_HPP