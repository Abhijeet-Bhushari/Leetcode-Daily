class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string mod1 = "", mod2 ="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#' && mod1.size()>0){
                mod1.erase(mod1.size()-1, 1);
            }
            else if(s[i]!='#'){
                mod1 += s[i];
            }
        }
        for(int i=0; i<t.size(); i++){
            if(t[i]=='#' && mod2.size()>0){
                mod2.erase(mod2.size()-1, 1);
            }
            else if(t[i]!='#'){
                mod2 += t[i];
            }
        }
        cout<<mod1<<" "<<mod2<<endl;
        return mod1 == mod2;
    }
};