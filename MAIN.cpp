#include <iostream>
#include "Administrator.h"
#include "User.h"

int main() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (Administrator::Login(username, password)) {
        std::cout << "Logged in as Administrator.\n";
    }
    else if (User::Login(username, password)) {
        std::cout << "Logged in as User.\n";
    }
    else {
        std::cout << "Invalid username or password.\n";
    }

    return 0;
}