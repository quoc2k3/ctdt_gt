#include <iostream>

using namespace std;

const int SIZE = 8;
int queens[SIZE];

void output(){
    for(int i = 0 ;i < SIZE ; i++){
        for(int j = 0; j < SIZE; j++){
            if(queens[i] == j){
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}
void queen(int idx){
    for(int j = 0; j < SIZE;j++){
        if(isSafe(idx, j)){
            queens[idx] = j;
            if(idx == SIZE -1)

                output();
            else
                queen(idx + 1);

            queens[idx] = 0;
        }
    }
}
int main() {

    queen(0);
    return 0;
}