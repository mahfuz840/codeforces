#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

	vector<int> v[30];
	int p[30];
	string s;
	int n, m;

	cin >> n >> s;

	for(int i = 0; i < n ; i++)
		v[s[i] - 'a'].push_back(i);

	cin >> m;
	while(m--)
	{
	    memset(p, 0, sizeof(p));
		cin >> s;
		int ans = -1;
		for(int i = 0; i < s.size(); i++)
		{

			ans = max(ans, v[s[i] - 'a'][p[s[i] - 'a']++]);
		}

		printf("%d\n", ans + 1);
	}


	return 0;
}
