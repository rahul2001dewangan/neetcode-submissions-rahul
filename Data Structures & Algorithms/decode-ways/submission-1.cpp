class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0')
            return 0;
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            int c = 0;
            if (s[i - 1] != '0')
                c += b;
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num >= 10 && num <= 26)
                c += a;
            a = b;
            b = c;
        }
        return b;
    }
};