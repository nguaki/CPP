//Aug 7, 18
//POSTFIX evaluation which is a stack problem.
//The important part of the solution of utilizing string object.
//string class has member functions similar to vector.
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

int
iDoMath( stack<int> &st, char cOperator )
{
    int operand1, operand2;
    
    operand1 = st.top();
    st.pop();
    operand2 = st.top();
    st.pop();
   //Note that - and / operations, the operands are flipped. 
    switch(cOperator){
        case '+': return operand1 + operand2;
                    break;
        case '-': return operand2 - operand2;
                    break;
        case '*': return operand1 * operand2;
                    break;
        case '/': return operand2 / operand1;
                    break;
        default: break;
    }
}

int
iEvaluate( char *cpExpression )
{
    int i, j;
    stack<int> st;
    int iRes;
    string str; 
    for( i = 0; i < strlen(cpExpression); i++ )
    {
        if( cpExpression[i] >= '0' && cpExpression[i] <= '9' )
            str.push_back(cpExpression[i]);
        if( cpExpression[i] == ' ' ){
            //str.pop_back();    
            iRes = stoi(str);
            st.push(iRes);
            str.erase(); 
        } else if( cpExpression[i] == '+' || cpExpression[i] == '-' || cpExpression[i] =='*' || cpExpression[i] == '/'){
            if( str.size() > 0 ){
                //str.pop_back();    
                iRes = stoi(str);
                st.push(iRes);
                str.erase(); 
            }
            //Replace 2 operands with one result
            st.push(iDoMath(st, cpExpression[i]));
        }
    }
    
    return st.top();

}

int
main(void)
{
    char caExpression[] = "2 4+5 6+*4/";
    
    int iA = iEvaluate( (char *)caExpression );
    cout << iA;
    return 0;
}