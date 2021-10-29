// client for chatting with server side

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>

#define MAX 80 
#define PORT 8084
#define SA struct sockaddr 

void clientChat(int sockfd) 
{ 
    char buff[MAX]; 
    int i; 
    for (;;) { 
        // Send a string to server
		bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        i = 0; 
        while ((buff[i++] = getchar()) != '\n'); 
        write(sockfd, buff, sizeof(buff)); 
        
		// Receive a string from server
		bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
        
		// Exit if the received string is "exit"
		if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client exits...\n"); 
            break; 
        } 
    } 
} 
  
int main() 
{ 
    int sockfd, vsockfd; 
    struct sockaddr_in servAddr;  
  
    // socket creation and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(-1); 
    } 
    else
        printf("Socket successfully created..\n"); 
      
    // assign IP, PORT 
    servAddr.sin_family = AF_INET; 
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servAddr.sin_port = htons(PORT); 
	memset(servAddr.sin_zero, 0, sizeof servAddr.sin_zero);
	
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servAddr, sizeof(servAddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(-2); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chatting with server
    clientChat(sockfd); 
  
    // close the socket 
    if (!close(sockfd)) printf("Socket on port %d is succesfully closed\n",PORT); 
	else printf("Cannot close socket on port %d \n",PORT); 
}