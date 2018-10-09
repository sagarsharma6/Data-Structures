//sorting two sorted arrays into a new array
#include<iostream>
using namespace std;
void sort(int *arr1,int *arr2,int *arr3,int n1,int n2,int n3)
{
    int i=0,j=0;
    for(int k=0;k<n3;++k)
    {
        if(arr1[i]<arr2[j]&&i!=n1||j==n2)
        {
            arr3[k]=arr1[i];
            ++i;
        }
        else if(j!=n2)
        {
            arr3[k]=arr2[j];
            ++j;
        }
    }

}
int main()
{
    int arr1[]={1,6,7,33,66,99};            //sorted array1
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={0,22,25,34,67,100};         //sorted array2
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int n3=n1+n2;
    int arr3[n3];
    sort(arr1,arr2,arr3,n1,n2,n3);
    for(int i=0;i<n3;++i)
        cout<<arr3[i]<<" ";
    return 0;
}
