#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(0, "RU");
    char str[101] = "Анна Павловна почти закрыла глаза в знак того, никто не может судить за то, что нравится императрице";
    char dict[43] = "БВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфxцчшщ";
    bool ifsogl;
    int k = 0;
    cout << "Исходная строка: " << endl << str << endl << endl;
    for (int i = 0; i < 101; i++) {
        ifsogl = false;
        for (int j = 0; j < 43; j++) {
            if (str[i] == dict[j]) {
                ifsogl = true;
                break;
            }
        }
        if (!ifsogl) {
            str[k] = str[i];
            k++;
        }
    }
    for (int i = k; i < 101; i++)
        str[i] = '\0';

    cout << "Строка без согласных: " << endl << str;

    //_________________________________________________________________________________________________________________________

    cout << endl << endl << "__________Пункт 2___________" << endl << endl;

    clock_t start = clock();

    //Чтение заданного слова----------------------------------------------
    string wrd;
    ifstream fin("input.txt");
    if (fin.is_open())
        fin >> wrd;
    else
    {
        cout << "Файл input.txt не открыт. Введите слово: ";
        cin >> wrd;
    }
    fin.close();

    cout << "Заданное слово: " << wrd;

    //Удаление повторяющихся букв (из "АБВвбабвабб" получаем "абв")-------
    string  rule = wrd;
    int index = 0;
    for (int i = 0; i < wrd.length(); i++) {
        wrd[i] = tolower(wrd[i]);
        int j;
        for (j = 0; j < i; j++)
            if (wrd[i] == wrd[j])
                break;
        if (i == j)
            rule[index++] = wrd[i];
    }
    rule.erase(index, wrd.length() - index);
    cout << " (" << rule << ")" << endl << endl;

    //Получение массива слов----------------------------------------------
    string s;
    string result[10];
    bool is_rule, is_similar;
    ifstream file("text.txt");
    if (!file.is_open()) {
        cout << "Файл text.txt не открыт";
        return -1;
    }

    while (!file.eof()) {
        file >> s;
        is_rule = true;
        int i = 0;

        //Проверка условия-------------------------------------
        for (char const& c : s) {

            //Проверка на русские буквы------------------------
            if (!((s[i] >= -64) && (s[i] <= -1) || (s[i] == -72) || (s[i] == -88))) {
                if (((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))) {
                    is_rule = false;
                    break;      //Если английская буква - переходим к след слову
                }
                s.erase(i, 1);  //Если не русская буква, например, точка или запятая - удаляем
            }
            else {
                s[i] = tolower(s[i]);

                //Проверка на наличие заданных букв------------
                for (int j = 0; j < rule.length(); j++) {
                    if (s[i] == rule[j]) {
                        is_rule = false;
                        break;
                    }
                }
                if (!is_rule)
                    break;      //Если встретили букву из заданного слова - переходим к след слову
                i++;
            }

        }

        //Заполнение массива------------------------------------
        if (is_rule && !(s == "")) {

            //Сравнение с наименьшим словом массива-------------
            if (s.length() > result[0].length()) {
                is_similar = false;

                //Проверка на совпадение слов-------------------
                for (int i = 9; i > 0; i--) { //Идём справа налево
                    if (result[i] == "")
                        break;  //Если ячейка пуста - останавливаем проверку
                    if (s == result[i]) {
                        is_similar = true;
                        break;
                    }
                }
                if (!is_similar) {
                    result[0] = s;

                    //Сортировка по возрастанию длины------------
                    for (int i = 0; i < 9; i++)
                        if (result[i].length() > result[i + 1].length())
                            swap(result[i], result[i + 1]);
                        else
                            break;
                }

            }
        }
    }
    file.close();

    //Вывод в result.txt---------------------------------------------------
    ofstream fout("result.txt");
    if (fout.is_open()) {
        cout << "Файл открыт" << endl;

        //Вывод по невозрастанию-----------
        for (int i = 9; i >= 0; i--)
            fout << 10 - i << ") " << result[i] << " (" << result[i].length() << ")" << endl;
        cout << "Данные записаны" << endl << endl << "Результат: " << endl;
    }
    else {
        cout << "Файл не открыт" << endl << endl << "Результат: " << endl;
    }
    fout.close();

    //Вывод в консоль-------------------------------------------------------
    for (int i = 9; i >= 0; i--)
        cout << 10 - i << ") " << result[i] << " (" << result[i].length() << ")" << endl;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout.precision(3);
    cout << "\nВремя работы: " << seconds << " сек\n";
}