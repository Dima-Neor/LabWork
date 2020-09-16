#include <iostream>
//#include <clocale>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;
void filling(string &str) //заполнение строк
{
    string fileName;
    int menu;
    cout << "Как вы хотите заполнить строку:\n[1]- Вручную\n[2]- Из файла\n";
    cout << "Ваш выбор: ";
    cin >> menu;
    if (menu == 1)
    {
        cin.ignore(32767, '\n');
        cout << "Введите строку: ";
        getline(cin, str, '\n');
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некоректный ввод Введите строку снова: ";
            getline(cin, str, '\n');
        }
    }
    else
    {
        cout << "Введите название файла: ";
        cin >> fileName;
        ifstream file(fileName);
        if (file.is_open())
        {
            getline(file, str, '\n');
        }
        else
        {
            cout << "Такой файл не найден\n";
        }
    }
}
void filling(char *cSrt) //заполнение Си строк
{
    string fileName;
    int menu;
    cout << "Как вы хотите заполнить строку:\n[1]- Вручную\n[2]- Из файла\n";
    cout << "Ваш выбор: ";
    cin >> menu;
    if (menu == 1)
    {
        cin.ignore(32767, '\n');
        cout << "Введите строку: ";
        cin.getline(cSrt, 100, '\n');
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некоректный ввод Введите строку снова: ";
            cin.getline(cSrt, '\n');
        }
    }
    else
    {
        cout << "Введите название файла: ";
        cin >> fileName;
        ifstream file(fileName);
        if (file.is_open())
        {
            file.getline(cSrt, 100, '\n');
        }
        else
        {
            cout << "Такой файл не найден\n";
        }
    }
}
void filling(wstring &wStr) //заполнение широких строк
{
    string fileName;
    int menu;
    cout << "Как вы хотите заполнить строку:\n[1]- Вручную\n[2]- Из файла\n";
    cout << "Ваш выбор: ";
    cin >> menu;
    if (menu == 1)
    {
        cin.ignore(32767, '\n');
        cout << "Введите строку: ";
        getline(wcin, wStr);
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некоректный ввод Введите строку снова: ";
            getline(wcin, wStr);
        }
    }
    else
    {
        cout << "Введите название файла: ";
        cin >> fileName;
        wifstream file(fileName);
        if (file.is_open())
        {
            getline(file, wStr);
        }
        else
        {
            cout << "Такой файл не найден\n";
        }
    }
}

void filling2(vector<string> &array)
{
    int menu;
    cout << "Как вы хотите заполнить строку:\n[1]- Вручную\n[2]- Из файла\n";
    cout << "Ваш выбор: ";
    cin >> menu;
    if (menu == 1)
    {
        stringstream words;
        string k;
        cin.ignore(32767, '\n');
        cout << "Введите строку: ";
        getline(cin, k, ':');
        words << k;
        for (int i = 0; !words.eof(); i++)
        {
            array.resize(i + 1);
            getline(words, array[i], ';');
        }
    }
    else
    {
        string fileName;
        cout << "Введите название файла: ";
        cin >> fileName;
        ifstream file(fileName);
        if (file.is_open())
        {
            for (int i = 0; !file.eof(); i++)
            {
                array.resize(i + 1);
                getline(file, array[i], ';');
            }
            array[array.size() - 1].pop_back();
        }
        else
        {
            cout << "Такой файл не найден\n";
        }
    }
}
void filling2(vector<char *> &array)
{
    int menu;
    char t[100];
    cout << "Как вы хотите заполнить строку:\n[1]- Вручную\n[2]- Из файла\n";
    cout << "Ваш выбор: ";
    cin >> menu;
    if (menu == 1)
    {
        stringstream words;
        cin.ignore(32767, '\n');
        cout << "Введите строку: ";
        cin.getline(t, 100, ':');
        cout << "t = " << t << "\n";
        words << t;
        for (int i = 0; !words.eof(); i++)
        {
            words.getline(t, 100, ';');
            cout << "t = " << t << "\n";
            array.resize(i + 1);
            array[i] = new char[strlen(t) + 1];
            strcpy(array[i], "");
            strcat(array[i], t);
        }
    }
    else
    {
        string fileName;
        cout << "Введите название файла: ";
        cin >> fileName;
        ifstream file(fileName);
        if (file.is_open())
        {
            int i;
            for (i = 0; !file.eof(); i++)
            {
                file.getline(t, ';');
                array.resize(i + 1);
                array[i] = new char[strlen(t) + 1];
                strcpy(array[i], "");
                strcat(array[i], t);
            }
        }
        else
        {
            cout << "Такой файл не найден\n";
        }
    }
}
int tasck1(char *cStr) // первое задание для С строк
{
    char ch;
    int counter = 0;
    cout << "Введите символ который хотите удалить: ";
    cin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите символ снова: ";
        cin >> ch;
    }
    for (int i = 0; i < strlen(cStr); i++)
    {
        if (cStr[i] == ch)
        {
            counter++;
            for (int j = i; j < strlen(cStr); j++)
            {
                cStr[j] = cStr[j + 1];
            }
            i--;
        }
    }
    return counter;
}
int tasck1(string &str) // первое задание для С++ строк
{
    char ch;
    int counter = 0;
    cout << "Введите символ который хотите удалить: ";
    cin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите символ снова: ";
        cin >> ch;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ch)
        {
            counter++;
            str.erase(str.begin() + i);
            i--;
        }
    }
    return counter;
}
int tasck1(wstring &str) // первое задание для широких строк
{
    wchar_t ch;
    int counter = 0;
    cout << "Введите символ который хотите удалить: ";
    wcin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите символ снова: ";
        wcin >> ch;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ch)
        {
            counter++;
            str.erase(str.begin() + i);
            i--;
        }
    }
    return counter;
}

int tasck2(vector<string> array)
{
    int counter = 0;
    char c;
    cout << "Какой символ нуно икать ?: ";
    cin >> c;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i].at(array[i].size() - 1) == c)
            counter++;
    }
    return counter;
}
int tasck2(vector<char *> &array)
{
    int counter = 0;
    char c;
    cout << "Какой символ нужно икать ?: ";
    cin >> c;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i][strlen(array[i]) - 1] == c)
            counter++;
    }
    return counter;
}

int submenu() //меню выбора типа стороки
{
    int menu;
    cout << "Какой тип строк вы хотите использовать ?\n";
    cout << "[1]- С-строки\n[2]- класс string\n[3]- широкие строки\n";
    cin >> menu;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некоректный ввод! Введите символ снова: ";
        cin >> menu;
    }
    while (menu > 3 && menu < 1)
    {
        cout << "Такого пункта нет, выберите имеющийся пункт меню: ";
        cin >> menu;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некоректный ввод! Введите символ снова: ";
            cin >> menu;
        }
    }
    if (menu == 1)
    {
        return 1;
    }
    else if (menu == 2)
    {
        return 2;
    }
    else
    {
        return 3;
    }
    return 0;
}

int main()
{
    //setlocale(LC_ALL, "rus");
    char cStr[100];
    vector<char *> arrayCStr;
    string stdStr;
    //string arrayStdStr[100];
    vector<string> arrayStdStr;
    wstring wStr;
    wstring arrayWStr[1];
    int menu;
    int count;
    cout << "Лабараторная работа № 8. Вариант № 9. Выполнил: Булатов Дмитрий\n";
    do
    {
        cout << "\n_MENU_\n";
        cout << "[1]- Задание №1\n[2]- Задание №2\n[3]- Задание №3\n[0]- Выход\n";
        cout << "Выберите задание: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Задание: В заданной строке удалить все заданные символы и подсчитать количество удаленных символов.\n";
            switch (submenu())
            {
            case 1:
                filling(cStr);
                cout << "Строка до изменения: ";
                cout << cStr << "\n";
                count = tasck1(cStr);
                cout << "Строка после изменения: ";
                cout << cStr;
                cout << " Удалено символов: ";
                cout << count;
                break;
            case 2:
                filling(stdStr);
                cout << "Строка до изменения: ";
                cout << stdStr << "\n";
                count = tasck1(stdStr);
                cout << "Строка после изменения: ";
                cout << stdStr;
                cout << " Удалено символов: ";
                cout << count;
                break;
            case 3:
                filling(wStr);
                cout << "Строка до изменения: ";
                wcout << wStr << "\n";
                count = tasck1(wStr);
                cout << "Строка после изменения: ";
                wcout << wStr;
                cout << " Удалено символов: ";
                cout << count;
                break;
            default:
                break;
            }

            break;
        case 2:
            cout << "Задание: Дан набор слов, разделенных точкой с запятой (;). Набор заканчивается двоеточием (:). Определить, сколько в нем слов, заканчивающихся заданной буквой.";
            switch (submenu())
            {
            case 1:
                filling2(arrayCStr);
                count = tasck2(arrayCStr);
                cout << "Количество слов окачивающихся на данную букву: " << count << "\n";
                break;
            case 2:
                filling2(arrayStdStr);
                count = tasck2(arrayStdStr);
                cout << "Количество слов окачивающихся на данную букву: " << count << "\n";
                break;

            default:
                break;
            }
            /* code */
            break;
        case 3:
            /* code */
            break;
        default:
            break;
        }
    } while (menu != 0);

    return 0;
}