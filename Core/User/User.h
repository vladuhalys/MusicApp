
#include "../../Library/Library.h"

struct User
{
public:

	void setName(const string& n);
	void setPassword(const string& p);


	string getName() const;
	string getPassword() const;


	User();
	explicit User(const string& n);
	User(const string& n, const string& p);

	~User();

private:
	string name;
	string password;
};