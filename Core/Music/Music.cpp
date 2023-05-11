#include "Music.h"

void Music::setName(const string& n)
{
	name = n;
}
void Music::setAuthor(const string& a)
{
	author = a;
}
void Music::setLength(int l)
{
	length = l;
}

string Music::getName() const
{
	return name;
}
string Music::getAuthor() const
{
	return author;
}
int Music::getLength() const
{
	return length;
}

Music::Music()
{
	setName("NULL");
	setAuthor("NULL");
	setLength(0);
}

Music::Music(const string& n) : Music()
{
	setName(n);
}
Music::Music(const string& n, const string& a) : Music(n)
{
	setAuthor(a);
}
Music::Music(const string& n, const string& a, int l) : Music(n, a)
{
	setAuthor(a);
}

Music::~Music()
{
	name = "NULL";
	author = "NULL";
	length = 0;
}