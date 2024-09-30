class CustomStack {
    int size = 0, max_size = 0;
    int* stack;
    int* head = nullptr;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
        size = 0;
        stack = new int[maxSize];
    }
    
    void push(int x) {
        if (size < max_size)
        {
            if (size == 0)
                head = stack;
            else
                head++;
            
            *head = x;
            size++;
        }
    }
    
    int pop() {
        if (size == 0)
            return -1;
        
        size--;
        int return_val = *head;
        if (size == 0)
            head = nullptr;
        else
            head--;

        return return_val;
    }
    
    void increment(int k, int val) {
        if (head)
        {
            int* temp_pointer = head;
            temp_pointer = head - (size - 1);
            for (int i = 0; i < k && i < size; i++)
                *(temp_pointer + i) = *(temp_pointer + i) + val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */