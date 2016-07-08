#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void merge(vector<ll>&nums, int p, int m, int q)
{
    int a=m-p+1, b=q-m;
    vector<ll> A, B;
    for(int i=0; i<a; i++)
        A.push_back(nums[p+i]);
    for(int i=0; i<b; i++)
        B.push_back(nums[m+1+i]);
    A.push_back(INT_MAX);
    B.push_back(INT_MAX);
    int i=0, j=0;
    for(int k=p; k<=q; k++)
    {
        if(A[i]<=B[j])
            nums[k]=A[i++];
        else
            nums[k]=B[j++];
    }
}

void recursive_merge(vector<ll>& nums, int p, int q)
{
    if(p<q)
    {
        int m=(p+q)/2;
        recursive_merge(nums, p, m);
        recursive_merge(nums, m+1, q);
        merge(nums, p, m, q);
    }
}

void merge_sort(vector<ll>& nums)
{
    recursive_merge(nums, 0, nums.size()-1);
}

int main()
{
    int N;
    cin >> N;
    vector<ll> nums(N, (ll)0);
    for(int i=0; i<N; i++)
        cin >> nums[i];
    merge_sort(nums);
    for(int i=0; i<N; i++)
        cout << nums[i] << endl;
	system("pause");
    return 0;
}