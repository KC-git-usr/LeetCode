class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        unordered_map<char, char> hash_map {
                {')','('},
                {'}','{'},
                {']','['}
        };

        for(const char& bracket : s) {
            // character is a closing bracket
            if(hash_map.find(bracket) != hash_map.end()) {
                // stack is not empty and top of stack is corresponding opening bracket
                if(!(my_stack.empty()) && (my_stack.top() == hash_map[bracket]))
                    my_stack.pop();
                else
                    return false;
            } else {
                // character is opening bracket, so push to stack
                my_stack.push(bracket);
            }
        }
        return my_stack.empty();
    }
};