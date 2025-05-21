#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<vector<int>> rotate(const vector<vector<int>>& matrix);
int get_opt(const vector<vector<int>>& S, const vector<vector<int>>& T);

int main() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    vector<vector<int>> T(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            S[i][j] = (row[j] == '#') ? 1 : 0;
        }
    }

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            T[i][j] = (row[j] == '#') ? 1 : 0;
        }
    }

    cout << get_opt(S, T) << endl;
    return 0;
}

vector<vector<int>> rotate(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    vector<vector<int>> rotated(N, vector<int>(N));
    // first transpose the matrix
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[i][j] = matrix[j][i];
        }
    }
    // next reverse each row
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N / 2; j++) {
    //         int temp = rotated[i][j];
    //         rotated[i][j] = rotated[i][N - 1 - j];
    //         rotated[i][N - 1 - j] = temp;
    //     }
    // }
    for (int i = 0; i < N; i++) {
        reverse(rotated[i].begin(), rotated[i].end());
    }
    
    return rotated;
}

int get_opt(const vector<vector<int>>& S, const vector<vector<int>>& T) {
    vector<vector<int>> rotated[4];
    rotated[0] = S;
    for (int i = 1; i < 4; i++) {
        rotated[i] = rotate(rotated[i - 1]);
    }
    int diff[4] = {0, 1, 2, 3};
    int N = S.size();
    for (int c = 0; c < 4; c++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                diff[c] += abs(rotated[c][i][j] - T[i][j]);
            }
        }
    }
    return *min_element(diff, diff + 4);
}