#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int size) {
    for (int start = 0, end = size - 1; start < end; start++, end--) {
        swap(arr[start], arr[end]);
    }
}

int calculateParity(int i, int hamarr[], int hlen) {
    int exor = 0;
    for (int j = hlen - 1; j > i; j--) {
        if ((j & i) == i) {
            exor ^= hamarr[j];
        }
    }
    return exor;
}

int main() {
    cout << "Enter the Message: ";
    string message;
    cin >> message;

    reverse(message.begin(), message.end());

    int mlen = message.size();
    vector<int> msgarr(mlen);
    for (int i = 0; i < mlen; i++) {
        msgarr[i] = message[i] - '0';
    }

    int r = 0;
    while ((1 << r) < mlen + r + 1) {
        r++;
    }

    int hlen = mlen + r + 1;
    vector<int> hamarr(hlen, 2);

    cout << "(" << mlen << ")message_bits + (" << r << ")redundant_bits + 1 parity_bit = " << hlen << " bits\n\n";

    for (int i = 0, j = 0; i < hlen; i++) {
        if (i == 0 || fmod(log2(i), 1) == 0) {
            hamarr[i] = 2;
        } else {
            hamarr[i] = msgarr[j++];
        }
    }

    for (int i = 1; i < hlen; i++) {
        if (hamarr[i] == 2) {
            hamarr[i] = calculateParity(i, hamarr.data(), hlen);
        }
    }

    hamarr[0] = calculateParity(0, hamarr.data(), hlen);

    reverseArray(hamarr.data(), hlen);

    cout << "The required hamming code is:\n\n";
    for (int bit : hamarr) {
        cout << bit;
    }

    return 0;
}
