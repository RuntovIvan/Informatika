#include "Pair.h"
#include "file_work.h"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	Pair p;
	int kol, code;
	string filename;

	do
	{
		cout << endl << "1. ������� ����" << endl;
		cout << "2. ����� � �������" << endl;
		cout << "3. �������� ������ ���������" << endl;
		cout << "4. ��������� ����� �����" << endl;
		cout << "5. ��������� ������������ �����" << endl;
		cout << "6. �������� K ��������� ����� ��������� ������" << endl;
		cout << "0. �����" << endl;
		cout << '>';  cin >> code; cin.ignore(1);

		switch (code)
		{
		case 1:
			cout << "������� ��� �����: "; getline(cin, filename);
			kol = make_file(filename);
			if (kol < 0) cout << "���������� ������� ����\n";
			break;
		case 2:
			cout << "������� ��� �����: "; getline(cin, filename);
			kol = print_file(filename);
			if (kol < 0) cout << "���������� ��������� ����\n";
			if (kol == 0) cout << "���� ������\n";
			break;
		case 3:
			cout << "������� ��� �����: "; getline(cin, filename);
			kol = del_fewer(filename);
			if (kol < 0) cout << "���������� ��������� ����\n";
			if (kol == 0) cout << "���� ������\n";
			break;
		case 4:
			cout << "������� ��� �����: "; getline(cin, filename);
			kol = add_int(filename);
			if (kol < 0) cout << "���������� ��������� ����\n";
			if (kol == 0) cout << "���� ������\n";
			break;
		case 5:
			cout << "������� ��� �����: "; getline(cin, filename);
			kol = add_double(filename);
			if (kol < 0) cout << "���������� ��������� ����\n";
			if (kol == 0) cout << "���� ������\n";
			break;
		case 6:
			cout << "������� ��� �����: "; getline(cin, filename);
			kol = add_file(filename);
			if (kol < 0) cout << "���������� ��������� ����\n";
			if (kol == 0) cout << "���� ������\n";
			break;
		}
	} while (code != 0);

	return 0;
}


