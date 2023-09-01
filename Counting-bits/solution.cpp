class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        int t, cnt=0;
        for(int i=0; i<n+1; i++){
            t = i;
            while(t){
                if(t%2==1) cnt++;
                t/=2;
            }
            arr.push_back(cnt);
            cnt=0;
        }
        return arr;
    }
};