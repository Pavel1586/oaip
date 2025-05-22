#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Добавление узла
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Поиск узла
Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    else return search(root->right, key);
}

// Минимальное значение в дереве (для удаления)
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// Удаление узла
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
        root->right = remove(root->right, temp->key);
    }
    return root;
}

// Подсчёт всех узлов
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Обход in-order
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Подсчёт левых дочерних вершин (не считая корень)
int countLeftChildren(Node* node) {
    if (!node) return 0;
    int count = 0;
    if (node->left) count += 1 + countLeftChildren(node->left);
    count += countLeftChildren(node->right);
    return count;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    Node* root = nullptr;
    int choice, key;
    while (true) {
        cout << "\n1. Добавить узел\n";
        cout << "2. Поиск узла по ключу\n";
        cout << "3. Удалить узел по ключу\n";
        cout << "4. Подсчитать все узлы дерева\n";
        cout << "5. Вывести дерево (in-order)\n";
        cout << "6. Подсчитать левые дочерние вершины\n";
        cout << "8. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите ключ: ";
            cin >> key;
            root = insert(root, key);
            break;
        case 2:
            cout << "Введите ключ для поиска: ";
            cin >> key;
            if (search(root, key)) cout << "Узел найден\n";
            else cout << "Узел не найден\n";
            break;
        case 3:
            cout << "Введите ключ для удаления: ";
            cin >> key;
            root = remove(root, key);
            break;
        case 4:
            cout << "Всего узлов: " << countNodes(root) << "\n";
            break;
        case 5:
            cout << "Дерево (in-order): ";
            inorder(root);
            cout << "\n";
            break;
        case 6:
            if (root)
                cout << "Количество левых дочерних вершин: " << countLeftChildren(root) << "\n";
            else
                cout << "Дерево пустое\n";
            break;
        case 8:
            return 0;
        default:
            cout << "Неверный выбор\n";
        }
    }
}