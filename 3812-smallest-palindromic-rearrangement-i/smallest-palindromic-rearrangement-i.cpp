class Solution {
public:
    string smallestPalindrome(string s) {
        int hash[26] = {0};
        int n = s.size();

        for(char c : s)
            hash[c - 'a']++;

        string res(n, ' ');

        int l = 0;
        int r = n - 1;

        // Place pairs
        for(int i = 0; i < 26; i++) {
            while(hash[i] >= 2) {
                res[l++] = char('a' + i);
                res[r--] = char('a' + i);
                hash[i] -= 2;
            }
        }

        // Place middle character (if any)
        for(int i = 0; i < 26; i++) {
            if(hash[i] == 1) {
                res[l] = char('a' + i);
                break;
            }
        }

        return res;
    }
};