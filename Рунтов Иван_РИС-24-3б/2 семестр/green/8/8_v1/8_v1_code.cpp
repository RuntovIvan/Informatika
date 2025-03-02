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
		cout << "Фамилия: ";
		getline(cin, lastname);
		cout << "Имя: ";
		getline(cin, name);
		cout << "Отчество: ";
		getline(cin, patronymic);
		cout << "Дата рождения: ";
		getline(cin, birth_date);
		cout << "Адрес проживания: ";
		getline(cin, address);
		cout << "Рейтинг: ";
		getline(cin, rating);
		cout << endl;
	}

	void show_student_data()
	{
		cout << "Фамилия: " << lastname << endl;
		cout << "Имя: " << name << endl;
		cout << "Отчество: " << patronymic << endl;
		cout << "Дата рождения: " << birth_date << endl;
		cout << "Адрес проживания: " << address << endl;
		cout << "Рейтинг: " << rating << endl;
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

	int n; // количество студентов
	cout << "Введите количество студентов: ";
	cin >> n;
	while (n < 3)
	{
		cout << "Студентов должно быть не менее 5. Введите повторно: ";
		cin >> n;
	}
	getchar(); // для пропуска символа '\n'

	// изначальный массив структур
	Student* students = new Student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Студент #" << i + 1 << endl;
		students[i].fill_student_data();
	}

	//запрос имени файла
	string filename;
	cout << "Введите имя файла: ";
	getline(cin, filename);

	write_to_bin_file(students, n, filename);
	clear_students(students, n);

	cout << "Изначально в файле" << endl;
	read_from_bin_file(students, n, filename);
	print_to_console(students, n);

	insert_before_lastname(students, n);
	write_to_bin_file(students, n, filename);
	clear_students(students, n);

	cout << "Добавление перед заданной фамилией" << endl;
	read_from_bin_file(students, n, filename);
	print_to_console(students, n);

	delete_repeats_date(students, n);
	write_to_bin_file(students, n, filename);
	clear_students(students, n);

	cout << "Удаление совпаающих дат рождения" << endl;
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
	cout << endl << "Записанные в файл студенты: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Студент #" << i + 1 << endl;
		students[i].show_student_data();
	}
}

void write_to_bin_file(Student* students, int n, string filename)
{
	FILE* file = fopen(filename.c_str(), "wb");
	
	if (file == nullptr)
	{
		cout << "Ошибка открытия файла при записи." << endl;
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
		cout << "Ошибка открытия файла при чтении." << endl;
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
		cout << "Введите фамилию, перед которой нужно вставить нового студента: ";
		getline(cin, last);

		for (int i = 0; i < n; i++)
			if (students[i].lastname == last)
				ind = i;

		if (ind == -1)
			cout << "Такой фамилии нет." << endl;
	}

	n++;
	Student* new_students = new Student[n];

	for (int i = 0; i < ind; i++)
		new_students[i] = students[i];

	cout << endl << "Заполните данные о новом студенте:" << endl;
	new_students[ind].fill_student_data();

	for (int i = ind + 1; i < n; i++)
		new_students[i] = students[i - 1];

	delete[] students;
	students = new_students;
}

void delete_repeats_date(Student*& students, int& n)
{
	string* dates = new string[n]; // даты рождения студентов
	for (int i = 0; i < n; i++)
		dates[i] = students[i].birth_date; // заполнение дат

	for (int i = 0; i < n; i++) // проходим по каждой дате
	{
		int date_count = 0; // счетчик даты
		for (int j = 0; j < n; j++)
			if (dates[j] == dates[i])
				date_count += 1;

		if (date_count >= 2) // если есть совпадения
		{
			Student* new_students = new Student[n - date_count]; // список студентов без совпадений дат
			int ind = 0;
			for (int k = 0; k < n; k++)
				if (dates[k] != dates[i]) // если дата не совпадает, то добавляем студента
				{
					new_students[ind] = students[k];
					ind++;
				}

			// обновляем список студентов
			delete[] students;
			students = new_students;
			n -= date_count;

			// обновляем список дат
			delete[] dates;
			dates = new string[n];
			for (int m = 0; m < n; m++)
				dates[m] = students[m].birth_date;

			// для повторного прохождения по датам
			i = -1;
		}
	}
	delete[] dates;
}