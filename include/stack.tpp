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