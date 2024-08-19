#include <iostream>
using namespace std;

const int N = 6;

int queens[N]; // Mảng lưu vị trí của các con hậu
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}
void solve(int row) {
    if (row == N ) {
    // In ra cách xếp hậu
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                    if (queens[i] == j) {
                        cout << "Q ";
                    } else {
                        cout << ". ";
                    }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            queens[row] = col;
            solve(row + 1);
        }
    }
}
int main() {
    solve(0);

    return 0;
}