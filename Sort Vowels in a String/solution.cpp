class Solution {
public:
    string sortVowels(string s) {
        vector<char> vow;
        set<char> st = {'A','E','I','O','U','a','e','i','o','u'};
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()) vow.push_back(s[i]);
        }
        sort(vow.begin(), vow.end());
        string res = s;
        int k = 0;
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                res[i] = vow[k];
                k++;
            } 
        }
        return res;
    }
};