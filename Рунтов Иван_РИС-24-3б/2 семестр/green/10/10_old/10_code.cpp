#include  <iostream>
#include <clocale>
#define STR_LEN 50
using namespace std;

void get_str(char* str, int len);
void skip();
void fill_str_mass(char** str, int len);
void print_mass(char** str, int len);
void paste_str(char** str, int len, int pos);

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

	// �������� ���������� ������������� �������
	char** str = new char* [n + 1];
	for (int i = 0; i < n + 1; i++)
		str[i] = new char[STR_LEN];

	skip();
	// ���������� n �����
	cout << "������� ������:\n";
	fill_str_mass(str, n);

	// ����� ������������ �������
	cout << endl;
	cout << "�� ����� ��������� ������:\n";
	print_mass(str, n);

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

	// ���������� ����� ������
	paste_str(str, n + 1, pos);

	// ����� ����������� �������
	cout << endl;
	cout << "������ � ������ ����������� ������:\n";
	print_mass(str, n + 1);

	// �������� �������
	for (int i = 0; i < n + 1; i++)
		delete[] str[i];

	delete[] str;
	return 0;
}

// ���� ������ � �������
void get_str(char* str, int len)
{
	char ch = getchar();
	int i = 0;
	while (ch != '\n' && i < len - 1)
	{
		str[i] = ch;
		ch = getchar();
		i++;
	}
	str[i] = '\0';
}

// ������� ������� '\n' ��� ����� ������������� ����������
void skip()
{
	int ch = getchar();
}

// ��������� ������� ��������
void fill_str_mass(char** str, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << ". ";
		get_str(str[i], STR_LEN);
	}
}

// ����� ������� �����
void print_mass(char** str, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << i + 1 << ". ";
		int j = 0;
		while (str[i][j] != '\0')
		{
			cout << str[i][j];
			j++;
		}
		cout << endl;
	}
}

// ���� ����� ������
void paste_str(char** str, int len, int pos)
{
	if (pos == len)
	{
		cout << "������� ����� ������:\n";
		skip();
		get_str(str[pos - 1], STR_LEN);
	}
	else
	{
		for (int i = len - 1; i > pos - 1; i--)
			for (int j = 0; j < STR_LEN; j++)
				str[i][j] = str[i - 1][j];

		cout << "������� ����� ������:\n";
		skip();
		get_str(str[pos - 1], STR_LEN);
	}
}