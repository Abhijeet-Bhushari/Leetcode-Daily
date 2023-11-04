#include<bits/stdc++.h>

class solution{
    public:
    int getLastMoment(int n, vector<int> left, vector<int> right){
        int mx = 0;
        for(int i=0; i<left.size(); i++){
            mx = max(left[i], mx);
        }
        for(int i=0; i<right.size(); i++){
            mx = max(right[i], mx);
        }
        return mx;
    }
}