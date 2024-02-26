#include <bits/stdc++.h>
using namespace std;
typedef struct coins{
  int val;
  int cnt;
} coins;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int opt, sum;
  cin >> opt; cin >> sum;
  int dp[sum+1];
  for(int i=0; i<sum+1; i++)  dp[i] = 0;
  dp[0]=1;
  coins coin[opt];
  for(int i=0; i<opt; i++){
      cin >> coin[i].val;
      cin >> coin[i].cnt;
  }

  for(int i=0; i<opt; i++){
    for(int j=coin[i].val; j<=sum; j++){
      cout << "dp[" << j << "] += dp[" << j << "-" << "coin[" << i << "].val]" << endl;
      cout << dp[j] << "+=" << dp[j-coin[i].val] << endl;
      dp[j] += dp[j-coin[i].val];
    }
  }
  cout << dp[sum];
}
