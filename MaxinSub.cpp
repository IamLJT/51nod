/*
题目：序列中最大的数
要求：有这样一个序列a：

a[0] = 0

a[1] = 1

a[2i] = a[i]

a[2i+1] = a[i] + a[i+1]

输入一个数N，求a[0] - a[n]中最大的数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int T;
	cin >> T;
	vector<int> num(T,0);
	
	for(int i=0; i<T; i++)
	{
		cin >> num[i];
	}
	vector<int> temp(num);
	sort(num.begin(),num.end());
	vector<ll> A(num.back()+1,0),dpmax(num.back()+1,0);
	A[0]=0;
	A[1]=1;
	dpmax[0]=0;
	dpmax[1]=1;
	for(int i=2; i<=(int)num.back(); i++)
	{
		A[i]=A[i/2]+(i%2?1:0)*A[i/2+1];
		dpmax[i]=A[i]>dpmax[i-1]?A[i]:dpmax[i-1];
	}
	for(int i=0; i<(int)temp.size(); i++)
	{
		cout << dpmax[temp[i]] << endl;
	}
	system("pause");
	return 0;
}