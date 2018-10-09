#include<iostream>
using namespace std;
class stack
{
    struct node
    {
        int value;
        struct node *next;
    };
    struct node *top;
    struct node *new_node;
    struct node *temp;
    struct node *ptr;
public:
    stack()
    {
        top=NULL;
    }
    void push(int);
    void pop();
    void show();
};
void stack::push(int num)
{
    new_node=new node;
    new_node->value=num;
    new_node->next=top;
    top=new_node;
    cout<<"Element Pushed.";
}
void stack::pop()
{
    if(top==NULL)
        cout<<"Underflow";
    else
    {
        temp=top;
        top=temp->next;
        temp->next=NULL;
        delete temp;
        cout<<"Element Popped.";
    }
}
void stack::show()
{
    if(top==NULL)
        cout<<"Empty Stack";
    else
    {
        ptr=top;
        cout<<ptr->value<<" ";
    }
}
int main()
{
    stack obj;
    int option;
    do
    {
        cout<<"\nEnter 1 to push,2 to pop,3 to display,0 to exit: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter element you want to push: ";
            int num;
            cin>>num;
            obj.push(num);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.show();
            break;
        case 0:
            option=0;
            break;
        default:
            cout<<"Invalid choice";
        }
    }
    while(option!=0);
    return 0;
}

