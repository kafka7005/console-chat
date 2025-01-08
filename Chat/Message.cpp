#include "Message.h"

Message::Message(const std::string& sender, std::string recipient, const std::string& msg, bool privateMessage = true) : _sender(sender), _recipient(recipient), _msg(msg), _isPrivate(privateMessage) {}

const std::string& Message::getSender() const
{
	return _sender;
}

const std::string& Message::getRecipient() const
{
	return _recipient;
}

const std::string& Message::getMsg() const
{
	return _msg;
}

const bool Message::getIsPrivate() const
{
	return _isPrivate;
}