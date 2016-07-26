/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp0(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first<p2.first)
		return 1;
	else 
		return 0;
}

//struct cmp0{
//	bool operator ()(const pair<int, int> p1, const pair<int, int> p2)
//	{
//		return p1.first<p2.first;
//	}
//};

int roomnum(vector<pair<int, int>> num)
{
	sort(num.begin(), num.end(), cmp0);
	int i=0, count=0;
	while(num.size())
	{
		auto it=lower_bound(num.begin(), num.end(), make_pair(num[i].second,0), cmp0);
		int t;
		if(it==num.end()) 
		{t=0;count++;}
		else t=it-num.begin();
		num.erase(num.begin()+i);
		i=(t==0?0:t-1);
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> num(n, pair<int, int>(0, 0));
	for(int i=0; i<n; i++)
		cin >> num[i].first >> num[i].second;
	cout << roomnum(num) << endl;
	system("pause");
	return 0;
}