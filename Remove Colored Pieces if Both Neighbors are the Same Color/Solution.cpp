class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0, b = 0;
        for(int i=1; i<n-1; i++){
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A') a++;
            if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B') b++;
        }
        if(a>b) return true;
        else return false;
    }
};