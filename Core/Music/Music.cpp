#include "Music.h"

void Music::setId(uint64_t i)
{
	id = i;
}
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

uint64_t Music::getId() const
{
	return id;
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
	setId(0);
	setName("NULL");
	setAuthor("NULL");
	setLength(0);
}
Music::Music(uint64_t i) : Music()
{
	setId(i);
}
Music::Music(uint64_t i, const string &n) : Music(i)
{
	setName(n);
}
Music::Music(uint64_t i, const string &n, const string &a) : Music(i,n)
{
	setAuthor(a);
}
Music::Music(uint64_t i, const string &n, const string &a, int l) : Music(i,n,a)
{
	setLength(l);
}

Music::~Music()
{
	setId(0);
	name.clear();
	author.clear();
	setLength(0);
}