#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int totalWeight,N;
    cin>>totalWeight>>N;

    vector<int> value(N+1);
    vector<int> weight(N+1);
    for (int i = 1; i <=N; i++)
    {
        cin>>weight[i]>>value[i];
    }

    vector<vector<int>> dp(N+1,vector<int>(totalWeight+1, 0));
    for(int i=0;i<=N;i++)
    {
        for (int j = 1; j <= totalWeight; j++)
        {
            if(j<weight[i])//˵��װ����
            {
                dp[i][j]=dp[i-1][j];
            }
            else{//��װ�£�����ҲҪ���ǣ�װ����װ����Ӧ�����
            dp[i][j]=max(dp[i-1][j - weight[i]] + value[i],dp[i-1][j]);
            //dp[i-1][j - weight[i]] + value[i]��Ӧװ�� ���
            //dp[i-1][j]��Ӧ��װ�� ���
            }
        }
        
    }
    cout<<dp[N][totalWeight]<<endl;




    return 0;
}
