#include <bits/stdc++.h>
using namespace std;

int calculateParity(int pos, const vector<int>& arr) {
    int parity = 0;
    for (int i = 0; i < arr.size(); i++)
        if (i & pos) parity ^= arr[i];
    return parity;
}

void detectAndCorrect(vector<int>& arr) {
    int error_pos = 0;
    for (int i = 0; i < log2(arr.size()); i++)
        if (calculateParity(1 << i, arr))
            error_pos += 1 << i;
    
    if (error_pos) {
        cout << "Error at: " << error_pos << "\n";
        arr[error_pos] ^= 1;
    }
}

int main() {
    string code;
    cin >> code;
    vector<int> arr(code.length());
    for (int i = 0; i < code.length(); i++)
        arr[i] = code[i] - '0';
        
    detectAndCorrect(arr);
    
    cout << "Message: ";
    for (int i = 1; i < arr.size(); i++)
        if ((i & (i-1)) != 0)  // if not power of 2
            cout << arr[i];
            
    return 0;
}