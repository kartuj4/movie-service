#ifndef USER_MANAGER_H
#define USER_MANAGER_H
#include "User.h"
#include <string>

class UserManager {
public:
    static bool userExists(const std::string& username);
    static bool isValidPassword(const std::string& password);
    static void registerUser();
    static bool loginUser(std::string& loggedInUser);
};

#endif // USER_MANAGER_H