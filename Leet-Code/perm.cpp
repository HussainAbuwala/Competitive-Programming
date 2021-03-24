class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> perm;
        permute_aux(0,nums,perm,result);
        return result;
    }
    
    void permute_aux(int index, vector<int>& nums,vector<int> &perm, vector<vector<int>> &result){
        if(index == int(nums.size())){
            result.push_back(perm);
        }
        else{
            for (int i = index; i < int(nums.size()); i++) {
                swapInt(nums, i, index);
                perm.push_back(nums[index]);
                permute_aux(index + 1, nums, perm, result);
                swapInt(nums, i, index);
                perm.pop_back();
            }
        }
    }
    
    
    void swapInt(vector<int> &v, int i, int j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    
};