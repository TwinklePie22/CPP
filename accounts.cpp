#include <iostream>
#include <fstream>
using namespace std;
struct bank
{
    char name[20];
    double bal;
    long acc;
};
int main()
{
    int n, i;
    cout << "Enter no. of entries : ";
    cin >> n;
    struct bank b[n];
    ofstream outfile("bank.txt", ios::out);
    if (!outfile)
    {
        cout << "Cannot outfileen file \n";
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter a/c number of customer " << i + 1 << ": ";
        cin >> b[i].acc ;
        cout << "Enter name of customer " << i + 1 << ": ";
        cin >>b[i].name;
        cout << "Enter balamce of customer " << i + 1 << ": ";
        cin >>b[i].bal;
        outfile.write((char *)&b[i], sizeof(struct bank));
    }
    outfile.close();
    
    ifstream infile("bank.txt", ios::in);
    if (!infile)
    {
        cout << "File doesn't exists \n";
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (infile)
        {   
            cout<<"\nDetails of customer "<<i+1;
            infile.read((char *)&b[i], sizeof(struct bank));
            cout << "A/c number  : " << b[i].acc << "\n";
            cout << "Name : " << b[i].name << "\n";
            cout << "Balance (in INR) : " << b[i].bal << "\n";
        }
    }

    infile.close();
    return 0;
}
