// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int calculate(char op, int num1, int num2)
{
    int res = 0;

    switch (op)
    {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num2 - num1;
        break;
    case '*':
        res = num1 * num2;
        break;
    case '/':
        res = num2 / num1;
        break;
    }
    return res;
}

bool hasPrecedence(char op1, char op2)
{
    if (op2 == ')' || op2 == '(')
    {
        return false;
    }

    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
    {
        return false;
    }
    return true;
}

int calculate(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }

    stack<int> nums;
    stack<char> ops;

    int i = 0;
    int num = 0;
    int n = s.length();

    while (i < n)
    {
        char c = s[i];

        if (isdigit(c))
        {
            num = c - '0';

            while (i + 1 < n && isdigit(s[i + 1]))
            {
                num = 10 * num + s[i + 1] - '0';
                ++i;
            }
            nums.push(num);
        }
        else if (isOperator(c))
        {
            while (!ops.empty() && hasPrecedence(c, ops.top()))
            {
                int x = nums.top();
                nums.pop();
                int y = nums.top();
                char ch = ops.top();
                ops.pop();
                nums.pop();
                nums.push(calculate(ch, x, y));
            }
            ops.push(c);
        }
        else if (c == '(')
        {
            ops.push(c);
        }
        else if (c == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int x = nums.top();
                nums.pop();
                int y = nums.top();
                char ch = ops.top();
                ops.pop();
                nums.pop();
                nums.push(calculate(ch, x, y));
            }
            ops.pop();
        }
        ++i;
    }

    while (!ops.empty())
    {
        int x = nums.top();
        nums.pop();
        int y = nums.top();
        char ch = ops.top();
        ops.pop();
        nums.pop();
        nums.push(calculate(ch, x, y));
    }

    return (nums.empty() ? 0 : nums.top());
}

int main()
{
    string s;
    cin >> s;
    cout << calculate(s);
}