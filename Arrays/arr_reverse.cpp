#include<iostream>
using namespace std;
void reverse_arr(int *arr,int start,int end)
{
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        ++start;
        --end;
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    cout<<"Enter starting index: ";
    int start;
    cin>>start;
    cout<<"Enter ending index: ";
    int end;
    cin>>end;
    reverse_arr(arr,start,end);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
        cout<<arr[i]<<" ";
    return 0;
}
