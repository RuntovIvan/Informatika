#include <iostream>
#include <clocale>
using namespace std;

void show();
bool check(int row, int col);
void game(int row);

const int size_arr = 8;
int pole[size_arr][size_arr]{};
int k = 0;

int main()
{
	setlocale(LC_ALL, "RU");
	game(0);
	return 0;
}

void show()
{
	for (int i = 0; i < size_arr; i++)
	{
		for (int j = 0; j < size_arr; j++)
			cout << ((pole[i][j]) ? "! " : "# ");
		cout << endl;
	}
}

bool check(int row, int col)
{
	// проверка столбца сверху
	for (int i = 0; i < row; i++)
		if (pole[i][col])
			return false;

	// проверка главной диагонали сверху
	for (int i = 1; row - i >= 0 && col - i >= 0; i++)
		if (pole[row - i][col - i])
			return false;

	// проверка побочной диагонали сверху
	for (int i = 1; row - i >= 0 && col + i < size_arr; i++)
		if (pole[row - i][col + i])
			return false;

	return true;
}

void game(int row)
{
	if (row == size_arr)
	{
		cout << "Расстановка #" << ++k << endl << endl;
		show();
		cout << endl;
		return;
	}

	for (int col = 0; col < size_arr; col++)
		if (check(row, col))
		{
			pole[row][col] = 1;
			game(row + 1);
			pole[row][col] = 0;
		}

	return;
}