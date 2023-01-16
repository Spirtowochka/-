#include "TypographyOrder.h"
using namespace std;

ostream& operator<<(ostream& os, const Book& book)
{
	os << book.m_nameBook << endl;
	os << book.m_nameAuthor << endl;
	os << book.m_surnameAuthor << endl;
	os << book.m_numberBooksCopy << endl;
	return os;
}

istream& operator>>(istream& is, Book& book)
{
	is >> book.m_nameBook >> book.m_nameAuthor >> book.m_surnameAuthor >> book.m_numberBooksCopy;
	return is;
}

bool operator==(const Book& book_1, const Book& book_2)
{
	return book_1.m_nameBook == book_2.m_nameBook;
}

ostream& operator<<(ostream& os, const Poster& poster)
{
	os << poster.m_typePoster << endl;
	return os;
}

istream& operator>>(istream& is, Poster& poster)
{
	is >> poster.m_typePoster;
	return is;
}

bool operator==(const Poster& poster_1, const Poster& poster_2)
{
	return poster_1.m_typePoster == poster_2.m_typePoster;
}

ostream& operator<<(ostream& os, const BusinessCard& businessCard)
{
	os << businessCard.m_name << endl;
	os << businessCard.m_surname << endl;	
	os << businessCard.m_service << endl;
	os << businessCard.m_phoneNumber << endl;

	return os;
}

istream& operator>>(istream& is, BusinessCard& businessCard)
{
	is >> businessCard.m_name >> businessCard.m_surname >> businessCard.m_service >> businessCard.m_phoneNumber;
	return is;
}

bool operator==(const BusinessCard& businessCard_1, const BusinessCard& businessCard_2)
{
	return businessCard_1.m_service == businessCard_2.m_service;
}
