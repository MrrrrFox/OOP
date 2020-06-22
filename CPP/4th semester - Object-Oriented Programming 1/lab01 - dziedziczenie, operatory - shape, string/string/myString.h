#pragma once
#include <iostream>

// klasa pochodna od Shape reprezentujaca kolo
class MyString
{
private:
	char* _wyraz;
public:
	
	MyString(const char *);
	MyString(const MyString &);
	~MyString();

	int operator==(const MyString&) const;
	int operator==(const char *) const;
	MyString& operator=(const MyString&);
	MyString& operator=(const char *);
	MyString operator+(const MyString&) const;
	MyString operator+(const char *) const;
	MyString operator+(const char) const;
	MyString operator*(int) const;
	char & operator[](int) const;

    	friend std::ostream& operator <<(std::ostream&, const MyString&);

	void print() const;
	char* str() const;
};

MyString operator*(int, const MyString&);
