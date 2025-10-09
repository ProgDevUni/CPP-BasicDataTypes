namespace mystd {
    template <typename T>
    bool Stack<T>::empty() const{
        return data.empty();
    }
    
    template <typename T>
    std::size_t Stack<T>::size() const {
        return data.size();
    }

    template <typename T>
    void Stack<T>::push(const T& value) {
        data.push_back(value);
    }

    template <typename T>
    T& Stack<T>::peek() {
        if (!data.empty()) {
            return data.back();
        }
    }

    template <typename T>
    const T& Stack<T>::peek() const {
        if (!data.empty()) {
            return data.back();
        }
    }

    template <typename T>
    T& Stack<T>::pop() {
        if (!data.empty()) {
            T& res = data.back();
            data.pop_back();
            return res;
        }
    }
}

/*
    mystd::Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    for (int i=0;i<4;i++) {
        std::cout << stack.pop() << " ";
    }
    std::cout<<std::endl<<stack.empty()<<std::endl;
    stack.push(-13);
    stack.push(-45);
    stack.push(100);
    stack.push(12222);
    std::cout << stack.size() << " " << stack.peek();
*/