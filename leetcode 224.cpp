224. Basic Calculator
Hard
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
**code**//

class Solution {
public:
    int calculate(string s) {
       long long int sum=0;
        int sign=1;
        stack<pair<int,int>>st;
        for(int i=0;i<s.length();i++){
          char ch=s[i];
         long long  int num=0;
          if(isdigit(s[i])){
          while(i<s.length()&&isdigit(s[i])){
              num=num*10+s[i]-'0';
              i++;
          }
          i--;
          sum+=num*sign;
          sign=1;
        }
        else if(ch=='('){
            st.push(make_pair(sum,sign));
            sum=0;
            sign=1;
            
        }
        else if(ch==')'){
            sum=st.top().first+(st.top().second*sum);
            st.pop();
        }
        else if(ch=='-')
        sign=-1*sign;

        }
        return sum;
    }
};