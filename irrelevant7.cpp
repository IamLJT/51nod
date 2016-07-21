#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> sum0;
ll sum=(ll)0;

ll irrelevant7(int N, int& max)
{
	if(N<=max) return sum0[N-1];
	for(int i=max; i<N; i++)
	{
		ll temp=i+1;
		if(temp%7==0)
		{
			sum+=(ll)temp*(ll)temp;
			temp=0;
		}
		while(temp)
		{
			if(temp%10==7)
			{
				sum+=(ll)(i+1)*(ll)(i+1);
				break;
			}
			temp/=10;
		}
		sum0.push_back((ll)(i+1)*(ll)(i+2)*(ll)(2*i+3)/6-sum);
	}
	max=N;
	return sum0.back();
}

int main()
{
	int T, max=0;
	cin >> T;
	vector<int> N(T, 0);
	for(int i=0; i<T; i++)
		cin >> N[i];
	for(int i=0; i<T; i++)
		cout << irrelevant7(N[i], max) << endl;
	system("pause");
	return 0;
}