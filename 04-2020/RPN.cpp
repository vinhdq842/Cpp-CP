//
// Created by admin on 08/04/2020.
//

#include <bits/stdc++.h>

using namespace std;

char operators[] = {'(', ')', '+', '-', '*', '/'};

int getPriority(char);

bool in(char c);

string toRPN(string);

double evaluateRPN(string);

string refine(string);


int main() {
    string expr;
    getline(cin, expr);
    cout << evaluateRPN(toRPN(expr));
    return 0;
}

bool in(char c) {
    for (int i = 0; i < 6; i++)if (c == operators[i])return true;
    return false;
}

string toRPN(string s) {
    s = refine(s);
    stack<char> stack;
    string rpn = "";
    for (int i = 0; i < s.length(); ++i) {
        if (in(s[i])) {
            if (stack.empty() || s[i] == '(')stack.push(s[i]);
            else {
                while (!stack.empty() && stack.top() != '(' && getPriority(stack.top()) >= getPriority(s[i])) {
                    if (rpn.back() != ' ')rpn.push_back(' ');
                    rpn.push_back(stack.top());
                    stack.pop();
                }
                if (s[i] == ')')stack.pop();
                else stack.push(s[i]);
            }
        } else {
            if (s[i] == ' ') {
                if (rpn.length() > 0 && rpn.back() != ' ')rpn.push_back(s[i]);
            } else
                rpn.push_back(s[i]);
        }
    }
    while (!stack.empty()) {
        rpn.push_back(' ');
        rpn.push_back(stack.top());
        stack.pop();
    }
    return rpn;
}

double evaluateRPN(string expr) {
    stack<double> stack;
//    cout << expr;
    int j = 0;
    expr += " ";
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') {
            string part = expr.substr(j, i - j);
            if (in(part[0])) {
                double b = stack.top();
                stack.pop();
                double a = stack.top();
                stack.pop();
                switch (part[0]) {
                    case '+':
                        stack.push(a + b);
                        break;
                    case '-':
                        stack.push(a - b);
                        break;
                    case '*':
                        stack.push(a * b);
                        break;
                    case '/':
                        stack.push(a / b);
                        break;
                }
            } else stack.push(stod(part));
            j = i + 1;
        }
    }
    return stack.top();
}

string refine(string s) {
    string rs = "";
    for (int i = 0; i < s.length(); ++i)
        if (s[i] != ' ') {
            bool opt = false;
            switch (s[i]) {
                case '-':
                case '+':
                case '*':
                case '/':
                    opt = true;
                    rs += " ";
            }
            rs += s[i];
            if (opt)
                rs += " ";
        }
    return rs;
}

int getPriority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    return 0;
}