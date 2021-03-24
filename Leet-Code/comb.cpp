class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        combAux(n,k,1, comb,result);
        return result;
    }
    
    void combAux(int n, int k, int index, vector<int> &comb, vector<vector<int>> &result){
        if(int(comb.size()) == k){
            result.push_back(comb);
            return;
        }
        else{
            for (int i = index; i < n+1 ; i++) {
                comb.push_back(i);
                combAux(n,k, i + 1,comb,result);
                comb.pop_back();
            }
        }
    }
};