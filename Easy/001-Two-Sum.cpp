//https://leetcode.com/problems/two-sum/
//Given an array of numbers, find the pair of numbers that adds up to the target.

//Brute Force Method.
//This is a simple method for looping through each element in the table, and then testing each other number until we find a pair of numbers that adds up to the target.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
        {
            for(int j= i+1; j<nums.size();j++)
            {
                if (nums[j] + nums[i] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Hash Table Solution
// Create a hash for the input vector of ints, and compare each value to it's complement. If the hash's complement already exists in the table (and it's not the input itself), then return the index, as well as it's complement.
// This method reduces the compute time significantly because you only have to traverse the entire input exactly two times: Once to hash each input, and once to check the complements.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i=0;i<nums.size();i++){
            hash[nums[i]] = i;
        }
        for (int i=0; i<nums.size();i++){
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }
    //if nothing valid is found, return and empty vector:
        return {};
    }
};

// Single Pass Hash Table Solution
// This is largely the same approach as the Hash Table Solution, but as each complement 
// is calculated, we look back at the map of values and if we find the complement already, 
// we return it and the index all in one go.
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }

        // Return an empty vector if no solution is found
        return {};
    }
};
