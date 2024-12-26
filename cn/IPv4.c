#include <stdio.h>

int main() {
    int a, b, c, d; // Variables for the 4 octets of the IP address
    char class;     // To store the class of the IP address

    // Input the IP address
    printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    // Determine the class and calculate Network ID and Host ID
    if (a >= 1 && a <= 126) {
        class = 'A';
        printf("Class: %c\n", class);
        printf("Network ID: %d.0.0.0\n", a);
        printf("Host ID: 0.%d.%d.%d\n", b, c, d);
    } else if (a >= 128 && a <= 191) {
        class = 'B';
        printf("Class: %c\n", class);
        printf("Network ID: %d.%d.0.0\n", a, b);
        printf("Host ID: 0.0.%d.%d\n", c, d);
    } else if (a >= 192 && a <= 223) {
        class = 'C';
        printf("Class: %c\n", class);
        printf("Network ID: %d.%d.%d.0\n", a, b, c);
        printf("Host ID: 0.0.0.%d\n", d);
    } else if (a >= 224 && a <= 239) {
        class = 'D';
        printf("Class: %c (Used for Multicasting)\n", class);
    } else if (a >= 240 && a <= 255) {
        class = 'E';
        printf("Class: %c (Used for Experimental purposes)\n", class);
    } else {
        printf("Invalid IP address.\n");
    }

    return 0;
}
