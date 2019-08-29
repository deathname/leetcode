class Solution {
public:
    int N;
    vector<int > DP;
    int solve(){
        DP[N] = 1;
        DP[N+1] = 0;
        for(int i=N-1;i>=0;i--){
            DP[i] = DP[i+1]+DP[i+2];
        }
        return DP[0];
    }
    int climbStairs(int n) {
        N = n;
        DP.resize(N+5,0);
        return solve();
    }
};