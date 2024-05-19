#ifndef USER_H
#define USER_H

#include <string>
#include "Security.h"

class User {
public:
    static bool Login(std::string username, std::string password);
};

#endif // USER_H