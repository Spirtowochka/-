#include <fstream>
#include <windows.h>
#include "Typography.h"

using namespace std;

char getCh();

void mainMenu();
void orderMenu();
void deleteOrderMenu();

void inputOrdersFromFile(Typography& typography);
void outOrdersInFile(const Typography& typography);
void outOrderOnScreen(const Typography& typography);

void order(Typography& typography);
void orderBook(Typography& typography);
void orderPoster(Typography& typography);
void orderBusinessCard(Typography& typography);

void deleteOrder(Typography& typography);
bool deleteBook(Typography& typography);
bool deletePoster(Typography& typography);
bool deleteBusinessCard(Typography& typography);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Typography typography;
	char ch;

	cout << "Заказы клининговой компании" << endl << endl;

	mainMenu();
	while ((ch = getCh()) != '6')
	{
		switch (ch)
		{
		case '1':
			order(typography);
			break;
		case '2':
			deleteOrder(typography);
			break;
		case '3':
			outOrderOnScreen(typography);
			break;
		case '4':
			inputOrdersFromFile(typography);
			break;
		case '5':
			outOrdersInFile(typography);
			break;
		}
		mainMenu();
	}

	return 0;
}

void order(Typography& typography)
{
	char ch;
	orderMenu();
	while ((ch = getCh()) != '2')
	{
		switch (ch)
		{
		case'1':
			orderBook(typography);
			break;
		case'2':
			orderPoster(typography);
			break;
		}
		cout << "Заказ добавлен" << endl << endl;
		orderMenu();
	}
}

void orderPoster(Typography& typography)
{
	Poster poster;
	String string;


	poster.ChangeTypePoster(string);

	typography.AddPoster(poster);
}

void orderBook(Typography& typography)
{
	Book book;
	String string;

	cout << "Введите адресс помещения " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNameBook(string);

	cout << "Введите имя заказчика: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNameAuthor(string);

	cout << "Введите цену заказа: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeSurnameAuthor(string);

	typography.AddBook(book);

}

void deleteOrder(Typography& typography)
{
	bool successDelete;
	char ch;
	deleteOrderMenu();
	while ((ch = getCh()) != '2')
	{
		switch (ch)
		{
		case'1':
			successDelete = deleteBook(typography);
			break;
		}

		if (successDelete)
			cout << "Заказ удалён" << endl << endl;
		else
			cout << "Заказ не найден" << endl << endl;
		deleteOrderMenu();
	}
}

bool deleteBook(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "Введите адресс удаляемого заказа:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeleteBook(temp);
}


void outOrderOnScreen(const Typography& typography)
{
	cout << "Ваши заказы: " << endl << endl;
	cout << typography;
}

void inputOrdersFromFile(Typography& typography)
{
	ifstream file("input/Orders.txt");
	file >> typography;
	file.close();
}

void outOrdersInFile(const Typography& typography)
{
	ofstream file("input/Orders.txt");
	file << typography;
	file.close();
}

void mainMenu()
{
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Оформить заказ" << endl;
	cout << "2 - Удалить заказ" << endl;
	cout << "3 - Посмотреть заказы" << endl;
	cout << "4 - Прочитать заказы из файла" << endl;
	cout << "5 - Сохранить заказы в файл" << endl;
	cout << "6 - Завершить программу" << endl;
	cout << endl;
}

void orderMenu()
{
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Внести заказ" << endl;
	cout << "2 - Отмена" << endl;
	cout << endl;
}

void deleteOrderMenu()
{
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Удалить заказ" << endl;
	cout << "2 - Отмена" << endl;
	cout << endl;
}

char getCh()
{
	char ch;
	cin.get(ch);
	cout << endl;
	while (getchar() != '\n')
		continue;
	return ch;
}