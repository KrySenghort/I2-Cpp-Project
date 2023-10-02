#include <iostream>
#include <sqlite3.h>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Inserting();
void Deleting();
void Searching();
void Displaying();
void Modifying();
void Operation_Function();

class Beverage
{
public:
	std::string product_name;
	int product_ID;
	int product_quantity;
	double product_price;

	Beverage* next;
	Beverage* previous;

	//constructor
	Beverage(int ID , string name , int quantity , double price)
	{
		this->product_ID = ID;
		this->product_name = name;
		this->product_quantity = quantity;
		this->product_price = price;
		next = nullptr;
		previous = nullptr;
	}
};

struct List
{
	int n;

	Beverage* head;
	Beverage* tail;
};

class Operation
{
public:
	List* createList() {

		List* list = new List();
		list->n = 0;
		list->head = nullptr;
		list->tail = nullptr;

		return list;
	}
	Beverage* insert_item(int, string, int, double , List*);
	int delete_item(int, List*);
	void modify_item(int, List*);
	int search_item(int, List*);
	int display_item(List*);
};

class Database
{
public:
	static int _createDataBase();
	static int _createTable();
	static int insert_item(int, string, int, double);
	static int delete_item(int);
	static int modify_item(int);
	static int modify_item_ID(int, int);
	static int modify_item_Name(int, std::string);
	static int modify_item_Quantity(int, int);
	static int modify_item_Price(int, double);
	static int search_item(int);
	static int display_item();
	static int call_back(void* Data, int argc, char** argv, char** azColName);
};

int Database::_createDataBase()
{
	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open("DataBaseSystem.db", &DB);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\t\tError in creating Database...!";
	}

	sqlite3_close(DB);
	return 0;
}

int Database::_createTable()
{
	sqlite3* DB;
	char* messageError;

	std::string sql_table = "CREATE TABLE IF NOT EXISTS BEVERAGES("
		"ID INT PRIMARY KEY NOT NULL,"
		"NAME TEXT NOT NULL,"
		"QUANTITY INT NOT NULL,"
		"PRICE DOUBLE NOT NULL);";
	try
	{
		int exit;
		exit = sqlite3_open_v2("DataBaseSystem.db", &DB, SQLITE_OPEN_READWRITE, nullptr);
		exit = sqlite3_exec(DB, sql_table.c_str(), nullptr, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			std::cout << "\n\tError in creating table!" << std::endl;
			sqlite3_errmsg(DB);
			sqlite3_free(messageError);
		}

		sqlite3_close(DB);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}

int Database::insert_item(int ID, std::string name, int quantity, double price)
{
	sqlite3* DB;
	int exit = 0;
	char* messageError;

	exit = sqlite3_open("DataBaseSystem.db", &DB);

	std::string query = ("INSERT INTO BEVERAGES (ID , NAME , QUANTITY , PRICE) VALUES (" + std::to_string(ID) + " , '" + name + "', " + std::to_string(quantity) + " , " + std::to_string(price) + ");");


	exit = sqlite3_exec(DB, query.c_str(), nullptr, 0, &messageError);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "Error in inserting data!" << std::endl;
	//}
	sqlite3_close(DB);
	return 0;
}

Beverage* Operation::insert_item(int id, string name, int quantity, double price , List* list)
{
	Beverage* operation = new Beverage(id , name , quantity , price);

	if (list->n == 0)
	{
		operation->previous = nullptr;
		list->head = operation;
	}
	else
	{
		list->tail->next = operation;
		operation->previous = list->tail;
	}

	list->tail = operation;
	list->n = list->n + 1;

	return operation;
}

int Database::delete_item(int id)
{
	sqlite3* DB;
	char* messageError;
	std::string sql;

	int exit = sqlite3_open("DataBaseSystem.db", &DB);

	sql = "DELETE from BEVERAGES where ID = " + std::to_string(id) + ";";

	exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

	sqlite3_close(DB);

	return 0;
}

int Operation::delete_item(int id, List* list)
{
	Beverage* curr, * prev, * temp;

	if (list->n == 0)
	{
		std::cout << "\n\t\tNO RECORD TO DELETE...!";
	}
	else
	{
		curr = prev = list->head;

		while ((curr != nullptr) && (curr->product_ID) != id)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr == nullptr)
		{
			cout << "\n\t\tThe Item's ID Is Not Found...!";
		}
		else if (curr == list->head)
		{
			list->head = list->head->next;
			cout << "\n\t\tDATA DELETED...!" << id;
		}
		else
		{
			prev->next = curr->next;
			if (curr->next == nullptr)
			{
				temp = prev;
			}
			cout << "\n\t\tDATA DELETED...!" << id;
		}
		delete(curr);
	}
	return 0;
}

int Database::modify_item_ID(int id , int new_id)
{
	sqlite3* DB;
	int exit;
	char* messageError;
	std::string sql;

	exit = sqlite3_open("DataBaseSystem.db", &DB);

	sql = "UPDATE BEVERAGES SET ID = " + std::to_string(new_id) + " WHERE ID = " + std::to_string(id) + ";";

	exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\tError in updating data!." << std::endl;
		sqlite3_free(messageError);
	}
	sqlite3_close(DB);
	return 0;
}

int Database::modify_item_Name(int id , std::string new_name)
{
	sqlite3* DB;
	int exit;
	char* messageError;
	std::string sql;

	exit = sqlite3_open("DataBaseSystem.db", &DB);

	sql = "UPDATE BEVERAGES SET NAME = '" + new_name + "' WHERE ID = " + to_string(id) + ";";


	exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\tError in updating data!." << std::endl;
		sqlite3_free(messageError);
	}
	sqlite3_close(DB);
	return 0;
}

int Database::modify_item_Quantity(int id, int new_quantity)
{
	sqlite3* DB;
	char* messageError;
	std::string sql;
	int exit = 0;

	exit = sqlite3_open("DataBaseSystem.db", &DB);

	sql = "UPDATE BEVERAGES SET QUANTITY = " + std::to_string(new_quantity) + " WHERE ID = " + std::to_string(id) + " ;";

	exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\tError in updating data!." << std::endl;
		sqlite3_free(messageError);
	}
	sqlite3_close(DB);
	return 0;
}

int Database::modify_item_Price(int id , double new_price)
{
	sqlite3* DB;
	char* messageError;
	std::string sql;
	int exit = 0;

	exit = sqlite3_open("DataBaseSystem.db", &DB);

	sql = "UPDATE BEVERAGES SET PRICE = " + std::to_string(new_price) + " WHERE ID = " + std::to_string(id) + " ;";

	exit = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\tError in updating data!." << std::endl;
		sqlite3_free(messageError);
	}
	sqlite3_close(DB);
	return 0;
}

int Database::modify_item(int id)
{
	int choice;

	std::cout << "\n\t\tWhat Do You Want To Modify?";
	std::cout << "\n\t\t1]. Product's ID ";
	std::cout << "\n\t\t2]. Product's Name ";
	std::cout << "\n\t\t3]. Product's Quantity";
	std::cout << "\n\t\t4]. Product's Price";
	std::cout << "\n\t\tEnter Your Choice  ";
	std::cout << "[ ]\b\b";
	std::cin >> choice;

	if (choice == 1)
	{
		int new_id;
		system("cls");
		cout << "\n\t\t Enter Product New ID : ";
		cin >> new_id;
		modify_item_ID(id, new_id);
	}
	else if (choice == 2)
	{
		string new_name;
		system("cls");
		cout << "\n\t\t Enter Product New Name : ";
		cin >> new_name;
		modify_item_Name(id, new_name);
	}
	else if (choice == 3)
	{
		int new_quantity;
		system("cls");
		cout << "\n\t\t Enter Product New Quantity : ";
		cin >> new_quantity;
		modify_item_Quantity(id, new_quantity);
	}
	else if (choice == 4)
	{
		double new_price;
		system("cls");
		cout << "\n\t\t Enter Product New Price : ";
		cin >> new_price;
		modify_item_Price(id, new_price);
	}
	else
	{
		Operation_Function();
	}
	return 0;
}

void Operation::modify_item(int id, List* list)
{
	Beverage* current;

	if (list->n == 0)
	{
		std::cout << "\n\t\tNO RECORD TO MODIFY...!";
	}
	else
	{
		current = list->head;

		while ((current != nullptr) && (current->product_ID != id))
		{
			current = current->next;
		}

		if (current == nullptr)
		{
			std::cout << "\n\t\tThe Item's ID Is Not Found...!";
		}

		else if (current->product_ID == id)
		{
			int choice;

			std::cout << "\n\t\tWhat Do You Want To Modify?";
			std::cout << "\n\t\t1]. Product's ID ";
			std::cout << "\n\t\t2]. Product's Name ";
			std::cout << "\n\t\t3]. Product's Quantity";
			std::cout << "\n\t\t4]. Product's Price";
			std::cout << "\n\t\tEnter Your Choice  ";
			std::cout << "[ ]\b\b";
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				cout << "\n\t\tEnter Product's New ID :";
				cin >> (current->product_ID);
				break;
			case 2:
				cout << "\n\t\tEnter Product's New Name :";
				cin >> (current->product_name);
				break;
			case 3:
				cout << "\n\t\tEnter Product's New Quantity :";
				cin >> (current->product_quantity);
				break;
			case 4:
				cout << "\n\t\tEnter Product's New Price :";
				cin >> (current->product_price);
				break;
			default:
				cout << "\n\t\tPlease Choose The Corresponding Line...!";
				break;
			}
			cout << "\n\t\t\tRECORD MODIFIED...!";
		}
	}
}
int Database::search_item(int code)
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open("DataBaseSystem.db", &DB);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\tError in selecting data." << std::endl;
	}

	std::string sql = "SELECT * FROM BEVERAGES WHERE ID = " + std::to_string(code) + ";";
	exit = sqlite3_exec(DB, sql.c_str(), call_back, nullptr, &messageError);

	sqlite3_close(DB);

	return 0;
}

int Operation::search_item(int id, List* list)
{
	if (list->n == 0)
	{
		std::cout << "\n\t\tNO RECORD TO SEARCH...!";
	}
	else
	{
		Beverage* current = list->head;

		while ((current != nullptr) && current->product_ID != id)
		{
			current = current->next;
		}

		if (current == nullptr)
		{
			std::cout << "\n\t\tThe Item's ID Is Not Found...!";
		}

		else if (current->product_ID == id)
		{
			std::cout << "\n\t\t\t------------------------------";
			std::cout << "\n\t\t Product's ID : " << current->product_ID;
			std::cout << "\n\t\t  Product's name : " << current->product_name;
			std::cout << "\n\t\t  Product's quantity : " << current->product_quantity;
			std::cout << "\n\t\t  Product's price : " << current->product_price;
			std::cout << "\n\t\t\t------------------------------";
		}
	}
	return 0;
}

int Database::display_item()
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open("DataBaseSystem.db", &DB);

	if (exit != SQLITE_OK)
	{
		std::cerr << "\n\tError in selecting data." << std::endl;
	}

	std::string sql = "SELECT * FROM BEVERAGES;";
	exit = sqlite3_exec(DB, sql.c_str(), call_back, nullptr, &messageError);

	sqlite3_close(DB);

	return 0;
}

int Operation::display_item(List* list)
{
	int total = 0;

	if (list->n == 0)
	{
		std::cout << "\n\t\tNO ITEM IN THE LIST...!";
	}
	else
	{
		Beverage* current = list->head;

		std::cout << "\n\t\t\t\t\tPRODUCT'S LIST";
		while (current != nullptr)
		{
			std::cout << "\n\t\t\t\t---------------------------------------"
				<< "\n\t\t\t\tProduct's ID   : " << current->product_ID
				<< "\n\t\t\t\tProduct's Name   : " << current->product_name
				<< "\n\t\t\t\tProduct's Quantity   : " << current->product_quantity
				<< "\n\t\t\t\tProduct's Price   : " << current->product_price
				<< "\n\t\t\t\t---------------------------------------";
			current = current->next;
			total = total + 1;
		}
	}
	return total;
}

int Database::call_back(void* Data, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++)
	{
		std::cout << "\n\t\t\t" << azColName[i] << " : " << argv[i] << std::endl;
	}
	std::cout << "\n";

	return 0;
}

Operation op_;
Database db_;
List* L1 = new List();

void Inserting()
{
	int choice;

	int pro_id;
	std::cout << "\n\t\tEnter product's ID : ";
	std::cin >> pro_id;

	std::string pro_name;
	std::cout << "\n\t\tEnter product's Name : ";
	std::cin >> pro_name;

	int pro_quantity;
	std::cout << "\n\t\tEnter product's Quantity : ";
	std::cin >> pro_quantity;

	double pro_price;
	std::cout << "\n\t\tEnter product's Price : ";
	std::cin >> pro_price;

	system("cls");
    do
	{
		Menu:
		std::cout << "\n\n\t\t\t1].  To Insert Item In Linked List";
		std::cout << "\n\t\t\t2].  To Insert Item In Database";
		std::cout << "\n\t\t\t3]. To Clear Screen";

		std::cout << "\n\n\t\tEnter your choice : ";
		std::cout << "[ ]\b\b";
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			Beverage* function;
			function = op_.insert_item(pro_id, pro_name, pro_quantity, pro_price, L1);

			if (function)
			{
				cout << "\n\t\tInsert In Linked List Successfully!";
			}
			else
			{
				cout << "\n\t\tInsert In Linked List Unsuccessfully!";
			}
		}

	    else if (choice == 2)
		{
			system("cls");
			int function;

			function = db_.insert_item(pro_id, pro_name, pro_quantity, pro_price);

			if (function == 0)
			{
				cout << "\n\t\tInsert In Database Successfully!";
			}
			else
			{
				cout << "\n\t\tInsert In Database Unsuccessfully!";
			}
		}
		else if (choice == 3)
		{
			system("cls");
			goto Menu;
		}
		else
		{
			Operation_Function();
		}
	} while (true);
}

void Deleting()
{
	int choice;

	int pro_id;
	std::cout << "\n\t\tEnter product's ID : ";
	std::cin >> pro_id;

	do
	{
		Menu:
		std::cout << "\n\n\t\t\t1].  To Delete Item In Linked List";
		std::cout << "\n\t\t\t2].  To Delete Item In Database";
		std::cout << "\n\t\t\t3]. To Clear Screen";

		std::cout << "\n\n\t\tEnter your choice : ";
		std::cout << "[ ]\b\b";
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");

			int function;
			function = op_.delete_item(pro_id , L1);
			if (function)
			{
				cout << "\n\t\tDelete In Linked List Successfully! : ";
			}
		}
		else if (choice == 2)
		{
			system("cls");

			int function;
			function = db_.delete_item(pro_id);

			if (function == 0)
			{
				cout << "\n\t\tDelete In Database Successfully!";
			}
			else
			{
				cout << "\n\t\tDelete In Database Unsuccessfully!";
			}
		}
		else if (choice == 3)
		{
			system("cls");
			goto Menu;
		}
		else
		{
			Operation_Function();
		}
	} while (true);
}

void Searching()
{
	int choice;

	int pro_id;
	std::cout << "\n\t\tEnter product's ID : ";
	std::cin >> pro_id;
	system("cls");

	do
	{
		Menu:
		std::cout << "\n\n\t\t\t1].  To Search Item In Linked List";
		std::cout << "\n\t\t\t2].  To Search Item In Database";
		std::cout << "\n\t\t\t3]. To Clear Screen";

		std::cout << "\n\n\t\tEnter your choice : ";
		std::cout << "[ ]\b\b";
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			int function;
			function = op_.search_item(pro_id, L1);

			if (function)
			{
				cout << "\n\t\tItem In Linked List Found! : ";
			}
		}
		else if (choice == 2)
		{
			system("cls");

			int function;
			function = db_.search_item(pro_id);
			if (function == 0)
			{
				cout << "\n\t\tSearch In Database Successfully!";
			}
			else
			{
				cout << "\n\t\tSearch In Database Unsuccessfully!";
			}
		}
		else if (choice == 3)
		{
			system("cls");
			goto Menu;
		}
		else
		{
			Operation_Function();
		}
	} while (true);
}

void Displaying()
{
	int choice;

	system("cls");

	do
	{
		Menu:
		std::cout << "\n\n\t\t\t1].  To Display Item In Linked List";
		std::cout << "\n\t\t\t2].  To Display Item In Database";
		std::cout << "\n\t\t\t3]. To Clear Screen";

		std::cout << "\n\n\t\tEnter your choice : ";
		std::cout << "[ ]\b\b";
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			int function;
			function = op_.display_item(L1);
		}
		else if (choice == 2)
		{
			system("cls");

			int function;

			function = db_.display_item();

			if (function == 0)
			{
				cout << "\n\t\tDisplay From Database Successfully!";
			}
			else
			{
				cout << "\n\t\tDisplay From Database Unsuccessfully!";
			}
		}
		else if (choice == 3)
		{
			system("cls");
			goto Menu;
		}
		else
		{
			Operation_Function();
		}
	} while (true);
}

void Modifying()
{
	int choice;

	int pro_id;
	std::cout << "\n\t\tEnter product's ID : ";
	std::cin >> pro_id;

	system("cls");

	do
	{
		Menu:
		std::cout << "\n\n\t\t\t1].  To Modify Item In Linked List";
		std::cout << "\n\t\t\t2].  To Modify Item In Database";
		std::cout << "\n\t\t\t3]. To Clear Screen";

		std::cout << "\n\n\t\tEnter your choice : ";
		std::cout << "[ ]\b\b";
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			op_.modify_item(pro_id, L1);
		}
		else if (choice == 2)
		{
			int function;

			system("cls");
			function = db_.modify_item(pro_id);
			if (function == 0)
			{
				cout << "\n\t\tModified In Database Successfully!";
			}
			else
			{
				cout << "\n\t\tModified In Database Unsuccessfully!";
			}
		}
		else if (choice == 3)
		{
			system("cls");
			goto Menu;
		}
		else
		{
			Operation_Function();
		}
	} while (true);
}

void Operation_Function()
{
	db_._createDataBase();
	db_._createTable();

	int choice;

	system("cls");
	do
	{
	menu:
		std::cout << "\n\n\t\t1]. Insert Product's Record";
		std::cout << "\n\n\t\t2]. Modify Product's Record";
		std::cout << "\n\n\t\t3]. Delete Product's Record";
		std::cout << "\n\n\t\t4]. Search Product's Record";
		std::cout << "\n\n\t\t5]. Display All Product's Record";
		std::cout << "\n\n\t\t6]. Clear The Screen";
		std::cout << "\n\n\t\t7]. Exit";
		std::cout << "\n\n\t\tEnter your choice";
		std::cout << " [ ]\b\b";
		std::cin >> choice;

		if (choice == 1)
		{
			system("cls");
			Inserting();
		}
		else if (choice == 2)
		{
			system("cls");
			Modifying();
		}
		else if (choice == 3)
		{
			system("cls");
			Deleting();
		}
		else if (choice == 4)
		{
			system("cls");
			Searching();
		}
		else if (choice == 5)
		{
			system("cls");
			Displaying();
		}
		else if (choice == 6)
		{
			system("cls");
			goto menu;
		}
	} while (choice != 7);
}
void RITH_main()
{
	Operation_Function();
	return;
}
