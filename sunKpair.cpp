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
		// 有一种情况之后不用考虑，因为是从小到大排列，所以当这个数的两倍都大于K的话
		// 那么之后肯定不会再有满足和为K的组合。
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