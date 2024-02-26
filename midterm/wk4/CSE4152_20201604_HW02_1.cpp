#include <bits/stdc++.h>
using namespace std;
void quick_sort(int, int);

int* arr;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int arr[N][N];
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> arr[i][j];
  int K;
  cin >> K;

  int row = 0, col = N-1;
  while(K != arr[row][col]){
    if(col > 0 && K < arr[row][col]) col--;
    if(row < N && K > arr[row][col]) row++;
  }
  cout << row+1 << " " << col+1;
}