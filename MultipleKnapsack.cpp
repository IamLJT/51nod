/*
���⣺���ر�������

˼·1����dp[i][j]��ʾǰi����Ʒ��������Ϊj��ʱ�������ֵ��������ҳ�
dp�е����ֵ��(�ύʱ�������why��)

˼·2�����½��з��䣬��Ϊ����һ������������2���ݱ�ʾ������
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll MaxValueMultipack(ll W, vector<ll>& Wi, vector<ll>& Pi, vector<ll>& Ci)
{
	ll res=0;
	if(Wi.size()==0) return 0;

	// // ˼·1
	//vector<vector<ll>> dp(Wi.size(), vector<ll>(W+1, (ll)0));
	//for(ll i=0; i<Ci[0]; i++)
	//{
	//	if(i*Wi[0]>W) break;
	//	dp[0][i*Wi[0]]=i*Pi[0];
	//}
	//for(ll i=1; i<Wi.size(); i++)
	//{
	//	for(ll j=0; j<=W; j++)
	//		for(ll k=0; k<=min(j/Wi[i], Ci[i]); k++)
	//			dp[i][j]=max(dp[i][j], dp[i-1][j-k*Wi[i]]+k*Pi[i]);
	//	// ��̬�滮�Ĺؼ�
	//}
	//for(ll i=0; i<Wi.size(); i++)
	//	res=max(res, *max_element(dp[i].begin(), dp[i].end()));
	

	// ˼·2
	vector<ll> Wj, Pj;
	for(int i=0; i<Ci.size(); i++)
	{
		//ll k=(ll)floor(log(Ci[i])/log(2));
		//if(pow(2, k)==Ci[i]) k--;
		ll temp=Ci[i], j=0;
		while(temp-pow(2, j) >= 0)
		{
			temp-=(ll)pow(2, j);
			Wj.push_back((ll)pow(2, j)*Wi[i]);
			Pj.push_back((ll)pow(2, j)*Pi[i]);
			j++;
		}
		if(temp!=0)
		{
			//temp+=(ll)pow(2, j-1);
			Wj.push_back(temp*Wi[i]);
			Pj.push_back(temp*Pi[i]);
		}
	}
	//vector<vector<ll>> dp(Wj.size(), vector<ll>(W+1, 0));
	vector<ll> dp(W+1, 0);
	//dp[0][Wj[0]]=Pj[0];
	//for(ll j=1; j<=W; j++)
	for(int i=0; i<Wj.size(); i++)
	{
		//for(int i=1; i<Wj.size(); i++)
		for(int j=W; j>=Wj[i]; --j)
		{
			/*if(j>=Wj[i])
				dp[i][j]=max(dp[i][j], max(dp[i-1][j-Wj[i]]+Pj[i], dp[i-1][j]));//ǰi����Ʒ����j����������ֵ
			else
				dp[i][j]=dp[i-1][j];*/
			//if(j>=Wj[i])
				dp[j]=max(dp[j], dp[j-Wj[i]]+Pj[i]);
		}
	}
	return dp[dp.size()-1];

	//return dp[dp.size()-1][W];
}

int main()
{
	ll N, W;
	cin >> N >> W;
	vector<ll> Wi(N, 0), Pi(N, 0), Ci(N, 0);
	for(ll i=0; i<N; i++)
		cin >> Wi[i] >> Pi[i] >> Ci[i];
	cout << MaxValueMultipack(W, Wi, Pi, Ci) << endl;
	system("pause");
	return 0;
}