#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>

void error_handling(char *message);

int main(int argc, char* argv[]){
    int sock;
    int snd_buffer, rcv_buffer;
    socklen_t len;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    len = sizeof(snd_buffer);
    if(getsockopt(sock,SOL_SOCKET, SO_SNDBUF, (void*)&snd_buffer, &len) < 0){
        error_handling("getsockopt error");
    }
    len = sizeof(rcv_buffer);
    if(getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void*)&rcv_buffer, &len) < 0){
        error_handling("getsockopt error");
    }

    printf("input buffer size: %d\n", rcv_buffer);
    printf("output buffer size: %d\n",snd_buffer);
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}
