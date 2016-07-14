/*
题目：中国剩余定理
要求：一个正整数K，给出K Mod 一些质数的结果，求符合条件的最小的K。
例如，K % 2 = 1, K % 3 = 2, K % 5 = 3。符合条件的最小的K = 23。
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll n1,ll  n2)
{
	if(n2==0)
		return n1;
	return gcd(n2, n1%n2);
}

ll cd(ll n1, ll n2)
{
	ll e=gcd(n1, n2);
	return e*(n1/e)*(n2/e);
}

int main()
{
	int N;
	cin >> N;
	vector<pair<ll,ll>> nums(N, make_pair(0, 0));
	for(int i=0; i<N; i++)
	{
		cin >> nums[i].first >> nums[i].second;
	}
	while(nums.size()>1)
	{
		ll n11=nums.back().first;
		ll n12=nums.back().second;
		nums.pop_back();
		ll n21=nums.back().first;
		ll n22=nums.back().second;
		nums.pop_back();
		ll temp1, temp2;
		if(n12<n22)
		{
			temp1=n21;
			temp2=n22;
			n21=n11;
			n22=n12;
			n11=temp1;
			n12=temp2;
		}
		ll e1 = n12-n22%n11;
		ll e2 = n21%n11;
		int n=0;
		while((e2*(n++))%n11!=e1);
		ll e3=n11*n12;
		nums.push_back(make_pair(e3,((n-1)*n21+n22)%e3));
	}
	cout << nums.back().second << endl;
	system("pause");
	return 0;
}