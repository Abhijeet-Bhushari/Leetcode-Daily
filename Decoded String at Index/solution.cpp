class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]-'0'>1 && s[i]-'0'<=9){
                int temp = s[i]-'0';
                len = len*temp;
            }
            else{
                len++;
            }
        }
        for(int i=s.size()-1; i>=0; i--){
            // cout<<k<<" "<<len<<endl;

            if(s[i]-'0'>1 && s[i]-'0'<=9){
                int temp = s[i]-'0';
                len /= temp;
                if(len == 1) return s.substr(0, 1);
                if(k%len==0) k = len;
                else k %= len;
            }
            else{
                if(k == len) return s.substr(i, 1);
                len--;
            }
        }
        string res = "";
        res += s[k-1];
        return res;
    }
};