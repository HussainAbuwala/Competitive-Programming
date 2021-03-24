class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> m;
        vector<int> c;
        sort(candidates.begin(), candidates.end());
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
            
            for(int i = index; i < int(candidates.size()); i++){
                
                if(i == index || candidates[i] != candidates[i-1]){
                    comb.push_back(candidates[i]);
                    combSumAux(candidates, target - candidates[i],i + 1, comb,f);
                    comb.pop_back();
                }
                
            }
     
        }
        
    }

};