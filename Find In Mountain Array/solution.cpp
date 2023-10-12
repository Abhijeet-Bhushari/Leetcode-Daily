/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        int peak = 0;
        while(l <= r){
            int m = (l + r) / 2;
            if( ( m-1 >= 0 && mountainArr.get(m) > mountainArr.get(m - 1) ) && ( m + 1 < mountainArr.length() && mountainArr.get(m) > mountainArr.get(m + 1) ) ){
                peak = m;
                break;
            }
            else if(m - 1 >= 0 && mountainArr.get(m - 1) < mountainArr.get(m)) l = m + 1;
            else if(m == 0) l = m + 1;
            else r = m - 1;
        }
        if(target > mountainArr.get(peak)) return -1;
        l = 0; 
        r = peak;
        while(l<=r){
            int m = (l + r) / 2;
            if(mountainArr.get(m) == target) return m;
            else if(mountainArr.get(m) < target) l = m + 1;
            else r = m - 1;
        }
        l = peak; 
        r = mountainArr.length() - 1;
        while(l<=r){
            int m = (l + r) / 2;
            if(mountainArr.get(m) == target) return m;
            else if(mountainArr.get(m) < target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};