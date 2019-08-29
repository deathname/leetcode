// CTCI DP & Recursion

/*
 *
 * Robot in a Grid:
 * Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
 * The robot can only move in two directions, right and down, but certain cells are "off limits" such that
 * the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
 * the bottom right.
 *
 *  */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat;
    mat.resize(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int> > DP;
    DP.resize(n + 5, vector<int>(m + 5, 0));
    DP[n - 1][m - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        if(mat[i][m - 1] != -1)
            DP[i][m - 1] += DP[i + 1][m - 1];
    }

    for(int i = m - 2; i >= 0; i--) {
        if(mat[n - 1][i] != -1)
            DP[n - 1][i] += DP[n - 1][i + 1];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = m - 2; j >= 0; j--) {
            // can be reached
            if(mat[i][j] != -1) {
                DP[i][j] = DP[i + 1][j] + DP[i][j + 1];
            }
        }
    }
    cout << DP[0][0];
}
