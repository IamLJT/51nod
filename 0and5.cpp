/*
��Ŀ��0��5
Ҫ��СK������n���ƣ�ÿ��������һ��һλ�������������������0����5��
СK����Щ���ڳ�������ţ����ܳ�0�ţ����ų�һ�������������һ������
ʹ������������ܴ󣬶��ҿ��Ա�90������
ע�⣺
1.�����û��ǰ��0��
2.СK����Ҫʹ�����е��ơ�

˼·����9��������������λ����Ϊ9�ı���������������ֻ��0��5���������
Ҫ9��5�����������������ҳ�9�ı�����5�����0ȥ����������
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, zero=0, five=0;
	cin >> n;
	vector<int> num(n, 0);
	vector<int> res;
	for(int i=0; i<n; i++)
	{
		cin >> num[i];
		if(0==num[i])
			zero++;
		else
			five++;
	}
	if(zero==0)
	{
		cout << -1 << endl;
		system("pause");
		return 0;
	}
	if(five/9==0)
	{
		cout << 0 << endl;
		system("pause");
		return 0;
	}
	for(int i=0; i<five-five%9; i++)
		res.push_back(5);
	for(int i=0; i<zero; i++)
		res.push_back(0);
	for(int i=0; i<res.size(); i++)
		cout << res[i];
	cout << endl;
	system("pause");
	return 0;
}