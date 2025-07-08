class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if(isalpha(s[left]) && isalpha(s[right])  ){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }
            else if(!isalpha(s[left])){
             left++;
            }
            else{
                right--;
            }
        }
        return s;
    }
};