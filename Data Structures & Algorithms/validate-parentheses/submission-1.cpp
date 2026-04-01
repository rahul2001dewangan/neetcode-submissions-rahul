class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (char i : s) {
            if (i == '(' || i == '{' || i == '[')
                par.push(i);
            else if (!par.empty()) {
                char t = par.top();
                par.pop();
                if ((i == ')' && t != '(') || (i == '}' && t != '{') ||
                    (i == ']' && t != '['))
                    return false;
            } else
                return false;
        }
        if (par.empty())
            return true;
        return false;
    }
};