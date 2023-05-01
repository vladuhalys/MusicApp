#include "user.h"

void User::setName(const string& n)
{
	name = n;
}

void User::setPassword(const string& p)
{
	password = p;
}


string User::getName() const
{
	return name;
}

string User::getPassword() const
{
	return password;
}


User::User()
{
	setName("NULL");
	setPassword("NULL");
}
User::User(const string& n) : User()
{
	setName(n);
}
User::User(const string& n, const string& p) : User(n)
{
	setPassword(p);
}


User::~User()
{
	name.clear();
	password.clear();
}
