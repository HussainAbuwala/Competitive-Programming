class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = int(nums.size());
        k = k % len;
        reverse(nums,0,len - 1);
        reverse(nums,0,k-1);
        reverse(nums,k,len-1);
        
    }
    
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};