#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int ctnopen = 0;
        int ctnopen1 = 0;
        int ctnopen2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if ( !st.empty()  && st.top() == '(' && s[i] == ')') {
                st.pop();
            } else if (!st.empty()&& st.top() == '{' && s[i] == '}') {
                st.pop();
            } else if (!st.empty()&&st.top() == '[' && s[i] == ']') {
                st.pop();
            } else {
                if (s[i] == ')') {
                    ctnopen++;
                } else if (s[i] == '}') {
                    ctnopen1++;
                } else if (s[i] == ']') {
                    ctnopen2++;
                }
            }
        }
        if (ctnopen > 0 || ctnopen1 > 0 || ctnopen2 > 0 || st.size() > 0) {
            return false;
        }
        return true;
    }
};