#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    bool isPossible(int sx, int sy, int fx, int fy, int t){
        if(max(abs(fx-sx), abs(fy- sy))==0 && t==1) return false;
        return max(abs(fx-sx), abs(fy- sy)) <= t;
    }
}