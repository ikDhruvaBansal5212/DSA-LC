class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0;

        vector<vector<int>>psum(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum++;;
                if(matrix[i][j]=='0') sum=0;
                psum[i][j]=sum;
            }
        }

        for(int i=0;i<n;i++){
            res=max(res,largestRectangleArea(psum[i]));
        }
        return res;

    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxy=0;
        int n=heights.size();

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int h=heights[st.top()];
                st.pop();

                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }

                maxy=max(maxy,width*h);
            }
            st.push(i);
        }
        return maxy;
    }

};