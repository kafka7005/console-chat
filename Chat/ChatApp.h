#pragma once
#include "GroupChat.h"
#include "User.h"
#include <vector>


class ChatApp : public GroupChat
{
protected:
	std::vector<User> users;
	std::vector<GroupChat> chats;
	GroupChat generalChat;
public:

	bool registerUser(const std::string& login, const std::string& password);
	User* loginUser(const std::string& login, const std::string& password);
	GroupChat& getChat(const std::string& user1, const std::string& user2);

	void sendMessageToGeneralChat(const std::string& sender, const std::string& message);
	void showGeneralChat() const;
	void exitApp() const;
	const std::vector<User>& getUsers() const;
	const std::vector<GroupChat>& getChats() const;
};

