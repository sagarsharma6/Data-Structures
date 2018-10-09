#include<iostream>
#include<string>
using namespace std;
class priority_queue_matrix
{
    string arr[10][10];
    int front[10];
    int rear[10];
public:
    priority_queue_matrix()
    {
        for(int i=0;i<10;++i)
        {
            front[i]=-1;
            rear[i]=-1;
        }
    }
    void enq();
    void deq();
    void deq_whole_or_single(int);
    void display();
};
void priority_queue_matrix::enq()
{
    cout<<"Enter priority: ";
    int pr;
    cin>>pr;
    if(front[pr]==0&&rear[pr]==9||front[pr]==rear[pr]+1)
    {
        cout<<"Overflow"<<endl;
        return;
    }
    cout<<"Enter element: ";
    string ele;
    cin>>ele;
    if(front[pr]==-1&&rear[pr]==-1)
    {
        ++front[pr];
        ++rear[pr];
        arr[pr][rear[pr]]=ele;
    }
    else
    {
        if(rear[pr]==9)
            rear[pr]=0;
        else
            ++rear[pr];
        arr[pr][rear[pr]]=ele;
    }
}
void priority_queue_matrix::deq_whole_or_single(int pr)
{
    if(front[pr]==rear[pr])
        {
            front[pr]=-1;
            rear[pr]=-1;
        }
        else
        {
            if(front[pr]==9)
                front[pr]=0;
            else
                ++front[pr];
        }
}
void priority_queue_matrix::deq()
{
    cout<<"Enter priority of queue you  want to dequeue: ";
    int pr;
    cin>>pr;
    if(front[pr]==-1&&rear[pr]==-1)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    cout<<"Enter 1 if you want to deque the whole queue,0 to deque single element: ";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        while(front[pr]!=-1||rear[pr]!=-1)
            deq_whole_or_single(pr);
    }
    else if(ch==0)
        deq_whole_or_single(pr);
}
void priority_queue_matrix::display()
{
    cout<<"Enter priority of queue you want to display: ";
    int pr;
    cin>>pr;
    if(front[pr]==-1&&rear[pr]==-1)
        cout<<"Empty queue"<<endl;
    else
        cout<<arr[pr][front[pr]]<<endl;
}
int main()
{
    priority_queue_matrix obj;
    int ch;
    do
    {
        cout<<"Enter 1 to enq,2 to deq,3to display,0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.enq();
            break;
        case 2:
            obj.deq();
            break;
        case 3:
            obj.display();
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"try again"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
