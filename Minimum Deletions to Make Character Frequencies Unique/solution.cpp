class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mp;      
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;    
        }
        map<int , int> mp2;
        for(auto i: mp){
            mp2[i.second]++;
        }
        int ans=0;
        for(auto &i: mp2){
            while(i.second>1){
                int k = 1;
                while(mp2[i.first-k]!=0){
                    k++;
                }
                if(i.first-k>0)mp2[i.first-k]++;
                i.second--;
                ans+=k;
            }
        }
        return ans;
        
    }
};