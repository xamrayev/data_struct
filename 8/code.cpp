#include <iostream>
#include <algorithm>
using namespace std;

// 🔹 Tugun (Node) strukturasi
struct Node {
    int key;        // qiymat
    Node* left;     // chap farzand
    Node* right;    // o‘ng farzand
    int height;     // balandlik

    // Konstruktor
    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1; // yangi tugun balandligi 1
    }
};

// 🔹 Tugun balandligini olish
int height(Node* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

// 🔹 Maksimum qiymat
int getMax(int a, int b) {
    return (a > b) ? a : b;
}

// 🔹 Balance Factor hisoblash
int getBalance(Node* n) {
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

// 🔹 O‘ngga rotatsiya (Right Rotate) - LL holat
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotatsiya
    x->right = y;
    y->left = T2;

    // Balandliklarni yangilash
    y->height = getMax(height(y->left), height(y->right)) + 1;
    x->height = getMax(height(x->left), height(x->right)) + 1;

    return x; // yangi root
}

// 🔹 Chapga rotatsiya (Left Rotate) - RR holat
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotatsiya
    y->left = x;
    x->right = T2;

    // Balandliklarni yangilash
    x->height = getMax(height(x->left), height(x->right)) + 1;
    y->height = getMax(height(y->left), height(y->right)) + 1;

    return y; // yangi root
}

// 🔹 Insert (qo‘shish)
Node* insert(Node* root, int key) {

    // 1️⃣ Oddiy BST insert
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // duplicate yo‘q

    // 2️⃣ Height yangilash
    root->height = 1 + getMax(height(root->left), height(root->right));

    // 3️⃣ Balance aniqlash
    int balance = getBalance(root);

    // 4️⃣ Rotatsiya holatlari

    // 🔸 LL (Left Left)
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // 🔸 RR (Right Right)
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // 🔸 LR (Left Right)
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 🔸 RL (Right Left)
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 🔹 Inorder traversal (sorted chiqadi)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// 🔹 Daraxtni vizual chiqarish (simple)
void printTree(Node* root, int space = 0, int gap = 5) {
    if (root == nullptr)
        return;

    space += gap;

    // o‘ng subtree
    printTree(root->right, space);

    cout << endl;
    for (int i = gap; i < space; i++)
        cout << " ";
    cout << root->key << endl;

    // chap subtree
    printTree(root->left, space);
}

// 🔹 Main funksiyasi (test uchun)
int main() {
    Node* root = nullptr;

    // Test qiymatlar
    int values[] = {10, 20, 30, 40, 50, 25};

    cout << "Insert jarayoni:\n";

    for (int i = 0; i < 6; i++) {
        root = insert(root, values[i]);

        cout << "\nQo‘shildi: " << values[i] << endl;
        cout << "Inorder: ";
        inorder(root);

        cout << "\nDaraxt ko‘rinishi:\n";
        printTree(root);

        cout << "\n----------------------\n";
    }

    return 0;
}