class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=0;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                index=i;
                break;
            }
        }
        int left=0;
        int right=index;
        while(left<right){
            char aux=word[left];
            word[left]=word[right];
            word[right]=aux;
            left++;
            right--;
        }
        return word;
    }
};