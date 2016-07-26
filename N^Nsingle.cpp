#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main()
{
    int N;
	cin >> N;
	int t=((N%10)*(N%10))%10, count=2, t0=N, sum=N%10;
	if(N%10==0||N%10==1||N%10==5||N%10==6)
	{
		cout << N%10 << endl;
		system("pause");
		return 0;
	}
	while(t!=N%10)
	{
		count++;
		t=(t*(N%10))%10;
	}
	ll sum0=count;
	while(t0>sum0)
	{
		sum0*=count;
	}
    while(t0<sum0&&sum0!=1)
	{
		t0=t0%(sum0/count)+t0/(sum0/count);
		sum0=sum0/count;
	}
	for(int i=1; i<t0; i++)
		sum=(sum*(N%10))%10;
	cout << sum << endl;
    system("pause");
    return 0;
}