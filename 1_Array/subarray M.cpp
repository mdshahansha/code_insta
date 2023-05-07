class Solution {
public:
     void helper(vector<int>& nums,int index,vector<int>& sub,vector<vector<int>>& ans){
         
         ans.push_back(sub);
         for(int i=index;i<nums.size();i++)
         {
             sub.push_back(nums[i]);
             helper(nums,i+1,sub,ans);
             sub.pop_back();
         }
         return;
         
     }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
vector<vector<int>> ans; 
        helper(nums,0,sub,ans);
        return ans;
    }
};