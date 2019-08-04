#include<bits/stdc++.h>
using namespace std;

string subtract(string str1, string str2)
{
    if(str2.size() > str1.size())
    {
        string s=str1;
        str1=str2;
        str2=s;
    }
    else if(str2 > str1 && str2.size() == str1.size())
    {
        string s=str1;
        str1=str2;
        str2=s;
    }
    if(str2.size()<str1.size())
    {
        for(int i=str2.size(); i<str1.size(); i++)
        {
            str2 = '0'+str2;
        }
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    string dha ="";
    int carry =0;
    for(int i=0; i<str1.size(); i++)
    {
        int a = str1[i]-'0';
        int b = str2[i]-'0'+carry;
        if(a<b){
            a+=10;
            dha.push_back(a-b+'0');
            carry =1;
        }
        else
        {
            dha.push_back(a-b+'0');
            carry=0;
        }
    }
    reverse(dha.begin(), dha.end());
    string ans="";
    bool gfr = false;
    for(int i=0; i<dha.size(); i++)
    {
        if(dha[i] != '0')
        {
        	gfr = true;
        }
        if(!gfr)
        {
        	continue;
        }
        ans += dha[i];
    }
    return ans;
}
string add(string str1, string str2)
{
    int carry=0;
    string ans = "";
    if(str1.size() < str2.size())
    {
        string slo;
        slo=str1;
        str1=str2;
        str2=slo;
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    for(int i = 0; i< str2.size(); i++)
    {
        int sum = str1[i]-'0'+str2[i]-'0'+carry;
        ans+=sum%10+'0';
        carry=sum/10;
    }
    for(int i = str2.size(); i<str1.size(); i++)
    {
        int sum = str1[i]-'0'+carry;
        ans+=sum%10+'0';
        carry = sum/10;
    }
    if(carry)
    {
    	ans+= carry+'0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
bool check(string s1, string s2)
{
    if(s2.size() < s1.size())
    {
        return true;
    }
    else if(s2 <= s1 && s2.size() == s1.size())
    {
        return true;
    }
    return false;
}
string divide(string str1, string str2)
{
    if(str2.size() > str1.size())
    {
        string s=str1;
        str1=str2;
        str2=s;
    }
    else if(str2 > str1 && str2.size() == str1.size())
    {
        string s=str1;
        str1=str2;
        str2=s;
    }
    string rem="";
    string ans="";
    int j=0;
    while(1)
    {
        string divisor=str2;
        string dividend = rem;
        bool flag= false;
        if(j == 0)
        {
            for(int i=j; i<str1.size(); i++)
            {
            dividend += str1[i];
            if(check(dividend, divisor))
            {
                j = i+1;
                flag = true;
                break;
                }
            }
        }
        else
        {
        for(int i=j; i<str1.size(); i++)
        {
            dividend += str1[i];
            string str3="";
            for(int k =0 ; k<dividend.size(); k++)
            {
                if(dividend[k] == '0' && str3 == "")
                {
                    continue;
                }
                else
                {
                	str3+= dividend[k];
                }
            }
            dividend = str3;
            if(check(dividend, divisor))
            {
                j = i+1;
                flag = true;
                break;
            }
            ans += '0';
        }
        	
        }
        if(dividend == "")
        {
        	dividend = '0';
        }
        if(!flag && !check(dividend, divisor))
        {
            return dividend;
        }
        int rtj=0;
        while(check(dividend, divisor))
        {
            divisor = add(divisor, str2);
            rtj++;
        }
        divisor = subtract(divisor, str2);
        rem = subtract(dividend, divisor);
        if(rtj != 0)
        {
            ans += rtj+'0';
        }

    }
}
bool check2(string s1, string s2)
{
    if(s2.size() < s1.size())
    {
        return true;
    }
    else if(s2 < s1 && s2.size() == s1.size())
    {
        return true;
    }
    return false;
}
void prime(string s1)
{
    string cac = "2";
    if(s1 == "2")
    {
    	cout<<"Prime\n"; return;
    }
    if(s1 == "3")
    {
    	cout<<"Prime\n"; return;
    }
    while(check2(s1, cac))
    {
        if(divide(s1, cac) == "0")
        {
            cout<<"Not a Prime\n";
            return;
        }
        if(cac== "2")
        {
        cac = add(cac, "1");
        }
        else
        {
        	cac = add(cac, "2");
        }
    }
    cout<<"Prime\n";
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        prime(s);
    }
}