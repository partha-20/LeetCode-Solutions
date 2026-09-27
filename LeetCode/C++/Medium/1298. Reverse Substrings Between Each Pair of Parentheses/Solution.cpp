class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> s1; string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                s1.push(s[i]);
            }
            else if(s[i] == ')'){
                while((s1.empty() == 0)){
                    if(s1.top() == '('){s1.pop(); break;}
                    ans += s1.top();
                    s1.pop();
                }
                if(i == n - 1) { return ans;}
                for(char ch : ans){
                    s1.push(ch);
                }
                
                ans = "";
            }
            else s1.push(s[i]);
        }
        return "";
    }
};