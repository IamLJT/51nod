#include <iostream>
#include <string>
#include "addbignum.h"
using namespace std;

string addzero(string str, int n)
{
	if(str.size()==0) return "";
	while(n--)
		str+='0';
	return str;
}

string inttostr(int n)
{
	string res="";
	while(n!=0)
	{
		res=(char)(n%10+'0')+res;
		n/=10;
	}
	return res;
}

int strtoint(string str)
{
    int res=0;
    for(int i=0; i<str.size(); i++)
        res=res*10+(char)(str[i]-'0');
    return res;
}

string bignummulti(string str1, string str2)
{
	int len1=str1.size(), len2=str2.size();
	if(len1==0||len2==0)
	{
		return "";
	}
	if(len1<5&&len2<5)
	{
		int a=strtoint(str1);
		int b=strtoint(str2);
		int temp=a*b;
		return inttostr(temp);
	}
	string A=str1.substr(0, len1/2);
	string B=str1.substr(len1/2);
	string C=str2.substr(0, len2/2);
	string D=str2.substr(len2/2);
	string res1=addzero(bignummulti(A, C), len1-len1/2+len2-len2/2);
	string res2=addzero(bignummulti(A, D), len1-len1/2);
	string res3=addzero(bignummulti(B, C), len2-len2/2);
	string res4=bignummulti(B, D);
	return longposnumadd(longposnumadd(res1, res2), longposnumadd(res3, res4));
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	cout << bignummulti(str1, str2) << endl;
	system("pause");
	return 0;
}

