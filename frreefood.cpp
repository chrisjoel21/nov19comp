#include<iostream>

using namespace std;

int main()
{
	int n,i,j,count=0;
	cin>>n;
	int a[n], b[n], days[366]={0};
	for(i=0; i<n; i++)
	{
		cin>>a[i]>>b[i];
	}
	
	for(i=0; i<n; i++)
	{
		for(j=a[i]; j<=b[i]; j++)
		{
			if(days[j] == 0)
			{
				days[j] = 1;
				count++;
			}
		}
	}
	
	cout<<count;
}