#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char buf[512];
    int sckfd, nwfd, servlen, i, get;
    struct sockaddr_in cli_addr, serv_addr;
    
    // Create the socket
    if ((sckfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Server down");
        close(sckfd);
        exit(1);
    }
    
    // Initialize server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // Listen on all interfaces
    serv_addr.sin_port = htons(1500); // Set the port to 1500
    
    // Bind the socket to the address
    if (bind(sckfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Can not bind");
        close(sckfd);
        exit(1);
    }
    
    servlen = sizeof(cli_addr);
    printf("Server ready to receive data...\n");
    
    // Main loop to receive data
    while (1) {
        printf("\nReceiving data...\n");
        
        // Receive the data from client
        get = recvfrom(sckfd, buf, sizeof(buf), 0, (struct sockaddr *)&cli_addr, &servlen);
        
        if (get < 0) {
            perror("Failed to receive data");
            break;
        }
        
        printf("\n$Server :: %s\n", buf);
        
        // If received message is 'x', exit the loop
        if (strcmp(buf, "x") == 0) {
            break;
        }
    }
    
    printf("Server down\n");
    close(sckfd);
    return 0;
}

