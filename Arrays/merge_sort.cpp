#include<iostream>
using namespace std;
class merge_sort
{
    int arr[50];
public:
    void get(int);
    void sort_(int,int);
    void merging(int,int,int);
    void display(int);
};
void merge_sort::get(int n)
{
    for(int i=0;i<n;++i)
        cin>>arr[i];
}
void merge_sort::sort_(int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        sort_(p,q);
        sort_(q+1,r);
        merging(p,q,r);
    }
}
void merge_sort::merging(int p,int q,int r)
{
    int n1=q+1-p;
    int *left=new int[n1];
    int u=0;
    for(int i=p;i<=q;++i)
    {
        left[u]=arr[i];
        ++u;
    }
    int n2=r-q;
    int *right=new int[n2];
    int v=0;
    for(int i=q+1;i<=r;++i)
    {
        right[v]=arr[i];
        ++v;
    }
    int i=0,j=0;
    for(int k=0;k<n1+n2;++k)
    {
        if(left[i]<right[j]&&i!=n1||j==n2)
        {
            arr[p]=left[i];
            ++i;
        }
        else if(j!=n2)
        {
            arr[p]=right[j];
            ++j;
        }
        ++p;
    }
}
void merge_sort::display(int n)
{
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    merge_sort obj;
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
