#include <iostream>
#include <vector>
#include "CircularBuffer.h"

int RunCommand(char cmd, CircularBuffer<int> &cb)
{
    int val;
    switch(cmd) {
        case 'e':
            std::cin >> val;
            if (cb.Enqueue(val) < 0) {
                std::cout << "enqueue failed: insufficient space in queue\n";
            }
            break;
        case 'd':
            if (cb.Dequeue(val) < 0) {
                std::cout << "dequeue failed: empty queue\n";
                break;
            }
            std::cout << "removed: " << val << "\n";
            break;
        case 'p':
            Print(cb);
            break;
        case 'x':
            return 0;
        default:
            std::cout << "Help:\ne <int>\tenqueue an integer value\nd\tdequeue\np\tprint the buffer\nx\texit\n";
    }
    return 1;
}

int main()
{
    std::cout << "Enter buffer size:\n";
    int bufferSize;
    std::cin >> bufferSize;
    auto cb = CircularBuffer<int>(bufferSize);
    bool cont = 1;
    char cmd;
    while (cont) {
        std::cin >> cmd;
        cont = RunCommand(cmd, cb);
    }
    return 0;
}