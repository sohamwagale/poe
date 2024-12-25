#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class StopAndWaitProtocol {
private:
    bool waitForAck() {
        // Simulate network delay
        this_thread::sleep_for(std::chrono::milliseconds(500));
        
        // Simulate 90% success rate for acknowledgments
        return (rand() % 100) < 90;
    }

public:
    void sendData(const std::string& data) {
        int frameNumber = 0;
        size_t pos = 0;
        const size_t frameSize = 4; // Send 4 characters per frame
        
        while (pos < data.length()) {
            // Prepare frame
            string frame = data.substr(pos, frameSize);
            bool frameAcknowledged = false;
            
            // Keep trying until frame is acknowledged
            while (!frameAcknowledged) {
                cout << "Sending frame " << frameNumber 
                         << ": " << frame << std::endl;
                
                if (waitForAck()) {
                    cout << "Frame " << frameNumber 
                             << " acknowledged\n" << std::endl;
                    frameAcknowledged = true;
                } else {
                    cout << "Frame " << frameNumber 
                             << " timeout, retransmitting...\n" << std::endl;
                }
            }
            
            pos += frameSize;
            frameNumber++;
        }
    }
};

int main() {
    StopAndWaitProtocol protocol;
    
    string message = "Hello, Stop and Wait Protocol!";
    cin>>message;
    cout << "Sending message: " << message << "\n\n";
    protocol.sendData(message);
    
    return 0;
}


/*
Let me explain the first Stop & Wait protocol code like you're 5! Imagine you're sending letters to your friend, but you want to make sure each letter arrives safely.

Let's break down the code step by step:

1. First, we create a special helper called `StopAndWaitProtocol` that has two main parts:
```cpp
class StopAndWaitProtocol {
    private:
        // Secret helper function
    public:
        // Main function that sends data
}
```
Think of this like having a special mailbox with rules!

2. The `waitForAck()` function is like waiting for your friend to say "I got your letter!":
```cpp
bool waitForAck() {
    // Wait for half a second (like waiting for mail)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    // Most times (90%) your friend says "Got it!"
    // Sometimes (10%) they say "Didn't get it!"
    return (rand() % 100) < 90;
}
```

3. The main `sendData` function is where the magic happens:
```cpp
void sendData(const std::string& data) {
    int frameNumber = 0;              // Start counting letters
    size_t pos = 0;                   // Keep track of where we are
    const size_t frameSize = 4;       // Send 4 letters at a time
```
Imagine you're sending a long message, but you can only write 4 letters per page!

4. The main loop is like sending each page:
```cpp
while (pos < data.length()) {
    // Take 4 letters and put them on a page
    std::string frame = data.substr(pos, frameSize);
    bool frameAcknowledged = false;
```

5. The inner loop is like making sure each page arrives:
```cpp
while (!frameAcknowledged) {
    std::cout << "Sending frame " << frameNumber << ": " << frame << std::endl;
    
    if (waitForAck()) {
        // Your friend got it! Move to next page
        std::cout << "Frame " << frameNumber << " acknowledged\n" << std::endl;
        frameAcknowledged = true;
    } else {
        // Your friend didn't get it! Send the same page again
        std::cout << "Frame " << frameNumber << " timeout, retransmitting...\n" << std::endl;
    }
}
```

Here's a real-world example:
- Imagine sending "HELLO WORLD"
1. First, it sends "HELL" (first 4 letters)
   - Waits for friend to say "Got it!"
   - If friend says "Got it!", moves to next letters
   - If friend doesn't respond, sends "HELL" again
2. Then sends "O WO" (next 4 letters)
3. Finally sends "RLD" (last 3 letters)

The main program part:
```cpp
int main() {
    StopAndWaitProtocol protocol;                         // Create our special mailbox
    std::string message = "Hello, Stop and Wait Protocol!"; // Our message
    protocol.sendData(message);                           // Send the message!
}
```

Just like in real life:
- You write a letter (frame)
- Send it
- Wait for your friend to say they got it
- If they don't respond, you send the same letter again
- Once they say they got it, you can send the next letter
- Repeat until all letters are sent!

Would you like me to clarify any part of this explanation? Or would you like to see how it works with a specific example message?
*/