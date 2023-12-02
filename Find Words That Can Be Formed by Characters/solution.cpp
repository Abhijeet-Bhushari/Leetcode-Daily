class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> mp;
        for(int i=0; i<chars.size(); i++){
            mp[chars[i]]++;
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            bool flag = true;
            map<char, int> temp = mp;
            for(int j=0; j<words[i].size(); j++){
                if(temp[words[i][j]] <= 0){
                    temp[words[i][j]]--;
                    flag = false;
                    break;
                }
                temp[words[i][j]]--;
            }
            if(flag == true) ans += words[i].size();
        }
        return ans;
    }
};