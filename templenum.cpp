/*

*/

#include <iostream>
#include <vector>
using namespace std;

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

int min0(int n1, int n2)
{
	return n1<n2?n1:n2;
}

int templenum(vector<vector<int>> num)
{
	if(num.empty()) return 0;
	if(num.size()==1) return num[0][0];
	vector<vector<int>> dp(num);
	int max_num=0;
	for(int i=1; i<num.size(); i++)
	{
		int len=num[i].size();
		for(int j=0; j<len; j++)
		{
			dp[i][j]=max0(dp[i-1][max0(0, j-1)], dp[i-1][min0(len-2, j)])+num[i][j];
			//	以num[i][j]结尾的数只能从它上面的数和其上前面的数来得到
			max_num=max0(dp[i][j], max_num);
		}
	}
	return max_num;
}

int main()
{
	int N;
	vector<vector<int>> num;
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		vector<int> temp(i, 0);
		for(int j=0; j<i; j++)
			cin >> temp[j];
		num.push_back(temp);
	}
	cout << templenum(num) << endl;
	system("pause");
	return 0;
}