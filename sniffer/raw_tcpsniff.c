#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "hacking.h"

int main(){
    int i, recv_len, sockfd;

    unsigned char buffer[9000];
    
    if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) -1){
        fatal("in socket");
    }

    for(i=0; i<3; i++){
        recv_len = recv(sockfd, buffer, 8000, 0);
        printf("Got a %d byte packet\n", recv_len);
        dump(buffer, recv_len);
    }
}