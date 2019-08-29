class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mnPrice = INT_MAX;
        int mxProfit = 0;
        
        for(int i=0;i<n;i++){
            if(prices[i] < mnPrice){
                mnPrice = prices[i];
            }else if(prices[i]-mnPrice > mxProfit){
                mxProfit = prices[i]-mnPrice;
            }
        }
        return mxProfit;
    }
};