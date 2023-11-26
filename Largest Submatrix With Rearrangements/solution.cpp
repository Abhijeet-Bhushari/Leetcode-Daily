// 1 0 1
// 0 1 0

// 1 1 1 
// 1 1 0
// 1 0 1

// 1 1 1 
// 1 1 0
// 0 1 1

//        2     2       1        1      1     1       1
// mp = {{0}, {0,1}, {0,1,1}, {0,1,0}, {1}, {1,1}, {1,1,1}};

//{1, 1, 1}

// mp2 = {0, 1, 2}


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<vector<int>, int> mp;
        for(int i=0; i<m; i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                if(matrix[j][i] == 1){
                    temp.push_back(j);
                    mp[temp]++;
                }
            }
        }
        // for(auto i: mp){
        //     for(auto j: i.first) cout<<j<<" ";
        //     cout<<endl;
        //     cout<<i.second<<endl;
        // }
        // cout<<endl;
        for(auto i: mp){
            map<int, int> mp2;
            for(auto j : i.first){
                mp2[j]++;
            }
            for(auto j: mp){
                if(j.first == i.first) continue;
                bool flag = true;
                for(int k=1; k<j.first.size(); k++){
                    if(mp2[j.first[k]] != 1){
                        flag = false;
                        break;
                    }
                }
                if(flag == true && j.first.size()<i.first.size() && j.first[0]!=i.first[0]){
                    mp[j.first]++;
                }
            }
        }
        int ans = INT_MIN;
        for(auto i: mp){
            cout<<i.first.size()<<" "<<i.second<<endl;
            ans = max((int)i.first.size()*i.second, ans);
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};