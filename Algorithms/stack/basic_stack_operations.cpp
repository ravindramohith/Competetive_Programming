#include <bits/stdc++.h>
using namespace std;

void printStack(const std::stack<int> &myStack)
{
    std::stack<int> tempStack = myStack; // Create a copy of the original stack

    std::cout << "Contents of the stack: ";
    while (!tempStack.empty())
    {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::stack<int> stack1_equal, stack2_equal;

    stack1_equal.push(10);
    stack1_equal.push(20);
    stack1_equal.push(30);

    stack2_equal.push(10);
    stack2_equal.push(20);
    stack2_equal.push(30);

    // Example 2: Less than (<) comparison
    std::stack<int> stack1_less;

    stack1_less.push(10);
    stack1_less.push(20);

    std::stack<int> stack2_less;

    stack2_less.push(10);
    stack2_less.push(20);
    stack2_less.push(30);

    // Example 3: Greater than (>) comparison
    std::stack<int> stack1_greater;

    stack1_greater.push(10);
    stack1_greater.push(20);
    stack1_greater.push(30);

    std::stack<int> stack2_greater;

    stack2_greater.push(10);
    stack2_greater.push(20);

    // Example 4: Less than or equal to (<=) comparison
    std::stack<int> stack1_less_equal;

    stack1_less_equal.push(10);
    stack1_less_equal.push(20);

    std::stack<int> stack2_less_equal;

    stack2_less_equal.push(10);
    stack2_less_equal.push(20);
    stack2_less_equal.push(30);

    // Example 5: Greater than or equal to (>=) comparison
    std::stack<int> stack1_greater_equal;

    stack1_greater_equal.push(10);
    stack1_greater_equal.push(20);
    stack1_greater_equal.push(30);

    std::stack<int> stack2_greater_equal;

    stack2_greater_equal.push(10);
    stack2_greater_equal.push(20);

    // Perform comparisons
    if (stack1_equal == stack2_equal)
    {
        printStack(stack1_equal);
        printStack(stack2_equal);
        std::cout << "Stacks are equal." << std::endl
                  << "----------------------------------------------------------------\n";
    }

    if (stack1_less < stack2_less)
    {
        printStack(stack1_less);
        printStack(stack2_less);
        std::cout << "Stack1 is less than Stack2." << std::endl
                  << "----------------------------------------------------------------\n";
    }

    if (stack1_greater > stack2_greater)
    {
        printStack(stack1_greater);
        printStack(stack2_greater);
        std::cout << "Stack1 is greater than Stack2." << std::endl
                  << "----------------------------------------------------------------\n";
    }

    if (stack1_less_equal <= stack2_less_equal)
    {
        printStack(stack1_less_equal);
        printStack(stack2_less_equal);
        std::cout << "Stack1 is less than or equal to Stack2." << std::endl
                  << "----------------------------------------------------------------\n";
    }

    if (stack1_greater_equal >= stack2_greater_equal)
    {
        printStack(stack1_greater_equal);
        printStack(stack2_greater_equal);
        std::cout << "Stack1 is greater than or equal to Stack2." << std::endl
                  << "----------------------------------------------------------------\n";
    }

    return 0;
}