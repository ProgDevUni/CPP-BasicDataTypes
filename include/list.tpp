#include <iostream>

namespace mystd {
    namespace {
        template <typename T>
        void printNodeForward(Node<T>* node) {
            if (node == nullptr) return;
            std::cout<<node->value<<" ";
            printNodeForward(node->next);
        }

        template <typename T>
        void printNodeBackward(Node<T>* node) {
            if (node == nullptr) return;
            printNodeBackward(node->next);
            std::cout<<node->value<<" ";
        }
    }

    template <typename T>
    bool List<T>::empty() const {
        return count == 0;
    }

    template <typename T>
    size_t List<T>::size() const {
        return count;
    }

    template <typename T>
    void List<T>::pushFront(const T& value) {
        Node<T>* node = new Node<T>();
        node->value = value;
        node->next = head;
        this->head = node;
        count++;
    }

    template <typename T>
    void List<T>::pushBack(const T& value) {
        count++;
        if (head == nullptr) {
            Node<T>* node = new Node<T>();
            node->value = value;
            node->next = head;
            this->head = node;
            return;
        }

        Node<T>* cur = head;
        while (cur->next != nullptr){cur = cur->next;}

        Node<T>* node = new Node<T>();
        node->value = value;
        node->next = nullptr;
        cur->next = node;
    }

    template <typename T>
    void List<T>::insertAt(int index, const T& value) {
        count++;
        if (head == nullptr || index == 0) {
            Node<T>* node = new Node<T>();
            node->value = value;
            node->next = head;
            this->head = node;
            return;
        }

        int i = 0;
        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        while (i <= index-1) {
            i++;
            prev = cur;
            cur = cur->next;
        }

        Node<T>* node = new Node<T>();
        node->value = value;
        node->next = cur;
        prev->next = node;
    }

    template <typename T>
    void List<T>::removeFront() {
        if (head != nullptr) {
            head = head->next;
            count--;
        }
    }

    template <typename T>
    void List<T>::removeBack() {
        if (head != nullptr) {
            count--;
            Node<T>* cur = head;
            while (cur->next->next != nullptr) {
                cur = cur->next;
            }

            cur->next = nullptr;
        }
    }

    template <typename T>
    void List<T>::removeAt(int index) {
        if (head != nullptr) {
            count--;
            Node<T>* cur = head;
            int i = 0;
            while (i < index-1) {
                cur = cur->next;
                i++;
            }

            cur->next = cur->next->next;
        }
    }

    template <typename T>
    T& List<T>::getFront() {
        if (head != nullptr) {
            return head->value;
        }
    }

    template <typename T>
    T& List<T>::getBack() {
        if (head != nullptr) {
            Node<T>* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            return cur->value;
        }
    }

    template <typename T>
    T& List<T>::getAt(int index) {
        int i = 0;
        Node<T>* cur = head;
        while (i < index) {
            i++;
            cur = cur->next;
        }

        if (cur != nullptr) {
            return cur->value;
        }
    }

    template <typename T>
    int List<T>::find(const T& value) {
        Node<T>* cur = head;
        int i = 0;
        while (cur != nullptr) {
            if (cur->value == value) {
                return i;
            }
            i++;
            cur = cur->next;
        }

        return -1;
    }

    template <typename T>
    bool List<T>::contains(const T& value) {
        return find(value) != -1;
    }
    
    template <typename T>
    void List<T>::printForward() {
        printNodeForward(head);
        std::cout<<std::endl;
    }

    template <typename T>
    void List<T>::printBackward() {
        printNodeBackward(head);
        std::cout<<std::endl;
    }
}

/*
mystd::List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);

    list.insertAt(4, 100);

    list.printForward();
    std::cout<<list.size()<<std::endl;

    for (int i=-1;i<7;i++) {
        std::cout<<"I: " << i << " index: " << list.find(i) << std::endl;
    }

    std::cout<<list.getFront() << " " << list.getBack()  << " " << list.getAt(2) << std::endl;

    std::cout<<std::endl;
    list.removeFront();
    list.printForward();
    list.removeBack();
    list.printForward();
    list.removeAt(1);
    list.printForward();

    list.removeFront();
    list.removeFront();

    std::cout << list.empty() << std::endl;
*/