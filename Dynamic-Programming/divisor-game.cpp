class Solution {
public:
    vector<int > DP;
    int solve(int N){
        DP[1] = 0;
        for(int i=2;i<=N;i++){
            for(int j=1;j<i;j++){
                if(i%j==0 && DP[i-j]==0){
                    DP[i]=1;
                    break;
                }
            }
        }
        return DP[N];
    }
    bool divisorGame(int N) {
        DP.resize(N+1,0);
        return solve(N);
    }
};