#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "Security.h"

class Administrator {
public:
    static bool Login(std::string username, std::string password);
};

#endif // ADMINISTRATOR_H