#include<iostream>
using namespace std;
class array_operation
{
    int m_arr[100];
    int m_size;
    public:
        void input();
        void output();
        void insertion();
        void deletion();
        void searching();
        void sort();
};
void array_operation::input()
{
    cout<<"Enter size of array: ";
    cin>>m_size;
    for(int i=0;i<m_size;i++)
    {
        cin>>m_arr[i];
    }
}
void array_operation::output()
{
    for(int i=0;i<m_size;i++)
    {
        cout<<m_arr[i]<<" ";
    }
    cout<<endl;
}
void array_operation::insertion()
{
    cout<<"Enter position: ";
    int pos;
    cin>>pos;
    for(int i=m_size-1;i>=pos;--i)
    {
        m_arr[i+1]=m_arr[i];
    }
    cout<<"Enter value to be inserted: ";
    int value;
    cin>>value;
    m_arr[pos]=value;
    m_size++;
}
void array_operation::deletion()
{
    cout<<"Enter position to be deleted: ";
    int pos;
    cin>>pos;
    for(int i=pos+1;i<m_size;i++)
    {
        m_arr[i-1]=m_arr[i];
    }
    m_size--;
}
void array_operation::searching()
{
    cout<<"Enter element to be searched: ";
    int ele;
    cin>>ele;
    cout<<"Enter 1 for Linear search,2 for binary search: ";
    int search;
    cin>>search;
    switch(search)
    {
        case 1:
        {
            int flag=0;
            for(int i=0;i<m_size;i++)
            {
                if(m_arr[i]==ele)
                {
                    flag=1;
                    cout<<"Element "<<ele<<" found"<<endl;
                    break;
                }
            }
            if(flag==0)
                cout<<"Element "<<ele<<" not found"<<endl;
            break;
        }
        case 2:
        {
            int flag2=0;
            int beg=0;
            int end=m_size-1;
            while(beg<=end)
            {
                int mid=(beg+end)/2;
                if(ele==m_arr[mid])
                {
                    flag2=1;
                    cout<<"Element "<<ele<<" found "<<endl;
                    break;
                }
                else if(ele<m_arr[mid])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            if(flag2==0)
                cout<<"Element "<<ele<<" not found"<<endl;
            break;
        }
        default:
            cout<<"Invalid input";
    }
}
void array_operation::sort()
{
    for(int i=0;i<m_size-1;i++)
    {
        int flag=0;
        for(int j=0;j<m_size-i-1;j++)
        {
            if(m_arr[j]>m_arr[j+1])
            {
                flag=1;
                int temp;
                temp=m_arr[j];
                m_arr[j]=m_arr[j+1];
                m_arr[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
}
int main()
{
    array_operation obj;
    int flag=0;
    int option;
    do
    {
        cout<<"Menu:\nEnter:\n1 for input\n2 for output\n3 for insertion\n4 for deletion\n5 for searching\n6 for sorting\n0 to exit: ";
        cin>>option;
        switch(option)
        {
            case 1:
                flag=1;
                obj.input();
                break;
            case 2:
                if(flag==1)
                    obj.output();
                else
                    cout<<"Please input array first"<<endl;
                break;
            case 3:
                if(flag==1)
                    obj.insertion();
                else
                    cout<<"Please input array first"<<endl;
                break;
            case 4:
                if(flag==1)
                    obj.deletion();
                else
                    cout<<"Please input array first"<<endl;
                break;
            case 5:
                if(flag==1)
                    obj.searching();
                else
                    cout<<"Please input array first"<<endl;
                break;
            case 6:
                obj.sort();
                break;
            case 0:
                option=0;
                break;
            default:
                cout<<"Invalid input, try again"<<endl;
        }
    }
    while(option!=0);
    return 0;
}
