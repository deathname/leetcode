class Solution {
public:
    int N;
    vector<int > Cost;
    vector<int > DP;
    int solve(){
        DP[N] = 0;
        DP[N+1] = 0;
        for(int i=N-1;i>=0;i--){
            DP[i] = Cost[i] + min(DP[i+1], DP[i+2]);
        }
        return min(DP[0],DP[1]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        N = cost.size();
        Cost = cost;
        DP.resize(N+5,-1);
        return solve();
    }
};