// ���� ������� �����, ���� ������ ����������� ������� s[0], ..., s[n], ...  
// 1.   ��������, �� � � ��� ����������� ��� �������� s[i] , s[i+1]  //      �� s[i] � �� ���� ���� (','), � s[i+1] � ���� ���� ('�'),  
//      �� ��������� �� �������. 
// 2.   ������� ����� ����� �������  //    s[i]  �� ���� ���� (','), � s[i+1] � ���� ���� ('�')  ������� "*". 

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
using namespace std; 

int Count(char* str)
{
    if (strlen(str) < 2)      
        return 0;
    int k = 0;
    for (int i = 0; str[i + 1] != 0; i++)     
        if (str[i] == ',' && str[i + 1] == '-')
            k++;    
    return k;
}
char* Change(char* str)
{
    if (strlen(str) < 2)     
        return str;
    char* tmp = new char[strlen(str) ];  
    char* t = tmp;

    tmp[0] = '\0';   
    int i = 0;
    while (str[i + 2] != 0)
    {
        if (str[i] == ',' && str[i + 1] == '-')
        {
            strcat(t, "*");            
            t += 4;           
            i += 3;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';

    strcpy(str, tmp);

    return tmp;
}  int main() {
    char str[101];

    cout << "Enter string:" << endl;   
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of ',-'" << endl;
    char* dest = new char[151];    
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;   
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
