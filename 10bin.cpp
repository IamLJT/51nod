/*
题目：权势二进制
要求：一个十进制整数被叫做权势二进制，当他的十进制表示的时候只由0或1组成。
例如0，1，101，110011都是权势二进制而2，12，900不是。
当给定一个n的时候，计算一下最少要多少个权势二进制相加才能得到n。

思路：直接无法求解，可以看到，从1到1000000中的权势二进制的个数并不是很多，
先将所有的权势二进制数找出来，再用这些数去表示n即可。(一共是1+32+16+8+4+2+1=64种)
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//vector<int> Init()
//{
//	vector<int> res;
//	int a=0,b=0;
//	res.push_back(1);
//	for(int i=0; i<5; i++)
//	{
//		for(int j=a; j<=b; j++)
//		{
//			res.push_back(res[j]*10);
//			res.push_back(res[j]*10+1);
//		}
//		a=b+1;
//		b=res.size()-1;
//	}
//	res.push_back(1000000);
//	return res;
//}
//
//int maxnum(vector<int>& num, int s, int e, int sum)
//{
//	if(s>e) return sum;
//	while(s<=e&&num[s]==0)
//		s++;
//	if(s>e) return sum;
//	int min=num[s];
//
//	for(int i=s; i<=e; i++)
//		if(num[i]<min)
//			min=num[i];
//
//	int n=num[s], res=1;
//	sum+=n;
//	num[s]-=n;
//
//	for(int i=s+1; i<=e; i++)
//	{
//		if(num[i]>=n)
//		{
//			res=res*10+1;
//			num[i]-=n;
//		}
//		else
//		{
//			res*=10;
//		}
//	}
//
//	return maxnum(num, s+1, e, sum);
//}

int main()
{
	//vector<int> res=Init();
	int N, res=0;
	cin >> N;
	while(N)
	{
		res=max(res, N%10);
		N/=10;
	}
	//int t(N),len=1;
	//vector<int> nums;
	//nums.push_back(t%10);
	//while(t/=10)
	//	nums.push_back(t%10);
	//reverse(nums.begin(), nums.end());
	//cout << maxnum(nums, 0, nums.size()-1, 0) << endl;
	cout << res << endl;
	system("pause");
	return 0;
}