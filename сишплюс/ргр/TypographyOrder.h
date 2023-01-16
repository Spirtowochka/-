#pragma once
#include "String.h"
class Book
{
private:
	String m_nameBook;
	String m_nameAuthor;
	String m_surnameAuthor;
	String m_numberBooksCopy;

public:
	Book(const String& nameBook = "", const String& nameAuthor = "", const String& surnameAuthor = "", const String& numberBooks = "") : m_nameBook(nameBook), m_nameAuthor(nameAuthor), m_surnameAuthor(surnameAuthor), m_numberBooksCopy(numberBooks) {}
	void ChangeNameBook(const String& nameBook) { m_nameBook = nameBook; }
	void ChangeNameAuthor(const String& nameAuthor) { m_nameAuthor = nameAuthor; }
	void ChangeSurnameAuthor(const String& surnameAuthor) { m_surnameAuthor = surnameAuthor; }
	void ChangeNumberBooks(const String& numberBooks) { m_numberBooksCopy = numberBooks; }

	friend ostream& operator<<(ostream& os, const Book& book);
	friend istream& operator>>(istream& is, Book& book);
	friend bool operator==(const Book& book_1, const Book& book_2);
};

class Poster
{
private:
	String m_typePoster;

public:

	Poster(const String& typePoster = "") : m_typePoster(typePoster) {}
	void ChangeTypePoster(const String& typePoster) { m_typePoster = typePoster; }
	friend ostream& operator<<(ostream& os, const Poster& poster);
	friend istream& operator>>(istream& is, Poster& poster);
	friend bool operator==(const Poster& poster_1, const Poster& poster_2);
};

class BusinessCard
{
private:
	String m_name;
	String m_surname;	
	String m_service;
	String m_phoneNumber;
public:
	BusinessCard(const String& name = "", const String& surname = "", const String& service = "", const String& phoneNumber= "") : m_name(name), m_surname(surname), m_service(service), m_phoneNumber(phoneNumber) {}
	void ChangeName(const String& name) { m_name = name; }
	void ChangeSurname(const String& surname) { m_surname = surname; }
	void ChangeService(const String& service) { m_service = service; }
	void ChangePhoneNumber(const String& phoneNumber) { m_phoneNumber = phoneNumber; }
	
	friend ostream& operator<<(ostream& os, const BusinessCard& businessCard);
	friend istream& operator>>(istream& is, BusinessCard& businessCard);
	friend bool operator==(const BusinessCard& businessCard_1, const BusinessCard& businessCard_2);
};