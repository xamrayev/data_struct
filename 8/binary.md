## Mavzu: Ikkilik daraxtlar va ularni C++ tilida realizatsiya qilish

## 1\. Darsning maqsadi

Ushbu darsda talabalar:

*   ikkilik daraxt tushunchasini bilib oladi;
*   tugun, ildiz, chap va o‘ng farzand tushunchalarini o‘rganadi;
*   C++ da oddiy ikkilik daraxt yaratishni o‘rganadi;
*   daraxt elementlarini ekranga chiqarish usullarini ko‘radi;
*   daraxtlarning amaliy qo‘llanilish sohalari bilan tanishadi.

---

## 2\. Nazariy qism

### 2.1. Daraxt nima?

**Daraxt** — bu ma’lumotlarni ierarxik ko‘rinishda saqlovchi tuzilma.

Masalan:

*   oilaviy shajara
*   papkalar tizimi
*   tashkilot strukturasi

Daraxtning eng yuqori qismi **ildiz** deyiladi.

---

### 2.2. Ikkilik daraxt nima?

**Ikkilik daraxt** — bu shunday daraxtki, har bir tugun ko‘pi bilan **2 ta farzandga** ega bo‘ladi:

*   chap farzand
*   o‘ng farzand

Masalan:

```
        10
       /  \
      5    15
     / \     \
    3   7     20
```

Bu yerda:

*   `10` — ildiz
*   `5` — 10 ning chap farzandi
*   `15` — 10 ning o‘ng farzandi
*   `3` va `7` — 5 ning farzandlari

---

### 2.3. Asosiy tushunchalar

**Tugun (node)** — daraxtning bitta elementi.  
**Ildiz (root)** — daraxtning boshlang‘ich tuguni.  
**Barg (leaf)** — farzandi yo‘q tugun.  
**Chap qism daraxt** — tugunning chap tomondagi daraxti.  
**O‘ng qism daraxt** — tugunning o‘ng tomondagi daraxti.

---

## 3\. C++ da ikkilik daraxtni yaratish

Ikkilik daraxtni yaratish uchun odatda `struct` yoki `class` ishlatiladi.

### 3.1. Tugun strukturasi

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
```

Bu yerda:

*   `data` — tugundagi qiymat
*   `left` — chap farzandga ko‘rsatkich
*   `right` — o‘ng farzandga ko‘rsatkich

---

## 4\. Yangi tugun yaratish

```cpp
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
```

Bu funksiya:

*   yangi xotira ajratadi
*   qiymatni joylaydi
*   chap va o‘ng ko‘rsatkichlarni `NULL` qiladi

---

## 5\. Oddiy ikkilik daraxtni qo‘lda qurish

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    Node* root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(15);

    root->left->left = createNode(3);
    root->left->right = createNode(7);

    root->right->right = createNode(20);

    cout << "Ikkilik daraxt yaratildi." << endl;

    return 0;
}
```

### Natijadagi daraxt:

```
        10
       /  \
      5    15
     / \     \
    3   7     20
```

---

## 6\. Daraxt elementlarini ekranga chiqarish

Daraxtni ko‘rish uchun uni traversal qilish kerak.

### 6.1. Inorder traversal

Tartib:

*   chap
*   ildiz
*   o‘ng

```cpp
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
```

Bizning daraxt uchun natija:

```
3 5 7 10 15 20
```

---

### 6.2. Preorder traversal

Tartib:

*   ildiz
*   chap
*   o‘ng

```cpp
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
```

Natija:

```
10 5 3 7 15 20
```

---

### 6.3. Postorder traversal

Tartib:

*   chap
*   o‘ng
*   ildiz

```cpp
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
```

Natija:

```
3 7 5 20 15 10
```

---

## 7\. To‘liq kod

Quyidagi kod oddiy va tushunarli ko‘rinishda yozilgan:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(20);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
```

---

## 8\. Kodning tushuntirishi

### `struct Node`

Har bir tugun uchun tuzilma yaratadi.

### `createNode(int value)`

Yangi tugun yaratadi va qiymat beradi.

### `inorder(root)`

Chap tomonni yurib chiqadi, keyin ildizni, so‘ng o‘ng tomonni.

### `preorder(root)`

Avval ildizni chiqaradi, keyin chap va o‘ng tomonlarni.

### `postorder(root)`

Avval chap va o‘ng tomonlarni ko‘radi, oxirida ildizni chiqaradi.

---

## 9\. Hayotda ishlatilish sohalari

Ikkilik daraxtlar nazariy mavzu bo‘lib qolmaydi, ular amaliyotda juda ko‘p ishlatiladi.

### 9.1. Qidiruv tizimlari

Ma’lumotlarni tez topish uchun **Binary Search Tree** ishlatiladi.

Misol:

*   lug‘atdagi so‘zni qidirish
*   telefon kitobidan ism topish
*   talabalar ro‘yxatidan ID bo‘yicha qidirish

---

### 9.2. Kompilyatorlar

Dasturlash tillaridagi ifodalarni tahlil qilishda daraxtlar ishlatiladi.

Misol:

```
a + b * c
```

Bunday ifoda daraxt shaklida saqlanishi mumkin.

---

### 9.3. Fayl va papkalar tizimi

Kompyuterdagi kataloglar tizimi daraxtsimon ko‘rinishda bo‘ladi.

Misol:

```
Disk
 ├── Darslar
 │    ├── C++
 │    └── Python
 └── Rasmlar
```

---

### 9.4. Sun’iy intellekt va o‘yinlar

Qaror qabul qilish jarayonlarida **decision tree** ishlatiladi.

Misol:

*   “agar baho yuqori bo‘lsa — grant”
*   “agar foydalanuvchi xato parol kiritsa — qayta urinsin”

---

### 9.5. Ma’lumotlar bazasi va indekslash

Ba’zi indekslash usullarida daraxtlardan foydalaniladi. Bu katta hajmdagi ma’lumotlarni tez topishga yordam beradi.

---

## 10\. Afzalliklari va kamchiliklari

### Afzalliklari

*   ma’lumotlarni tartibli saqlash mumkin;
*   qidirish qulay;
*   ierarxik ma’lumotlar uchun juda mos.

### Kamchiliklari

*   noto‘g‘ri qurilsa, qidirish sekinlashadi;
*   ko‘rsatkichlar bilan ishlash yangi o‘rganuvchilar uchun biroz qiyin.

---

## 11\. Amaliy topshiriqlar

### 1-topshiriq

Yuqoridagi kodni kompyuterda ishga tushiring.  
Natijada `inorder`, `preorder`, `postorder` natijalarini yozing.

---

### 2-topshiriq

Quyidagi daraxtni C++ da yarating:

```
        8
       / \
      4   12
     / \  / \
    2  6 10 14
```

Va uni `inorder` usulida ekranga chiqaring.

---

### 3-topshiriq

Kodga yangi funksiya qo‘shing: daraxtdagi barcha elementlar yig‘indisini toping.

Masalan:  
`10 + 5 + 15 + 3 + 7 + 20 = 60`

---

### 4-topshiriq

Daraxtdagi tugunlar sonini topuvchi funksiya yozing.

---

### 5-topshiriq

Daraxtdagi eng katta qiymatni topuvchi funksiya yozing.

---

### 6-topshiriq

Daraxtdagi barg tugunlarni ekranga chiqaruvchi funksiya yozing.

---

## 12\. Mustaqil ishlash uchun savollar

1.  Daraxt va ikkilik daraxt o‘rtasida qanday farq bor?
2.  Ildiz tugun nima?
3.  Barg tugun nima?
4.  Har bir tugun nechta farzandga ega bo‘lishi mumkin?
5.  `inorder`, `preorder`, `postorder` o‘rtasidagi farq nima?
6.  Nima uchun daraxtlar fayl tizimida qulay?
7.  Nima uchun ko‘rsatkichlar (`pointer`) daraxtlarda kerak bo‘ladi?

---

## 13\. Kichik uyga vazifa

Quyidagi vazifani bajaring:

*   foydalanuvchidan 5 ta son oling;
*   shu sonlardan oddiy daraxt hosil qiling;
*   barcha sonlarni `preorder` va `inorder` usullarida chiqaring.

---

## 14\. Xulosa

Ikkilik daraxt — bu ma’lumotlarni ierarxik ko‘rinishda saqlash uchun qulay tuzilma. Har bir tugun ko‘pi bilan 2 ta farzandga ega bo‘ladi. C++ da bunday daraxtlar odatda `struct` va `pointer` yordamida quriladi. Ikkilik daraxtlar qidiruv tizimlari, kompilyatorlar, fayl tizimlari va qaror qabul qilish tizimlarida keng qo‘llaniladi.

---