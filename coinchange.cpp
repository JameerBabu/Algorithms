#include<bits/stdc++.h>
using namespace std;
int dp[200000];
int dp1[200000];
typedef long long int ll;
ll minCoins(int coins[], int m, int V)
{
	if(dp[V]!=-1)
	return dp[V];
   // base case
   if (V == 0) return 0;
 
   // Initialize result
   ll res = INT_MAX;
 
   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         res = min(res,1+minCoins(coins, m, V-coins[i]));
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
     }
   }
   return dp[V]=res;
}

ll maxCoins(int coins[], int m, int V)
{
	if(dp1[V]!=-1)
	return dp1[V];
   // base case
   if (V == 0) return 0;
 
   // Initialize result
   ll res = INT_MIN;
 
   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
          res = max(res,1+maxCoins(coins, m, V-coins[i]));
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         
     }
   }
   return dp1[V]=res;
}
 
// Driver program to test above function
int main()
{
	ll v,n;
	cin >> v >> n ;
    int coins[n];
    memset(dp,-1,sizeof(dp));
    memset(dp1,-1,sizeof(dp1));
    for(int i=0;i<n;i++)
    {
    	cin >> coins[i];
	}
	ll minans=0,maxans=0;
     ll m = sizeof(coins)/sizeof(coins[0]);
    maxans=maxCoins(coins, m, v);
    minans=minCoins(coins, m, v);
    if(minans==INT_MAX || maxans==INT_MIN)
    {
    	cout << "-1 -1" << endl;
	}
	else
	{
		 cout << minans << " " << maxans << endl;
	}
	
	
    
   
    return 0;
}

