#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
lli userval[1000001];
int main() 
{ 
  //fastio;
  int n;cin>>n;
  int maxid=0;
  int t;
  long long int q;
  cin>>q;
  while(q--)
  {
    cin>>t;
    if(t==1)
    {
      lli u,a;cin>>u>>a;
      userval[u]+=a;
      if(userval[u]>userval[maxid])
         maxid=u;
    }
    else
    {
      if(userval[maxid]==0)
      cout<<"NO DATA AVAILABLE\n";
      else
      cout<<maxid<<"\n";
    }
  }
  return 0; 	
}
