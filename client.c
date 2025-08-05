#include "unp.h"


int main(int argc,char**argv) {
    int sockfd,n;
    char recvline[MAXLINE+1];
    struct sockaddr_in servaddr;
    if (argc!=2) {
        printf("Usage: a.out <IPaddress>");
        exit(1);
    }
    if ((sockfd=socket(AF_INET,SOCK_STREAM,0))<0) {
        fprintf(stderr,"socket error\n",strerror(errno));
        exit(1);
    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8080);
    if (inet_pton(AF_INET,argv[1],&servaddr.sin_addr)<=0) {
        printf("inet_pton error for %s",argv[1]);
    }
    if (connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) {
        fprintf(stderr,"connect error\n",strerror(errno));
        exit(1);
    }
    while ((n=read(sockfd,recvline,MAXLINE))>0) {
        recvline[n]='\0';
        if (fputs(recvline,stdout)==EOF) {
            fprintf(stderr,"fputs error\n",strerror(errno));
            exit(1);
        }
    }
    if (n<0) {
        fprintf(stderr,"read error\n",strerror(errno));
        exit(1);
    }

    exit(0);
}