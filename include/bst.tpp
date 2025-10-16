#include <iostream>

namespace mystd {
    namespace {
        template <typename T>
        Node<T>* minNode(Node<T>* node) {
            if(node->left == nullptr) return node;
            return minNode(node->left);
        }

        template <typename T>
        Node<T>* maxNode(Node<T>* node) {
            if(node->right == nullptr) return node;
            return maxNode(node->right);
        }

        template <typename T>
        int sizeNode(Node<T>* node) {
            if (node == nullptr) return 0;
            return 1 + sizeNode(node->left) + sizeNode(node->right);
        }

        template <typename T>
        bool constainsNode(Node<T>* node, const T& value) {
            if (node == nullptr) return false;
            if (node->value == value) return true;
            return constainsNode(node->left, value) || constainsNode(node->right, value);
        }

        template <typename T>
        Node<T>* insertNode(Node<T>* node, const T& value) {
            if (node == nullptr) {
                Node<T>* newNode = new Node<T>();
                newNode->value = value;
                newNode->left = nullptr;
                newNode->right = nullptr;
                return newNode;
            }   

            if (node->value < value) {
                node->right = insertNode(node->right, value);
            }
            else if (node->value > value) {
                node->left = insertNode(node->left, value);
            }

            return node;
        }

        template <typename T>
        Node<T>* removeNode(Node<T>* node, const T& value) {
            if (node == nullptr) return nullptr;

            if (node->value < value) {
                node->right = removeNode(node->right, value);
            }
            else if (node->value > value) {
                node->left = removeNode(node->left, value);
            }
            else {
                if (node->left == nullptr && node->right == nullptr) {
                    delete node;
                    return nullptr;
                }
                else if (node->right == nullptr) {
                    Node<T>* temp = node->left;
                    delete node;
                    return temp;
                }
                else if (node->left == nullptr) {
                    Node<T>* temp = node->right;
                    delete node;
                    return temp;
                }
                else {
                    Node<T>* newNode = minNode(node->right);
                    node->value = newNode->value;
                    node->right = removeNode(node->right, newNode->value);
                }
            }

            return node;
         }

        template <typename T>
        void inorderNode(Node<T>* node, const std::function<void (const T&)>& visit) {
            if (node == nullptr) return;
            inorderNode(node->left, visit);
            visit(node->value);
            inorderNode(node->right, visit);
        }

        template <typename T>
        void preorderNode(Node<T>* node, const std::function<void (const T&)>& visit) {
            if (node == nullptr) return;
            visit(node->value);
            preorderNode(node->left, visit);
            preorderNode(node->right, visit);
        }

        template <typename T>
        void postorderNode(Node<T>* node, const std::function<void (const T&)>& visit) {
            if (node == nullptr) return;
            postorderNode(node->left, visit);
            postorderNode(node->right, visit);
            visit(node->value);
        }
    }

    template <typename T>
    void BSTree<T>::insert(const T& value) {
        root = insertNode(root, value);
    }

    template <typename T>
    void BSTree<T>::remove(const T& value) {
        root = removeNode(root, value);
    }

    template <typename T>
    bool BSTree<T>::contains(const T& value) {
        return constainsNode(root, value);
    }

    template <typename T>
    int BSTree<T>::size() {
        return sizeNode(root);
    }   

    template <typename T>
    bool BSTree<T>::empty() {
        return root == nullptr;
    }

    template <typename T>
    T BSTree<T>::min() {
        return minNode(root)->value;
    }

    template <typename T>
    T BSTree<T>::max() {
        return maxNode(root)->value;
    }

    template <typename T>
    void BSTree<T>::inorder(const std::function<void (const T&)>& visit) const {
        inorderNode(root, visit);
    }

    template <typename T>
    void BSTree<T>::preorder(const std::function<void (const T&)>& visit) const {
        preorderNode(root, visit);
    }

    template <typename T>
    void BSTree<T>::postrder(const std::function<void (const T&)>& visit) const {
        postrderNode(root, visit);
    }

    template <typename T>
    void BSTree<T>::clear(Node<T>* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
}