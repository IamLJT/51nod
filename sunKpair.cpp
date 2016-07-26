/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> sumKpair(vector<ll> num, ll K)
{
	vector<pair<ll, ll>> res;
	sort(num.begin(), num.end());
	for(int i=0; i<num.size(); i++)
	{
		if(2*num[i]>K) break;
		// ��һ�����֮���ÿ��ǣ���Ϊ�Ǵ�С�������У����Ե������������������K�Ļ�
		// ��ô֮��϶��������������ΪK����ϡ�
		int t=K-num[i];
		if(find(num.begin()+i+1, num.end(), t)!=num.end())
			res.push_back(make_pair(num[i], t));
	}
	return res;
}

int main()
{
	ll K, N;
	cin >> K >> N;
	vector<ll> num(N, (ll)0);
	for(ll i=0; i<N; i++)
		cin >> num[(int)i];
	vector<pair<ll, ll>> res=sumKpair(num, K);
	if(res.empty())
	{
		cout << "No Solution" << endl;
		system("pause");
		return 0;
	}
	for(int i=0; i<res.size(); i++)
		cout << res[i].first << " " << res[i].second << endl;
	system("pause");
	return 0;
}