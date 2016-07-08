#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

int rev_order(vector<ll> nums)
{
    set<ll> num;
    int sum=0, temp;
    set<ll>::iterator it;
    for(int i=nums.size()-1; i>=0; i--)
    {
        temp=0;
        num.insert(nums[i]);
        /*for(it=num.begin();it!=num.end();++it)
        {
            if(*it==nums[i])
                break;
            else
                temp++;
        }*/
        set<ll> temp0(num);
		it=temp0.find(nums[i]);
		temp0.erase(it, temp0.end());
        temp=temp0.size();
        sum+=temp;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    vector<ll> nums(N, (ll)0);
    for(int i=0; i<N; i++)
        cin >> nums[i];
    cout << rev_order(nums) << endl;
    return 0;
}