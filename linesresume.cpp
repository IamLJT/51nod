/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first<p2.first)
		return 1;
	else
		return 0;
}

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

int min0(int n1, int n2)
{
	return n1<n2?n1:n2;
}

int cover(pair<int, int> p, int end)
{
	int left=p.first;
	int right=min0(p.second, end);
	if(left<=right)
		return right-left;
	return 0;
}

int main()
{
	int N, n1, n2, maxlen=0;
	cin >> N;
	vector<pair<int, int>> num;
	for(int i=0; i<N; i++)
	{
		cin >> n1 >> n2;
		num.push_back(make_pair(min0(n1,n2), max0(n1,n2)));
	}
	sort(num.begin(), num.end(), cmp);
	int end=num[0].second;
	for(int i=1; i<N; i++)
	{
		maxlen=max0(cover(num[i],end), maxlen);
		end=max0(end, num[i].second);
	}
	cout << maxlen << endl;
	system("pause");
	return 0;
}