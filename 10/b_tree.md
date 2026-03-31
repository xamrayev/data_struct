## Mavzu: B-daraxtlar va ularni C++ tilida realizatsiya qilish

---

## 1. Darsning maqsadi

Talabalar:

* B-daraxt tushunchasini o‘rganadi;
* oddiy ikkilik daraxtdan farqini tushunadi;
* B-daraxtda tugunlar qanday ishlashini biladi;
* C++ da oddiy B-daraxt (insert amali) yozishni o‘rganadi;
* real hayotdagi qo‘llanilishini tushunadi.

---

## 2. Nazariy qism

### 2.1. B-daraxt nima?

**B-daraxt (B-tree)** — bu **balanslangan ko‘p tarmoqli daraxt** bo‘lib, katta hajmdagi ma’lumotlar bilan ishlash uchun mo‘ljallangan.

Oddiy daraxtdan farqi:

| Oddiy ikkilik daraxt           | B-daraxt                         |
| ------------------------------ | -------------------------------- |
| Har tugunda 2 ta farzand       | Har tugunda ko‘p farzand         |
| Ko‘p chuqurlik bo‘lishi mumkin | Balanslangan (balandligi kichik) |
| RAM uchun qulay                | Disk / DB uchun juda qulay       |

---

### 2.2. B-daraxtning asosiy xususiyatlari

Agar **t = daraja (degree)** bo‘lsa:

* Har tugunda **kamida t-1 ta kalit** bo‘ladi
* Har tugunda **ko‘pi bilan 2t-1 ta kalit** bo‘ladi
* Farzandlar soni: `kalitlar soni + 1`
* Daraxt har doim **balanslangan**

---

### 2.3. Oddiy misol (t = 2)

```text
        [10]
       /    \
   [5,7]   [15,20]
```

Bu yerda:

* tugunda bir nechta qiymat saqlanadi
* daraxt chuqurligi kichik bo‘ladi

---

## 3. Qayerda ishlatiladi?

### 3.1. Ma’lumotlar bazasi (Database)

B-daraxtlar **indekslash** uchun ishlatiladi:

* MySQL
* PostgreSQL

Sabab:

* diskdan kam o‘qish kerak bo‘ladi
* qidirish tez

---

### 3.2. Fayl tizimlari

Operatsion tizimlarda:

* NTFS
* EXT4

Fayllarni tez topish uchun B-daraxt ishlatiladi.

---

### 3.3. Katta hajmdagi ma’lumotlar

Millionlab yozuvlar bo‘lsa:

* oddiy daraxt sekin ishlaydi
* B-daraxt tez ishlaydi

---

## 4. C++ da B-daraxt (oddiy realizatsiya)

Quyida **soddalashtirilgan B-daraxt (faqat insert + print)** keltiriladi.

---

## 4.1. Tugun (Node) strukturasi

```cpp
#include <iostream>
using namespace std;

const int T = 2; // daraja (minimum degree)

struct BTreeNode {
    int keys[2*T-1];   // kalitlar
    BTreeNode* children[2*T]; // farzandlar
    int n; // nechta kalit bor
    bool leaf; // bargmi yoki yo‘q

    BTreeNode(bool leaf) {
        this->leaf = leaf;
        n = 0;
    }
};
```

---

## 4.2. Daraxtni ko‘rsatish (print)

```cpp
void printTree(BTreeNode* root) {
    if (root == NULL) return;

    for (int i = 0; i < root->n; i++) {
        if (!root->leaf)
            printTree(root->children[i]);

        cout << root->keys[i] << " ";
    }

    if (!root->leaf)
        printTree(root->children[root->n]);
}
```

---

## 4.3. Tugunni bo‘lish (split)

```cpp
void splitChild(BTreeNode* parent, int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T-1; j++)
        z->keys[j] = y->keys[j+T];

    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j+T];
    }

    y->n = T - 1;

    for (int j = parent->n; j >= i+1; j--)
        parent->children[j+1] = parent->children[j];

    parent->children[i+1] = z;

    for (int j = parent->n-1; j >= i; j--)
        parent->keys[j+1] = parent->keys[j];

    parent->keys[i] = y->keys[T-1];
    parent->n++;
}
```

---

## 4.4. Insert (asosiy qism)

```cpp
void insertNonFull(BTreeNode* node, int k) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && k < node->keys[i]) {
            node->keys[i+1] = node->keys[i];
            i--;
        }

        node->keys[i+1] = k;
        node->n++;
    } else {
        while (i >= 0 && k < node->keys[i])
            i--;

        i++;

        if (node->children[i]->n == 2*T-1) {
            splitChild(node, i, node->children[i]);

            if (k > node->keys[i])
                i++;
        }

        insertNonFull(node->children[i], k);
    }
}
```

---

## 4.5. Asosiy insert funksiyasi

```cpp
BTreeNode* insert(BTreeNode* root, int k) {
    if (root == NULL) {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*T-1) {
        BTreeNode* s = new BTreeNode(false);
        s->children[0] = root;

        splitChild(s, 0, root);

        int i = 0;
        if (k > s->keys[0])
            i++;

        insertNonFull(s->children[i], k);

        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}
```

---

## 4.6. To‘liq main dastur

```cpp
int main() {
    BTreeNode* root = NULL;

    int arr[] = {10, 20, 5, 6, 12, 30, 7, 17};

    for (int i = 0; i < 8; i++) {
        root = insert(root, arr[i]);
    }

    cout << "B-daraxt (inorder): ";
    printTree(root);

    return 0;
}
```

---

## 5. Kod tushuntirishi (oddiy)

* `keys[]` — tugundagi qiymatlar
* `children[]` — farzand tugunlar
* `splitChild()` — tugun to‘lsa bo‘lib yuboradi
* `insert()` — yangi element qo‘shadi
* `printTree()` — daraxtni chiqaradi

---

## 6. Afzalliklari va kamchiliklari

### Afzalliklari

* juda tez qidiruv (O(log n))
* disk bilan ishlash uchun ideal
* balanslangan

### Kamchiliklari

* kod murakkabroq
* tushunish qiyinroq (boshlovchilar uchun)

---

## 7. Amaliy topshiriqlar

### 1-topshiriq

Kodni ishga tushiring va natijani yozing.

---

### 2-topshiriq

Quyidagi sonlarni kiriting:

```
1, 2, 3, 4, 5, 6, 7, 8, 9
```

Natijada daraxt qanday o‘zgarishini kuzating.

---

### 3-topshiriq

`printTree` funksiyasini o‘zgartirib:

* har bir darajani alohida qatorda chiqaring

---

### 4-topshiriq

Daraxtda **element bor yoki yo‘qligini tekshiruvchi** funksiya yozing.

---

### 5-topshiriq

Daraxtdagi **eng katta elementni toping**

---

### 6-topshiriq

Foydalanuvchidan N ta son olib:

* B-daraxt hosil qiling
* natijani chiqaring

---

## 8. Savollar

1. B-daraxt nima?
2. Nima uchun u balanslangan?
3. Nega DB lar B-daraxt ishlatadi?
4. `splitChild` nima qiladi?
5. B-daraxt va Binary tree farqi nima?

---

## 9. Uyga vazifa

* B-daraxt uchun **search (qidiruv)** funksiyasini yozing
* Daraxtdagi elementlar sonini hisoblang
* Daraxtni darajalar bo‘yicha chiqarishni yozing

---

## 10. Xulosa

B-daraxt — katta hajmdagi ma’lumotlar bilan ishlash uchun eng muhim tuzilmalardan biri. U disk asosida ishlaydigan tizimlarda (DB, fayl tizimlari) juda samarali. C++ da uni pointerlar va massivlar yordamida qurish mumkin.

