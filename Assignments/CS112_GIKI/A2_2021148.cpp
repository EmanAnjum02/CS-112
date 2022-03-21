#include <iostream>
using namespace std;

size_t Mystrlen(const char *s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    cout << "The size of your string is: " << count << endl;
}

char *Mystrcpy(char *s1, const char *s2)
{
    for (int i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }
    cout << "The copied string is: ";
    return s1;
}

char *Mystrncpy(char *s1, const char *s2, size_t n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        s1[i] = s2[i];
    }
    cout << "The copied string is: ";
    return s1;
}

char *Mystrcat(char *s1, const char *s2)
{
    int count = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        count++;
    }
    int i = 0;
    for (int j = count; s2[i] != '\0'; j++)
    {
        s1[j] = s2[i];
        i++;
    }
    return s1;
}

char *Mystrncat(char *s1, const char *s2, size_t n)
{
    int count = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        count++;
    }
    int i = 0;
    for (int j = count; i < n; j++)
    {
        s1[j] = s2[i];
        i++;
    }
    return s1;
}

int Mystrcmp(const char *s1, const char *s2)
{
    int flag = 0;
    {
        if (*s1 != *s2)
        {
            if (*s1 > *s2)
            {
                return 1;
            }
            else if (*s1 < *s2)
            {
                return -1;
            }

            s1++;
            s2++;
        }
    }
    return flag;
}

int Mystrncmp(const char *s1, const char *s2, size_t n)
{
    int flag = 0;
    int i = 0;
    {
        while (i < n)
        {
            if (*s1 != *s2)
            {
                if (*s1 > *s2)
                {
                    return 1;
                }
                else if (*s1 < *s2)
                {
                    return -1;
                }

                s1++;
                s2++;
            }
            i++;
        }
    }
    return flag;
}

void clear(char *arr, int size)
{
    for (int k = 0; k < size; k++)
    {
        arr[k] = ' ';
    }
}

char *Mystrtok(char *s1, const char *s2)
{

    int i = 0, j = 0;
    char temp[10] = {};
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[0])
        {
            temp[j] = s1[i];
            i++;
            j++;
        }
        else
        {
            cout << temp << endl;
            clear(temp, j);
            i++;
            j = 0;
        }
    }
    cout << temp << endl;
    return 0;
}

int main()
{
    //initialize the arrays according to the requriment of your function
    char s1[20] = {};
    const char s2[20] = {};
    int n;
    cout << "Please enter the value of n: ";
    cin >> n;
    Mystrlen(s1);
    cout << Mystrcpy(s1, s2) << endl;
    cout << Mystrncpy(s1, s2, n) << endl;
    cout << Mystrcat(s1, s2) << endl;
    cout << Mystrncat(s1, s2, n) << endl;
    cout << Mystrcmp(s1, s2) << endl;
    cout << Mystrncmp(s1, s2, n) << endl;
    cout << Mystrtok(s1, s2) << endl; // give a delimeter in s2 array
    return 0;
}