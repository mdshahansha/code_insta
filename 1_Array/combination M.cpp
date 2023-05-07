// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.


class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int idx, int k,vector<int>&current,int n)
    {
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<n+1;i++)
        {
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        helper(1,k,current,n);
        return ans; //return answer
    }
};

// Intuition: Since we are asked to calculate all the possible combinations , hence we have to use backtracking

// Concept: In every backtracking problem , there are two things to keep in mind , which we will explore here as well :

// Base Case: Every problem of backtracking has some base case which tells us at which point we have to stop with the recursion process. In our case, when the size of our array current equals to k i.e. current.size()=k, we stop with the recursion and add it to our final result ans.

// Conditions: There is just one thing to keep in mind here:
// After generating combinations corresponding to a particular number i , proceed to the next element by popping the element from the temporary array current, as we used that already.

// We basically consider a number i, generate the combinations corresponding to it by recursively calling it again, and then we pop that element as we are done with it and proceed to the next!!