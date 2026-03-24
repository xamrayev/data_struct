# 📘 9-dars: AVL daraxti (bosqichma-bosqich)

## 🔹 1. AVL daraxti nima?

AVL daraxti — bu **balanslangan BST (Binary Search Tree)**.

Oddiy BST muammo:

*   Agar elementlar tartib bilan qo‘shilsa → daraxt **linked list** ga o‘xshab qoladi
*   Murakkablik: **O(n)**

AVL yechim:

*   Har doim balansni saqlaydi
*   Murakkablik: **O(log n)**

---

## 🔹 2. Balance Factor (Balans faktori)

Har tugun uchun:

BF = H\_{left} - H\_{right}

Shart:

*   BF ∈ {-1, 0, 1} → OK
*   Aks holda → rotatsiya kerak

---

## 🔹 3. Rotatsiyalar (Sxematik tushuncha)

### 1️⃣ LL (Right Rotation)

```
    y                x
   /                / \
  x      →         T1  y
 / \                  / \
T1 T2                T2 T3
```

---

### 2️⃣ RR (Left Rotation)

```
  x                  y
   \                / \
    y     →        x  T3
   / \            / \
  T2 T3          T1 T2
```

---

### 3️⃣ LR (Left + Right)

```
    z               z              x
   /               /              / \
  y      →        x      →       y   z
   \             /
    x           y
```

---

### 4️⃣ RL (Right + Left)

```
  z               z               x
   \               \             / \
    y     →         x     →     z   y
   /                 \
  x                   y
```

---

## 🔹 4. C++ da bosqichma-bosqich realizatsiya

---

## ✅ Qadam 1: Node struktura

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};
```

📌 Natija:

Har tugun:

*   qiymat
*   2 ta farzand
*   balandlik

---

## ✅ Qadam 2: Height funksiyasi

```cpp
int height(Node* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}
```

📌 Natija:

*   Har tugun balandligini olish mumkin

---

## ✅ Qadam 3: Balance Factor

```cpp
int getBalance(Node* n) {
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}
```

📌 Natija:

*   Tugun balanslangan yoki yo‘q aniqlanadi

---

## ✅ Qadam 4: Oddiy BST insert

```cpp
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        Node* node = new Node{key, nullptr, nullptr, 1};
        return node;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}
```

📌 Natija:

*   Oddiy BST hosil bo‘ladi (hali balans yo‘q)

---

## ✅ Qadam 5: Height yangilash

```cpp
root->height = 1 + max(height(root->left), height(root->right));
```

📌 Natija:

*   Har insertdan keyin balandlik to‘g‘ri hisoblanadi

---

## ✅ Qadam 6: Oddiy rotatsiya (Right Rotate)

```cpp
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}
```

📌 Natija:

*   LL muammo hal qilinadi

---

## ✅ Qadam 7: Balansni tekshirish

```cpp
int balance = getBalance(root);
```

📌 Natija:

*   Qaysi rotatsiya kerakligi aniqlanadi

---

## ✅ Qadam 8: LL holatni tuzatish

```cpp
if (balance > 1 && key < root->left->key)
    return rightRotate(root);
```

📌 Natija:

*   Chap-cho‘qqi og‘ish tuzatiladi

---

## 🔜 Keyingi darsda qo‘shiladi:

*   RR rotatsiya
*   LR va RL rotatsiya
*   Delete operatsiyasi

---

# 🔹 5. BST vs AVL

| Xususiyat | BST | AVL |
| --- | --- | --- |
| Balans | Yo‘q | Bor |
| Murakkablik | O(n) | O(log n) |
| Tezlik | Ba’zida sekin | Doim tez |
| Implementatsiya | Oddiy | Murakkabroq |

---

# 🔹 6. Qayerda ishlatiladi?

AVL daraxti ishlatiladi:

*   Database indexing
*   Memory management
*   Search engine
*   Compiler (symbol table)

---

# 🧠 Talabalar uchun topshiriq

### 📝 1. Nazariy savollar

1.  Balance factor nima?
2.  Nima uchun AVL tezroq?
3.  4 xil rotatsiyani tushuntiring

---

### 💻 2. Kod topshiriq

Yuqoridagi kodni yozing

5 ta son qo‘shing:

Har qo‘shishda:

*   height ni chiqaring
*   balance ni chiqaring

---

### 🔥 3. Challenge

*   RR rotatsiyani yozing
*   Daraxtni chizib ko‘rsating (qo‘lda)

---

### ⭐ Bonus

*   AVL daraxtni ekranga chiqarish (inorder)

---

```
10, 20, 30, 40, 50
```