#pragma once
#include "../../Library/Library.h"
#include "ClientScreen/ClientScreen.h"
#include "../../Core/User/User.h"
#include "../../Core/User/UserProvider/UserProvider.h"

struct Screen
{
public:
	int Register();  // register 
	int Login();
	int Menu();      // load screen

private:
	ClientScreen *clientScreen;
};

