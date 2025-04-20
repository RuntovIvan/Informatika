#include <iostream>
#include <clocale>
#include <set>
using namespace std;

typedef multiset<double> mset;

mset make_set(int n)
{
	mset ms;
	double tmp;

	for (int i = 0; i < n; i++)
	{
		tmp = (double)(rand() % 15) / 2.5;
		ms.insert(tmp);
	}
	return ms;
}

void show(mset ms)
{
	cout << "\nМножество с дубликатами:\n";
	for (mset::iterator it = ms.begin(); it != ms.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

double srednee(mset ms)
{
	double tmp = 0;
	for (mset::iterator it = ms.begin(); it != ms.end(); it++)
		tmp += *it;
	tmp /= ms.size();
	return tmp;
}

void erase_by_key(mset& ms, double key, int start, int end)
{
	mset::iterator it = ms.begin();
	for (int i = 0; i < start; i++)
		it++;

	for (int i = start; i < end; i++)
		if (*it == key)
			it = ms.erase(it);
		else
			it++;
}

void add_min_max(mset& ms)
{
	mset::iterator it = ms.begin();
	double min = *it, max = *it;
	
	for (; it != ms.end(); it++)
		if (*it > max)
			max = *it;
		else if (*it < min)
			min = *it;

	cout << endl << "min = " << min << endl;
	cout << "max = " << max << endl;
	cout << "min + max = " << min + max << endl;

	mset new_ms;
	for (it = ms.begin(); it != ms.end(); it++)
		new_ms.insert(*it + min + max);
	ms = new_ms;
}

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	mset ms = make_set(10);
	show(ms);

	//задание 3
	cout << endl << "Среднее: " << srednee(ms) << endl;
	ms.insert(srednee(ms));
	show(ms);

	//задание 4
	double key;
	int start, end;
	cout << endl;
	cout << "Введите ключ и диапазон для удаления:" << endl;
	cout << "key = "; cin >> key;
	cout << "start = "; cin >> start;
	cout << "end = "; cin >> end;

	erase_by_key(ms, key, start, end);
	show(ms);

	//задание 5
	add_min_max(ms);
	show(ms);

	return 0;
}