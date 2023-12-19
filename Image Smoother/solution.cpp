class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = 0, cells = 0;
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        int ni = i + k, nj = j + l;
                        if(ni>=0 &&ni<n && nj>=0 && nj<m){
                            sum += img[ni][nj]%256;
                            cells++;
                        }
                    }
                }
                img[i][j] += 256*(sum/cells);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                img[i][j] = img[i][j]/256;
            }
        }
        return img;
    }
};