class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> cnty(n+1), cntx(n+1);
        int ys = 0, yn = 0;
        cnty[n] = 0;
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y') ys++;
            cnty[i]=ys;
        }
        cntx[0] = 0;
        for(int i=0; i<n; i++){
            if(customers[i]=='N') yn++;
            cntx[i+1]=yn;
        }
        int min_hour, mn = INT_MAX;
        for(int i=0; i<=n; i++){
            if(mn>cnty[i]+cntx[i]){
                mn = cnty[i] + cntx[i];
                min_hour = i;
            }
        }
        return min_hour;
    }
};