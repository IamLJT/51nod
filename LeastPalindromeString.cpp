/*
��Ŀ�������ַ���
Ҫ�󣺻��Ĵ���ָaba��abba��cccbccc��aaaa�������ҶԳƵ��ַ�����ÿ���ַ���
������ͨ�����м����һЩ�ַ���ʹ֮��Ϊ�����ַ�����
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//	����1�������ԭ�ַ����������ַ���������������У�Ȼ�����ַ������ȼ�
//	��ȥ������еĳ��ȼ��ɡ��ö�̬�滮������⣺
//	dp[i][j]��ʾԭ�ַ���ǰi���ַ��������ַ���ǰj���ַ����е��������
//	�ַ�������
//	���s0[i]==s1[j]��dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i+1][j],dp[i][j+1]))
//	���s0[i]!=s1[j]��dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])

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

//	����2��ͬ���Ƕ�̬�滮�ķ�������dp[i][j]��ʾ��j��ʼ��i���ַ���Ϊ������Ҫ
//	��ӵ������ַ�������
//	��str[j]==str[j+i-1]ʱ��dp[i][j]=dp[i-2][j+1]
//	��str[j]!=str[j+i-1]ʱ��dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1

int Least_PalindromeString(string str)
{
	int len=str.size();
	vector<vector<int>> dp(len+1,vector<int>(len,0));

	// ��iΪ1��0ʱ��dp��Ϊ0�����ѭ����i=2��ʼ
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
