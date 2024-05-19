#include "Security.h"

int Security::validate(std::string username, std::string password) {
    if (username == "abbott" && password == "monday")
        return 1;
    else if (username == "costello" && password == "tuesday")
        return 2;
    else
        return 0;
}