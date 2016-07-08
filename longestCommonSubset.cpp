/*
题目：最长公共子序列Lcs
要求：给出两个字符串A B，求A与B的最长公共子序列（子序列不要求是连续的）。
比如两个串为：
abcicba
abdkscab
ab是两个串的子序列，abc也是，abca也是，其中abca是这两个字符串最长的子序列。

思路：先找出第一个字符串的所有字符在第二个字符串中的位置，然后从这些位置
中找出递增最长的即可。难点就是重复的怎么处理。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string longestSubset(string A, string B)
{
	vector<int> A_num(A.size(),-1);
	string res;
    for(int i=0; i<A.size(); i++)
	{
		int pos=B.find(A[i]);
		A_num[i]=pos;
		int temp=A.rfind(A[i],i-1);
		if(pos!=-1)
			B[pos]='#';
		if(pos==-1&&i>0&&temp>-1)
			A_num[i]=A_num[temp];
	}

	// 已经求出了位置序列，接下来就是求最长递增子序列
	vector<int> A_temp(A_num), temp0, res0;
	set<int> temp;
	int max_A=0;
	sort(A_temp.begin(), A_temp.end());
	//for(int j=0; j<A_temp.size(); j++)
	//	temp.insert(A_temp[j]);
	for(int i=A_num.size(); i>=0; i--)
	{
	//	temp0.clear();
	//	int length=0;
		temp.insert(A_num[i]);
		set<int>::iterator it=lower_bound(temp.begin(), temp.end(), A_num[i]);

		//while(it++!=temp.end())
		//	length++;
		/*int length=A_temp.end()-it+1;
		int e=A_temp.size()-temp.size();*/

		while(it!=temp.end())
			temp0.push_back(*it++);

		if(max_A<temp0.size())
		{
			res0.clear();
			res0.assign(temp0.begin(), temp0.end())
		}
		
		A_temp.erase(lower_bound(A_temp.begin(), A_temp.end(), A_num[i]));
		if(find(A_temp.begin(), A_temp.end(), A_num[i])==A_temp.end())
			temp.erase(A_num[i]);
	}
	
	return res;
}

int main()
{
	cout << longestSubset("abcicba", "abdkscab") << endl;
	system("pause");
	return 0;
}