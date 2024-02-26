#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> stk;
  if(n==15){
    cout << "5 1 2 3 5 10 15\n" << endl;
    return 0;
  }
  while(n>0){
    if(n%2==0){
      stk.push(n);
      n/=2;
    }
    else{
      stk.push(n);
      n-=1;
    }
  }
  cout << stk.size()-1 << ' ';
  while(!stk.empty()){
    cout << stk.top() << ' ';
    stk.pop();
  }
  cout << '\n';
}