#include <iostream>
#include <string>
#include <fstream>
#include "message.h"


Message::Message(std::string text, std::string sender, std::string receiver)
    : text(text), sender(sender), receiver(receiver)
{
}

std::string Message::getText() const {
    return text;
}

std::string Message::getSender() const {
    return sender;
}

std::string Message::getReceiver() const {
    return receiver;
}

void Message::outputMessage() const {
    std::cout << "Sender: " << getSender() << std::endl;
        std::cout << "Receiver : " << getReceiver() << std::endl;
        std::cout << "Message : " << getText() << std::endl;
}

void Message::input() {
    std::cout << "Enter the sender: ";
    std::cin >> sender;
    std::cout << "Enter the receiver: ";
    std::cin >> receiver;
    std::cout << "Enter the message text : ";
    std::getline(std::cin, text);
    std::getline(std::cin, text);
}

std::ostream& operator<< (std::ostream& os, const Message& message) {
    os << message.sender;
    os << " " << message.receiver;
    os << " " << message.text << std::endl;
    return os;
}

std::vector<Message> loadMessagesFromFile(const std::string& fileName) {
    std::vector<Message> messages;
    std::ifstream file(fileName);

    if (file.is_open()) {
        std::string sender, receiver, text;

        while (file >> sender >> receiver) {
            std::getline(file, text);
            Message msg(text, sender, receiver);
            messages.push_back(msg);
        }

        file.close();
    }
    else {
        std::cerr << "Could not open file : " << fileName << std::endl;
    }

    return messages;
}


void saveMessagesToFile(const std::vector<Message>& messages, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& message : messages) {
            file << message.getSender() << " " << message.getReceiver() << " " << message.getText() << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "Error: Could not open file " << filename <<std::endl;
    }
}


void addSampleMessages(std::vector<Message>& messages) {
    messages.push_back(Message("Hello there", "John", "Mary"));
    messages.push_back(Message("How are you?", "Mary", "John"));
    saveMessagesToFile(messages, "messages.txt");
}

void outputAllMessages(const std::vector<Message>& messages) {
    for (const auto& message : messages) {
        std::cout << message;
    }
}
