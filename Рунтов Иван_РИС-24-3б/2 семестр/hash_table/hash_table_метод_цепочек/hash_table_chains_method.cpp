#include <iostream>
#include <clocale>
#include <cmath>
#include <string>
using namespace std;

string name[30]{ "Александр", "Андрей", "Борис", "Вадим", "Виктор", "Владимир", "Геннадий", "Дмитрий", "Евгений", "Иван", "Игорь", "Кирилл", "Константин","Михаил","Никита","Олег","Павел","Роман","Сергей","Станислав","Тимофей","Федор","Юрий","Ярослав","Артем","Глеб","Денис","Леонид","Николай","Степан" };
string patronymic[30]{ "Александрович","Андреевич","Борисович","Вадимович","Викторович","Владимирович","Геннадьевич","Дмитриевич","Евгеньевич","Иванович","Игоревич","Кириллович","Константинович","Михайлович","Никитич","Олегович","Павлович","Романович","Сергеевич","Станиславович","Тимофеевич","Федорович","Юрьевич","Ярославович","Артемович","Глебович","Денисович","Леонидович","Николаевич","Степанович" };
string surname[30]{ "Смирнов","Иванов","Кузнецов","Попов","Васильев","Петров","Соколов","Михайлов","Новиков","Федоров","Морозов","Волков","Алексеев","Лебедев","Семенов","Егоров","Павлов","Козлов","Степанов","Николаев","Орлов","Андреев","Макаров","Захаров","Борисов","Сергеев","Романов","Яковлев","Тимофеев","Дмитриев" };
string ID[30]{ "USER_ID_001","USER_ID_002","USER_ID_003","USER_ID_004","USER_ID_005","USER_ID_006","USER_ID_007","USER_ID_008","USER_ID_009","USER_ID_010","USER_ID_011","USER_ID_012","USER_ID_013","USER_ID_014","USER_ID_015","USER_ID_016","USER_ID_017","USER_ID_018","USER_ID_019","USER_ID_020","USER_ID_021","USER_ID_022","USER_ID_023","USER_ID_024","USER_ID_025","USER_ID_026","USER_ID_027","USER_ID_028","USER_ID_029","USER_ID_030" };
string birth_date[]{ "01.01.1990","15.05.1985","24.12.2000","10.03.1978","04.07.1995","30.11.1982","18.09.2003","22.06.1975","07.02.1998","03.04.1988","26.10.2001","12.08.1972","29.01.1993","05.09.1980","08.05.2005","25.08.2006","21.03.1997","14.07.1984","09.11.2002","20.04.1970","06.06.1992","01.10.1981","11.02.2004","28.08.1979","15.04.1999","03.12.1987","01.07.2000","19.05.1973","23.09.1996","02.03.1983" };
int collisions = 0;

int get_sum_of_date(string bd)
{
	return stoi(bd.substr(0, 2)) + stoi(bd.substr(3, 2)) + stoi(bd.substr(6, 4));
}

int hash_function(string bd, int size)
{
	double a = ((sqrt(2) - 1) / 2) * get_sum_of_date(bd);
	double c = (a - static_cast<int>(a)) * size;
	return static_cast<int>(c);
}

struct Human
{
	string fio;
	string date_of_birth;
	string ID_num;

	Human()
	{
		fio = "NULL";
		date_of_birth = "NULL";
		ID_num = "NULL";
	}

	void show_human()
	{
		cout << "ФИО:\t" << fio << endl;
		cout << "ID:\t" << ID_num << endl;
		cout << "Дата рождения:\t" << date_of_birth << endl << endl;
	}
};

int get_random_num()
{
	return rand() % 30;
}

string get_random_fio()
{
	return surname[get_random_num()] + " " + name[get_random_num()] + " " + patronymic[get_random_num()];
}

string get_random_ID()
{
	return ID[get_random_num()];
}

string get_random_date()
{
	return birth_date[get_random_num()];
}

Human make_random_human()
{
	Human temp;
	temp.fio = get_random_fio();
	temp.ID_num = get_random_ID();
	temp.date_of_birth = get_random_date();
	return temp;
}

void fill_array_random_humans(Human* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = make_random_human();
}

struct Node
{
	Human human;
	Node* next_ptr = nullptr;

	void init_node(Human temp)
	{
		human = temp;
	}
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
	
	void push_back(Human data)
	{
		Node* node = new Node;
		node->init_node(data);

		if (tail != nullptr)
			tail->next_ptr = node;

		if (head == nullptr)
			head = node;

		tail = node;
		size++;
	}

	void pop_front()
	{
		if (size == 0)
			return;
		
		if (size == 1)
		{
			delete head;
			head = tail = nullptr;
			size--;
			return;
		}

		Node* node = head;
		head = head->next_ptr;
		delete node;
		size--;
	}

	void pop_back()
	{
		if (size == 0)
			return;

		if (size == 1)
		{
			delete tail;
			head = tail = nullptr;
			size--;
			return;
		}

		Node* node = head;
		while (node->next_ptr != tail)
			node = node->next_ptr;

		delete tail;
		node->next_ptr = nullptr;
		tail = node;
		size--;
	}

	int find_key_index(string date_of_birth_find)
	{
		Node* node = head;
		for (int i = 0; node != nullptr; i++)
		{
			if (node->human.date_of_birth == date_of_birth_find)
				return i;
			node = node->next_ptr;
		}
		return -1;
	}

	Node* get_node(int index)
	{
		if (index == -1)
			return nullptr;

		Node* node = head;
		for (int i = 0; i != index; i++)
			node = node->next_ptr;

		return node;
	}

	void erase(string date_of_birth_find)
	{
		int index_find = find_key_index(date_of_birth_find);

		if (index_find == -1)
			return;

		if (index_find == 0)
		{
			pop_front();
			return;
		}

		if (index_find == size - 1)
		{
			pop_back();
			return;
		}

		Node* left = get_node(index_find - 1);
		Node* node = left->next_ptr;
		Node* right = node->next_ptr;

		left->next_ptr = right;
		delete node;
		size--;
	}

	void clear()
	{
		while (head != nullptr)
		{
			Node* node = head;
			head = head->next_ptr;
			delete node;
			size--;
		}
		tail = nullptr;
	}

	void show_list()
	{
		if (size == 0)
		{
			cout << "Список пустой" << endl << endl;
			return;
		}

		Node* node = head;
		int i = 0;
		while (node != nullptr)
		{
			cout << "Индекс в списке " << i << endl;
			node->human.show_human();
			node = node->next_ptr;
			i++;
		}
	}
};

struct hash_table
{
	List* table_arr;

	void create_hash_table(int size)
	{
		table_arr = new List[size];
	}

	void clear_hash_table(int size)
	{
		for (int i = 0; i < size; i++)
			table_arr[i].clear();
		delete[] table_arr;
	}

	void add(Human human, int size)
	{
		int index = hash_function(human.date_of_birth, size);
		collisions += table_arr[index].size;
		table_arr[index].push_back(human);
	}

	void pop(string date_of_birth_delete, int size)
	{
		int index = hash_function(date_of_birth_delete, size);
		table_arr[index].erase(date_of_birth_delete);
	}

	int find_index(string birth_date, int size)
	{
		return hash_function(birth_date, size);
	}

	void show_hash_table(int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Индекс ячейки в хэш-таблице: " << i << endl;
			table_arr[i].show_list();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	int human_size;
	cout << "Введите количество человек: ";
	cin >> human_size;
	while (human_size < 1)
	{
		cout << "Количество должно быть натуральным числом: ";
		cin >> human_size;
	}

	int table_size;
	cout << "Введите размер хэш-таблицы: ";
	cin >> table_size;
	while (table_size < 1)
	{
		cout << "Размер должен быть натуральным числом: ";
		cin >> table_size;
	}

	Human* humans = new Human[human_size];
	fill_array_random_humans(humans, human_size);

	hash_table table;
	table.create_hash_table(table_size);

	for (int i = 0; i < human_size; i++)
		table.add(humans[i], table_size);

	table.show_hash_table(table_size);

	string date_of_birth = "25.08.2006";
	int table_index = table.find_index(date_of_birth, table_size);
	int list_index = table.table_arr[table_index].find_key_index(date_of_birth);

	if (list_index != -1)
		cout << "Человек с датой рождения " << date_of_birth << " содержится\nВ ячейке хэш-таблицы с индексом " << table_index << endl << "В списке по индексу: " << list_index << endl << endl;
	else
		cout << "Человека с датой рождения " << date_of_birth << " нет" << endl << endl;

	table.pop(date_of_birth, table_size);

	table.show_hash_table(table_size);

	cout << "Количество коллизий: " << collisions << endl;
	table.clear_hash_table(table_size);
	delete[] humans;
	return 0;
}