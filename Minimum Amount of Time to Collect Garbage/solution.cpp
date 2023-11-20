class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> prefix;
        int sum = 0;
        for(int i: travel){
            sum += i;
            prefix.push_back(sum);
        }
        int a=0, b=0, c=0, time = 0;
        for(int i=0; i<garbage.size(); i++){
            string s = garbage[i];
            for(int j=0; j<s.size(); j++){
                if(s[j] == 'M'){
                    // cout<<"M "<<i<<" "<<a<<endl;
                    if((i==1 && a!=1) || (i>1 && a==0)) time += prefix[i-1];
                    else if(i>1) time += prefix[i-1] - prefix[a-1];
                    time += 1;
                    a = i;
                    // cout<<time<<endl;
                }
                if(s[j] == 'P'){
                    // cout<<"P "<<i<<" "<<b<<endl;
                    if((i==1 && b!=1) || (i>1 && b==0)) time += prefix[i-1];
                    else if(i>1) time += prefix[i-1] - prefix[b-1];
                    time += 1;
                    if(i!=0) b = i;
                    // cout<<time<<endl;
                }
                if(s[j] == 'G'){
                    // cout<<"G "<<i<<" "<<c<<endl;
                    if((i==1 && c!=1) || (i>1 && c==0)) time += prefix[i-1];
                    else if(i>1) time += prefix[i-1] - prefix[c-1];
                    time += 1;
                    if(i!=0) c = i;
                    // cout<<time<<endl;
                }
            }
        }
        return time;
    }
};