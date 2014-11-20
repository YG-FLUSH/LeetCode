Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

1. create two stack 
2. push the min value into one stack while pushing each value into another stack;
3. when working, compare the inputted value with the top of the min stack, and push that value into the min stack if it is little;
4. pop from the second stack and check if it is the same with the min stack;
