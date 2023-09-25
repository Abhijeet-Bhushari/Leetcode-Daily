class Solution {
public:
    double champagneTower(int n, int r, int c) {
        vector<vector<double>> mat(r+2, vector<double>(r+2, 0));
        mat[0][0] = n;
        int i=0, j=0;
        
        for(int i=0; i<=r; i++){
            for(int j=0; j<=r; j++){
                double temp = (mat[i][j]-1)/2;
                if(temp>0){
                    mat[i][j+1] += temp;
                    mat[i+1][j] += temp;
                }
            }
        }
        return mat[r-c][c]>1?1:mat[r-c][c];
    }
};