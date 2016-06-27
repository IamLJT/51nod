/*
��Ŀ��ѭ����������Ӷκ�

˼·������Ӷ�ֻ�����������һ�־���ֱ�����͵��Ӵ���һ�־�������֮����
���ͣ���ô�м�Ĳ���һ������С���Ӵ���
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

ll MaxSumCircle(vector<ll>& nums)
{
	ll res=0, sum=0, sum1=0, sum2=0, res1=0, res2=0;
	for(int i=0; i<nums.size(); i++)
	{
		sum+=nums[i];
		// Max Sum
		sum1=max(sum1+nums[i], (ll)0);
		res1=max(sum1, res1);
		// Min Sum
		sum2=min(sum2+nums[i], (ll)0);
		res2=min(sum2, res2);
	}
	res=max(res1, sum-res2);
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<ll> nums(N, (ll)0);
	for(int i=0; i<N; i++)
		cin >> nums[i];
	cout << MaxSumCircle(nums) << endl;
	system("pause");
	return 0;
}