#include <iostream>
#include <clocale>
#include <fstream>
using namespace std;

void show_arr(int* arr, int start, int end);
int get_arr_size(string filename);
void fill_arr(int* arr, int size, string filename);
void arr_to_file(int* arr, int size, string filename);
int get_fib(int n);
int get_series_count(int* arr, int size);
void fill_fib_arr(int* fib_arr, int count);
void fill_starts_ends(int* arr, int size, int* starts, int* ends, int count);
void merge(int*& arr, int& size, int* starts, int* ends, int count, int ind_prev, int ind_max);
void copy(int*& arr, int& size, int* starts, int* ends, int count, int ind);
void del(int*& arr, int& size, int* starts, int* ends, int count, int start_del, int end_del);
void fictive_series(int*& arr, int size);

int main()
{
	setlocale(LC_ALL, "RU");

	// запись из файла в массив
	int size = get_arr_size("F1.txt");
	int* arr = new int[size];
	fill_arr(arr, size, "F1.txt");

	show_arr(arr, 0, size - 1);
	fictive_series(arr, size);
	show_arr(arr, 0, size - 1);

	arr_to_file(arr, size, "F2.txt");
	return 0;
}

void fill_arr(int* arr, int size, string filename)
{
	ifstream fin(filename);
	for (int i = 0; i < size; i++)
		fin >> arr[i];
	fin.close();
}

void show_arr(int* arr, int start, int end)
{
	cout << '{';
	for (int i = start; i <= end; i++)
		cout << arr[i] << ((i == end) ? "}\n" : ", ");
	cout << endl;
}

int get_arr_size(string filename)
{
	ifstream fin(filename);
	int count = 0;
	int t;
	while (fin >> t)
		count++;
	fin.close();
	return count;
}

void arr_to_file(int* arr, int size, string filename)
{
	ofstream fout(filename);

	for (int i = 0; i < size; i++)
		fout << arr[i] << ' ';

	fout.close();
}

int get_fib(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return get_fib(n - 1) + get_fib(n - 2);
}

int get_series_count(int* arr, int size)
{
	int count = 1;
	for (int i = 1; i < size; i++)
		if (arr[i] < arr[i - 1])
			count++;
	return count;
}

void fill_fib_arr(int* fib_arr, int count)
{
	int ind = 0, fib_s = 1;
	while (ind < count)
	{
		int fib_num = get_fib(fib_s);
		int fib_count = fib_num;
		for (int i = 0; i < fib_num && ind < count; i++)
			fib_arr[ind++] = fib_num;
		fib_s++;
	}
}

void fill_starts_ends(int* arr, int size, int* starts, int* ends, int count)
{
	int i = 0, start = 0, end = 0, ind = 0;
	while (i < size)
	{
		start = i, end = i;
		starts[ind] = start;

		while (i < size - 1 && arr[i] <= arr[i + 1])
			i++;

		end = i;
		i++;

		ends[ind] = end;
		ind++;
	}
}

void merge(int*& arr, int& size, int* starts, int* ends, int count, int ind_prev, int ind_max)
{
	int start1 = starts[ind_prev], end1 = ends[ind_prev], start2 = starts[ind_max], end2 = ends[ind_max];
	int len1 = end1 - start1 + 1, len2 = end2 - start2 + 1;
	int left = start1, right = start2;

	int* merged_ser = new int[len1 + len2];
	for (int i = 0; i < len1 + len2; i++)
		if (left <= end1 && (right > end2 || arr[left] < arr[right]))
			merged_ser[i] = arr[left++];
		else
			merged_ser[i] = arr[right++];

	int* newarr = new int[size + len1];
	int ind = 0;
	for (int i = 0; i < start2; i++)
		newarr[ind++] = arr[i];

	for (int i = 0; i < len1 + len2; i++)
		newarr[ind++] = merged_ser[i];

	for (int i = end2 + 1; i < size; i++)
		newarr[ind++] = arr[i];

	// обновляем индексы следующих в последнем
	for (int i = ind_max + 1; i < count; i++)
	{
		starts[i] += len1;
		ends[i] += len1;
	}

	delete[] arr;
	arr = newarr;
	size = size + len1;
}

void copy(int*& arr, int& size, int* starts, int* ends, int count, int ind)
{
	int len = ends[ind] - starts[ind] + 1;
	int* newarr = new int[size + len];

	int newind = 0;
	for (int i = 0; i < size; i++)
		newarr[newind++] = arr[i];

	for (int i = starts[ind]; i <= ends[ind]; i++)
		newarr[newind++] = arr[i];

	delete[] arr;
	arr = newarr;
	size = size + len;
}

void del(int*& arr, int& size, int* starts, int* ends, int count, int start_del, int end_del)
{
	int start = starts[start_del], end = ends[end_del];
	int len_del = end - start + 1;
	int* newarr = new int[size - len_del];

	int ind = 0;
	for (int i = 0; i < start; i++)
		newarr[ind++] = arr[i];

	for (int i = end + 1; i < size; i++)
		newarr[ind++] = arr[i];

	delete[] arr;
	arr = newarr;
	size = size - len_del;
}

void fictive_series(int*& arr, int size)
{
	int count = get_series_count(arr, size);

	if (count == 1)
		return;

	int* starts = new int[count];
	int* ends = new int[count];
	int* fib_arr = new int[count];

	fill_fib_arr(fib_arr, count);
	fill_starts_ends(arr, size, starts, ends, count);

	int max_fib = -1, pred_max_fib = -1, kol_max_fib = 0, kol_pred_max_fib = 0, indf_max_fib = -1, indf_pred_max_fib = - 1;

	max_fib = fib_arr[count - 1];
	for (int i = 1; pred_max_fib == -1; i++)
		if (get_fib(i + 1) == max_fib)
			pred_max_fib = get_fib(i);

	for (int i = 0; i < count; i++)
	{
		if (fib_arr[i] == max_fib)
		{
			kol_max_fib += 1;
			if (indf_max_fib == -1)
				indf_max_fib = i;
		}
		if (fib_arr[i] == pred_max_fib)
		{
			kol_pred_max_fib += 1;
			if (indf_pred_max_fib == -1)
				indf_pred_max_fib = i;
		}
	}

	for (int i = 0; i < min(kol_max_fib, kol_pred_max_fib); i++)
		merge(arr, size, starts, ends, count, indf_pred_max_fib + i, indf_max_fib + i);

	cout << "Сливаем" << endl;
	show_arr(arr, 0, size - 1);

	if (kol_max_fib < kol_pred_max_fib)
		for (int i = kol_max_fib; i < kol_max_fib + (kol_pred_max_fib - kol_max_fib); i++)
			copy(arr, size, starts, ends, count, indf_pred_max_fib + i);

	cout << "Копируем в конец" << endl;
	show_arr(arr, 0, size - 1);

	del(arr, size, starts, ends, count, indf_pred_max_fib, indf_pred_max_fib + kol_pred_max_fib - 1);
	
	show_arr(arr, 0, size - 1);

	delete[] starts, ends, fib_arr;
	fictive_series(arr, size);
}