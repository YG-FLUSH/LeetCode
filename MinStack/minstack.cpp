#include <iostream>
#include <stack>

class MinStack {
public:
    void push(int x) {
		if(minstack.empty()||minstack.top()>=x)
		{
			minstack.push(x);
		}
			realstack.push(x);	
    }

    void pop() {
        if(realstack.empty()||minstack.empty()) return ;
		if(realstack.top()==minstack.top()) 
		{
			minstack.pop();
		}
		realstack.pop();
    }

    int top() {
        return realstack.top();
    }

    int getMin() {
        if(realstack.empty()||minstack.empty()) return 0;
		return minstack.top();
    }
	private:
	std::stack<int> minstack;
	std::stack<int> realstack;
};
int main()
{
	MinStack minstack;
	minstack.push(2);
	minstack.push(3);
	minstack.push(1);
	std::cout << minstack.getMin()<<std::endl;
	minstack.pop();
	std::cout << minstack.getMin()<<std::endl;	
	minstack.pop();
}