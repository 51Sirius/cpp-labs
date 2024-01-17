#include "Logical.h"

using namespace std;


int main() {
    string command;
    Logical process;
    while (cin >> command) {
        process.execute(command);
    }
    return 0;
}