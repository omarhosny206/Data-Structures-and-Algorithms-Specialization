#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

// Check for digit.
bool isDigit(char Character)
{
    return (Character >= '0' && Character <= '9');
}

// Check for operator.
bool isOperator(char Character)
{
    return (Character == '+' || Character == '-' || Character == '*' || Character == '/');
}

// Check for the precedence of the operator.
int getPrecedence(char Character)
{
    return ((Character == '+' || Character == '-') ? 1 : (Character == '*' || Character == '/') ? 2 : 0);
}

// a function to perform the operator.
float performOperator(float Number1, float Number2, char Operator)
{

    switch (Operator)
    {
    case '+':
        return Number1 + Number2;
        break;
    case '-':
        return Number1 - Number2;
        break;
    case '*':
        return Number1 * Number2;
        break;
    case '/':
        return Number1 / Number2;
        break;
    default:
        return 0;
    }
}

// infix to postfix Function.
string infixToPosfix(string infixExpression)
{

    stack<char> Operators;         // a stack to store the operators.
    string postfixExpression = ""; // a string to store the postfix expression.
    int i = 0;                     // as a counter

    if (isOperator(infixExpression[0]))
    {
        postfixExpression += infixExpression[0];
        i = 1;
    }

    if (infixExpression[0] == '(' && infixExpression[1] == '-')
    {
        postfixExpression += infixExpression[1];
        i += 1;
        infixExpression[1] = '(';
    }

    for (i; i < infixExpression.size(); i++)
    {

        if (isDigit(infixExpression[i]))
        {

            if (isDigit(infixExpression[i + 1]))
                postfixExpression += infixExpression[i];

            else
            {
                postfixExpression += infixExpression[i];
                postfixExpression += " ";
            }
        }

        //            if (infixExpression[i] == '.' ) {
        //                postfixExpression += infixExpression[i];
        //            }

        else if (infixExpression[i] == '(')
            Operators.push(infixExpression[i]);

        else if (infixExpression[i] == ')')
        {
            // add all the values to the postfix expression till we reach to " ( ".
            while (Operators.top() != '(')
            {
                postfixExpression += Operators.top();
                postfixExpression += " ";
                Operators.pop();
            }

            // when we get " ( ", we need to remove it.
            Operators.pop();
        }

        // if the operator is [ +, -, *, / ]
        else
        {

            // we can't add the operator to the stack if its precedence is "<=" the top of the stack and if it isn't empty.
            while (!Operators.empty() && (getPrecedence(infixExpression[i]) <= getPrecedence(Operators.top())))
            {
                postfixExpression += Operators.top();
                postfixExpression += " ";
                // then we need to remove it.
                Operators.pop();
            }

            Operators.push(infixExpression[i]);
        }
    }

    // if there are some operators still present, we need to make them out.
    while (!Operators.empty())
    {
        postfixExpression += Operators.top();
        postfixExpression += " ";
        // then we need to remove it.
        Operators.pop();
    }

    // now at the end the postfix expression.
    return postfixExpression;
}

//Expression Evaluation Function.
float expressionEvaluation(string postfixExpression)
{
    stack<float> Numbers; // a stack to store the numbers.
    float pushedValue = 0;
    int i = 0;
    int Counter = 0, k = 1;

    if (Numbers.empty() && postfixExpression[0] == '-')
    {
        while (postfixExpression[k] != ' ')
        {
            Counter += 1;
            k++;
        }
        for (int m = 1; m < Counter + 1; m++)
        {
            pushedValue = (10 * pushedValue) + (postfixExpression[m] - '0');
        }

        Numbers.push(-1 * pushedValue);
        pushedValue = 0;
        i = Counter + 1;
    }

    //        if (postfixExpression)
    for (i; i < postfixExpression.size(); i++)
    {
        if (isDigit(postfixExpression[i]))
            pushedValue = (10 * pushedValue) + (postfixExpression[i] - '0');

        else
        {
            if (!isOperator(postfixExpression[i]) && pushedValue)
            {
                Numbers.push(pushedValue);
                pushedValue = 0;
            }
            else if (isOperator(postfixExpression[i]))
            {
                float Number2 = Numbers.top();
                Numbers.pop();
                float Number1 = Numbers.top();
                Numbers.pop();
                float pushedAnswer = performOperator(Number1, Number2, postfixExpression[i]);
                Numbers.push(pushedAnswer);
            }
        }
    }
    return Numbers.top();
}

int main()
{
    string Expression;
    getline(cin, Expression, '\n');
    cout << infixToPosfix(Expression) << endl;
    cout << expressionEvaluation(infixToPosfix(Expression)) << endl;
}

