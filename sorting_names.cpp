#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int main()
{
    ifstream input("F:\\input.txt"); // input
    if (!input)
    {
        cout << "Cannot open input file.\n";
        return 1;
    }
    ofstream output("TextFile1.txt"); // output
    if (!output)
    {
        cout << "Cannot open output file.\n";
        return 1;
    }
    char str[5][20];
    char t[20];
    int i, j;
    cout << "file contents \n";
    for (int i = 0; i < 5; i++)
    {
        input >> str[i];
        cout << str[i] << endl;
    }
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            if (strcmp(str[j - 1], str[j]) > 0)
            {
                strcpy(t, str[j - 1]);
                strcpy(str[j - 1], str[j]);
                strcpy(str[j], t);
            }
        }
    }
    cout << "Strings (Names) in alphabetical order : \n";
    for (i = 0; i < 5; i++)
    {
        cout << str[i] << "\n";
        output << str[i] << "\n";
    }
}
