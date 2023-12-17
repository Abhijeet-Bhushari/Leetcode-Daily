class Compare {
public:
    bool operator()(pair<int, string> a, pair<int, string> b){
        if(a.first > b.first) return false;
        else if(a.first == b.first && a.second < b.second) return false;
        return true;
    }
};

class FoodRatings {
public:
    map<string, pair<int, string>> rc;
    map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>> rf;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            rc[foods[i]] = {ratings[i], cuisines[i]};
            rf[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    void changeRating(string food, int newRating) {
        pair<int, string> &rc_pair = rc[food];
        rc_pair.first = newRating;
        rf[rc_pair.second].push({newRating, food});
    }
    string highestRated(string cuisine) {
        pair<int, string> rf_pair = rf[cuisine].top();
        while(rf_pair.first != rc[rf_pair.second].first){
            rf[cuisine].pop();
            rf_pair = rf[cuisine].top();
        }
        return rf_pair.second;
    }
};