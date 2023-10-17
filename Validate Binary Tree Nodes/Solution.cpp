class Solution {
public:

    bool solve(map<int, vector<int>> &mp, vector<int> &passed, int r, int n){
        if(passed.size() > n) return false;
        vector<int> temp = mp[r];
        for(int i=0; i<temp.size(); i++){
            passed.push_back(temp[i]);
            solve(mp, passed, temp[i], n);
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        map<int, vector<int>> mp;
        map<int, bool> root;
        for(int i=0; i<n; i++){
            root[i] = true;
        }
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                mp[i].push_back(leftChild[i]);
                root[leftChild[i]] = false;
            }
            if(rightChild[i]!=-1){
                mp[i].push_back(rightChild[i]);
                root[rightChild[i]] = false;
            }
        }
        int r = -1;
        for(int i=0; i<n; i++){
            if(root[i] == true) r = i;
        }
        if(r == -1 || (leftChild[r]==-1 && rightChild[r]==-1 && n>1)) return false;
        vector<int> passed = {r};
        if(!solve(mp, passed, r, n)) return false;
        if(passed.size() != n) return false;
        return true;
    }
};