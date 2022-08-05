#include <bits/stdc++.h>
using namespace std;

int precedence(char o) {
    if(o=='*'||o=='/') return 2;
    if(o=='+'||o=='-') return 1;
    return -1;
}

void infixToPostfix(string exp) {
    stack<char> st;
    char c;
    string result;
    for(int i=0; i<exp.length(); i++){
        c = exp[i];
        if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) result += c;

        else if (c == '(') st.push(c);

        else if(c==')') {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && precedence(c) != -1 && precedence(c) <= precedence(st.top())) 
            {
            result += st.top();
            st.pop();            
            }

            st.push(c);
        }

    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout<<result;

}

int main() {
    string exp;
    cin>>exp;
    infixToPostfix(exp);
    return 0;
}