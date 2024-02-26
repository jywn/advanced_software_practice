#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int cnt;
    cin >> cnt;
    stack<int> stk;
    int ans[cnt];
    for(int j = 0; j < cnt; j++)  ans[j] = j+1;
    int k = 0;
    int flag = 0;
    for(int x = 0; x < cnt; x++) {
      int tmp;
      cin >> tmp;
      stk.push(tmp);
      if(!stk.empty() && stk.top() == ans[k]) {
        while(!stk.empty() && k < cnt && stk.top() == ans[k]) {
          stk.pop();
          k++;
        }
      }
      if(k == cnt)  {
        flag = 1;
      }
    }
    if(flag)  cout << "POSSIBLE" << '\n';
    else cout << "IMPOSSIBLE" << '\n';
  }
}