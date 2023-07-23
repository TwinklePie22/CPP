#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int main()
{
    ifstream infile("F:\\input.txt"); // input file
    if (!infile)
    {
        cout << "Cannot open infile file.\n";
        return 1;
    }
    ofstream outfile("TextFile1.txt"); // output file
    if (!outfile)
    {
        cout << "Cannot open outfile file.\n";
        return 1;
    }
    char str[5][20];
    char temp[20];
    int i, j;
    cout << "file contents \n";
    for (int i = 0; i < 5; i++)
    {
        infile >> str[i];
        cout << str[i] << endl;
    }
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            if (strcmp(str[j - 1], str[j]) > 0)
            {
                strcpy(temp, str[j - 1]);
                strcpy(str[j - 1], str[j]);
                strcpy(str[j], tem[);
            }
        }
    }
    cout << "Strings (Names) in alphabetical order : \n";
    for (i = 0; i < 5; i++)
    {
        cout << str[i] << "\n";
        outfile << str[i] << "\n";
    }
}
