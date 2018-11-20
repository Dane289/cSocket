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

void connectToSocket(){
     int sockfd, portno = 80, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
  
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname("localhost");
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
        error("ERROR connecting");
}

void disconnectSocket(){
    printf("2");
}

void performGet(){
    printf("3");
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



