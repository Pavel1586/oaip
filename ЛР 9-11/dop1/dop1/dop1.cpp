#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Добавление узла
Node* addNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = addNode(root->left, key);
    else
        root->right = addNode(root->right, key);
    return root;
}

// Поиск узла
Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Найти минимум в дереве (для удаления)
Node* findMin(Node* node) {
    while (node->left) node = node->left;
    return node;
}

// Удаление узла
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
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
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Подсчет узлов
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// In-order обход
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// Подсчет листьев, которые являются правыми дочерними
int countRightLeaves(Node* root) {
    if (!root) return 0;
    int count = 0;
    if (root->right && !root->right->left && !root->right->right)
        count++;
    count += countRightLeaves(root->left);
    count += countRightLeaves(root->right);
    return count;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    Node* p1 = nullptr;
    int choice, key;

    do {
        cout << "\n1. Добавить узел\n";
        cout << "2. Поиск узла по ключу\n";
        cout << "3. Удалить узел по ключу\n";
        cout << "4. Подсчитать все узлы дерева\n";
        cout << "5. Вывести дерево (in-order)\n";
        cout << "6. Подсчитать правые листья\n";
        cout << "8. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите ключ: ";
            cin >> key;
            p1 = addNode(p1, key);
            break;
        case 2:
            cout << "Введите ключ для поиска: ";
            cin >> key;
            if (search(p1, key))
                cout << "Узел найден\n";
            else
                cout << "Узел не найден\n";
            break;
        case 3:
            cout << "Введите ключ для удаления: ";
            cin >> key;
            p1 = deleteNode(p1, key);
            break;
        case 4:
            cout << "Количество узлов: " << countNodes(p1) << endl;
            break;
        case 5:
            cout << "In-order обход: ";
            inOrder(p1);
            cout << endl;
            break;
        case 6:
            cout << "Правых листьев: " << countRightLeaves(p1) << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}
