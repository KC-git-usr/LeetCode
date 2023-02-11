class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> my_stack;

        int num_1, num_2;
        int result;
        for(const string& element : tokens) {
            // we found an operator
            if((element == "+") || (element == "-") || (element == "*") || (element == "/")) {
                num_1 = my_stack.top();
                my_stack.pop();
                num_2 = my_stack.top();
                my_stack.pop();
                if(element == "+")
                    result = num_2 + num_1;
                else if(element == "-")
                    result = num_2 - num_1;
                else if(element == "*")
                    result = num_2 * num_1;
                else if(element == "/")
                    result = num_2 / num_1;
            } else {
                result = stoi(element);
            }
            my_stack.push(result);
        }
        return my_stack.top();
    }
};