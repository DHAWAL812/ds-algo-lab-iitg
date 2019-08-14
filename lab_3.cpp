#include <bits/stdc++.h>
using namespace std;
bool check(string s,stack <char>& dha)
{
	bool vec=true;
	char x;
	for(long int a=0;a<s.length();++a)
	{
		if(s[a]=='{'||s[a]=='['||s[a]=='('||s[a]=='<')
		{
			dha.push(s[a]);
			continue;
		}
		if(s[a]=='|')
		{
			if(dha.empty())
			{
				dha.push(s[a]);
				continue;
			}
			else
			{
				x=dha.top();
				if(x==s[a])
				{
					dha.pop();
				}
				else
				{
					dha.push(s[a]);
				}
			}
			continue;
		}
		if(dha.empty())
		{
			vec=false;
			break;
		}
		if(s[a]==')')
		{
			x=dha.top();
			if(x=='(')
			{
				dha.pop();
				continue;
			}
			else
			{
				vec=false;
				break;
			}
		}
		else if(s[a]=='>')
		{
			x=dha.top();
			if(x=='<')
			{
				dha.pop();
				continue;
			}
			else
			{
				vec=false;
				break;
			}
		}
		else if(s[a]=='}')
		{
			x=dha.top();
			if(x=='{')
			{
				dha.pop();
				continue;
			}
			else
			{
				vec=false;
				break;
			}
		}
		else if(s[a]==']')
		{
			x=dha.top();
			if(x=='[')
			{
				dha.pop();
				continue;
			}
			else
			{
				vec=false;
				break;
			}
		}
	}
	return vec;
}
int main()
{
	long int t;
	cin>>t;
	for(long int a=0;a<t;++a)
	{
		stack <char> dha;
		string s;
		cin>>s;
		if(check(s,dha)==true&&dha.empty()==true)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}