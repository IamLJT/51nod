/*
��Ŀ����Ϊk����������
Ҫ��һ��������a1, a2, ... , an�������и������Լ���һ������k����һ������[i, j]��
(1 <= i <= j <= n)��ʹ��a[i] + ... + a[j] = k��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, int> p1, pair<ll, int> p2)
{
	if(p1.first==p2.first)
		return p1.second<p2.second;
	return p1.first<p2.first;
}

pair<int,int> RangeofSumk(vector<pair<ll, int>> num, ll k)
{
	vector<pair<ll, int>> n(num);
	pair<int,int> res(make_pair(-1,-1));
	sort(n.begin(), n.end(), cmp);
	for(int i=1; i<(int)num.size(); i++)
	{
		ll sum=k+num[i-1].first;	//	���ñȽ����һ��Ԫ�أ���Ϊ��ʼλ����i
		int pos1=lower_bound(n.begin(),n.end(),make_pair(sum,-1),cmp)-n.begin();
		int pos2=upper_bound(n.begin(),n.end(),make_pair(sum,-1),cmp)-n.begin();
		//	�����޷�ֱ����find����
		if(pos1==n.size()||n[pos1].first!=sum)
			continue;
		for(int j=pos1; j<=(pos2<n.size()?pos2:n.size()-1); j++)
		{
			if(n[j].second>=i)
			{
				res.first=i;
				res.second=n[j].second;
				return res;
			}
		}
	}
	return res;
}

int main()
{
	int N,K;
	cin >> N >> K;
	vector<pair<ll, int>> num(N+1,make_pair((ll)0,0));
	for(int i=0; i<N; i++)
	{
		cin >> num[i+1].first;
		num[i+1].first+=num[i].first;
		num[i+1].second=i+1;
	}
	pair<int,int> res=RangeofSumk(num, K);
	if(res.first==-1)
		printf("No Solution\n");
	else
		printf("%d %d\n",res.first, res.second);
	system("pause");
	return 0;
}