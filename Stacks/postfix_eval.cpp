#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class postfix
{
    int top;
    char postfix_[50];
    int stack_[50];
public:
    postfix()
    {
        top=-1;
    }
    void get();
    void eval();
    void push(int);
    int pop();
    void display();
};
void postfix::push(int i)
{
    ++top;
    stack_[top]=i;
}
int postfix::pop()
{
    if(top==-1)
        return -1;
    return stack_[top--];
}
void postfix::get()
{
    top=-1;
    cin>>postfix_;
}
void postfix::eval()
{
    int result;
    for(int i=0;i<strlen(postfix_);++i)
    {
        if(isdigit(postfix_[i]))
            push(int(postfix_[i]-'0'));
        else
        {
            int a=pop();
            int b=pop();
            if(a!=-1&&b!=-1)
            {
                switch(postfix_[i])
                {
                case '+':
                    result=b+a;
                    break;
                case '-':
                    result=b-a;
                    break;
                case '*':
                    result=b*a;
                    break;
                case '/':
                    result=b/a;
                    break;
                case '^':
                    result=pow(b,a);
                    break;
                default:
                    cout<<"Invalid character in stack"<<endl;
                }
                push(result);
            }
        }
    }
}
void postfix::display()
{
    if(top==0)
        cout<<"Result is "<<stack_[top]<<endl;
    else
        cout<<"Invalid postfix"<<endl;
}
int main()
{
    postfix obj;
    int ch;
    do
    {
        cout<<"Enter 1 to input postfix, 2 to display result, 0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.get();
            break;
        case 2:
            obj.eval();
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
