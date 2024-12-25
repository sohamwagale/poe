#include <iostream>
#include <string>
using namespace std;

// Function to perform XOR on two binary strings
string xorOperation(string a, string b) {
    string result = "";
    for (size_t i = 0; i < b.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

// CRC Receiver function
bool crcReceiver(string receivedData, string generator) {
    // Perform XOR division
    for (size_t i = 0; i < receivedData.length() - generator.length() + 1; i++) {
        if (receivedData[i] == '1') {
            string temp = receivedData.substr(i, generator.length());
            string remainder = xorOperation(temp, generator);
            receivedData.replace(i, generator.length(), remainder);
        }
    }

    // Check if the remainder is all zeros
    return receivedData.substr(receivedData.length() - generator.length() + 1) == string(generator.length() - 1, '0');
}

int main() {
    string receivedData = "1101011011100"; // Received message (with CRC)
    string generator = "1011";             // Generator polynomial

    // Check if the received data is valid
    if (crcReceiver(receivedData, generator)) {
        cout << "Data is valid (No error detected)." << endl;
    } else {
        cout << "Error detected in the data." << endl;
    }

    return 0;
}
