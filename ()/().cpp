#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char* str = new char[100];
    cin.get(str, 100);
    int a = strlen(str);
    cin.get();

    /*Алфавит, можно сделать через словарь <map>*/
    char alf[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char _alf[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == _alf[j])
            {
                str[i] = alf[j];
            }
        }
    }
    bool pointer = false;
    for (int i = 0; i <= a; i++)
    {
        if (pointer == true)
        {
            str[i - 1] = ')';
            pointer = false;
        }
        for (int j = i + 1; j <= a; j++)
        {
            if (str[i] == str[j])
            {
                str[j] = ')';
                pointer = true;

            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        if (str[i] != ')')
        {
            str[i] = '(';
        }
    }
    cout << str;
    delete[] str;
    return 0;
}
