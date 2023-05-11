#include "../../Library/Library.h"

struct Music
{
public: 
	void setName(const string& n);
	void setAuthor(const string& a);
	void setLength(int l);

	string getName() const;
	string getAuthor() const;
	int getLength() const;

	Music();
	explicit Music(const string& n);
	Music(const string& n, const string& a);
	Music(const string& n, const string& a, int l);

	~Music();

private:
	string name;
	string author;
	int length;
};