#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    cin >> N;
    vector<ll> A(N, (ll)0);
    vector<int> B(N, 0);

	//vector<ll> left, right;
 //   for(int i=0; i<N; i++)
 //   {
 //       cin >> A[i] >> B[i];
 //       if(B[i]==0)
 //           left.push_back(A[i]);
 //       else
 //           right.push_back(A[i]);
 //   }
 //   sort(left.begin(), left.end());
 //   sort(right.begin(), right.end());
 //   if(left.back()>right.back())
 //   {
 //       auto it=lower_bound(left.begin(), left.end(), right.back());
 //       cout << left.size()-(it-left.begin()) << endl;
 //   }
 //   else if(left.back()<right.back())
 //   {
 //       auto it=lower_bound(right.begin(), right.end(), left.back());
 //       cout << right.size()-(it-right.begin()) << endl;
 //   }
 //   else
 //       cout << 2 << endl;

	vector<ll> Rfish;
	ll sum=0;
	for(int i=0; i<N; i++)
	{
		cin >> A[i] >> B[i];
		if(B[i]==0&&Rfish.size()==0)
			sum++;
		else if(B[i]==1)
			Rfish.push_back(A[i]);
		else
		{
			while(Rfish.size()&&A[i]>Rfish.back())
				Rfish.pop_back();
			if(Rfish.size()==0)
				sum++;
		}
	}
	sum+=Rfish.size();
	cout << sum << endl;

    system("pause");
    return 0;
}