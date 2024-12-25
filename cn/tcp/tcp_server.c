#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {
    char buff[512];
    int SocketFD, connectFD;
    struct sockaddr_in stSockAddr, cli_addr;
    socklen_t addr_len = sizeof(cli_addr);

    // Create socket
    if ((SocketFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    bzero(&stSockAddr, sizeof(stSockAddr));
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(1109);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(SocketFD, (struct sockaddr*)&stSockAddr, sizeof(stSockAddr)) < 0) {
        perror("Cannot bind");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(SocketFD, 2);

    // Accept a client connection
    if ((connectFD = accept(SocketFD, (struct sockaddr*)&cli_addr, &addr_len)) < 0) {
        perror("Cannot accept connection");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive data from client
        int n = read(connectFD, buff, sizeof(buff) - 1);
        if (n <= 0) {
            break;  // Break if client closes the connection or error occurs
        }
        buff[n] = '\0';  // Null-terminate the received data
        printf("Received: %s\n", buff);

        // Exit if client sends "x"
        if (strcmp(buff, "x") == 0) {
            break;
        }

        // Send a response to the client
        printf("Enter response: ");
        fgets(buff, sizeof(buff), stdin);
        write(connectFD, buff, strlen(buff));
    }

    close(connectFD);
    close(SocketFD);
    return EXIT_SUCCESS;
}

