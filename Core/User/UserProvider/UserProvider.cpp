#include "UserProvider.h"

int UserProvider::addUser(User const *user, const string &filename) const
{
	// check if name already exists
	bool nameExists = false;
	std::ifstream infile;
	infile.open(filename);
	string line;
	while (getline(infile, line))
	{
		string name_temp = line.substr(0, line.find_first_of(","));
		if (name_temp == user->getName())
		{
			nameExists = true;
			break;
		}
	}
	infile.close();

	if (nameExists)
	{
		cout << "Error: this username already exists!\n";
		system("pause>0");
		return -1;
	}
	else
	{
		std::ofstream outfile;
		outfile.open(filename, std::ios_base::app);
		outfile << user->getName() << "," << user->getPassword() << '\n';
		outfile.close();
		return 0;
	}
}

int UserProvider::readUserData(vector<User> &userdata, const string &filename) const
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			string name, password;
			getline(ss, name, ',');
			getline(ss, password, ',');
			userdata.emplace_back(name, password);
		}
		file.close();
		return 0;
	}
	return -1;
}

bool UserProvider::userExists(User const *user, vector<User> &userdata) const
{
	const string name = user->getName();
	const string password = user->getPassword();
	auto it = std::find_if(userdata.begin(), userdata.end(), [&](User const &u) {
		return u.getName() == name, u.getPassword() == password;
		});
	return it != userdata.end();
}


