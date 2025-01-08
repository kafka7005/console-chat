#pragma once
#include <vector>
#include <string>
#include "Message.h"
#include "User.h"


class GroupChat : public Message, public User
{
protected:
	std::vector<Message> messages;

public:
	GroupChat() {}
	~GroupChat() {}

	void sendMessage(const std::string& sender, const char* recipient, const std::string& msg, bool privateMessage);
	void sendMessage(const std::string& sender, const std::string& recipient, const std::string& msg, bool privateMessage);
	void showMessage(bool isPublic) const;
	void showPrivateMessage(const std::string& login) const;
	bool hasChat(const std::string& user1, const std::string& user2) const;
};

