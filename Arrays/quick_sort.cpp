#include<iostream>
using namespace std;
class quick_sort
{
    int arr[50];
public:
    void get(int);
    void sort_(int,int);
    int partition_algo(int,int);
    void display(int);
};
void quick_sort::get(int n)
{
    for(int i=0;i<n;++i)
        cin>>arr[i];
}
int quick_sort::partition_algo(int p,int r)
{
   int pivot=arr[r];
   int j=p-1;
   for(int i=p;i<r;++i)
   {
       if(arr[i]<=pivot)
       {
           ++j;
           int temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
       }
   }
   int temp=arr[j+1];
   arr[j+1]=arr[r];
   arr[r]=temp;
   return j+1;
}
void quick_sort::sort_(int p,int r)
{
    if(p<r)
    {
        int q=partition_algo(p,r);
        sort_(p,q-1);
        sort_(q+1,r);
    }
}

void quick_sort::display(int n)
{
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    quick_sort obj;
    int n;
    int ch;
    do
    {
        cout<<"Enter 1 to input array,2 to sort,3 to display,0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter size of array: ";
            cin>>n;
            obj.get(n);
            break;
        case 2:
            obj.sort_(0,n-1);
            cout<<"Array sorted"<<endl;
            break;
        case 3:
            obj.display(n);
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

