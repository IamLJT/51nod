#include <iostream>
#include <vector>
using namespace std;

int max0(int n1, int n2)
{
	return n1>n2?n1:n2;
}

int maxmatrixnum(vector<vector<int>> num)
{
	int n=num.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0]=num[0][0];
	for(int i=1; i<n; i++)
		dp[0][i]=num[0][i]+dp[0][i-1];
	for(int i=1; i<n; i++)
		dp[i][0]=num[i][0]+dp[i-1][0];
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			dp[i][j]=max0(dp[i-1][j], dp[i][j-1])+num[i][j];
		}
	}
	return dp[n-1][n-1];
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> num(N, vector<int>(N, 0));
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> num[i][j];
	cout << maxmatrixnum(num) << endl;
	system("pause");
	return 0;
}