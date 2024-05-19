#ifndef SECURITY_H
#define SECURITY_H

#include <string>

class Security {
public:
    static int validate(std::string username, std::string password);
};

#endif // SECURITY_H