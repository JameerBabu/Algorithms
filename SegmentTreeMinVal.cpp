#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MAXN = 1000000007;
ll MAXIND = 1000007;
ll tree[1000007];
ll A[100007];


void initialize(ll node, ll b, ll e, ll M[1000007], ll A[1000007], ll N)
  {
      if (b == e)
          M[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          initialize(2 * node, b, (b + e) / 2, M, A, N);
          initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
  //search for the minimum value in the first and 
  //second half of the interval
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1]; 
      }
  } 

void update(ll node, ll b, ll e, ll M[1000007], ll A[1000007], ll N, ll pos, ll val)
{
	if(b==e)
	{
	
		
		A[pos]=val;
	}
	
	else
	{
		ll m = (b+e)/2;
		
		update(2*node,b,m,M,A,N,pos,val);
		update(2*node + 1,m+1,e,M,A,N,pos,val);
	
	}
}


ll query(ll node, ll b, ll e, ll M[1000007], ll A[1000007], ll i, ll j)
  {
      int p1, p2;
   
  //if the current interval doesn't intersect 
  //the query interval return -1
      if (i > e || j < b)
          return -1;
   
  //if the current interval is included in 
  //the query interval return M[node]
      if (b >= i && e <= j)
          return M[node];
   
  //compute the minimum position in the 
  //left and right part of the interval
      p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
      p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
   
  //return the position where the overall 
  //minimum is
      if (p1 == -1)
          return M[node] = p2;
      if (p2 == -1)
          return M[node] = p1;
      if (A[p1] <= A[p2])
          return M[node] = p1;
      return M[node] = p2;
  }
int main()
{
	ll n,q;
	cin >> n >> q;
	
	for(ll i=1;i<=n;i++)
	{
		cin >> A[i];
	}
	
	initialize(1,0,n-1,tree,A,n);
	ll a,l,r;
	for(ll i=0;i<q;i++)
	{
		cin >> a >> l >> r;
		if(a==1)
		{
			update(1,0,n-1,tree,A,n,l,r);
		}
		else if(a==2)
		{
			int ans = query(1,0,n-1,tree,A,l,r);
			cout << A[ans]<< endl;
		}
	}
	return 0;
}
