//
//  main.c
//  TC_Socket
//
//  Created by Ryan Price on 9/13/18.
//  Copyright © 2018 Ryan Price. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, const char * argv[]) {
    // creat the socket
    int netWorkSocket;
    netWorkSocket = socket(AF_INET, SOCK_STREAM, 0);
    //address for the scoket
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9002);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if(connect(netWorkSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress))<0){
        printf("Error making connection \n\n");
    }
    //recive
    char serverResponce[256];
    recv(netWorkSocket, &serverResponce, sizeof(serverResponce), 0);
    
    printf("%s", serverResponce);
    close(netWorkSocket);
    return 0;
}
