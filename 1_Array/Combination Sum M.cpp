class Solution {
public:
 vector<vector<int>> ans;

 void helper(vector<int>& C,int i,int target,vector<int>& sol)
 {
        if(target==0)
        {
            ans.push_back(sol);
            return;
        }
        if(target<0)
        return;

        //target is not 0,we dont have element to pick
        if(C.size()==i)
        return;

        //skip i element
        helper(C,i+1,target,sol); 
        sol.push_back(C[i]);
        //pick the i the element
        helper(C,i,target-C[i],sol);
        sol.pop_back();

 }
        
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> sol;
        helper(candidates,0,target,sol);
        return ans;
    }
};