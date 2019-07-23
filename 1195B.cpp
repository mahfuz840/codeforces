#include<stdio.h>
#include<iostream>

using namespace std;


int main()
{
	int n, k;
	long int total;
	int i;

	cin >> n >> k;
	total = n*(n+1)/2;
	i = n;

	while(total != k)
	{
		total -= (i+1);
		i--;
	}

	cout << (n-i) << endl;

	return 0;
}