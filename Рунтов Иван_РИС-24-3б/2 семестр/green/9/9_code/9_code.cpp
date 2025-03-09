#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <clocale>
using namespace std;

void output(string f);
void copy(string f1, string f2);
void num_max_dig(string f);

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "Строки в первом файле:" << endl;
    output("F1.txt");
    cout << endl;
    
    cout << "Слово с наибольшим количеством цифр в первом файле:" << endl;
    num_max_dig("F1.txt");
    cout << endl;

    copy("F1.txt", "F2.txt");

    cout << "Строки во втором файле:" << endl;
    output("F2.txt");
    cout << endl;

    cout << "Слово с наибольшим количеством цифр во втором файле:" << endl;
    num_max_dig("F2.txt");
    cout << endl;
    return 0;
}

// вывод строк из файла f в консоль
void output(string f)
{
    ifstream fin(f);
    string str;

    while (getline(fin, str))
        cout << str << endl;

    fin.close();
}

// Копирование строк по условию из файла f1 в файл f2
void copy(string f1, string f2)
{
    ifstream fin(f1);
    ofstream fout(f2);

    string line;
    while (getline(fin, line))
    {
        bool flag = false;
        string line_copy_1 = line;
        istringstream in_line(line_copy_1);

        string word;
        while (in_line >> word && flag == false)
        {
            int kol = 0;

            string line_copy_2 = line;
            istringstream in_line_cmp(line_copy_2);
            string word_cmp;
            while (in_line_cmp >> word_cmp)
                if (word_cmp == word)
                    kol++;

            if (kol >= 2)
                flag = true;
        }
        if (flag == true)
            fout << line << endl;
    }
    fin.close();
    fout.close();
}

// поиск слова с максимальным количеством цифр в файле f
void num_max_dig(string f)
{
    int num = 0; // номер слова в файле
    int max_dig = 0; // максимальное количество цифр в слове
    string s_max_dig; // слово с максимальным кол-вом цифр

    ifstream fin(f);
    string word;
    int i = 0;

    while (fin >> word)
    {
        i++;
        int kol_dig = 0;

        for (int ind = 0; ind < word.length(); ind++)
            if (isdigit(word[ind]))
                kol_dig++;

        if (kol_dig > max_dig)
        {
            max_dig = kol_dig;
            s_max_dig = word;
            num = i;
        }
    }

    fin.close();

    cout << "Слово: " << s_max_dig << endl;
    cout << "Количество цифр: " << max_dig << endl;
    cout << "Номер слова: " << num << endl;
}