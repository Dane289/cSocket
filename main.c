/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: stn
 *
 * Created on November 20, 2018, 10:13 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

int sockfd;

void connectToSocket(){
    int portno = 80, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
  
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        printf("ERROR connecting\n");
}

void disconnectSocket(){
    sockfd = -1;
}

void performGet(){
    char buf[2056];
    char *header = "GET / HTTP/1.1\r\n\r\n";
    send(sockfd,header,strlen(header),0);
    int byte_count = recv(sockfd,buf,sizeof(buf)-1,0); // <-- -1 to leave room for a null terminator
    buf[byte_count] = 0; // <-- add the null terminator
    printf("recv()'d %d bytes of data in buf\n",byte_count);
    printf("%s\n",buf);
}

void handleInput(int option) {
    if(option == 1) {
        connectToSocket();
    } else if(option == 2) {
        disconnectSocket();
    } else if(option == 3){
        performGet();
    } else if(option == 4){
        printf("Exiting...");
    } else {
        printf("Not available!\n\n");
    }
        
}
void showMenuContent() {
    printf("1. Connect to socket\n");
    printf("2. Disconnect\n");
    printf("3. GET\n");
    printf("4. Exit\n");
}

int main(int argc, char** argv) {

    int i;
    do {
        showMenuContent();
        scanf("%d", &i);
        handleInput(i);
    } while(i != 4);

    return (EXIT_SUCCESS);
}



