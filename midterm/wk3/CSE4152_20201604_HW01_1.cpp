#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  int n;
  cin >> n;
  //17
  //10001
  //7
  //111
  //6
  //110
  //15
  //1111
  bitset<32> bit(n);
  int cnt=0;
  for(int i=0; i<32; i++) if(bit[i]==1) cnt=i+1;
  if(bit.count()>1){
    cout << cnt << ' ';
    for(int i=0; i<cnt; i++)  cout << pow(2, i) << ' ';
    cout << n;
  }
  else{
    cout << cnt-1 << ' ';
    for(int i=0; i<cnt; i++)  cout << pow(2, i) << ' ';
  }
  cout << endl;
}

//소수 = n-1 + 1
// 일반수 %2 or %3