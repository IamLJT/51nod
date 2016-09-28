/*
题目：骨牌覆盖
要求：在2*N的一个长方形方格中，用一个1*2的骨牌排满方格。
问有多少种不同的排列方法。
*/

//	质数化简求C(n+m,m)
#include <iostream>
#include <vector>
using namespace std;
#define Mod 1000000007
typedef long long ll;
vector<int> prime;
//	计算n以内所有的质数
vector<int> primelessthanN(int n)
{
	vector<bool> isprime(n+1, true);
	vector<int> prime;
	prime.push_back(2);
	int i;
	for(i=3; i*i<=n; i+=2)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				isprime[j]=false;
		}
	}
	while(i<=n)
	{
		if(isprime[i])
			prime.push_back(i);
		i+=2;
	}
	return prime;
}
//	计算素数因子p的指数
int Cal(int n, int p)
{
	int res=0;
	ll rec=p;
	while((ll)n>=rec)
	{
		res+=(int)((ll)n/rec);
		rec*=(ll)p;
	}
	return res;
}
//	计算n^k对Mod取余
ll PowerMod(int n, int k)
{
	int t(k),n0(n);
	ll res=(ll)1;
	while(t)
	{
		if(t&1)
			res=(res*(ll)n0)%Mod;
		n0=(n0*n0)%Mod;
		t>>=1;
	}
	return res;
}
//	计算C(n,m)，即原式的C(n+m,m)
ll Cnm(int n, int m)
{
	ll res=1;
	for(int i=0; i<prime.size(); i++)
	{
		res=(res*(PowerMod(prime[i],Cal(n,prime[i])-Cal(n-m,prime[i])
			-Cal(m,prime[i]))))%Mod;
	}
	return res;
}

int main()
{
    int n, res=0;
    scanf("%d",&n);
    prime=primelessthanN(n);
    for(int i=0; i<=n/2; i++)
        res=(Cnm(n-i,i)+res)%Mod;
    cout << res << endl;
    system("pause");
    return 0;
}