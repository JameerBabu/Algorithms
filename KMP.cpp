
// rotate(s.begin() + l, s.begin() + k, s.begin() + r); - rotate string[l-- r] .. k times.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void LPS(string s, ll lps[]);

ll KMP(string pat,string txt)
{
	ll m = pat.size();
	ll n = txt.size();
	
	ll c=0;
	ll lps[m];
	LPS(pat,lps);
	
	ll i=0;
	ll j=0;
	
	while(i<n)
	{
		if(txt[i]==pat[j])
		{
			j++;
			i++;
		}
		
		if(j==m)
		{
			c++;
			j=lps[j-1];
		}
		
		else if(i<n && pat[j]!=txt[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	
	return c;
	
}


void LPS(string pat, ll lps[] )
{
	ll len = 0;
	ll m = pat.size();
	lps[0]=0;
	ll i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	
}

int main()
{
	string text,pattern;
	cin >> text >> pattern;
	ll ans = KMP(pattern,text);
	cout << ans  << endl;
	return 0;
}
