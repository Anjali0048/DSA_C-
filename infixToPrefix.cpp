#include<bits/stdc++.h>
using namespace std;

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

string infixToPrefix(string infix){

    stack<char> operators;
    stack<string> operands;

    for(int i=0; i<infix.length(); i++){

        if(infix[i] == '('){
            operators.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(!operators.empty() && operators.top()!='('){
                string op1 = operands.top();
                operands.pop();

                string op2 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                string tmp = op + op2 + op1;
                operands.push(tmp);

            }
            // pop opening brackets from stack
            operators.pop();
        }
         
        else if(isOperand(infix[i])){
            operands.push(string(1,infix[i]));
        }

        else{
            while(!operators.empty() && prec(infix[i])<=prec(operators.top())){
                string op1 = operands.top();
                operands.pop();

                string op2 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                string tmp = op + op2 + op1;
                operands.push(tmp);
            }
            operators.push(infix[i]);
        }
    }

    while(!operators.empty()) {
        string op1 = operands.top();
        operands.pop();

        string op2 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        string tmp = op + op2 + op1;
        operands.push(tmp);
    }
    return operands.top();

}

int main(){

    string s = "(A-B/C)*(A/K-L)";
    cout << "infix : " << s << endl;
    cout << "prefix : " << infixToPrefix(s) << endl;
    
    return 0;
}