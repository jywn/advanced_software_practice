#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N; //FIRST INPUT::SIZE OF PROBLEM
  cin.ignore();//CLEAR BUFF
  int arr[N];
  for(int i=0; i<N; i++)  cin >> arr[i];//SECOND INPUT::ARRAY OF NUMBERS
  int maxSubSeq=0, maxTail=0;
  for(int i=0; i<N; i++){
    int tmp = maxTail + arr[i];
    if(tmp <= 0)  maxTail = 0;
    else maxTail = tmp;
    if(maxSubSeq < maxTail) maxSubSeq = maxTail;
  }
  cout << maxSubSeq << '\n';
}