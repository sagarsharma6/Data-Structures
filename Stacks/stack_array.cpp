#include<iostream>
using namespace std;
class stack
{
    int arr[10];
    int top;
    int max;
    int min;
public:
    stack()
    {
        top=-1;
        max=3;
        min=0;
    }
    void push(int);
    void pop();
    void peek();
};
void stack::push(int ele)
{
    if(top>max)
        cout<<"Overflow"<<endl;
    else
    {
        ++top;
        arr[top]=ele;
        cout<<"Element "<<ele<<" pushed"<<endl;
    }
}
void stack::pop()
{
    if(top<min)
        cout<<"Underflow"<<endl;
    else
    {
        --top;
        cout<<"Element popped"<<endl;
    }
}
void stack::peek()
{
    if(top==-1)
        cout<<"Empty Stack"<<endl;
    else
        cout<<arr[top]<<endl;
}
int main()
{
    stack obj;
    int ch;
    do
    {
        cout<<"Enter 1 to push, 2 to pop, 3 to peek, 0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter Element to push: ";
            int ele;
            cin>>ele;
            obj.push(ele);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.peek();
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"Invalid input,try again: "<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
