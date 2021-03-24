void swapInt(vector<int> &v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void reverseV(vector<int> &nums,int i,int j){
    while (i < j){
        swapInt(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums) {
    
    int size = int(nums.size());
    int i = size - 2;
    
    while (i>=0 && nums[i] >= nums[i+1]){
        i--;
    }
    
    int j = size - 1;
    if(i>=0){
        while(j>=0 && nums[j] <= nums[i]){
            j--;
        }
        swapInt(nums, i,j);
    }
    reverseV(nums,i+1,size-1);
    
}

