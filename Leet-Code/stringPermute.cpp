void permuteString(string &str, int i){
    
    if (i == str.length()){
        cout<<str<<endl;
    }
    else{
        for (int j = i; j < str.length(); j++){
            swap(str,i,j);
            permuteString(str, i + 1);
            swap(str,i,j);
        }
    }
}