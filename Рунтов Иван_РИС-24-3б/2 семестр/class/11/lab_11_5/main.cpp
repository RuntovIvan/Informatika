#include "List.h"
#include "Pair.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(nullptr));

	try
	{
		List<Pair> lst(3);
		lst.show();

		// задание 3
		lst.add(lst.srednee());
		lst.show();

		// задание 4
		Pair key;
		int start, end;

		cout << "Введите ключ и границы интервала:" << endl;
		cout << "key:"; cin >> key;
		cout << "start = "; cin >> start; if (start < 0) throw 1;
		cout << "end = "; cin >> end; if (end > lst.get_size()) throw 2;

		lst.erase_by_key(key, start, end);
		lst.show();

		// задание 5
		lst.add_min_max();
		lst.show();
	}
	catch (int)
	{
		cout << endl << "error" << endl;
	}

	return 0;
}