#include <iostream>
#include <string>
#include <stack>

using namespace std;

string checkBracket(string input) {
   stack<char> stack;
   int size = input.size();
   for (int i = 0; i < size; i++) {
      char bracket = input.at(i);
      if (bracket == '(') {
         stack.push(bracket);
      }
      else {
         if (stack.size() == 0) {
            return "NO";
         }
         stack.pop();
      }
   }
   if (!stack.empty()) {
      return "NO";
   }
   else {
      return "YES";
   }
   
}

int main()
{
   string input_num;
   string input;
   string output;
   getline(cin, input_num);
   int num = stoi(input_num);
   while (num--) {
      getline(cin, input);
      output = output + checkBracket(input) + '\n';
   }
   cout << output;
    return 0;
}