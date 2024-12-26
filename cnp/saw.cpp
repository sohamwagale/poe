#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For sleep function

using namespace std;

int main() {
    int n, timeout = 5, delay = 0;
    int frame[30];

    // Get the number of frames from the user
    cout << "Enter number of frames: ";
    cin >> n;

    // Get the data for the frames
    cout << "\nEnter the data for frames:\n";
    for (int i = 0; i < n; ++i) {
        cin >> frame[i];
    }

    // Frame transmission loop
    for (int i = 0; i < n; ++i) {
        cout << "\nFrame sent = " << i + 1 << "\t Data = " << frame[i];

        // Simulate delay
        delay = rand() % 10; // Random delay between 0 and 9
        cout << "\nDelay = " << delay << endl;

        if (delay < timeout) {
            // Acknowledgement received
            cout << "\nAcknowledgement received = " << i + 1 << endl;
            continue;
        } else {
            // Simulate waiting due to timeout
            while (delay != timeout) {
                cout << "\nWaiting... ";
                sleep(2); // Wait for 2 seconds before retrying
                --delay;
            }

            cout << "\nTimeout\n";
            cout << "\nResending Frame = " << i + 1 << "\t Data = " << frame[i] << endl;

            // Retry sending the frame by jumping back to the delay simulation
            i--; // Decrement i to resend the current frame
        }
    }

    cout << "\n\nAll data frames sent!" << endl;

    return 0;
}
