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
        int len = mountainArr.length();
        int l = 0, r = len - 1;
        int peak = 0;
        while(l <= r){
            int m = (l + r) / 2;
            int at_m = mountainArr.get(m), at_bm, at_am;
            if(m > 0) at_bm = mountainArr.get(m - 1);
            if(m < len - 1) at_am = mountainArr.get(m + 1);
            
            if( ( m-1 >= 0 && at_m > at_bm ) && ( m + 1 < len && at_m > at_am ) ){
                peak = m;
                break;
            }
            else if(m - 1 >= 0 && at_bm < at_m) l = m + 1;
            else if(m == 0) l = m + 1;
            else r = m - 1;
        }
        cout<<"peak: "<<peak<<endl;
        if(target > mountainArr.get(peak)) return -1;
        l = 0; 
        r = peak;
        while(l<=r){
            int m = (l + r) / 2;
            int at_m = mountainArr.get(m);
            if(at_m == target) return m;
            else if(at_m < target) l = m + 1;
            else r = m - 1;
        }
        l = peak; 
        r = len - 1;
        while(l<=r){
            int m = (l + r) / 2;
            int at_m = mountainArr.get(m);
            if(at_m == target) return m;
            else if(at_m < target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};