#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

struct stackItem
{
    char bracketType;
    int Index;
};

string isBalanced(string Expression)
{
    stack<stackItem> expressionStack;

    for (int i = 0; i < Expression.length(); i++)
    {
        if (Expression[i] == '[' || Expression[i] == '{' || Expression[i] == '(')
        {
            stackItem Item;
            Item.bracketType = Expression[i];
            Item.Index = i;
            expressionStack.push(Item);
        }
        else if (Expression[i] == ']' || Expression[i] == '}' || Expression[i] == ')')
        {
            if (expressionStack.empty())
                return to_string(i + 1);

            stackItem Top = expressionStack.top();
            expressionStack.pop();
            if ((Top.bracketType == '[' && Expression[i] != ']') || (Top.bracketType == '{' && Expression[i] != '}') || (Top.bracketType == '(' && Expression[i] != ')'))
                return to_string(i + 1);
        }
    }

    return (expressionStack.empty() ? "Success" : to_string(expressionStack.top().Index + 1));
}

int main()
{
    string Expression;
    getline(cin, Expression);
    cout << isBalanced(Expression) << endl;
    return 0;
}