class Solution {
public:
    int m,n;
    typedef long long ll;
    int mod=1e9+7; 
    vector<vector<pair<ll,ll>>>t;
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();


        /*t=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
        auto [maxprod,minprod]= solve(0,0,grid);
        if(maxprod<0){
            return -1;
        }
        return maxprod % mod;*/

        vector<vector<pair<ll,ll>>>t(m,vector<pair<ll,ll>>(n));
        //t[i][j]={maxval,minval} to reach from (0,0) to (i,j)
        t[0][0]={grid[0][0],grid[0][0]};

        //fill first row
        for(int j=1;j<n;j++){
            t[0][j].first=t[0][j-1].first * grid[0][j];
            t[0][j].second=t[0][j-1].second * grid[0][j];
        }

        //fill 1st column
        for(int i=1;i<m;i++){
            t[i][0].first=t[i-1][0].first * grid[i][0];
            t[i][0].second=t[i-1][0].second * grid[i][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=t[i-1][j].first;
                ll upmin=t[i-1][j].second;

                ll leftmax=t[i][j-1].first;
                ll leftmin=t[i][j-1].second;

                t[i][j].first=max({upmax*grid[i][j],upmin*grid[i][j],leftmin*grid[i][j],leftmax*grid[i][j]});
                t[i][j].second=min({upmax*grid[i][j],upmin*grid[i][j],leftmin*grid[i][j],leftmax*grid[i][j]});
            }
        }
        
        auto [maxprod,minprod]= t[m-1][n-1];
        if(maxprod<0){
            return -1;
        }
        return maxprod % mod;

    }




    ///
    /*pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }
        ll maxval=LLONG_MIN;
        ll minval=LLONG_MAX;
        if(t[i][j]!= make_pair(LLONG_MIN,LLONG_MAX)){
                return t[i][j];
        }
        //Down
        if(i+1<m){
        auto [downmax,downmin]=solve(i+1,j,grid);
        maxval=max({maxval,grid[i][j]*downmax,grid[i][j]*downmin});
        minval=min({minval,grid[i][j]*downmax,grid[i][j]*downmin});
        }

        //Right
        if(j+1<n){
        auto [rightmax,rightmin]=solve(i,j+1,grid);
        maxval=max({maxval,grid[i][j]*rightmax,grid[i][j]*rightmin});
        minval=min({minval,grid[i][j]*rightmax,grid[i][j]*rightmin});
        }

        return t[i][j]={maxval,minval};
    }*/
};