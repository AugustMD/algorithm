#include <iostream>
#include <string>
#include <stack>

using namespace std;

int steelPipe(string input) {
    stack<int> stack;
    int input_size = input.size();
    int old_top;
    int sum = 0;
    char bracket;

    for(int i = 0; i < input_size; i++) {
        bracket = input.at(i);

        if(bracket == '(') {
            stack.push(i);
        } else {
            if(stack.size() == 0) {
                return -1;
            }
            old_top = stack.top();
            stack.pop();
            if(i - old_top == 1) {
                sum = sum + stack.size();
            } else {
                sum = sum + 1;
            }
        }
    }

    if(!stack.empty()) {
        return -1;
    } else {
        return sum;
    }
}

int main() {
    string input;
    getline(cin, input);
    int output = steelPipe(input);
    if(output == -1) {
        cout << "error" << '\n';    
    } else {
        cout << output << '\n';
    }

    return 0;
}