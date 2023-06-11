#include "user.h"
#include <fstream>

User::User(std::string login, std::string pass) :
    login(login), pass(pass)
{
}

std::string User::getLogin() const {
    return login;
}

std::string User::getPass() const {
    return pass;
}

void User::outputUser() const {
    std::cout << "Login: " << login << ", Password : " << pass << std::endl;
}

void User::input() {
    std::cout << "Enter login : ";
        std::cin >> login;
    std::cout << "Enter password : ";
        std::cin >> pass;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.getLogin() << " " << user.getPass();
    return os;
}

std::vector<User> loadUsersFromFile(const std::string& fileName) {
    std::vector<User> users;
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string login, pass;
        while (file >> login >> pass) {
            users.push_back(User(login, pass));
        }
        file.close();
    }
    else {
        std::cerr << "Could not open file: " << fileName << std::endl;
    }
    return users;
}

void saveUsersToFile(const std::vector<User>& users, const std::string& fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.getLogin() << " " << user.getPass() << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Could not open file: " << fileName << std::endl;
    }
}

void outputAllUsers(const std::vector<User>& users) {
    for (const auto& user : users) {
        std::cout << user << std::endl;
    }
}

void addSampleUsers(std::vector<User>& users) {
        users.emplace_back(User("user1", "password1"));
        users.emplace_back(User("user2", "password2"));
        users.emplace_back(User("user3", "password3"));
        saveUsersToFile(users, "users.txt");
}
