class Solution {
public:
    vector<int> dp;  // A memoization table to store computed results for subproblems.
public:
    Solution(): dp(50, -1) {}  // Initialize the memoization table with -1 values.

    int solve(string &s, vector<string> &dictionary, int start, int cur) {
        if (start >= s.size()) return 0;  // Base case: If we've reached the end of the input string, return 0.

        int n, res, mn = INT_MAX;  // Variables to store various values.

        // Loop through the words in the dictionary to find a match.
        for (int i = 0; i < dictionary.size(); i++) {
            n = dictionary[i].size();  // Get the size of the current word in the dictionary.

            // Check if the substring of 's' starting at 'start' and of length 'n' matches the dictionary word.
            if (s.substr(start, n) == dictionary[i]) {
                // If we have a match, check if we've already computed the result for the next position.
                if (start + n < 50 && dp[start + n] >= 0)
                    res = dp[start + n];  // Use the memoized result if available.
                else
                    res = solve(s, dictionary, start + n, cur);  // Otherwise, recursively calculate it.

                mn = min(res, mn);  // Update the minimum result.
            }
        }

        res = 1 + solve(s, dictionary, start + 1, cur + 1);  // Try adding an extra character.
        mn = min(mn, res);  // Update the minimum result.

        dp[start] = mn;  // Memoize the result for the current position.
        return mn;  // Return the minimum result.
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        return solve(s, dictionary, 0, 0);  // Start the recursive solving process from the beginning of 's'.
    }
};
