// Single thread server for chatting with client

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <stdlib.h> 
#include <string.h> 

#define MAX 80 
#define PORT 8084
#define SA struct sockaddr 
  
void serverChat(int sockfd) 
{ 
    char buff[MAX]; 
    int i; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
		// read a message from client to buffer 
		read(sockfd, buff, sizeof(buff)); 
		
        // print the message in buffer  
        printf("From client: %s\t To client : ", buff); 
        
		bzero(buff, MAX); 
        i = 0; 
        // input server message to buffer 
        while ((buff[i++] = getchar()) != '\n'); 
  
        // and send buffer data to client 
        write(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server exits...\n"); 
            break; 
        } 
    } 
} 
  

int main() 
{ 
    int sockfd, vsockfd, len; 
    struct sockaddr_in servAddr, cliAddr; 
  
    // socket creation and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
      
    // assign IP, PORT 
    servAddr.sin_family = AF_INET; 
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servAddr.sin_port = htons(PORT); 
	memset(servAddr.sin_zero, 0, sizeof servAddr.sin_zero);
  
    // Bind newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servAddr, sizeof(servAddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen  
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cliAddr); 
  
    // Accept the data packet from client and verification 
    vsockfd = accept(sockfd, (SA*)&cliAddr, &len); 
    if (vsockfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    // Function for chatting with client 
    serverChat(vsockfd); 
  
    // After chatting close the socket 
	if (!close(sockfd)) printf("Socket on port %d is succesfully closed\n",PORT); 
	else printf("Cannot close socket on port %d \n",PORT); 
}