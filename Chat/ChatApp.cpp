#include "ChatApp.h"

bool ChatApp::registerUser(const std::string& login, const std::string& password)
{
	for (const auto& user : users)
	{
		if (user.getUserLogin() == login)
		{
			std::cout << "\x1B[31mПользователь с таким именем уже существует!\n\033[0m";
			return false;
		}
	}
	users.push_back(User(login, password));
	std::cout << "\x1B[32mРегистрация прошла успешно!\n\033[0m";
	return true;
}

User* ChatApp::loginUser(const std::string& login, const std::string& password)
{
	for (auto& user : users)
	{
		if (user.getUserLogin() == login && user.checkPassword(password))
		{
			std::cout << "\x1B[32mАвторизация успешна!\n\033[0m";
			return &user;
		}
	}
	std::cout << "\x1B[31mНеверное имя пользователя или пароль!\n\033[0m";
	return nullptr;
}

GroupChat& ChatApp::getChat(const std::string& user1, const std::string& user2)
{
	for (auto& chat : chats)
	{
		if (chat.hasChat(user1, user2))
		{
			return chat;
		}
	}
	chats.push_back(GroupChat());
	return chats.back();
}

void ChatApp::sendMessageToGeneralChat(const std::string& sender, const std::string& message)
{
	generalChat.sendMessage(sender, "\x1B[33mОбщий чат\033[0m", message, false); // false означает, что это сообщение публичное
}

void ChatApp::showGeneralChat() const
{
	std::cout << "\x1B[33m\nОбщий чат:\n\033[0m";
	generalChat.showMessage(true); // true означает, что показываются только публичные сообщения

}

void ChatApp::exitApp() const
{
	std::cout << "\x1B[31m\nВы вышли из программы.\tДо свидания!\n\033[0m";
	exit(0);
}

const std::vector<User>& ChatApp::getUsers() const
{
	return users;
}

const std::vector<GroupChat>& ChatApp::getChats() const
{
	return chats;
}