#include "addbignum.h"

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

string longposnumadd(string str1, string str2)
{
	string res="";
	if(str1.size()==0||str2.size()==0) return str1+str2;
	int len=max0(str1.size(), str2.size());
	for(int i=str1.size(); i<len; i++)
		str1='0'+str1;
	for(int i=str2.size(); i<len; i++)
		str2='0'+str2;
	int e=0, sum=0;
	for(int i=len-1; i>=0; i--)
	{
		sum=((str1[i]-'0')+(str2[i]-'0')+e)%10;
		e=((str1[i]-'0')+(str2[i]-'0')+e)/10;
		res=(char)(sum+'0')+res;
	}
	if(e>0)
		res=(char)(e+'0')+res;
	return res;
}

string longposnumdiv(string str1, string str2)
{
	string res="";
	int len=max0(str1.size(), str2.size());
	for(int i=str1.size(); i<len; i++)
		str1='0'+str1;
	for(int i=str2.size(); i<len; i++)
		str2='0'+str2;
	int e=0, sum=0;
	for(int i=len-1; i>=0; i--)
	{
		sum=((str1[i]-'0')-(str2[i]-'0')-e);
		if(sum<0)
		{
			e=1;
			sum+=10*e;
			while(sum<0)
			{
				e++;
				sum+=10;
			}
		}
		else
			e=0;
		res=(char)(sum+'0')+res;
	}
	if(e>0)
	{
		res="";
		e=0;
		res=longposnumdiv(str2, str1);
		res='-'+res;
	}
	return res;
}

string bignum(string str1, string str2)
{
	int A0=1, B0=1;
	string res="";
	if(str1.size()&&str1[0]=='-')
	{
		str1=str1.substr(1);
		A0=-1;
	}
	if(str2.size()&&str2[0]=='-')
	{
		str2=str2.substr(1);
		B0=-1;
	}
	if(A0*B0==-1)
	{
		res=longposnumdiv(str1, str2);
	}
	else
	{
		res=longposnumadd(str1, str2);
	}
	if(res.size()==0) return "";
	if(res[0]=='-')
	{
		if(A0==-1)
			res=res.substr(1);
	}
	else
	{
		if(A0==-1)
			res='-'+res;
	}
	if(res[0]=='-')
	{
		while(res[1]=='0'&&res.size()>2)
			res=res.substr(0,1)+res.substr(2);
		if(res[0]=='0') res=res.substr(1);
	}
	else
	{
		while(res[0]=='0'&&res.size()>1)
			res=res.substr(1);
	}
	return res;
}