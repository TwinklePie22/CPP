#include <iostream>
#include <fstream>
using namespace std;
struct bank
{
    string name;
    double bal;
    long acc;
};
int main()
{
    int n;
    cout << "Enter no. of entries: ";
    cin >> n;
    struct bank arr[n];
    ofstream outfile("F:\\bank.txt");
    if (!outfile)
    {
        cout << "Cannot open file\n";
        return 1;
    }
    outfile << "Name,Account Number,Balance\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter name of customer " << i + 1 << ": ";
        cin >> arr[i].name;
        cout << "Enter a/c number of customer " << i + 1 << ": ";
        cin >> arr[i].acc;
        cout << "Enter balance of customer " << i + 1 << ": ";
        cin >> arr[i].bal;
        outfile << arr[i].name << "," << arr[i].acc << "," << arr[i].bal << "\n";
    }
    outfile.close();
    ifstream infile("F:\\bank.txt");
    if (!infile)
    {
        cout << "File doesn't exist\n";
        return 1;
    }
    string header;
    getline(infile, header); // Skip the header line
    for (int i = 0; i < n; i++)
    {
        cout << "\nDetails of customer " << i + 1 << endl;
        getline(infile, arr[i].name, ',');
        infile >> arr[i].acc;
        infile.ignore(); // Ignore the comma
        infile >> arr[i].bal;
        infile.ignore(); // Ignore the newline character
        cout << "Name: " << arr[i].name << "\n";
        cout << "A/c number: " << arr[i].acc << "\n";
        cout << "Balance (in INR): " << arr[i].bal << "\n";
    }
    infile.close();
    return 0;
}
