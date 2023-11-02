// 4 Вариант
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251 >> null");
    setlocale(0, "RU");

    cout << endl << endl << "__________Пункт 1___________" << endl << endl;

    char str[101] = "Анна Павловна почти закрыла глаза в знак того, никто не может судить за то, что нравится императрице";
    char dict[22] = "бвгджзйклмнпрстфxцчшщ";
    bool ifsogl;
    int k = 0;
    cout << "Исходная строка: " << endl << str << endl << endl;
    for (int i = 0; i < 101; i++) {
        ifsogl = false;
        for (int j = 0; j < 21; j++) {
            if ((str[i] == dict[j]) || (str[i] == (char)((int)dict[j] - 32))) {
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

    //Таблица символов
    cout << endl << endl;
    for (int i = -64; i < -32; i++) {
        cout << (char)i << " (" << i << ")" << "     ";
        cout << (char)(i + 32) << " (" << i + 32 << ")" << endl;
    }
    cout << (char)-72 << " (" << -72 << ")" << "     ";
    cout << (char)-88 << " (" << -88 << ")" << endl;
    cout << '.' << " (" << (int)'.' << ")" << "     ";
    cout << ',' << " (" << (int)',' << ")" << endl;
    cout << '!' << " (" << (int)'!' << ")" << "     ";
    cout << '?' << " (" << (int)'?' << ")" << endl;
    cout << '(' << " (" << (int)'(' << ")" << "     ";
    cout << ')' << " (" << (int)')' << ")" << endl;
    cout << '"' << " (" << (int)'"' << ")" << "     ";
    cout << '-' << " (" << (int)'-' << ")" << endl;
    cout << ':' << " (" << (int)':' << ")" << "     ";
    cout << ';' << " (" << (int)';' << ")" << endl << endl;

    //_________________________________________________________________________________________________________________________

    cout << endl << endl << "__________Пункт 2___________" << endl << endl;

    //Чтение заданного слова----------------------------------------------
    short N;
    string wrd;
    ifstream fin("input.txt");
    //В файле input.txt данные хранятся в формате число пробел строчка (10 Прекрасный)
    if (fin.is_open())
        fin >> N >> wrd;
    else {
        cout << "Файл input.txt не открыт. Введите слово: ";
        cin >> wrd;
        cout << "Введите N: ";
        cin >> N;
    }
    if (N < 0 || N > 10) {
        cout << "Введён некорректный N (" << N << ") \nУстановлено число N = 10 \n";
        N = 10;
    }
    else
        cout << "N = " << N << endl;
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
        while(i < s.length()) {

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
            /*от*/
            //Сравнение с наименьшим словом массива-------------
            if (s.length() > result[0].length()) {
                is_similar = false;

                //Проверка на совпадение слов-------------------
                for (int i = N - 1; i > 0; i--) { //Идём справа налево
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
                    for (int i = 0; i < N - 1; i++)
                        if (result[i].length() > result[i + 1].length())
                            swap(result[i], result[i + 1]);
                        else
                            break;
                }

            }
            /*до*/

            /*
            for (int i = N - 1; i >= 0; i--) {
                if (s == result[i])
                    break;
                if (s.length() > result[i].length()) {
                    for (int j = 0; j < i; j++) {
                        result[j] = result[j + 1];
                    }
                    result[i] = s;
                    break;
                }
            }
            */

            /*
            int min_l = INT16_MAX;
            int min_i;
            is_similar = false;
            for (int i = 0; i < N; i++) {
                if (result[i].length() < min_l) {
                    min_l = result[i].length();
                    min_i = i;
                }
                if (s == result[i]) {
                    is_similar = true;
                    break;
                }
            }
            if (!is_similar) {
                if (s.length() > min_l)
                    result[min_i] = s;
            }
            //Для этого способа неоюходима сортировка перед выводом в result.txt и консоль
            */

            //Часть между от и до можно менять на одну из частей в комментариях
            //Это иные способы заполнения массива)
            //За объяснением можно в лс t.me/lipllleon
        }
    }
    file.close();

    //Вывод в result.txt---------------------------------------------------
    ofstream fout("result.txt");
    if (fout.is_open()) {
        cout << "Файл открыт" << endl;

        //Вывод по невозрастанию-----------
        for (int i = N - 1; i >= 0; i--)
            fout << N - i << ") " << result[i] << " (" << result[i].length() << ")" << endl;
        cout << "Данные записаны" << endl << endl << "Результат: " << endl;
    }
    else {
        cout << "Файл не открыт" << endl << endl << "Результат: " << endl;
    }
    fout.close();

    //Вывод в консоль-------------------------------------------------------
    for (int i = N - 1; i >= 0; i--)
        cout << N - i << ") " << result[i] << " (" << result[i].length() << ")" << endl;

    //_________________________________________________________________________________________________________________________

    //Недоделан :(

    cout << endl << endl << "__________Доп___________" << endl << endl;

    ifstream filedop("textdop.txt");
    ofstream output("output.txt");
    string st;
    int l;
    while (!filedop.eof()) {
        filedop >> st;
        l = st.length();
        for (int i = 0; i < l - 1; i++) {
            if ((st[i] >= -64) && (st[i] <= -1) || (st[i] == -72) || (st[i] == -88)) {
                if (st[i] == st[i + 1]) {
                    st[i] = toupper(st[i]);
                    st[i + 1] = toupper(st[i + 1]);
                    st = st + "(" + st[i] + st[i + 1] + ")";
               }
            }
        }
        output << st << " ";
    }
    filedop.close();
    output.close();
    cout << "Отформатированный текст записан в output.txt" << endl << endl;
}
