/*
��Ŀ�������������Lcs
Ҫ�󣺸��������ַ���A B����A��B������������У������в�Ҫ���������ģ���
����������Ϊ��
abcicba
abdkscab
ab���������������У�abcҲ�ǣ�abcaҲ�ǣ�����abca���������ַ�����������С�

˼·�����ҳ���һ���ַ����������ַ��ڵڶ����ַ����е�λ�ã�Ȼ�����Щλ��
���ҳ�������ļ��ɡ��ѵ�����ظ�����ô����
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

	// �Ѿ������λ�����У������������������������
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