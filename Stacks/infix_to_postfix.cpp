#include<iostream>
#include<cstring>
using namespace std;
class stack
{
    char infix[50];
    char postfix[50];
    char stack_[50];
    int top;
public:
    stack()
    {
        top=0;
        stack_[0]='(';
    }
    void push(char);
    void pop(int&);
    void get();
    void display();
    void conversion();
    int precedence(char);
};
void stack::get()
{
    top=0;
    cin>>infix;
    int len=strlen(infix);
    infix[len]=')';
    infix[len+1]='\0';
}
void stack::conversion()
{
    int j=0;
    for(int i=0;infix[i]!='\0';++i)
    {
        if(isalpha(infix[i])||isdigit(infix[i]))
        {
            postfix[j]=infix[i];
            ++j;
        }
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            if(precedence(infix[i])>precedence(stack_[top]))
                push(infix[i]);
            else
            {
                while(precedence(stack_[top])>=precedence(infix[i]))
                    pop(j);
                push(infix[i]);
            }
        }
        else if(infix[i]==')')
        {
            while(stack_[top]!='(')
            {
                pop(j);
            }
            pop(j);
        }
    }
    postfix[j]='\0';
}
void stack::display()
{
    int len=strlen(infix);
    infix[len-1]='\0';
    cout<<"Infix: "<<infix<<endl;
    cout<<"Postfix: "<<postfix<<endl;
}
void stack::push(char c)
{
    ++top;
    stack_[top]=c;
}
void stack::pop(int &j)
{
    if(stack_[top]!='(')
    {
        postfix[j]=stack_[top];
        ++j;
    }
    --top;
}
int stack::precedence(char ch)
{
    if(ch=='^')
        return 4;
    if(ch=='*'||ch=='/')
        return 3;
    if(ch=='+'||ch=='-')
        return 2;
    return 1;
}
int main()
{
    stack obj;
    int ch;
    do
    {
        cout<<"Enter 1 to input infix, 2 to display postfix, 0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.get();
            break;
        case 2:
            obj.conversion();
            obj.display();
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"Invalid input,try again"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
