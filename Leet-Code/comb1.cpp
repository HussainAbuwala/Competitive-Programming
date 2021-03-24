class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> m;
        vector<int> c;
        combSumAux(candidates, target,0, c,m);
        return m;
    }
    
    void combSumAux(vector<int>& candidates, int target,int index, vector<int> &comb,vector<vector<int>> &f){
        
        if(target == 0){
            f.push_back(comb);
            return;
        }
        else if(target < 0){
            return;
        }
        else{
            
            if(index < int(candidates.size())){
                comb.push_back(candidates[index]);
                combSumAux(candidates, target - candidates[index],index, comb,f);
                comb.pop_back();
        
                combSumAux(candidates, target,index + 1, comb,f);
            }
            
        }
        
    }
};