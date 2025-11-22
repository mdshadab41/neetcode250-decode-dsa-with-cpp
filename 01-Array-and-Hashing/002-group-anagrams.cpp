#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // step 1: create an empty hasmap
        unordered_map<string, vector<string>> anagramGroups;

        // step 2: process each string in the input array
        for (const string &str : strs)
        {

            // step 2a: make a copy of string and sort it
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // step 2b: add the original string to its anagram group
            // If key doesn't exist, it's automatically created
            anagramGroups[sortedStr].push_back(str);
        }

        // step 3: extract all groups from the hasmap
        vector<vector<string>> result;
        for (auto &pair : anagramGroups)
        {
            result.push_back(pair.second);
        }

        // step 4: Return the final result
        return result;
    }
};

int main()
{
    Solution sol;

    vector<string> strs1 = {"act", "pots", "tops", "cats", "stop", "hat"};

    vector<vector<string>> ans = sol.groupAnagrams(strs1);

    for (auto &group : ans)
    {
        cout << "[ ";
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]\n";
    }
}