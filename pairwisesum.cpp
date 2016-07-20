#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// 考虑2和1的情况即可，2只能和1和2组合才能有1,1和除1之外任意数组合有1，
// 1和1组合有2。其他情况都是0，不用考虑。

int main()
{
    int N, len1=0, len2=0;
    cin >> N;
    vector<ll> num(N, (ll)0);
    ll sum=0;
    for(int i=0; i<N; i++)
    {
        cin >> num[i];
        if(num[i]==1)
            len1++;
		if(num[i]==2)
			len2++;
    }
	int len=len1;
    for(int i=0; i<N; i++)
    {
        if(num[i]==1)
        {
            sum+=N-i-len1;
            len1--;
        }
		else
		{
			sum+=len1;
		}
    }
    if(len>1)
        sum+=len*(len-1);
	if(len2>1)
		sum+=len2*(len2-1)/2;
    cout << sum << endl;
    system("pause");
    return 0;
}