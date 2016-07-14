/*
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
	int N, Q;
	cin >> N;
	vector<ll> nums(N, 0);
	for(int i=0; i<N; i++)
		cin >> nums[i];
	vector<ll> sums(N+1, 0);
	for(int i=0; i<N; i++)
		sums[i+1]=sums[i]+nums[i];
	cin >> Q;
	vector<pair<int, int>> list0(Q, make_pair(0, 0));
	vector<ll> res(Q, 0);
	for(int i=0; i<Q; i++)
	{
		cin >> list0[i].first >> list0[i].second;
		res[i]=sums[list0[i].second+list0[i].first-1]-sums[list0[i].first-1];
	}
	for(int i=0; i<Q; i++)
		cout << res[i] << endl;
	system("pause");
	return 0;
}