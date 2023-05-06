#pragma once
#include "../User.h"

struct UserProvider
{
	int addUser(User const *user, const string &Path = "Data/UserData.csv") const;
	int readUserData(vector<User> &userdata, const string &Path = "Data/UserData.csv") const;
	bool userExists(User const *user, vector<User> &userdata) const;
};

