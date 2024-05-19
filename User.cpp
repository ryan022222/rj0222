#include "User.h"

bool User::Login(std::string username, std::string password) {
    int clearance = Security::validate(username, password);
    return clearance >= 1; // User or Administrator clearance
}