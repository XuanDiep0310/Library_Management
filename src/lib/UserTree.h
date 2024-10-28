#pragma once
#include "UserNode.h"
#include <iostream>
#include <fstream>
#include <sstream>

class UserTree {
private:
    UserNode* root;

    UserNode* insert(UserNode* node, User* user) {
        if (node == nullptr) {
            return new UserNode(user);
        }
        if (user->getUsername() < node->user->getUsername()) {
            node->left = insert(node->left, user);
        }
        else if (user->getUsername() > node->user->getUsername()) {
            node->right = insert(node->right, user);
        }
        return node;
    }

    User* search(UserNode* node, const string& username) const {
        if (node == nullptr || node->user->getUsername() == username) {
            return node ? node->user : nullptr;
        }
        if (username < node->user->getUsername()) {
            return search(node->left, username);
        }
        return search(node->right, username);
    }

    // Helper function for in-order traversal to display users
    void displayInOrder(UserNode* node) const {
        if (node != nullptr) {
            displayInOrder(node->left);
            std::cout << "Username: " << node->user->getUsername() << std::endl;
            displayInOrder(node->right);
        }
    }

    // Helper function to delete a user
    UserNode* deleteUser(UserNode* node, const string& username) {
        if (node == nullptr) return node;

        if (username < node->user->getUsername()) {
            node->left = deleteUser(node->left, username);
        }
        else if (username > node->user->getUsername()) {
            node->right = deleteUser(node->right, username);
        }
        else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                UserNode* temp = node->right;
                delete node->user;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                UserNode* temp = node->left;
                delete node->user;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor
            UserNode* temp = findMin(node->right);
            node->user = temp->user;
            node->right = deleteUser(node->right, temp->user->getUsername());
        }
        return node;
    }

    UserNode* findMin(UserNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void destroyTree(UserNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node->user;
            delete node;
        }
    }

public:
    UserTree() : root(nullptr) {
        loadUsersFromFile("users.txt"); // Load users from file on initialization

        // Create the admin user and add it to the UserTree
        Date adminBirthday(1, 1, 2000);  // Example date for the admin
        User* adminUser = new User("Admin Name", adminBirthday, "admin@example.com", "admin", "admin123");
        addUser(adminUser);
    }

    ~UserTree() {
        destroyTree(root);
    }

    // Function to insert a user
    void addUser(User* user) {
        root = insert(root, user);
    }

    // Function to search for a user by username
    User* searchUser(const string& username) const {
        return search(root, username);
    }

    // Function to display all users
    void displayUsers() const {
        displayInOrder(root);
    }

    // Function to delete a user by username
    void deleteUser(const string& username) {
        root = deleteUser(root, username);
    }

    // Function to handle user login
    bool login(const string& username, const string& password) const {
        User* user = searchUser(username); // Corrected to use searchUser
        if (user) {
            if (user->getPassword() == password) {
                return true; // Login successful
            }
            else {
                std::cout << "Incorrect password." << std::endl;
            }
        }
        else {
            std::cout << "User not found." << std::endl;
        }
        return false; // Login failed
    }

    void createAccount() {
        User* newUser = User::createAccount();
        if (newUser) {
            addUser(newUser);
            std::cout << "User account created successfully!" << std::endl;
        }
    }

    // Function to save users to a file
    void saveUsersToFile(const string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            saveUsersToFile(root, outFile);
            outFile.close();
        }
        else {
            std::cerr << "Error opening file for writing." << std::endl;
        }
    }

    void saveUsersToFile(UserNode* node, std::ofstream& outFile) const {
        if (node != nullptr) {
            // Save user details in a structured format
            outFile << node->user->getUsername() << ","
                << node->user->getPassword() << ","
                << node->user->getName() << ","
                << node->user->getBirthday().getDay() << ","
                << node->user->getBirthday().getMonth() << ","
                << node->user->getBirthday().getYear() << std::endl;
            saveUsersToFile(node->left, outFile);
            saveUsersToFile(node->right, outFile);
        }
    }

    // Function to load users from a file
    void loadUsersFromFile(const string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                std::istringstream iss(line);
                string username, password, name;
                int day, month, year;
                if (std::getline(iss, username, ',') &&
                    std::getline(iss, password, ',') &&
                    std::getline(iss, name, ',') &&
                    (iss >> day) && (iss.ignore()) &&
                    (iss >> month) && (iss.ignore()) &&
                    (iss >> year)) {

                    Date birthday(day, month, year); // Assume Date has a suitable constructor
                    User* user = new User(name, birthday, "dummy@mail.com", username, password); // Use dummy email for now
                    addUser(user);
                }
            }
            inFile.close();
        }
        else {
            std::cerr << "Error opening file for reading." << std::endl;
        }
    }
};
