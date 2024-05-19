#include "Administrator.h"

bool Administrator::Login(std::string username, std::string password) {
    int clearance = Security::validate(username, password);
    return clearance == 2;
}