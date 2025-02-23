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

    cout << "Слово с наибольшим количеством цифр в первофм файле:" << endl;
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
    ifstream in(f);
    string str;

    while (getline(in, str))
    {
        cout << str << endl;
    }

    in.close();
}

// Копирование строк по условию из файла f1 в файл f2
void copy(string f1, string f2)
{
    ifstream inf(f1);
    ofstream ouf(f2);

    string line;
    while (getline(inf, line))
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
            {
                if (word_cmp == word)
                    kol++;
            }

            if (kol >= 2)
                flag = true;
        }
        if (flag == true)
            ouf << line << endl;
    }
    inf.close();
    ouf.close();
}

// поиск слова с максимальным количеством цифр в файле f
void num_max_dig(string f)
{
    int num = 0;
    int max_dig = 0;
    string s_max_dig;

    ifstream inf(f);
    string word;
    int i = 0;

    while (inf >> word)
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

    inf.close();

    cout << "Слово: " << s_max_dig << endl;
    cout << "Количесвто цифр: " << max_dig << endl;
    cout << "Номер слова: " << num << endl;
}