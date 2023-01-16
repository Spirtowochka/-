#include "Typography.h"

using namespace std;

ostream& operator<<(ostream& os, const Typography& typography)
{
	for (int i = 0; i < typography.m_books.size(); i++)
	{
		os << "Книга" << endl;
		os << typography.m_books[i] << endl;
	}
				
	for (int i = 0; i < typography.m_posters.size(); i++)
	{
		os << "Постер" << endl;
		os << typography.m_posters[i] << endl;
	}
		
	for (int i = 0; i < typography.m_businessCards.size(); i++)
	{
		os << "Визитка" << endl;
		os << typography.m_businessCards[i] << endl;
	}
		
	return os;
}

istream& operator>>(istream& is, Typography& typography)
{
	
	while (!is.eof())
	{
		String string;
		is >> string;

		while (string == "")
			if (!is) 
				break;
			else		
				is >> string;
			
		if (string == "Книга")
		{
			Book book;
			is >> book;
			typography.AddBook(book);
		}
		else if (string == "Постер")
		{
			Poster poster;
			is >> poster;
			typography.AddPoster(poster);

		}
		else if (string == "Визитка")
		{
			BusinessCard businessCard;
			is >> businessCard;
			typography.AddBusinessCard(businessCard);
		}
	}

	return is;
}


