class Solution {
public:
    static bool myComp(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        else if(a[0]>b[0]) return false;
        else if(a[1]<b[1]) return true;
        return false;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> answer(people.size(), 0);
        vector<int> start(flowers.size()), endf(flowers.size());
        for(int i=0; i<flowers.size(); i++){
            start[i] = flowers[i][0];
            endf[i] = flowers[i][1];
        }
        sort(start.begin(), start.end());
        sort(endf.begin(), endf.end());
        sort(flowers.begin(), flowers.end(), myComp);
        for(int i=0; i<people.size(); i++){
            int bloomed = 0, rotted = 0;
            bloomed = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            rotted = lower_bound(endf.begin(), endf.end(), people[i]) - endf.begin();
            answer[i] = bloomed - rotted;
        }
        return answer;
    }
};