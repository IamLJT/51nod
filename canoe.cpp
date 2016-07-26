/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numcanoe(vector<int> num, int m)
{
	sort(num.begin(), num.end());
	auto it=lower_bound(num.begin(), num.end(), m);
	int len=it-num.begin();
	int left=0, right=len-1;
	int count=0;
	while(left<right)
	{
		if(num[left]+num[right]>m)
		{
			right--;
			count++;
		}
		else 
		{
			right--;
			left++;
			count++;
		}
	}
	if(left==right) count++;
	count+=num.size()-len;
	return count;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> num(n, 0);
	for(int i=0; i<n; i++)
		cin >> num[i];
	cout << numcanoe(num, m) << endl;
	system("pause");
	return 0;
}