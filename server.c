#include "unp.h"
#include <time.h>

#include <errno.h>



int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server running on 127.0.0.1:8080...\n");

    for (;;) {
        connfd = accept(listenfd, NULL, NULL);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        ticks = time(NULL);
        char *time_str = ctime(&ticks);
        if (time_str == NULL) {
            fprintf(stderr, "ctime returned NULL\n");
            close(connfd);
            continue;
        }

        snprintf(buff, sizeof(buff), "%24s\r\n", time_str);
        write(connfd, buff, strlen(buff));
        close(connfd);
    }
}
