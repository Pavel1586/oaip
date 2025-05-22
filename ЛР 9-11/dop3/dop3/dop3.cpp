#include <iostream>
using namespace std;

struct Node {
    int key;
    int value1, value2;
    Node* left;
    Node* right;
};

Node* createNode(int key, int value1, int value2) {
    Node* node = new Node{ key, value1, value2, nullptr, nullptr };
    return node;
}

Node* insert(Node* root, int key, int value1, int value2) {
    if (!root) return createNode(key, value1, value2);
    if (key < root->key)
        root->left = insert(root->left, key, value1, value2);
    else if (key > root->key)
        root->right = insert(root->right, key, value1, value2);
    return root;
}

Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* remove(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->value1 = temp->value1;
        root->value2 = temp->value2;
        root->right = remove(root->right, temp->key);
    }
    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << "Key: " << root->key << ", Values: " << root->value1 << ", " << root->value2 << "\n";
    inOrder(root->right);
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void findMaxSumNode(Node* root, Node*& maxNode, int& maxSum) {
    if (!root) return;
    int sum = root->value1 + root->value2;
    if (sum > maxSum) {
        maxSum = sum;
        maxNode = root;
    }
    findMaxSumNode(root->left, maxNode, maxSum);
    findMaxSumNode(root->right, maxNode, maxSum);
}

Node* removeMaxSumNode(Node* root) {
    Node* maxNode = nullptr;
    int maxSum = INT_MIN;
    findMaxSumNode(root, maxNode, maxSum);
    if (maxNode) {
        cout << "Удаляется узел с ключом: " << maxNode->key << " (макс. сумма " << maxSum << ")\n";
        root = remove(root, maxNode->key);
    }
    return root;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    Node* root = nullptr;
    int choice;
    while (true) {
        cout << "\n1. Добавить узел\n";
        cout << "2. Поиск узла по ключу\n";
        cout << "3. Удалить узел по ключу\n";
        cout << "4. Подсчитать все узлы дерева\n";
        cout << "5. Вывести дерево (in-order)\n";
        cout << "6. Удалить узел с максимальной суммой значений\n";
        cout << "8. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 1) {
            int key, v1, v2;
            cout << "Введите ключ, value1 и value2: ";
            cin >> key >> v1 >> v2;
            root = insert(root, key, v1, v2);
        }
        else if (choice == 2) {
            int key;
            cout << "Введите ключ: ";
            cin >> key;
            Node* result = search(root, key);
            if (result)
                cout << "Найден: " << result->key << " (" << result->value1 << ", " << result->value2 << ")\n";
            else
                cout << "Узел не найден\n";
        }
        else if (choice == 3) {
            int key;
            cout << "Введите ключ: ";
            cin >> key;
            root = remove(root, key);
        }
        else if (choice == 4) {
            cout << "Всего узлов: " << countNodes(root) << "\n";
        }
        else if (choice == 5) {
            inOrder(root);
        }
        else if (choice == 6) {
            root = removeMaxSumNode(root);
        }
        else if (choice == 8) {
            break;
        }
        else {
            cout << "Неверный выбор\n";
        }
    }
    return 0;
}