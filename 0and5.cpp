/*
题目：0和5
要求：小K手中有n张牌，每张牌上有一个一位数的数，这个字数不是0就是5。
小K从这些牌在抽出任意张（不能抽0张），排成一行这样就组成了一个数。
使得这个数尽可能大，而且可以被90整除。
注意：
1.这个数没有前导0，
2.小K不需要使用所有的牌。

思路：被9整除的数都必须位数和为9的倍数，而本题数字只有0和5，因此至少
要9个5才能满足条件，先找出9的倍数张5，配合0去组成这个数。
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