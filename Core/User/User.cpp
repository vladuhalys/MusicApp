#include "User.h"

void User::setName(const string& n)
{
	name = n;
}
void User::setPassword(const string& p)
{
	password = p;
}
void User::setFav(const vector<uint64_t> &f)
{
	fav = f;
}

string User::getName() const
{
	return name;
}
string User::getPassword() const
{
	return password;
}
vector<uint64_t> User::getFav() const
{
	return fav;
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
User::User(const string &n, const string &p, const vector<uint64_t> &f) : User(n, p)
{
	setFav(f);
}

User::~User()
{
	name.clear();
	password.clear();
	fav.clear();
}

