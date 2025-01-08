#include "User.h"

User::User(const std::string& login, const std::string& password) : _login(login), _password(password) {}
User::User(std::string& login, std::string& password) : _login(login), _password(password) {};

bool User::checkPassword(const std::string& password) const 
{
	return _password == password;
}

const std::string& User::getUserLogin() const
{
	return _login;
}

void User::setUserLogin(const std::string& login)
{
	_login = login;
}

const std::string& User::getUserPassword() const
{
	return _password;
}

void User::setUserPassword(const std::string& password)
{
	_password = password;
}

const std::string& User::getUserName() const
{
	return _name;
}