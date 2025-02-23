#include <iostream>
#include <string>
using namespace std;

void fill(string* str, int n);
void show(string* str, int n);
void paste(string*& str, int& n);

int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	// ����������� ���������� �����
	int n;
	cout << "������� ���������� �����: ";
	cin >> n;
	while (n < 1)
	{
		cout << "���������� ����� ������ ���� �����������. ������� ��� ���: ";
		cin >> n;
	}

	// �������� ����������� ������������� �������
	string* str = new string[n];

	getchar(); // ������� ������� '\n'

	// ���������� n �����
	cout << "������� ������:\n";
	fill(str, n);

	// ����� ������������ �������
	cout << endl;
	cout << "�� ����� ��������� ������:\n";
	show(str, n);

	paste(str, n);

	// ����� ����������� �������
	cout << endl;
	cout << "������ � ������ ����������� ������:\n";
	show(str, n);

	delete[] str;

	return 0;
}

void fill(string* str, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". ";
		getline(cin, str[i]);
	}
}

void show(string* str, int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ". " << str[i] << endl;
}

void paste(string*& str, int& n)
{
	// ������ ������ ����� ������
	int pos;
	cout << endl;
	cout << "������� ����� ����� ������: ";
	cin >> pos;
	while (pos < 1 || pos > n + 1)
	{
		cout << "����� ������ ������ ���� �� " << 1 << " �� " << n + 1 << ". ������� ��� ���: ";
		cin >> pos;
	}
	pos -= 1;

	// �������� ������ �������
	n++;
	string* new_str = new string[n];

	for (int i = 0; i < pos; i++)
		new_str[i] = str[i];

	cout << "������� ����� ������: ";
	getchar(); // ������� ������� '\n'
	getline(cin, new_str[pos]);

	for (int i = pos + 1; i < n; i++)
		new_str[i] = str[i - 1];

	delete[] str;
	str = new_str;
	new_str = nullptr;
}