#include <iostream>
using namespace std;
typedef long long ll;

//	容斥原理，先排除掉所有2,3,5,7的倍数，然后加上重复的即可。

ll Rongchi(ll N)
{
	ll i2=N/2;
	ll i3=N/3;
	ll i5=N/5;
	ll i7=N/7;

	ll i6=N/6;
	ll i10=N/10;
	ll i14=N/14;
	ll i15=N/15;
	ll i21=N/21;
	ll i35=N/35;

	ll i30=N/30;
	ll i42=N/42;
	ll i70=N/70;
	ll i105=N/105;

	ll i210=N/210;

	return N-(i2+i3+i5+i7)+(i6+i10+i14+i15+i21+i35)-(i30+i42+i70+i105)+i210;
}

int main()
{
	ll N;
	cin >> N;
	cout << Rongchi(N) << endl;
	system("pause");
	return 0;
}