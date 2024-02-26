#include <bits/stdc++.h>
using namespace std;
typedef struct coins{
  int val;
  int cnt;
} coins;
/*
3 15
5 3
3 5
2 5


*/
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> stk;//coin value, index
  vector<pair<int, int>>::iterator iter;
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
  string ansSht;
  string finAns;
  int ans=0;
//WE CAN SOLVE THIS PROB WITH DFS, MAYBE?
for(int k=0; k<opt; k++){
  int acc=0, prev=-1;
  acc+=coin[k].val;
  coin[k].cnt-=1;
  stk.push_back({coin[k].val, k});
  // cout << "pushed " << coin[k].val << '\n';
  while(!stk.empty()){
    if(acc<sum){
      for(int i=0; i<opt; i++){
        if(coin[i].cnt>0 && i>prev){
          acc+=coin[i].val;
          coin[i].cnt-=1;
          stk.push_back({coin[i].val, i});
          // cout << "pushed " << coin[i].val << '\n';
          break;
        }
        if(i==opt-1){
        prev = (stk.back().second);
        acc -= stk.back().first;
        coin[stk.back().second].cnt+=1;
        // cout << "popped " << stk.back().first << '\n';
        stk.pop_back();
      }
      }
    }
    else if(acc==sum){
      ans+=1;
      for(iter = stk.begin(); iter != stk.end(); iter++){
        ansSht += (iter.base()->first + '0');
        ansSht += ' ';
        if((iter+1) == stk.end()) ansSht += '\n';
      }
      prev = (stk.back().second);
      acc -= stk.back().first;
      // cout << "popped " << stk.back().first << '\n';
      coin[stk.back().second].cnt+=1;
      stk.pop_back();
    }
    else{
      prev = (stk.back().second);
      acc -= stk.back().first;
      coin[stk.back().second].cnt+=1;
      // cout << "popped " << stk.back().first << '\n';
      stk.pop_back();
    }
  }
  coin[k].cnt=0;
}
  finAns += (ans + '0');
  finAns += '\n';
  finAns += ansSht;
  cout << finAns;
}
