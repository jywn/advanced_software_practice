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
    arr = (int *)malloc(sizeof(int)*(N*N));
    for(int i=0; i<N*N; i++)  cin >> arr[i];
    quick_sort(0, N*N-1);
    for(int i=0; i<N; i++)  cout << arr[i] << " ";
}


void quick_sort(int start, int end){
    if(start >= end)  return; 
    int piv = start;
    int i = piv + 1;
    int j = end;
    int tmp;
    while(i <= j){
        while(i <= end && arr[i] >= arr[piv]) i++;
        while(j > start && arr[j] <= arr[piv])  j--;
        if(i > j){
            tmp = arr[j];
            arr[j] = arr[piv];
            arr[piv] = tmp;
        }
        else{
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    } 
    quick_sort(start, j - 1);
    quick_sort(j + 1, end);
}