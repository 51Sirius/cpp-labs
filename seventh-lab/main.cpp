#include <iostream>
#include "buffer.h"

int main() {
    Buffer<int> buffer(5);
    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.push_back(4);
    buffer.push_back(6);
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "\n";
    buffer.pop_back();
    buffer.pop_front();
    buffer.push_front(10);
    buffer.push_front(12);
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "Begin: " << buffer.front() << "\n";
    std::cout << "End: " << buffer.back() << "\n";
    std::cout << "Second: " << buffer[1] << "\n";
    std::cout << "Size: " << buffer.size() << "\n";
    std::cout << "Capacity: " << buffer.capacity() << "\n";
    buffer.resize(10);
    std::cout << "Capacity: " << buffer.capacity() << "\n";
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Max: " << *std::max_element(buffer.begin(), buffer.end())<<"\n";
    buffer.erase(buffer.begin()+1);
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    int a = 100;
    std::cout << "\n";
    buffer.insert(buffer.begin(), a);
    for (int i = 0; i < buffer.size(); ++i) {
        std::cout << buffer[i] << " ";
    }
    return 0;
}