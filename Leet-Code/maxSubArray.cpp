int maxSubArrayBruteForce(vector<int>& nums) {
    int maxSum = nums[0];
    int temp = 0;
    for (int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            temp = findSum(nums, i, j);
            if(maxSum < temp){
                maxSum = temp;
            }
        }
    }
    return maxSum;
}

int findSum(vector<int> &num,int i, int j){
    int sum = 0;
    for (int m = i; m < j+1; m++){
        sum = sum + num[m];
    }
    return sum;
}



int maxSubArrayBFModification(vector<int> &nums){
    int maxSum = nums[0];
    int temp = 0;
    for (int i = 0; i < nums.size(); i++){
        temp = nums[i];
        if(maxSum < temp){
            maxSum = temp;
        }
        for(int j = i+1; j < nums.size(); j++){
            //cout<<i<<' '<<j<<endl;
            //print(nums, i,j);
            //temp = findSum(nums, i, j);
            temp = temp + nums[j];
            if(maxSum < temp){
                maxSum = temp;
            }
        }
    }
    return maxSum;
}

int maxCrossSubArray(int i, int mid, int j, vector<int> &nums){
    
    int leftSum = INT_MIN;
    int acc = 0;
    int k = mid;
    
    while(k >= i){
        acc = acc + nums[k];
        if(acc > leftSum)
            leftSum = acc;
        k--;
    }
    
    int rightSum = INT_MIN;
    acc = 0;
    int l = mid + 1;
    
    while(l <= j){
        acc = acc + nums[l];
        if(acc > rightSum)
            rightSum = acc;
        l++;
    }
    
    return leftSum + rightSum;
}


int findMssDC(vector<int> &v, int i, int j){
     
    if(i == j){
        return v[i];
    }
    else{
        int mid = (i + j) / 2;
        int leftSM = findMssDC(v, i, mid);
        int rightSM = findMssDC(v, mid + 1, j);
        int crossSM = maxCrossSubArray(i, mid, j, v);
        return max(max(leftSM,rightSM), crossSM);
    }
}

int MSS_aux(vector<int> &v){
    return findMssDC(v, 0, int(v.size()) - 1);
}