class Solution {
public:
    vector<int > v;
    vector<int > DP;
    int N;
    int solve(int id){
        if(id>N-1){
            return 0;
        }
        if(DP[id] != -1){
            return DP[id];
        }
        int ans = max(0, v[id] + solve(id+1));
        return DP[id]=ans;
    }
    
    int maxSubArray(vector<int>& nums) {
        N = nums.size();
        v = nums;
        int ans = INT_MIN;
        DP.resize(N+5,-1);
        int mxval = INT_MIN;
        solve(0);
        for(int i=0;i<N;i++){
            ans = max(ans, DP[i]);
            mxval = max(v[i], mxval);
        }
        if(ans == 0){
            ans = mxval;
        }
        return ans;
    }
};