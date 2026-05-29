class Solution {
public:
    int reverse(int x) {
         if (x <= INT_MIN) {
            return 0;
        }
        bool check=false;
        if(x<0){check=true;
        x=-x;}
        stack<int> st1;
        stack<int> st2;
        while(x>0){
            st1.push(x%10);
            x=x/10;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int res=0;
        while(!st2.empty()){
            int temp=st2.top();
            st2.pop();
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > INT_MAX % 10)){return 0;}
            res= res*10 + temp;  
        }

        if(check==true){
            return -res;
        }
        else
        return res;
    }
};