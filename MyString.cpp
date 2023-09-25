#include "MyString.h"

MyString::MyString() : MyString("\0"){}

MyString::MyString(const char* str)
{
	if (str == nullptr || this->str == str)
	{
		return;
	}

	char* temp = new (std::nothrow) char[strlen(str) + 1];
	if (!temp)
	{
		return;
	}
	
	strcpy(temp, str);
	this->str = temp;
	this->lenght = strlen(str);
}

MyString::MyString(const MyString& other)
{
	if (this == &other) return;

	char* temp = new (std::nothrow) char[other.lenght + 1];
	if (!temp)
	{
		std::cerr << "Not enough memory!";
		return;
	}
	strcpy(temp, other.str);
	str = temp;
	lenght = other.lenght;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other) return *this;

	char* temp = new (std::nothrow) char[other.lenght + 1];
	if (!temp)
	{
		std::cerr << "Not enough memory!";
		return *this;
	}

	strcpy(temp, other.str);
	delete[] str;
	str = temp;
	lenght = other.lenght;

	return *this;
}

MyString::~MyString()
{
	delete[] str;
}

size_t MyString::getSize()
{
	return this->lenght;
}

const char* MyString::getStr() const
{
	return str;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* temp = new(std::nothrow) char[lenght + other.lenght + 1];
	if (!temp)
	{
		std::cerr << "Not enough memory!";
		return *this;
	}

	strcpy(temp, str);
	strcat(temp,other.str);

	str = temp;
	lenght = strlen(temp);

	return *this;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff; //is >> std::setw(1024) >> buff;
	
	char* temp = new (std::nothrow) char[strlen(buff) + 1];
	if (!temp)
	{
		std::cerr << "Not enoug memory!";
		return is;
	}

	strcpy(temp, buff);
	delete[] str.str;
	str.str = temp; 

	return is;
}

std::ostream& operator<<(std::ostream& os, MyString& str)
{
	os << str.str;
	return os;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result+=rhs;
	return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr()) == 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr()) > 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr()) < 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return lhs == rhs || lhs > rhs;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return lhs == rhs || lhs < rhs;
}