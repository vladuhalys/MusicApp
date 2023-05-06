#include "Screen.h"

User *current_user;

int Screen::Register()
{
	system("cls");
	cout << "<----------- REGISTRATION ----------->\n";
	string name, password;
	cout << "Input name\n-> ";
	cin >> name;
	cout << "Input password\n-> ";
	cin >> password;
	auto *user = new User(name, password);
	auto *user_provider = new UserProvider();
	if (user_provider->addUser(user) == -1)  // check if addUser() threw error
	{
		return -1;  // then throw error too
	}
	delete user;
	delete user_provider;
	system("cls");
	return 0;
}

int Screen::Login()
{
	system("cls");
	cout << "<--------------- LOGIN --------------->\n";

	string name;
	cout << "Input name\n-> ";
	cin >> name;
	string password;
	cout << "Input password\n-> ";
	cin >> password;

	current_user = new User(name, password);

	vector<User> UserData;
	auto *user_provider = new UserProvider();
	user_provider->readUserData(UserData);

	if (!user_provider->userExists(current_user, UserData))
	{
		cout << "Error: there is no such user or your input is wrong!\n";
		system("pause>0");
		return -1;
	}
	system("cls");

	delete user_provider;
	return 0;
}

int Screen::Menu()
{
	cout << "<--------------- MENU --------------->\n";
	int isRegistered;
	cout << "Are you registered? (1 - yes; 0 - no)\n-> ";
	cin >> isRegistered;

	if (!isRegistered)
	{
		// register loop
		while (Register() == -1) // if error occurs, user tries to register again
		{
			Register();
		}
	}
	else if (isRegistered != 1)
	{
		cout << "Error: wrong input!\n";
		return -1;
	}

	// login loop
	while (Login() == -1)
	{
		Login();
	}

	clientScreen = new ClientScreen();
	clientScreen->Menu();
	return 0;
}

