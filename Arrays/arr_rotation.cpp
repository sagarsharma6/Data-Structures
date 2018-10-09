#include<iostream>
using namespace std;
/*void rot(int arr[],int d,int n)
{
    for(int i=0;i<d;++i)
    {
        int temp=arr[0];
        int j;
        for(j=0;j<n-1;++j)
            arr[j]=arr[j+1];
        arr[j]=temp;
    }
}*/
/*int get_gcd(int a,int b)
{
    return (b==0?a:get_gcd(b,a%b));
}
void rot_gcd(int *arr,int d,int n)
{
    for(int i=0;i<get_gcd(d,n);++i)
    {
        if(d>n)
            d%=n;
        //move i-th values of blocks
        int temp = arr[i];
        int j = i;
        while(1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}*/
/*void reverse_arr(int *arr,int start,int end)
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
void rot_reverse(int *arr,int d,int n)
{
    reverse_arr(arr,0,d-1);
    reverse_arr(arr,d,n-1);
    reverse_arr(arr,0,n-1);
}*/
/*void swap_block(int *arr,int fi,int si,int d)
{
    for(int i=0;i<d;++i)
    {
        int temp=arr[fi+i];
        arr[fi+i]=arr[si+i];
        arr[si+i]=temp;
    }
}
void rot_block_swap(int *arr,int d,int n)
{
    if(d==0||d==n)
        return;
    if(d==n-d)
    {
        swap_block(arr,0,n-d,d);
        return;
    }
    if(d<n-d)
    {
        swap_block(arr,0,n-d,d);
        rot_block_swap(arr,d,n-d);
    }
    else
    {
        swap_block(arr,0,d,n-d);
        rot_block_swap(arr+n-d,2*d-n,d);
    }
}*/
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"by how much you want to rotate: ";
    int d;
    cin>>d;
    //rot(arr,d,n);                                      //time complexity=O(n*d),space complexity=O(1)
    //rot_gcd(arr,d,n);                                  //time complexity=O(n), space complexity=O(1)  //JUGGLING ALGoRITHM
    //rot_reverse(arr,d,n);                              //time complexity=O(n), space complexity=O(1)  //REVERSAL ALGORITHM
    //rot_block_swap(arr,d,n);                           //time complexity=O(n), space complexity=O(1)  //BLOCK SWAP ALGORITHM
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
    return 0;
}
