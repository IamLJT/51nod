#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

// 提交时出错，可能是数据范围不对

long long MaxRangeSum(vector<vector<long>>& nums, vector<vector<long>>& res0)
{
    int a=0, b=0, c=0, d=0;
	long long res=0, sum0=0;
    int n=nums.size();
	int m;
    if(n==0) return 0;
    else
        m=nums[0].size();
    vector<int> sum(n,0);
    for(int i=0; i<m; i++)
    {
        for(int j=i; j<m; j++)
        {
            for(int k=0; k<n; k++)
                sum[k]=(j==i)?nums[j][k]:(sum[k]+nums[j][k]);
            sum0=0;
            for(int k=0; k<n; k++)
            {
                sum0+=sum[k];
                if(sum0>res) 
                {
                    res=sum0;
                    c=i; d=j;
                    b=k;
                }
                if(sum0<0) 
                {
                    sum0=0;
                    a=k+1;
                }
            }
        }
    }
    vector<long> temp;
    if(a<=b)
    {
        for(int i=c; i<=d; i++)
        {
            temp.clear();
            for(int j=a; j<=b; j++)
                temp.push_back(nums[i][j]);
            res0.push_back(temp);
        }
    }
    return res;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<vector<long>> nums(n, vector<long>(m,0)), res;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> nums[i][j];
    cout << MaxRangeSum(nums, res) << endl;
    system("pause");
    return 0;
}