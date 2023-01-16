#pragma once
#include "TypographyOrder.h"
#include "Vector.h"

class Typography
{
private:
	Vector<Book> m_books;
	Vector<Poster> m_posters;
	Vector<BusinessCard> m_businessCards;

public:

	Typography() {}

	void AddBook(const Book& book) { m_books.pushBack(book); }
	void AddPoster(const Poster& poster) { m_posters.pushBack(poster); }
	void AddBusinessCard(const BusinessCard& businessCard) { m_businessCards.pushBack(businessCard); }
	
	bool DeleteBook(const String& nameBook) { return m_books.remove(Book(nameBook, "", "", "")); }
	bool DeletePoster(const String& typePoster) { return m_posters.remove(Poster(typePoster)); }
	bool DeleteBusinessCard(const String& service) { return m_businessCards.remove(BusinessCard("", "", service, "")); }

	friend ostream& operator<<(ostream& os, const Typography& typography);
	friend istream& operator>>(istream& is, Typography& typography);
};