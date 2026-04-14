#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int error()
{
    std::cerr << "Error" << std::endl;
    return -1;
}

int RPN(std::string str)
{
    int counter = 0;
    std::stack<long> s;
    for (int i = 0; str[i]; i++)
    {
        char c = str[i];

        if (c == ' ')
            continue;
        else if (isdigit(c))
        {
            s.push(c - '0');
            counter++;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (s.size() < 2)
                return error();

            long num1 = s.top();
            s.pop();  
            long num2 = s.top();
            s.pop();
            if(num1  > 2147483647 || num2 > 2147483647  || num1 < -2147483648|| num1 <-2147483648)
                return error(); 
            if (c == '+') 
                s.push(num2 + num1);
            else if (c == '-') 
                s.push(num2 - num1);
            else if (c == '*') 
                s.push(num2 * num1);
            else if (c == '/')
            {
                if (num1 == 0)
                    return error();
                s.push(num2 / num1);
            }
        }
        else
            return error();
    }

    if (s.size() != 1  || counter == 1)
        return error();

    std::cout << s.top() << "\n";
    return 0;
}