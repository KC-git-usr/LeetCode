// lesson learnt : careful of the if else statements

class MinStack {
private:
    list<int> my_stack;
    // maintain a min stack of (value, frequency)
    list<pair<int, int>> min_stack;
public:
    MinStack() {
    }

    void push(int val) {
        this->my_stack.push_back(val);
        // if min_stack is empty or new min ele found, add to min_stack
        if(min_stack.empty() || (val < this->min_stack.back().first)) {
            this->min_stack.push_back({val, 1});
        } else if(val == this->min_stack.back().first) // if same min value found, inc freq
            this->min_stack.back().second++;
    }

    void pop() {
        // if we're popping the min ele from my_stack, update min_stack too
        if(this->min_stack.back().first == this->my_stack.back()) {
            this->min_stack.back().second--;
            if(this->min_stack.back().second == 0)
                this->min_stack.pop_back();
        }
        this->my_stack.pop_back();
    }

    int top() {
        return this->my_stack.back();
    }

    int getMin() {
        return this->min_stack.back().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */