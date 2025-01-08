#pragma once
#include "User.h"

class Message
{
protected:
	std::string _sender;
	std::string _recipient;
	std::string _msg;
	bool _isPrivate;

public:
	Message() {}
	~Message() {}

	Message(const std::string& sender, std::string recipient, const std::string& msg, bool privateMessage);

	const std::string& getSender() const;
	const std::string& getRecipient() const;
	const std::string& getMsg() const;

	const bool getIsPrivate() const;
};

