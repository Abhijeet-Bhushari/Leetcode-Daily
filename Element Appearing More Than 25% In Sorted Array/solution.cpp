class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int k = ceil(arr.size()/(double)4);
        if(arr.size()%4 == 0) k++;
        int l = 0, r = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] == arr[i+1]){
                r++;
            }
            else{
                if(r - l + 1 >= k) return arr[i]; 
                l = i+1;
                r = i+1;
            }
        }
        return arr[arr.size()-1];
    }
};