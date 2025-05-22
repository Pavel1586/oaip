#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    string data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key, const string& data) {
    if (!root)
        return new Node{ key, data, nullptr, nullptr };
    if (key < root->key)
        root->left = insert(root->left, key, data);
    else if (key > root->key)
        root->right = insert(root->right, key, data);
    else
        root->data = data;
    return root;
}

void inorder(Node* root, int depth = 0) {
    if (!root) return;
    inorder(root->right, depth + 1);
    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << root->key << " " << root->data << endl;
    inorder(root->left, depth + 1);
}

Node* search(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    else return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

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
        Node* minNode = findMin(root->right);
        root->key = minNode->key;
        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->key);
    }
    return root;
}

int countAllNodes(Node* node) {
    if (!node) return 0;
    return 1 + countAllNodes(node->left) + countAllNodes(node->right);
}

int countAllRightBranchNodes(Node* node) {
    if (!node) return 0;

    int count = 0;

    if (node->right) count += 1;


    count += countAllRightBranchNodes(node->right);

    return count;
}

void menu() {
    cout << "1. Добавить узел\n";
    cout << "2. Поиск узла по ключу\n";
    cout << "3. Удалить узел по ключу\n";
    cout << "4. Подсчитать все узлы дерева\n";
    cout << "5. Вывести дерево (in-order)\n";
    cout << "6. Посчитать все узлы в правых ветвях\n";
    cout << "7. Выход\n";
    cout << "Выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Node* root = nullptr;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string data;
            cout << "Введите ключ (целое число): ";
            cin >> key;
            cout << "Введите строку данных: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, data);
            root = insert(root, key, data);
            break;
        }
        case 2: {
            int key;
            cout << "Введите ключ для поиска: ";
            cin >> key;
            Node* result = search(root, key);
            if (result)
                cout << "Найден узел: Ключ = " << result->key << ", Данные = " << result->data << endl;
            else
                cout << "Узел с таким ключом не найден.\n";
            break;
        }
        case 3: {
            int key;
            cout << "Введите ключ для удаления: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Узел удалён (если существовал).\n";
            break;
        }
        case 4:
            cout << "---------------------------------------\n";
            cout << "Всего узлов в дереве: " << countAllNodes(root) << endl;
            cout << "---------------------------------------\n";
            break;
        case 5:
            cout << "---------------------------------------\n";
            if (root) {
                cout << "Обход дерева:\n";
                inorder(root);
            }
            else {
                cout << "Дерево пустое.\n";
            }
            cout << "---------------------------------------\n";
            break;
        case 6:
            cout << "---------------------------------------\n";
            cout << "Количество всех узлов в правых ветвях: " << countAllRightBranchNodes(root) << endl;
            cout << "---------------------------------------\n";
            break;
        case 7:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Повторите.\n";
        }
    } while (choice != 7);

    return 0;
}


//50 "A"
//30 "B"
//70 "C"
//20 "D"
//40 "E"
//60 "F"
//80 "G"
//10 "H"
//45 "I"
//48 "K"
//90 "J"