#include <bits/stdc++.h>
using namespace std;
void primeFactors(int n)
{
	
       
}
 

int main()
{
    int n;
    cin >> n;
    
    
    map <int,int>m;
    
    int sum =0;
    
    while (n%2 == 0)
    {
        
        n = n/2;
        sum+=1;
    }
    m.insert(pair<int,int>(2,sum));
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    
    
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
		sum=0;
        
        while (n%i == 0)
        {
           
            n = n/i;
            sum+=1;
        }
        m.insert(pair<int,int>(i,sum));
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
    m.insert(pair<int,int>(n,1));
    
    map <int, int> :: iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        cout  <<  '\t' << itr->first <<  '\t' << itr->second << '\n';
              
    }
    cout << endl;
    
    
    return 0;
}
