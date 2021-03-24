    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int len = int(height.size());
        int temp;
        for(int i = 0; i < len - 1; i++){
            
            for(int j = i + 1; j < len; j++){
                temp = getArea(height[i],height[j],i,j);
                if(maxArea < temp){
                    maxArea = temp;
                }
            }                         
        }
        return maxArea;
    }

    int maxArea(vector<int>& height) {
        
        int maxArea = INT_MIN;
        int len = int(height.size());
        int temp;
        int ptr1 = 0;
        int ptr2 = len - 1;
        
        while (ptr1 < ptr2){
            temp = getArea(height[ptr1],height[ptr2],ptr1,ptr2);
            if (maxArea < temp){
                maxArea = temp;
            }
            if(height[ptr1] >= height[ptr2]){
                ptr2--;
            }
            else{
                ptr1++;
            }
        }

        return maxArea;
    }
    
    int getArea(int h1,int h2,int index1,int index2){
        int heigthToUse;
        
        if(h1 == h2){
            heigthToUse = h1;
        }
        else if(h1 > h2){
            heigthToUse = h2;
        }
        else{
            heigthToUse = h1;
        }
        
        return heigthToUse * (index2 - index1);
        
    }