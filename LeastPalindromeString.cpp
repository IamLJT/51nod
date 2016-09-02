/*
题目：回文字符串
要求：回文串是指aba、abba、cccbccc、aaaa这种左右对称的字符串。每个字符串
都可以通过向中间添加一些字符，使之变为回文字符串。
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//	方法1：先求出原字符串和逆序字符串的最长公共子序列，然后用字符串长度减
//	减去最长子序列的长度即可。用动态规划可以求解：
//	dp[i][j]表示原字符串前i个字符与逆序字符串前j个字符所有的最长子序列
//	字符个数。
//	如果s0[i]==s1[j]，dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i+1][j],dp[i][j+1]))
//	如果s0[i]!=s1[j]，dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])

int LCS_PalindromeString(string str)
{
	string str0=str;
	reverse(str0.begin(),str0.end());
	int len=str.size();
	vector<vector<int>> dp(len+1, vector<int>(len+1,0));
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len; j++)
		{
			dp[i+1][j+1]=max(dp[i][j]+(str[i]==str0[j]?1:0), max(dp[i][j+1],dp[i+1][j]));
		}
	}
	return len-dp.back().back();
}

//	方法2：同样是动态规划的方法，用dp[i][j]表示从j开始的i个字符变为回文需要
//	添加的最少字符个数：
//	当str[j]==str[j+i-1]时，dp[i][j]=dp[i-2][j+1]
//	当str[j]!=str[j+i-1]时，dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1

int Least_PalindromeString(string str)
{
	int len=str.size();
	vector<vector<int>> dp(len+1,vector<int>(len,0));

	// 当i为1或0时，dp均为0，因此循环从i=2开始
	for(int i=2; i<len+1; i++)
	{
		for(int j=0; j<len-i+1; j++)
		{
			if(str[j]==str[j+i-1])
				dp[i][j]=dp[i-2][j+1];
			else
				dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+1;
		}
	}

	return dp[len][0];
}

int main()
{
	string str="BBBB";
	cout << Least_PalindromeString(str) << endl
		<< LCS_PalindromeString(str) << endl;

	system("pause");
	return 0;
}
