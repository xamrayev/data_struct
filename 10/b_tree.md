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

-Zo‘r tayyorlangan konspekt — endi uni **didaktik jihatdan kuchaytiramiz**:
👉 har bir asosiy operatsiyada **strukturali `cout` loglar** qo‘shamiz, shunda talabalar **daraxt ichida nima bo‘layotganini real vaqt rejimida ko‘radi**.

Quyida siz bergan kodingiz **debug / tushuntiruvchi versiya**ga aylantirildi.

---

# 📘 4. C++ da B-daraxt (STEP-BY-STEP LOG bilan)

## 🔹 4.1. Tugun (Node)

```cpp
#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;              // kalitlar
    vector<BTreeNode*> children;   // bolalar
    bool isLeaf;                   // bargmi?
    int t;                         // daraja

    BTreeNode(int t, bool isLeaf) {
        this->t = t;
        this->isLeaf = isLeaf;
    }
};
```

---

# 🔹 4.2. Daraxtni chiqarish (inorder + log)

```cpp
void printTree(BTreeNode* root) {
    if (root == NULL) return;

    cout << "[Node: ";
    for (int k : root->keys)
        cout << k << " ";
    cout << "]\n";

    for (int i = 0; i < root->children.size(); i++) {
        cout << " -> child " << i << ":\n";
        printTree(root->children[i]);
    }
}
```

---

# 🔹 4.3. SPLIT — eng muhim qism (to‘liq log bilan)

```cpp
void splitChild(BTreeNode* parent, int i) {
    BTreeNode* y = parent->children[i];

    cout << "\n[SPLIT BOSHLANDI]\n";
    cout << "Parent node: ";
    for (int k : parent->keys) cout << k << " ";
    cout << "\nSplit qilinayotgan child: ";
    for (int k : y->keys) cout << k << " ";
    cout << endl;

    BTreeNode* z = new BTreeNode(y->t, y->isLeaf);

    // o‘ng qismini olish
    for (int j = y->t; j < y->keys.size(); j++)
        z->keys.push_back(y->keys[j]);

    int middle = y->keys[y->t - 1];

    // chap qismini saqlab qolamiz
    y->keys.resize(y->t - 1);

    // agar barg bo‘lmasa farzandlarni ham bo‘lamiz
    if (!y->isLeaf) {
        for (int j = y->t; j < y->children.size(); j++)
            z->children.push_back(y->children[j]);

        y->children.resize(y->t);
    }

    // parentga qo‘shamiz
    parent->children.insert(parent->children.begin() + i + 1, z);
    parent->keys.insert(parent->keys.begin() + i, middle);

    cout << "O‘rtadagi element yuqoriga chiqdi: " << middle << endl;

    cout << "Chap child: ";
    for (int k : y->keys) cout << k << " ";
    cout << "\nO‘ng child: ";
    for (int k : z->keys) cout << k << " ";
    cout << "\n[SPLIT TUGADI]\n";
}
```

---

# 🔹 4.4. Insert (log bilan)

```cpp
void insertNonFull(BTreeNode* node, int k) {
    cout << "\n[INSERT NON FULL] k = " << k << endl;

    int i = node->keys.size() - 1;

    // Agar barg bo‘lsa
    if (node->isLeaf) {
        cout << "Barg tugun. Oddiy qo‘shish...\n";

        node->keys.push_back(0); // joy ochamiz

        while (i >= 0 && k < node->keys[i]) {
            node->keys[i+1] = node->keys[i];
            i--;
        }

        node->keys[i+1] = k;

        cout << "Natija: ";
        for (int x : node->keys) cout << x << " ";
        cout << endl;

    } else {
        cout << "Ichki tugun. Qaysi childga tushishini aniqlaymiz...\n";

        while (i >= 0 && k < node->keys[i])
            i--;

        i++;

        cout << "Tanlangan child index: " << i << endl;

        // agar child to‘la bo‘lsa
        if (node->children[i]->keys.size() == 2*node->t - 1) {
            cout << "Child to‘la → split qilamiz\n";

            splitChild(node, i);

            if (k > node->keys[i]) {
                i++;
                cout << "O‘ng childga o‘tdi\n";
            }
        }

        insertNonFull(node->children[i], k);
    }
}
```

---

# 🔹 4.5. Asosiy insert (log bilan)

```cpp
BTreeNode* insert(BTreeNode* root, int k, int t) {

    cout << "\n=========================\n";
    cout << "INSERT: " << k << endl;

    // agar daraxt bo‘sh bo‘lsa
    if (root == NULL) {
        cout << "Yangi root yaratilmoqda\n";

        root = new BTreeNode(t, true);
        root->keys.push_back(k);

        return root;
    }

    // root to‘la bo‘lsa
    if (root->keys.size() == 2*t - 1) {
        cout << "Root to‘la → yangi root + split\n";

        BTreeNode* s = new BTreeNode(t, false);
        s->children.push_back(root);

        splitChild(s, 0);

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

# 🔹 4.6. MAIN (to‘liq jarayonni ko‘rish)

```cpp
int main() {
    int t = 2;
    BTreeNode* root = NULL;

    int arr[] = {10, 20, 5, 6, 12, 30, 7, 17};

    for (int i = 0; i < 8; i++) {
        root = insert(root, arr[i], t);

        cout << "\n--- HOZIRGI DARAxt ---\n";
        printTree(root);
        cout << "----------------------\n";
    }

    return 0;
}
```

---

# 📘 5. Talaba nimani ko‘radi (MUHIM)

Dastur ishlaganda quyidagilar chiqadi:

### 🔹 Misol:

```text
INSERT: 6
Child to‘la → split qilamiz

[SPLIT BOSHLANDI]
Split qilinayotgan child: 5 10 20
O‘rtadagi element yuqoriga chiqdi: 10
Chap child: 5
O‘ng child: 20
[SPLIT TUGADI]
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

# 📘 Qo‘shimcha topshiriqlar (log asosida)

### 🔹 1-topshiriq

Loglardan foydalanib yozing:

👉 qaysi insertda split bo‘ldi?

---

### 🔹 2-topshiriq

Har bir bosqichdan keyin:

👉 daraxtni qo‘lda chizing

---

### 🔹 3-topshiriq

Logni kengaytiring:

```cpp
cout << "Hozir node darajasi: ???";
```

---

### 🔹 4-topshiriq

Search funksiyasiga ham log qo‘shing:

```cpp
cout << "Qidirilmoqda: " << k << endl;
```

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

