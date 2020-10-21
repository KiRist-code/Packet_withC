#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>

void error_handling(char* message);

int main(int argc, char* argv[]){
    int tcp_sock, udp_sock;
    int sock_type;

    socklen_t optlen = sizeof(sock_type);
    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET,SOCK_DGRAM,0);

    if(getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen)<0){
        error_handling("getsockopt error");
    }
    printf("socket type one : %d", sock_type);

    if(getsockopt(udp_sock, SOL_SOCKET,SO_TYPE, (void*)&sock_type,&optlen)<0){
        error_handling("getsockopt error");
    }
    printf("socket type two : %d", sock_type);
    return 0;
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}
