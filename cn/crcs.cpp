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

// CRC Sender function
string crcSender(string data, string generator) {
    // Append zeros based on the degree of the generator
    data += string(generator.length() - 1, '0');

    // Perform XOR division
    for (size_t i = 0; i < data.length() - generator.length() + 1; i++) {
        if (data[i] == '1') {
            string temp = data.substr(i, generator.length());
            string remainder = xorOperation(temp, generator);
            data.replace(i, generator.length(), remainder);
        }
    }

    // Return the remainder (CRC)
    return data.substr(data.length() - generator.length() + 1);
}

int main() {
    string data = "1101011011"; // Original message
    string generator = "1011";   // CRC Generator polynomial

    // Calculate and append CRC to data
    string crc = crcSender(data, generator);
    cout << "Transmitted Data (Message + CRC): " << data + crc << endl;

    return 0;
}
