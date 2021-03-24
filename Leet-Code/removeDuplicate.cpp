int removeDup(vector<int> &nums){
    
    int r(vector<int> &nums){
    if(nums.size() == 0){
        return 0;
    }
    
    int slowInd = 0;
    
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[slowInd]){
            continue;
        }
        else{
            nums[slowInd+1] = nums[i];
            slowInd = slowInd+1;
        }
    }
    
    return slowInd + 1;
    
    }
}