class Solution {
public:
    string largestGoodInteger(string num) {
        int x = 0;
        bool flag = false;
        for(int i=0; i<num.size()-2; i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                flag = true;
                x = max(x, num[i]-'0');
            }
        }
        if(flag == false) return "";
        if(x == 0) return "000";
        string ans = "";
        for(int i=0; i<3; i++){
            ans += '0'+x;
        }
        return ans;
    }
};