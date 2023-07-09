#include <iostream>
using namespace std;
#define size 5
class stack
{
    int stck[size];
    int tos;
public:
    void init();
    void push();
    int pop();
    void display();
};

void stack::init()
{
    tos = 0;
}

void stack::push()

{
    int i;
    if (tos == size)
    {
        cout << "Stack overflowl \n";
        return;
    }
    cout << "Enter element: ";
    cin >> i;
    stck[tos] = i;
    tos++;
}

int stack::pop()
{
    if (tos == 0)
    {
        cout << "Stack underflow\n";
        return 1;
    }
    tos--;
    cout <<"Popped element is "<< stck[tos]<<"\n";
    return 0;

}
void stack::display()
{
    if (tos == 0)
    {
        cout << "Stack is empty \n";
        return;
    }
    for (int i = 0; i < tos; i++)
    {
       cout << stck[i] << "\n";
    }
}

int main()
{
    int ch, i;
    stack s;
    s.init();
    cout << "1-Push 2-Pop 3-Display 4-Exit \n";
    while (1)
    {
        cout<< "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1: s.push();
                break;
        case 2: s.pop();
                break;
        case 3: s.display();
                break;
        case 4: exit(0);
                break;
        default:
            cout<<"Enter a valid choice!\n";
        return 0;
       }
    }
}
