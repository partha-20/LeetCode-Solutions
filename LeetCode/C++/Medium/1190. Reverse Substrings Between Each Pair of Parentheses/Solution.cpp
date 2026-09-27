class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> s1; string ans = "", suffix = "", prefix = "", rev = "";
        int store1 = -1, store2 = -1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ')') {store2 = i; break;}
            else suffix = s[i] + suffix;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '('){store1 = i; break;}
            else prefix += s[i];
        }
        for(int i = store1; i <= store2; i++){
            if(s[i] == '('){
                s1.push(s[i]);
            }
            else if(s[i] == ')'){
                while((s1.empty() == 0)){
                    if(s1.top() == '('){s1.pop(); break;}
                    ans += s1.top();
                    s1.pop();
                }
                if(i == store2) { rev = ans;}
                for(char ch : ans){
                    s1.push(ch);
                }
                
                ans = "";
            }
            else s1.push(s[i]);
        }
        
        return prefix + rev + suffix;
    }
};