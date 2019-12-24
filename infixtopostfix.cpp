#include<bits/stdc++.h>
using namespace std;
bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}
int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return -1;
}
string infixToPostFix(string str) {
    stack<char> st;
    string res = "";
    for(char ch : str) {
        if(isAlpha(ch) || isDigit(ch)) {
            res += ch;
        } else if(ch == '(') {
            st.push(ch);
        } else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && precedence(ch) <= precedence(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostFix(exp) << endl;
    return 0;
}