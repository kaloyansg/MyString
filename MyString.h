#pragma once
#pragma warning (disable:4996)
#include <iostream>

class MyString
{
private:
	char* str;
	size_t lenght;

public:
	MyString();
	MyString(const char*);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t getSize();
	const char* getStr() const;

	MyString& operator+=(const MyString& other);

	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend std::ostream& operator<<(std::ostream& os, MyString& str);
};

MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);

bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);