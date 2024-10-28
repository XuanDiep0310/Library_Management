#pragma once
#include "User.h"

class UserNode {
public:
    User* user;
    UserNode* left;
    UserNode* right;

    UserNode(User* user) : user(user), left(nullptr), right(nullptr) {}
};
