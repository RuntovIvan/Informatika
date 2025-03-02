#include <iostream>
#include <stdio.h>
#include <clocale>
#include <string>
using namespace std;

struct Student
{
	string lastname = "";
	string name = "";
	string patronymic = "";
	string birth_date = "";
	string address = "";
	string rating = "";

	void fill_student_data()
	{
		cout << "�������: ";
		getline(cin, lastname);
		cout << "���: ";
		getline(cin, name);
		cout << "��������: ";
		getline(cin, patronymic);
		cout << "���� ��������: ";
		getline(cin, birth_date);
		cout << "����� ����������: ";
		getline(cin, address);
		cout << "�������: ";
		getline(cin, rating);
		cout << endl;
	}

	void show_student_data()
	{
		cout << "�������: " << lastname << endl;
		cout << "���: " << name << endl;
		cout << "��������: " << patronymic << endl;
		cout << "���� ��������: " << birth_date << endl;
		cout << "����� ����������: " << address << endl;
		cout << "�������: " << rating << endl;
		cout << endl;
	}

	void clear_student_data()
	{
		lastname = "";
		name = "";
		patronymic = "";
		birth_date = "";
		address = "";
		rating = "";
	}
};

void clear_students(Student* students, int n);
void print_to_console(Student* students, int n);
void insert_before_lastname(Student*& students, int& n);
void delete_repeats_date(Student*& students, int& n);
void write_to_bin_file(Student* students, int n, string filename);
void read_from_bin_file(Student* students, int n, string filename);

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	int n; // ���������� ���������
	cout << "������� ���������� ���������: ";
	cin >> n;
	while (n < 3)
	{
		cout << "��������� ������ ���� �� ����� 5. ������� ��������: ";
		cin >> n;
	}
	getchar(); // ��� �������� ������� '\n'

	// ����������� ������ ��������
	Student* students = new Student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "������� #" << i + 1 << endl;
		students[i].fill_student_data();
	}

	//������ ����� �����
	string filename;
	cout << "������� ��� �����: ";
	getline(cin, filename);

	write_to_bin_file(students, n, filename);
	clear_students(students, n);

	cout << "���������� � �����" << endl;
	read_from_bin_file(students, n, filename);
	print_to_console(students, n);

	insert_before_lastname(students, n);
	write_to_bin_file(students, n, filename);
	clear_students(students, n);

	cout << "���������� ����� �������� ��������" << endl;
	read_from_bin_file(students, n, filename);
	print_to_console(students, n);

	delete_repeats_date(students, n);
	write_to_bin_file(students, n, filename);
	clear_students(students, n);

	cout << "�������� ���������� ��� ��������" << endl;
	read_from_bin_file(students, n, filename);
	print_to_console(students, n);

	delete[] students;
	return 0;
}

void clear_students(Student* students, int n)
{
	for (int i = 0; i < n; i++)
		students[i].clear_student_data();
}

void print_to_console(Student* students, int n)
{
	cout << endl << "���������� � ���� ��������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "������� #" << i + 1 << endl;
		students[i].show_student_data();
	}
}

void write_to_bin_file(Student* students, int n, string filename)
{
	FILE* file = fopen(filename.c_str(), "wb");
	
	if (file == nullptr)
	{
		cout << "������ �������� ����� ��� ������." << endl;
		return;
	}

	fwrite(students, sizeof(Student), n, file);
	fclose(file);
}

void read_from_bin_file(Student* students, int n, string filename)
{
	FILE* file = fopen(filename.c_str(), "rb");

	if (file == nullptr)
	{
		cout << "������ �������� ����� ��� ������." << endl;
		return;
	}

	fread(students, sizeof(Student), n, file);
	fclose(file);
}

void insert_before_lastname(Student*& students, int& n)
{
	int ind = -1;
	string last;
	while (ind == -1)
	{
		cout << "������� �������, ����� ������� ����� �������� ������ ��������: ";
		getline(cin, last);

		for (int i = 0; i < n; i++)
			if (students[i].lastname == last)
				ind = i;

		if (ind == -1)
			cout << "����� ������� ���." << endl;
	}

	n++;
	Student* new_students = new Student[n];

	for (int i = 0; i < ind; i++)
		new_students[i] = students[i];

	cout << endl << "��������� ������ � ����� ��������:" << endl;
	new_students[ind].fill_student_data();

	for (int i = ind + 1; i < n; i++)
		new_students[i] = students[i - 1];

	delete[] students;
	students = new_students;
}

void delete_repeats_date(Student*& students, int& n)
{
	string* dates = new string[n]; // ���� �������� ���������
	for (int i = 0; i < n; i++)
		dates[i] = students[i].birth_date; // ���������� ���

	for (int i = 0; i < n; i++) // �������� �� ������ ����
	{
		int date_count = 0; // ������� ����
		for (int j = 0; j < n; j++)
			if (dates[j] == dates[i])
				date_count += 1;

		if (date_count >= 2) // ���� ���� ����������
		{
			Student* new_students = new Student[n - date_count]; // ������ ��������� ��� ���������� ���
			int ind = 0;
			for (int k = 0; k < n; k++)
				if (dates[k] != dates[i]) // ���� ���� �� ���������, �� ��������� ��������
				{
					new_students[ind] = students[k];
					ind++;
				}

			// ��������� ������ ���������
			delete[] students;
			students = new_students;
			n -= date_count;

			// ��������� ������ ���
			delete[] dates;
			dates = new string[n];
			for (int m = 0; m < n; m++)
				dates[m] = students[m].birth_date;

			// ��� ���������� ����������� �� �����
			i = -1;
		}
	}
	delete[] dates;
}