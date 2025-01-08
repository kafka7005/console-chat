#include "GroupChat.h"

void GroupChat::sendMessage(const std::string& sender, const char* recipient, const std::string& msg, bool privateMessage = true)
{
	messages.push_back(Message(sender, recipient, msg, privateMessage));
}

void GroupChat::sendMessage(const std::string& sender, const std::string& recipient, const std::string& msg, bool privateMessage = true)
{
	messages.push_back(Message(sender, recipient, msg, privateMessage));
}

void GroupChat::showMessage(bool isPublic = false) const
{
	for (auto& msg : messages)
	{
		if (isPublic && msg.getIsPrivate()) {
			continue;
		}
		std::cout << msg.getSender() << "\x1B[32m -> \033[0m" << msg.getRecipient() << ": " << msg.getMsg() << "\n";
	}
}

void GroupChat::showPrivateMessage(const std::string& login) const
{
	for (const auto& msg : messages)
	{
		if (msg.getSender() == login || msg.getRecipient() == login)
		{
			std::cout << msg.getSender() << "\x1B[32m -> \033[0m" << msg.getRecipient() << ": " << msg.getMsg() << "\n";
		}
	}
}

bool GroupChat::hasChat(const std::string& user1, const std::string& user2) const
{
	for (const auto& msg : messages)
	{
		if ((msg.getSender() == user1 && msg.getRecipient() == user2) ||
			(msg.getSender() == user2 && msg.getRecipient() == user1))
		{
			return true;
		}
	}
	return false;
}