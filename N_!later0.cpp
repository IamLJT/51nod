/*
题目：阶乘后面0的数量

思路：能实现有0的组合只会是2的倍数乘5的倍数，或是10的倍数，10的倍数很好统计，
主要是2的倍数与5的倍数的乘积如何得到，每10个数内（除10的倍数）2的倍数有4个，
而5的倍数只有1个。而产生复数个0的也只有10的倍数和5的幂数，而10的倍数也可以拆
成2和5倍数的乘积，所以我们只需求5的幂级数的个数。
*/

#include <iostream>
using namespace std;

int N_laternum0(int N)
{
	int sum=0, t=5;
	while(t<=N)
	{
		sum+=N/t;
		t*=5;
	}
	return sum;
}

int main()
{
	int N;
	cin >> N;
	cout << N_laternum0(N) << endl;
	system("pause");
	return 0;
}