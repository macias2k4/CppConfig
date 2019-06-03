// ────────────────────────────────────────────────────────────────────────────────────────────── //
// std
#include <iostream>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Example
#include <example/ConfigExample.h>

using namespace std;

int main() {
    auto host = Example::ConfigExample::instance().root().serverHost();
    auto port = Example::ConfigExample::instance().root().serverPort();
    std::cout << std::endl << "host -> " << host << ":" << port << std::endl;
    return 0;
}
