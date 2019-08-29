// CTCI DP & Recursion

/* Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
 * Implement a method to count how many possible ways the child can run up the stairs.
 *  */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> DP(n + 5, 0);
    DP[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        DP[i] = DP[i + 1] + DP[i + 2] + DP[i + 3];
    }
    cout << DP[0];
}
