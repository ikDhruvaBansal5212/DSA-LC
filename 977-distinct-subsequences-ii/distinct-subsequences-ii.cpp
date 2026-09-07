class Solution {
public:
    int distinctSubseqII(string s) {
        
        const long long MOD = 1e9 + 7;
        
        long long total = 0;
        long long end[26] = {0};
        
        for (char c : s) {
            
            int idx = c - 'a';
            
            // Number of new subsequences formed by adding c
            long long newSubseq = (total + 1) % MOD;
            
            // Remove duplicates created by previous occurrence of c
            total = (total + newSubseq - end[idx] + MOD) % MOD;
            
            // Update subsequences ending with c
            end[idx] = newSubseq;
        }
        
        return total;
    }
};