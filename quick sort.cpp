#include<iostream>
using namespace std;


void quick_s(int start,int end, int *arr,int n)
{

if(start<end)
{
	int pivot=arr[end];         //making the pivot element the last one
	int t;

	 
	int i=start-1;
	int j=start;                //initialising with a previous value

	for(int j=start;j<end;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			t=arr[j];
			arr[j]=arr[i];
			arr[i]=t;
		}
	}


t=arr[i+1];                 //replace without updating i++
arr[i+1]=arr[end];
arr[end]=t;
quick_s(start,i,arr,n);     //where segmentation fault occurs
quick_s(i+2,end,arr,n);     //i+1 is the pivot element, at its right position
}

}
			
			
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	int s=0;
	int e=n-1;

	quick_s(s,e,arr,n);

for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<endl;

return 0;
}
