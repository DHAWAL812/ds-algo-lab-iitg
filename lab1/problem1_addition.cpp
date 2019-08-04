#include <bits/stdc++.h>
using namespace std;
void add(string s1,string s2,vector <int>&dha)
{
	long long int n1=s1.length();
	long long int n2=s2.length();
	long long int carry =0;
	if(n1>n2)
	{
		while(n2!=0)
		{
			long long int x=s1.at(n1-1)-'0'+s2.at(n2-1)-'0'+carry;
			dha.push_back(x%10);
			carry=x/10;
			n1--;
			n2--;
		}
		while(n1!=0)
		{
			long long int x=carry+s1.at(n1-1)-'0';
			carry=x/10;
			dha.push_back(x%10);
			n1--;
		}
		while(carry)
		{
			dha.push_back(carry%10);
			carry/=10;
		}
	}
	else
	{
		while(n1!=0)
		{
			long long int x=s1.at(n1-1)-'0'+s2.at(n2-1)-'0'+carry;
			dha.push_back(x%10);
			carry=x/10;
			n1--;
			n2--;
		}
		while(n2!=0)
		{
			long long int x=carry+s2.at(n2-1)-'0';
			carry=x/10;
			dha.push_back(x%10);
			n2--;
		}
		while(carry)
		{
			dha.push_back(carry%10);
			carry/=10;
		}
	}
}
int main()
{
	long long int t;
	cin>>t;
	for(long long int a=0;a<t;++a)
	{
	string s1,s2;
	cin>>s1>>s2;
	vector <int>dha;
	add(s1,s2,dha);
	long long int n=dha.size()-1;
	while(n>=0)
	{
		cout<<dha[n];
		n--;
	}
	cout<<"\n";
	}
}