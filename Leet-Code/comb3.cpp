class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> comb;
        combAux(n,k,1, comb,result);
        return result;
    }
    
    void combAux(int target, int k, int index, vector<int> &comb, vector<vector<int>> &result){
        if(int(comb.size()) == k && target == 0){
            result.push_back(comb);
            return;
        }
        else if(int(comb.size()) == k && target!= 0){
            return;
        }
        else{
            for (int i = index; i < 10 ; i++) {
                comb.push_back(i);
                combAux(target - i,k, i + 1,comb,result);
                comb.pop_back();
                if(target - i <= 0)
                    break;
            }
        }
    }
};