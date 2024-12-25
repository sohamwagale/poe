#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main() {
    char buf[512];
    int sckfd, get;
    struct sockaddr_in serv_addr;
    
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    
    // Use inet_pton for better portability
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(1);
    }
    
    serv_addr.sin_port = htons(1500);
    
    // Create the socket
    if ((sckfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        close(sckfd);
        exit(1);
    }
    
    printf("\nConnected to server\n");
    
    while (1) {
        printf("\nEnter the string: ");
        scanf("%s", buf); // No need for '&' with arrays
        
        // Sending data
        get = sendto(sckfd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        
        if (get < 0) {
            perror("Send failed");
            break;
        }

        printf("Data sent: %s\n", buf);
        
        if (strcmp(buf, "x") == 0) {
            break;
        }
    }
    
    printf("Client down\n");
    close(sckfd);
    return 0;
}

