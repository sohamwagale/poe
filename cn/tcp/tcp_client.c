#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    char buff[512];
    int SocketFD;
    struct sockaddr_in stSockAddr;

    // Create socket
    if ((SocketFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    bzero(&stSockAddr, sizeof(stSockAddr));
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(1109);

    // Use inet_pton instead of inet_addr
    if (inet_pton(AF_INET, "127.0.0.1", &stSockAddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(SocketFD, (struct sockaddr*)&stSockAddr, sizeof(stSockAddr)) < 0) {
        perror("Cannot connect");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Send data to server
        printf("Enter data to send: ");
        fgets(buff, sizeof(buff), stdin);
        write(SocketFD, buff, strlen(buff));

        // Receive response from server
        int n = read(SocketFD, buff, sizeof(buff) - 1);
        if (n <= 0) {
            break;  // Break if server closes the connection or error occurs
        }
        buff[n] = '\0';  // Null-terminate the received data
        printf("Received from server: %s\n", buff);

        // Exit if server sends "x"
        if (strcmp(buff, "x") == 0) {
            break;
        }
    }

    close(SocketFD);
    return EXIT_SUCCESS;
}

