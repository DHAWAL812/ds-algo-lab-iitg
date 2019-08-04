#include<bits/stdc++.h> 
using namespace std; 

void multiply(string num1, string num2) 
{ 
	int len1 = num1.size(); 
	int len2 = num2.size(); 
	vector<int> result(len1 + len2, 0); 

	int i_n1 = 0; 
	int i_n2 = 0; 
	
	for (int i=len1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = num1[i] - '0'; 

		i_n2 = 0; 
		
		for (int j=len2-1; j>=0; j--) 
		{ 
			int n2 = num2[j] - '0'; 

			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

			carry = sum/10; 
			result[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 

		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 
		i_n1++; 
	} 
	int i = result.size() - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 
    int c=0;
	if (i == -1) 
	{cout<<0<<"\n";
      c=1;}
	
	while (i >= 0) 
	{	cout<<(result[i--]);} 
	   if(c==0){cout<<"\n";}
} 

int main() 
{ 
	long int t;
	cin>>t;
	for(long int a=0;a<t;++a)
	{
	string str1,str2;
	cin>>str1>>str2;
	
	multiply(str1, str2); 
	}
} 
