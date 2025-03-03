#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main() {
    int soc = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { AF_INET, htons(7891), inet_addr("127.0.0.1") };
    connect(soc, (struct sockaddr*)&addr, sizeof(addr));

    printf("Connected to server\nEnter file name: ");
    char fname[50], buffer[1024];
    scanf("%s", fname);
    send(soc, fname, strlen(fname) + 1, 0);
    while (recv(soc, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
    }
    close(soc);
    return 0;
}



#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int welcome = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { AF_INET, htons(7891), inet_addr("127.0.0.1") };
    bind(welcome, (struct sockaddr*)&addr, sizeof(addr));
    listen(welcome, 5);

    int new_soc = accept(welcome, NULL, NULL);
    char fname[50], buffer[1024];
    recv(new_soc, fname, sizeof(fname), 0);
    int fd = open(fname, O_RDONLY);

    if (fd < 0) {
        send(new_soc, "File not found\n", 15, 0);
    } else {
        while (read(fd, buffer, sizeof(buffer)) > 0) {
            send(new_soc, buffer, sizeof(buffer), 0);
        }
        close(fd);
    }
    close(new_soc);
    close(welcome);
    return 0;
}




