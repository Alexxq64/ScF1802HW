#ifndef MESSAGE_H
#define MESSAGE_H


#include <iostream>
#include <vector>

class Message {
public:
    Message(std::string text, std::string sender, std::string receiver);

    std::string getText() const;
    std::string getSender() const;
    std::string getReceiver() const;

    void outputMessage() const;
    void input();
    friend std::ostream& operator<< (std::ostream& os, const Message& message);

private:
    std::string text;
    std::string sender;
    std::string receiver;
};

std::vector<Message> loadMessagesFromFile(const std::string& fileName);
void saveMessagesToFile(const std::vector<Message>& messages, const std::string& filename);
void addSampleMessages(std::vector<Message>& messages);
void outputAllMessages(const std::vector<Message>& messages);

#endif
