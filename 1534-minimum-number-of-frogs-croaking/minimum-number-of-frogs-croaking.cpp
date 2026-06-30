class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0;
        int frogs = 0;
        int ans = 0;

        for (char ch : croakOfFrogs) {

            if (ch == 'c') {
                c++;
                frogs++;
                ans = max(ans, frogs);
            }
            else if (ch == 'r') {
                if (c == 0) return -1;
                c--;
                r++;
            }
            else if (ch == 'o') {
                if (r == 0) return -1;
                r--;
                o++;
            }
            else if (ch == 'a') {
                if (o == 0) return -1;
                o--;
                a++;
            }
            else { // ch == 'k'
                if (a == 0) return -1;
                a--;
                frogs--;
            }
        }

        // If any frog hasn't finished saying "croak"
        if (c != 0 || r != 0 || o != 0 || a != 0)
            return -1;

        return ans;
    }
};