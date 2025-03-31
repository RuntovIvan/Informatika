#include <iostream>
#include <clocale>
#include <cmath>
#include <string>
using namespace std;

string name[30]{"���������", "������", "�����", "�����", "������", "��������", "��������", "�������", "�������", "����", "�����", "������", "����������","������","������","����","�����","�����","������","���������","�������","�����","����","�������","�����","����","�����","������","�������","������"};
string patronymic[30]{"�������������","���������","���������","���������","����������","������������","�����������","����������","����������","��������","��������","����������","��������������","����������","�������","��������","��������","���������","���������","�������������","����������","���������","�������","�����������","���������","��������","���������","����������","����������","����������"};
string surname[30]{"�������","������","��������","�����","��������","������","�������","��������","�������","�������","�������","������","��������","�������","�������","������","������","������","��������","��������","�����","�������","�������","�������","�������","�������","�������","�������","��������","��������"};
string ID[30]{"USER_ID_001","USER_ID_002","USER_ID_003","USER_ID_004","USER_ID_005","USER_ID_006","USER_ID_007","USER_ID_008","USER_ID_009","USER_ID_010","USER_ID_011","USER_ID_012","USER_ID_013","USER_ID_014","USER_ID_015","USER_ID_016","USER_ID_017","USER_ID_018","USER_ID_019","USER_ID_020","USER_ID_021","USER_ID_022","USER_ID_023","USER_ID_024","USER_ID_025","USER_ID_026","USER_ID_027","USER_ID_028","USER_ID_029","USER_ID_030"};
string birth_date[30]{"01.01.1990","15.05.1985","24.12.2000","10.03.1978","04.07.1995","30.11.1982","18.09.2003","22.06.1975","07.02.1998","03.04.1988","26.10.2001","12.08.1972","29.01.1993","05.09.1980","08.05.2005","25.08.2006","21.03.1997","14.07.1984","09.11.2002","20.04.1970","06.06.1992","01.10.1981","11.02.2004","28.08.1979","15.04.1999","03.12.1987","01.07.2000","19.05.1973","23.09.1996","02.03.1983"};

int collisions = 0;

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
};

struct hash_table
{
	Human* arr; // ������ ���-�������

	void create_hash_table(int size)
	{
		arr = new Human[size];
	}

	void clear_hash_table()
	{
		delete[] arr;
	}

	void add(Human temp, int size); // ��� ���������� �������� � ���-�������
	void pop(string birth_date, int size); // �������� �������� �� ���-������� �� ���� ��������
	int find_index(string birth_date, int size); // ����� ������� � ���-������� �� ���� ��������
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

void show_human(Human t)
{
	cout << "���:\t" << t.fio << endl;
	cout << "ID:\t" << t.ID_num << endl;
	cout << "���� ��������:\t" << t.date_of_birth << endl << endl;
}

void show_hash_table(hash_table table, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "�����c: " << i << endl;
		show_human(table.arr[i]);
	}
}

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

int hash_table::find_index(string birth_date, int size)
{
	int hash = hash_function(birth_date, size);
	int index = hash;

	while (arr[index].date_of_birth != birth_date && index < size)
		index++;

	if (index >= size)
	{
		index = 0;

		while (arr[index].date_of_birth != birth_date && index < hash)
			index++;

		if (index >= hash)
			return -1;
		else
			return index;
	}
	else
		return index;
}

void hash_table::add(Human temp, int size)
{
	int hash = hash_function(temp.date_of_birth, size);
	int index = hash;

	if (arr[index].fio == "NULL")
	{
		arr[index] = temp;
		return;
	}
	else
	{
		while (index < size)
		{
			if (arr[index].fio == "NULL")
			{
				arr[index] = temp;
				return;
			}
			index++;
			collisions++;
		}

		if (index >= size)
		{
			index = 0;
			while (index < hash)
			{
				if (arr[index].fio == "NULL")
				{
					arr[index] = temp;
					return;
				}
				index++;
				collisions++;
			}
		}
	}
}

void hash_table::pop(string birth_date, int size)
{
	int index = find_index(birth_date, size);

	if (index != -1)
		arr[index] = Human();
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	int size;
	cout << "������� ������ ���-�������: ";
	cin >> size;
	while (size < 1)
	{
		cout << "������ ������ ���� ����������� ������: ";
		cin >> size;
	}

	Human* humans = new Human[size];
	fill_array_random_humans(humans, size);

	hash_table table;
	table.create_hash_table(size);

	for (int i = 0; i < size; i++)
		table.add(humans[i], size);

	show_hash_table(table, size);

	string date_of_birth = "25.08.2006";
	int index = table.find_index(date_of_birth, size);

	if (index != -1)
		cout << "������� � ����� �������� " << date_of_birth << " ���������� �� ������� " << index << endl;
	else
		cout << "�������� � ����� �������� " << date_of_birth << " ���" << endl;

	table.pop(date_of_birth, size);

	show_hash_table(table, size);

	cout << "���������� ��������: " << collisions << endl;
	table.clear_hash_table();
	delete[] humans;
	return 0;
}