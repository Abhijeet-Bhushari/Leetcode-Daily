class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        return (((long long)((2*n-1)*(2*n-2))/2 + 2*n - 1)*countOrders(n-1))%1000000007;
    }
};