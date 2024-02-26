#include <iostream>

using namespace std;

const int MAX_N = 100;

int main() {
    int N; // 행렬 크기를 입력하세요
    cin >> N;

    int A[MAX_N][MAX_N] = {0};
    int cumulativeSum[MAX_N][MAX_N] = {0};

    int updates;
    cin >> updates; // 업데이트 횟수를 입력하세요

    for (int k = 0; k < updates; k++) {
        int R1, R2, C1, C2;
        int V;
        cin >> R1 >> R2 >> C1 >> C2 >> V;

        // 주어진 범위에 해당하는 요소에 값을 더하고, 누적 합에 반영
        A[R1 - 1][C1 - 1] += V;
        if (R2 < N) A[R2][C1 - 1] -= V; 
        if (C2 < N) A[R1 - 1][C2] -= V;
        if (R2 < N && C2 < N) A[R2][C2] += V;
    }
    cout << "-------------\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------\n";
    // 누적 합 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // cumulativeSum[i][j] = A[i][j];
            if (i > 0) A[i][j] += A[i - 1][j];
            if (j > 0) A[i][j] += A[i][j - 1];
            if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
        }
    }

    // 업데이트된 행렬 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}