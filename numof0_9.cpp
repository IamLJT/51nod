/*
题目：数字0-9的数量
要求：给出一段区间a-b，统计这个区间内0-9出现的次数。
比如 10-19，1出现11次（10,11,12,13,14,15,16,17,18,19,其中11包括2个1)，其余
数字各出现1次。
*/

#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

vector<ll> numof0_9lessthanN(ll n)
{
	vector<ll> num(10, (ll)0);
	int len=1,num0(n);
	while(num0/=10)
		len++;
	int i;
	while(len--)
	{
		for(i=0; i<n/(int)(pow(10,len)); i++)
		{
			if(i!=0||len==0)
				num[i]+=pow(10,len);
			for(int j=0;j<10;j++)
				num[j]+=len*pow(10,len-1);
		}
		n%=(int)pow(10,len);
		num[i]+=n+1;
	}
	return num;
}

int main()
{
	ll a,b;
	cin >> a >> b;
	vector<ll> num1=numof0_9lessthanN(a);
	vector<ll> num2=numof0_9lessthanN(b);
	while(a)
	{
		num2[a%10]++;
		a/=10;
	}
	for(int i=0; i<10; i++)
		printf("%d\n",num2[i]-num1[i]);
	system("pause");
	return 0;
}
