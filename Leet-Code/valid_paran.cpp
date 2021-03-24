class Solution {
public:
    //'(', ')', '{', '}', '[' and ']
    bool isValid(string s) {
        
        stack<char> stck;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stck.push(s[i]);
            }
            else{
                if(stck.empty() == true){
                    return false;
                }
                else if((stck.top() == '(' && s[i] == ')') ||
                        (stck.top() == '[' && s[i] == ']') ||
                        (stck.top() == '{' && s[i] == '}')){
                    
                    stck.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(stck.empty() == true){
            return true;
        }
        return false;
    }
    
};
