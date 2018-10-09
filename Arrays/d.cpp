#include <iostream>
#include <cstring>
using namespace std;
void fun(char arr[])
{
int i;
int n = sizeof(arr)/sizeof(arr[0]);
cout<<sizeof(arr);
for (i=0; i<n; i++)
	cout<<arr[i];
}

// Driver program
int main()
{
char arr[] = {'g','e','e','k','s','q','u','i','z'};

cout<<*arr;
fun(arr);
return 0;
}
