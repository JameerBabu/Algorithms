#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MaxN = 500500;
void insert(string s,bool created[],ll end[],ll next[][MaxN],ll sz)
{
	int v = 0;
    
	for (int i = 0; i < s.size(); ++i) {
		int c = s[i] - 'a';
		if (!created[next[c][v]]) {
			next[c][v] = ++sz;
			created[sz] = true;
		}
		v = next[c][v];
	}
	++end[v];
}

bool search (string tmp,bool created[],ll end[],ll next[][MaxN]) 
{
	int v = 0;
	
	for (int i = 0; i < tmp.size(); ++i) {
		int c = tmp[i] - 'a';
		if (!created[next[c][v]])
			return false;
		v = next[c][v];
	}
	return end[v] > 0;
}
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		
		ll sz = 0;
		
		ll next[27][MaxN];
		ll end[MaxN];
		bool created[MaxN];
		
		ll n,q;
		cin >> n >> q;
		vector<string>str;
		
		for(ll i=0;i<n;i++)
		{
			string s;
			cin >> s;
			insert(s,created,end,next,sz);
			sz=sz+s.size();
		}
		
		
		// cout << sz << endl;
		
		
		for(ll i=0;i<q;i++)
		{
			string s;
			cin >> s;
			
			if(search(s,created,end,next))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
	
	return 0;
}
