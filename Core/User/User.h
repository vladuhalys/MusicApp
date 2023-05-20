#pragma once
#include "../../Library/Library.h"

struct User
{
public:

	void setName(const string &n);
	void setPassword(const string &p);
	void setFav(const vector<uint64_t> &f);

	string getName() const;
	string getPassword() const;
	vector<uint64_t> getFav() const;

	User();
	explicit User(const string &n);
	User(const string &n, const string &p);
	User(const string &n, const string &p, const vector<uint64_t> &f);

	~User();

private:
	string name;
	string password;
	vector<uint64_t> fav;
};

extern User *current_user;

