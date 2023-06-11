#include <iostream>
#include <fstream>
#include <string>

#include "user.h"
#include "message.h"

using namespace std;

int main() {
	// Load users and messages
	vector<User> users;
	users = loadUsersFromFile("users.txt");
	vector<Message> messages;
	messages = loadMessagesFromFile("messages.txt");
	if (users.empty()) {
		cout << "Add sample users and messages? (y/n)";
		char choise = 'n';
		cin >> choise;
		if (choise == 'y'){
			addSampleUsers(users);
			addSampleMessages(messages);
			}
	}

	// Display options
	int option = -1;
	while (option != 0) {
		cout << "Menu:" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Add user" << endl;
		cout << "2. Add message" << endl;
		cout << "3. Show all users" << endl;
		cout << "4. Show all messages" << endl;
		cout << "Enter an option: ";
		cin >> option;
		cout << endl;

		// Process option
		switch (option) {
		case 1: {
			// Add User
			User newUser("", "");
			newUser.input(); // Prompt user to enter information
			users.push_back(newUser); // Add user to vector
			outputAllUsers(users);
			// Write to file
			ofstream userFile("users.txt", ios::app); // Open file for output
			userFile << newUser; // Write User object to output stream
			userFile.close(); // Close file
			break;
		}

		case 2: {
			// Add Message
			Message newMessage("", "", "");
			newMessage.input(); // Prompt user to enter information
			messages.push_back(newMessage); // Add message to vector
			outputAllMessages(messages);
			// Write to file
			ofstream messageFile("messages.txt", ios::app); // Open file for output
			messageFile << newMessage; // Write Message object to output stream
			messageFile.close(); // Close file
			break;
		}

		case 3: {
			outputAllUsers(users);
			break;
		}

		case 4: {
			outputAllMessages(messages);
			break;
		}

		case 0: {
			// Exit program
			cout << "Exiting program." << endl;
			break;
		}

		default: {
			// Invalid option
			cout << "Invalid option. Please try again." << endl;
			break;
		}
		}

		cout << endl;
	}

	return 0;
}
