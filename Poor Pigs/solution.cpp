class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trails = minutesToTest / minutesToDie, pigs = 0;
        while(pow(trails + 1, pigs) < buckets) pigs++;
        return pigs;
    }
};