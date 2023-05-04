class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
    if (k < 0) return 0;

    int count = 0;
    unordered_map<int,int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    for (auto it : freq) {
        if (k == 0) {
            if (it.second > 1) {
                count++;
            }
        } else if (freq.count(it.first + k)) {
            count++;
        }
    }

    return count;
}
};


// Intuition
// Using a hash table to store the frequency of each number in the array allows 
// for efficient lookups of a given number, specifically, if number+k exists. 
// Iterating through the array or hash table and check if a number+k exists, 
// then counting it if so, is effective as it only requires a single iteration over the array.

// Approach
// Use a hash table (unordered_map) to store the frequency of each number in
//  the array. Iterate through the array or the hash table, and chek if the nu
//  mber+k exists in the hash table. If it does exist, increment the count.
//   If k equals 0, check if the frequncy of the number is greater than 1, 
//   if so, increment the count. Return the count at the end.

