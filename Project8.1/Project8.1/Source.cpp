#include <iostream>
#include <string>

using namespace std;

bool CheckPair(const string& s)
{
    for (size_t i = 0; i < s.length() - 1; i++)
    {
        if ((s[i] == 'n' && s[i + 1] == 'o') || (s[i] == 'o' && s[i + 1] == 'n'))
        {
            return true;  
        }
    }
    return false;  
}

string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("no", pos)) != string::npos)
    {
        s.replace(pos, 2, "***");
        pos += 3; 
    }

    pos = 0;  
    while ((pos = s.find("on", pos)) != string::npos)
    {
        s.replace(pos, 2, "***");
        pos += 3; 
    }

    return s;  
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);  // Читання рядка з консолі

    if (CheckPair(str))
    {
        cout << "There is a pair of adjacent 'no' or 'on'." << endl;
    }
    else
    {
        cout << "There are no pairs of adjacent 'no' or 'on'." << endl;
    }

    string dest = Change(str);
    cout << "Modified string: " << dest << endl;  

    return 0;
}
