#include "../../Library/Library.h"

struct Music
{
public: 
	void setId(uint64_t i);
	void setName(const string& n);
	void setAuthor(const string& a);
	void setLength(int l);

	uint64_t getId() const;
	string getName() const;
	string getAuthor() const;
	int getLength() const;

	Music();
	explicit Music(uint64_t i);
	Music(uint64_t i, const string &n);
	Music(uint64_t i, const string &n, const string &a);
	Music(uint64_t i, const string &n, const string &a, int l);

	~Music();

private:
	uint64_t id;
	string name;
	string author;
	int length;
};