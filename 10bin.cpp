/*
��Ŀ��Ȩ�ƶ�����
Ҫ��һ��ʮ��������������Ȩ�ƶ����ƣ�������ʮ���Ʊ�ʾ��ʱ��ֻ��0��1��ɡ�
����0��1��101��110011����Ȩ�ƶ����ƶ�2��12��900���ǡ�
������һ��n��ʱ�򣬼���һ������Ҫ���ٸ�Ȩ�ƶ�������Ӳ��ܵõ�n��

˼·��ֱ���޷���⣬���Կ�������1��1000000�е�Ȩ�ƶ����Ƶĸ��������Ǻܶ࣬
�Ƚ����е�Ȩ�ƶ��������ҳ�����������Щ��ȥ��ʾn���ɡ�(һ����1+32+16+8+4+2+1=64��)
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