#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    int A[N][N];
    int accSum[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            A[i][j] = 0;
            accSum[i][j] = 0;
        }
    }

    for (int k = 0; k < N; k++) {
        int R1, R2, C1, C2;
        int V;
        cin >> R1 >> R2 >> C1 >> C2 >> V;
        A[R1-1][C1-1] += V;
        if (R2 < N) A[R2][C1-1] -= V; 
        if (C2 < N) A[R1-1][C2] -= V;
        if (R2 < N && C2 < N) A[R2][C2] += V;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) A[i][j] += A[i-1][j];
            if (j > 0) A[i][j] += A[i][j-1];
            if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}