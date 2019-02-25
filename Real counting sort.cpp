#include<iostream>
using namespace std;

void display(int n, int *output)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<output[i]<<" ";
}


void count_s(int n,int *arr, int max)
{
	max=max+1;
	int f[max];

	int output[n];
	for(int i=0;i<n;i++)
	output[i]=0;

	for(int i=0;i<max;i++)
	f[i]=0;

	for(int i=0;i<n;i++)
	f[arr[i]]++;

	for(int i=1;i<max;i++)			//progressive sum of frequencies, gives the ending index of a particular element
	f[i]=f[i]+f[i-1];



	for(int i=0;i<max;i++)
	cout<<f[i]<<" ";

cout<<endl;
	
	int ele=arr[n-1];

	for(int i=n-1;i>=0;i--)     //backwards parsing becuase cumulative sum, we know the ending indices.
	{
		ele=arr[i];			//backwards selscting of element 
		output[f[ele]-1]=ele;		//Index problem solved, the index was exceeding the size of the array
		f[ele]--;			//Updating the index using frequency array
	}

	display(n,output);



}
		

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	

	
	
	int max=arr[0];
	for(int i=1;i<n;i++)
	if(max<arr[i])
	max=arr[i];

	cout<<max<<endl;

	max=max+1;
	count_s(n,arr,max);

return 0;

}
