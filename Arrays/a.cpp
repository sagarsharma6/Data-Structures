//seperating positive and negative numbers with maintaing order of numbers
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={-88,1,2,-5,-6,3,4,-7,-8,5,6,7,8,-1,9,10,11};
    for(int i=0;i<17;++i)
    {
        if(a[i]>0)
        for(int j=i-1;j>=0&&a[j]<0;--j)
        {
            swap(a[j+1],a[j]);
        }
    }
    for(int i=0;i<17;++i)
        cout<<a[i]<<" ";
    return 0;
}
