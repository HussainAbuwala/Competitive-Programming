class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int fpos = findFirstPos(nums,target);
        if(fpos == -1){
            vector<int> result = {-1,-1};
            return result;
        }
        int lpos = findLastPos(nums,target);
        vector<int> result = {fpos,lpos};
        return result;
    
    }
    
    
    int findFirstPos(vector<int>& nums, int target){
        
        int low = 0;
        int high = int(nums.size()) - 1;
        int mid;
        int result = -1;
        while(low <= high){
            
            mid = (low + high) / 2;       
            if(target == nums[mid]){
                result = mid;
                high = mid - 1;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        return result;
    }
    
    int findLastPos(vector<int>& nums, int target){
        
        int low = 0;
        int high = int(nums.size()) - 1;
        int mid;
        int result = -1;
        while(low <= high){
            
            mid = (low + high) / 2;       
            if(target == nums[mid]){
                result = mid;
                low = mid + 1;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        return result;
    }
    
};



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int fpos = findFirstPos(nums,target);
        int lpos = findFirstPos(nums,target + 1) - 1;
        if(fpos <= lpos){
            return {fpos,lpos};
        }
        else{
            return {-1,-1};
        }
 
    
    }
    
    
    int findFirstPos(vector<int>& nums, int target){
        
        int low = 0;
        int high = int(nums.size()) - 1;
        int mid;
        int result = int(nums.size());
        
        while(low <= high){
            
            mid = (low + high) / 2;       
            if(nums[mid] >= target){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        return result;
    }
    
};