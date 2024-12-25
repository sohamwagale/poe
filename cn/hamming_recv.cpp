#include<bits/stdc++.h>
using namespace std;

// Function to reverse an array
void reverseArray(int arr[], int size) {
    for (int start = 0, end = size - 1; start < end; start++, end--) {
        swap(arr[start], arr[end]);
    }
}

// Function to calculate parity bit at a given index
int calculateParity(int i, int hamarr[], int hlen) {
    int exor = 0;
    for (int j = hlen - 1; j > i; j--) {
        if ((j & i) == i) {
            exor ^= hamarr[j];
        }
    }
    return exor;
}

// Function to check and correct errors in the received Hamming code
int checkAndCorrect(int hamarr[], int hlen) {
    int error_pos = 0;

    // Check parity bits
    for (int i = 1; i < hlen; i++) {
        if (hamarr[i] == 2) {
            hamarr[i] = calculateParity(i, hamarr, hlen);
        }
    }

    // Calculate the error position using parity bits
    for (int i = 1; i < hlen; i++) {
        if (hamarr[i] != calculateParity(i, hamarr, hlen)) {
            error_pos |= (1 << i);
        }
    }

    // If there's an error, correct it
    if (error_pos != 0) {
        cout << "Error at position: " << error_pos << "\n";
        hamarr[error_pos] ^= 1;  // Flip the erroneous bit
    }
    
    return error_pos;
}

int main() {
    cout << "Enter the received Hamming code: ";
    string received_code;
    cin >> received_code;

    int hlen = received_code.size();
    vector<int> hamarr(hlen);
    
    for (int i = 0; i < hlen; i++) {
        hamarr[i] = received_code[i] - '0';
    }

    // Reverse the received Hamming code to check parity
    reverseArray(hamarr.data(), hlen);

    // Check for errors and correct them if necessary
    checkAndCorrect(hamarr.data(), hlen);

    // Extract the original message (remove parity bits)
    cout << "Extracted original message: ";
    for (int i = 1, bit_count = 0; i < hlen; i++) {
        // If it's not a parity bit
        if (fmod(log2(i), 1) != 0) {
            cout << hamarr[i];
            bit_count++;
        }
    }

    cout << "\n";

    return 0;
}
/*
Reverse the received code: Since the Hamming code was generated with the bits reversed, we first reverse the received code for consistent checking.

Calculate parity for each index: The receiver re-calculates the parity bits and compares them with the received bits to detect errors.

Error Detection and Correction: If the parity check reveals a mismatch, the checkAndCorrect function determines the error position using the parity bits. It flips the incorrect bit to correct the message.

Extract the original message: Once the Hamming code is verified (and corrected if necessary), the program extracts the original message by ignoring the parity bits (which are powers of 2 indices).

*/