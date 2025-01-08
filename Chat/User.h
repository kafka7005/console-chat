#pragma once
#include <string>
#include <iostream>


class User
{
protected:
	const std::string _name;
	std::string _login;
	std::string _password;

public:	
	User() {}
	~User() {}

	User(const std::string& login, const std::string& password);
	User(std::string& login, std::string& password);

	bool checkPassword(const std::string& password) const;

	const std::string& getUserLogin() const;
	void setUserLogin(const std::string& login);
	const std::string& getUserPassword() const;
	void setUserPassword(const std::string& password);
	const std::string& getUserName() const;
};

