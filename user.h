#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

class User {
public:
    User(std::string login, std::string pass);

    std::string getLogin() const;
    std::string getPass() const;

    void outputUser() const;
    void input();
    friend std::ostream& operator<<(std::ostream& os, const User& user);

private:
    std::string login;
    std::string pass;
};

std::vector<User> loadUsersFromFile(const std::string& fileName);
void saveUsersToFile(const std::vector<User>& users, const std::string& fileName);
void outputAllUsers(const std::vector<User>& users);
void addSampleUsers(std::vector<User>& users);

#endif
