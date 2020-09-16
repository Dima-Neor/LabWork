#include <iostream>
//#include <clocale>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;
void filling(string &str) //���������� ��ப
{
    string fileName;
    int menu;
    cout << "��� �� ��� ��������� ��ப�:\n[1]- ������\n[2]- �� 䠩��\n";
    cout << "��� �롮�: ";
    cin >> menu;
    if (menu == 1)
    {
        cin.ignore(32767, '\n');
        cout << "������ ��ப�: ";
        getline(cin, str, '\n');
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����४�� ���� ������ ��ப� ᭮��: ";
            getline(cin, str, '\n');
        }
    }
    else
    {
        cout << "������ �������� 䠩��: ";
        cin >> fileName;
        ifstream file(fileName);
        if (file.is_open())
        {
            getline(file, str, '\n');
        }
        else
        {
            cout << "����� 䠩� �� ������\n";
        }
    }
}
void filling(char *cSrt) //���������� �� ��ப
{
    string fileName;
    int menu;
    cout << "��� �� ��� ��������� ��ப�:\n[1]- ������\n[2]- �� 䠩��\n";
    cout << "��� �롮�: ";
    cin >> menu;
    if (menu == 1)
    {
        cin.ignore(32767, '\n');
        cout << "������ ��ப�: ";
        cin.getline(cSrt, 100, '\n');
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����४�� ���� ������ ��ப� ᭮��: ";
            cin.getline(cSrt, '\n');
        }
    }
    else
    {
        cout << "������ �������� 䠩��: ";
        cin >> fileName;
        ifstream file(fileName);
        if (file.is_open())
        {
            file.getline(cSrt, 100, '\n');
        }
        else
        {
            cout << "����� 䠩� �� ������\n";
        }
    }
}
void filling(wstring &wStr) //���������� �ப�� ��ப
{
    string fileName;
    int menu;
    cout << "��� �� ��� ��������� ��ப�:\n[1]- ������\n[2]- �� 䠩��\n";
    cout << "��� �롮�: ";
    cin >> menu;
    if (menu == 1)
    {
        cin.ignore(32767, '\n');
        cout << "������ ��ப�: ";
        getline(wcin, wStr);
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����४�� ���� ������ ��ப� ᭮��: ";
            getline(wcin, wStr);
        }
    }
    else
    {
        cout << "������ �������� 䠩��: ";
        cin >> fileName;
        wifstream file(fileName);
        if (file.is_open())
        {
            getline(file, wStr);
        }
        else
        {
            cout << "����� 䠩� �� ������\n";
        }
    }
}

void filling2(vector<string> &array)
{
    int menu;
    cout << "��� �� ��� ��������� ��ப�:\n[1]- ������\n[2]- �� 䠩��\n";
    cout << "��� �롮�: ";
    cin >> menu;
    if (menu == 1)
    {
        stringstream words;
        string k;
        cin.ignore(32767, '\n');
        cout << "������ ��ப�: ";
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
        cout << "������ �������� 䠩��: ";
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
            cout << "����� 䠩� �� ������\n";
        }
    }
}
void filling2(vector<char *> &array)
{
    int menu;
    char t[100];
    cout << "��� �� ��� ��������� ��ப�:\n[1]- ������\n[2]- �� 䠩��\n";
    cout << "��� �롮�: ";
    cin >> menu;
    if (menu == 1)
    {
        stringstream words;
        cin.ignore(32767, '\n');
        cout << "������ ��ப�: ";
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
        cout << "������ �������� 䠩��: ";
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
            cout << "����� 䠩� �� ������\n";
        }
    }
}
int tasck1(char *cStr) // ��ࢮ� ������� ��� � ��ப
{
    char ch;
    int counter = 0;
    cout << "������ ᨬ��� ����� ��� 㤠����: ";
    cin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ᨬ��� ᭮��: ";
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
int tasck1(string &str) // ��ࢮ� ������� ��� �++ ��ப
{
    char ch;
    int counter = 0;
    cout << "������ ᨬ��� ����� ��� 㤠����: ";
    cin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ᨬ��� ᭮��: ";
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
int tasck1(wstring &str) // ��ࢮ� ������� ��� �ப�� ��ப
{
    wchar_t ch;
    int counter = 0;
    cout << "������ ᨬ��� ����� ��� 㤠����: ";
    wcin >> ch;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ᨬ��� ᭮��: ";
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
    cout << "����� ᨬ��� �㭮 ����� ?: ";
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
    cout << "����� ᨬ��� �㦭� ����� ?: ";
    cin >> c;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i][strlen(array[i]) - 1] == c)
            counter++;
    }
    return counter;
}

int submenu() //���� �롮� ⨯� ��ப�
{
    int menu;
    cout << "����� ⨯ ��ப �� ��� �ᯮ�짮���� ?\n";
    cout << "[1]- �-��ப�\n[2]- ����� string\n[3]- �ப�� ��ப�\n";
    cin >> menu;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "����४�� ����! ������ ᨬ��� ᭮��: ";
        cin >> menu;
    }
    while (menu > 3 && menu < 1)
    {
        cout << "������ �㭪� ���, �롥�� ����騩�� �㭪� ����: ";
        cin >> menu;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "����४�� ����! ������ ᨬ��� ᭮��: ";
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
    cout << "������ୠ� ࠡ�� � 8. ��ਠ�� � 9. �믮����: �㫠⮢ ����਩\n";
    do
    {
        cout << "\n_MENU_\n";
        cout << "[1]- ������� �1\n[2]- ������� �2\n[3]- ������� �3\n[0]- ��室\n";
        cout << "�롥�� �������: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "�������: � �������� ��ப� 㤠���� �� ������� ᨬ���� � �������� ������⢮ 㤠������ ᨬ�����.\n";
            switch (submenu())
            {
            case 1:
                filling(cStr);
                cout << "��ப� �� ���������: ";
                cout << cStr << "\n";
                count = tasck1(cStr);
                cout << "��ப� ��᫥ ���������: ";
                cout << cStr;
                cout << " ������� ᨬ�����: ";
                cout << count;
                break;
            case 2:
                filling(stdStr);
                cout << "��ப� �� ���������: ";
                cout << stdStr << "\n";
                count = tasck1(stdStr);
                cout << "��ப� ��᫥ ���������: ";
                cout << stdStr;
                cout << " ������� ᨬ�����: ";
                cout << count;
                break;
            case 3:
                filling(wStr);
                cout << "��ப� �� ���������: ";
                wcout << wStr << "\n";
                count = tasck1(wStr);
                cout << "��ப� ��᫥ ���������: ";
                wcout << wStr;
                cout << " ������� ᨬ�����: ";
                cout << count;
                break;
            default:
                break;
            }

            break;
        case 2:
            cout << "�������: ��� ����� ᫮�, ࠧ�������� �窮� � ����⮩ (;). ����� �����稢����� �����稥� (:). ��।�����, ᪮�쪮 � ��� ᫮�, �����稢������ �������� �㪢��.";
            switch (submenu())
            {
            case 1:
                filling2(arrayCStr);
                count = tasck2(arrayCStr);
                cout << "������⢮ ᫮� ���稢������ �� ������ �㪢�: " << count << "\n";
                break;
            case 2:
                filling2(arrayStdStr);
                count = tasck2(arrayStdStr);
                cout << "������⢮ ᫮� ���稢������ �� ������ �㪢�: " << count << "\n";
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