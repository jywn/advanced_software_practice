#include <iostream>

int minimizeAdditions(int n) {
    int x0 = 1;
    int x1 = 1;
    int k = 0;

    while (x1 < n) {
        int xk_plus_1 = x0 + x1;
        x0 = x1;
        x1 = xk_plus_1;
        k++;
    }

    if (x1 == n) {
        return k + 1; // x1과 n이 같으면 덧셈 한 번 더 필요
    } else if (x0 == n) {
        return k; // n이 x0과 같으면 이미 계산된 값이므로 덧셈 필요 없음
    } else {
        return k + std::min(n - x0, x1 - n) + 1;
    }
}

int main() {
    int n1 = 15;
    int n2 = 7;
    int n3 = 16;

    std::cout << minimizeAdditions(n1) << std::endl; // 출력: 5
    std::cout << minimizeAdditions(n2) << std::endl; // 출력: 4
    std::cout << minimizeAdditions(n3) << std::endl; // 출력: 4

    return 0;
}