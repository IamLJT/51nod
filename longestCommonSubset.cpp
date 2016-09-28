///*
//��Ŀ�������������Lcs
//Ҫ�󣺸��������ַ���A B����A��B������������У������в�Ҫ���������ģ���
//����������Ϊ��
//abcicba
//abdkscab
//ab���������������У�abcҲ�ǣ�abcaҲ�ǣ�����abca���������ַ�����������С�
//
//˼·�����ҳ���һ���ַ����������ַ��ڵڶ����ַ����е�λ�ã�Ȼ�����Щλ��
//���ҳ�������ļ��ɡ��ѵ�����ظ�����ô����
//*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//
//string longestSubset(string A, string B)
//{
//	vector<int> A_num(A.size(),-1);
//	string res, t(B);
//    for(int i=0; i<A.size(); i++)
//	{
//		int pos=B.find(A[i]);
//		A_num[i]=pos;
//		int temp=A.rfind(A[i],i-1);
//		if(pos!=-1)
//			B[pos]='#';
//		if(pos==-1&&i>0&&temp>-1)
//			A_num[i]=A_num[temp];
//	}// ����������,��A�ظ������ֽ϶�ʱ���������ò�����
//
//	// �Ѿ������λ�����У������������������������
//	//vector<int> A_temp(A_num), temp0, res0;
//	//set<int> temp;
//	//int max_A=0;
//	//sort(A_temp.begin(), A_temp.end());
//	////for(int j=0; j<A_temp.size(); j++)
//	////	temp.insert(A_temp[j]);
//	//for(int i=A_num.size(); i>=0; i--)
//	//{
//	////	temp0.clear();
//	////	int length=0;
//	//	temp.insert(A_num[i]);
//	//	set<int>::iterator it=lower_bound(temp.begin(), temp.end(), A_num[i]);
//
//	//	//while(it++!=temp.end())
//	//	//	length++;
//	//	/*int length=A_temp.end()-it+1;
//	//	int e=A_temp.size()-temp.size();*/
//
//	//	while(it!=temp.end())
//	//		temp0.push_back(*it++);
//
//	//	if(max_A<temp0.size())
//	//	{
//	//		res0.clear();
//	//		res0.assign(temp0.begin(), temp0.end())
//	//	}
//	//	
//	//	A_temp.erase(lower_bound(A_temp.begin(), A_temp.end(), A_num[i]));
//	//	if(find(A_temp.begin(), A_temp.end(), A_num[i])==A_temp.end())
//	//		temp.erase(A_num[i]);
//	//}
//	
//	vector<int> dp(A.size(), 1), p(A.size(),-1);
//	int m=0, maxlen=1;
//	for(int i=0; i<A.size(); i++)
//	{
//		for(int j=0; j<i; j++)
//		{
//			if(A_num[i]>=0&&A_num[j]>=0&&A_num[i]>A_num[j]&&dp[i]<dp[j]+1)
//			{
//				dp[i]=dp[j]+1;
//				p[i]=j;
//			}
//			if(maxlen<dp[i])
//			{
//				m=i;
//				maxlen=dp[i];
//			}
//		}
//	}
//
//	while(m!=-1)
//	{
//		res=t[A_num[m]]+res;
//		m=p[m];
//	}
//
//	return res;
//}
//
//int main()
//{
//	string str1, str2;
//	cin >> str1 >> str2;
//	cout << longestSubset(str1, str2) << endl;
//	system("pause");
//	return 0;
//}

/*
��Ŀ�������������Lcs
Ҫ�󣺸��������ַ���A B����A��B������������У������в�Ҫ���������ģ���
����������Ϊ��
abcicba
abdkscab
ab���������������У�abcҲ�ǣ�abcaҲ�ǣ�����abca���������ַ�����������С�

˼·���ö�̬�ع滮����dp[i][j]��ʾ�ַ���1ǰi���ַ����ַ���2ǰj���ַ���
������������ַ�������

*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int max0(int n1,int n2)
{
    return n1>n2?n1:n2;
}

int LCS(string str1, string str2)
{
    int len1=str1.size(), len2=str2.size();
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    
    for(int i=0; i<len1; i++)
    {
        for(int j=0; j<len2; j++)
        {
            //  ���str1[i]==str2[j]����dp[i+1][j+1]=dp[i][j]+1
            //  ������ȣ���dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])
            dp[i+1][j+1]=max0(dp[i][j]+(str1[i]==str2[j]?1:0),max0(dp[i+1][j],dp[i][j+1]));
        }
    }
    return dp.back().back();
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	cout << LCS(str1, str2) << endl;
	system("pause");
	return 0;
}