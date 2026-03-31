# 📘 1. B-daraxt

Tasavvur qiling:

👉 Oddiy daraxtda: 1 ta tugun = 1 ta qiymat
👉 B-daraxtda: 1 ta tugun = **bir nechta qiymat**

---

## Misol (t = 2)

```text
[10, 20]
```

Bu bitta tugun ichida 2 ta qiymat bor.

---

# 📘 2. Asosiy qoida (t = 2 uchun)

* max element: **3 ta (2t-1 = 3)**
* min element: **1 ta (t-1 = 1)**

---

# 📘 3. 1-qadam: Birinchi elementni qo‘shish

### Amal:

`10` ni qo‘shamiz

### Natija:

```text
[10]
```

---

### Kod

```cpp
// Tugun yaratish
BTreeNode* root = new BTreeNode(true);

// 1-element qo‘shish
root->keys[0] = 10;
root->n = 1; // nechta element bor
```

---

# 📘 4. 2-qadam: Oddiy qo‘shish (split yo‘q)

### Amal:

`20` ni qo‘shamiz

### Natija:

```text
[10, 20]
```

---

### Tushuntirish

* tugun to‘lmagan
* shunchaki qo‘shamiz va tartiblaymiz

---

### Kod

```cpp
// tugun barg bo‘lsa oddiy qo‘shamiz
int i = root->n - 1;

// o‘rnini topamiz
while (i >= 0 && 20 < root->keys[i]) {
    root->keys[i+1] = root->keys[i]; // o‘ngga suramiz
    i--;
}

// yangi element qo‘shamiz
root->keys[i+1] = 20;
root->n++;
```

---

# 📘 5. 3-qadam: Tugun to‘ladi

### Amal:

`5` ni qo‘shamiz

### Natija:

```text
[5, 10, 20]
```

---

### Tushuntirish

* hali ham joy bor (max 3 ta)
* tartib bilan joylashadi

---

### Kod

```cpp
int k = 5;
int i = root->n - 1;

// katta elementlarni o‘ngga suramiz
while (i >= 0 && k < root->keys[i]) {
    root->keys[i+1] = root->keys[i];
    i--;
}

// joyiga qo‘yamiz
root->keys[i+1] = k;
root->n++;
```

---

# 📘 6. 4-qadam: Eng muhim bosqich — SPLIT

### Amal:

`6` ni qo‘shamiz

### Oldin:

```text
[5, 10, 20]  (to‘la)
```

---

### Nima bo‘ladi?

Tugun to‘lgani uchun:

👉 uni **2 ga bo‘lamiz**

---

### Natija:

```text
        [10]
       /    \
    [5,6]   [20]
```

---

## Qanday bo‘lindi?

* o‘rtadagi element: `10` → yuqoriga chiqadi
* chap: `[5]`
* o‘ng: `[20]`
* keyin `6` chapga tushadi

---

# 📘 7. SPLIT kodi

```cpp
void splitChild(BTreeNode* parent, int i, BTreeNode* y) {
    // y - to‘lib ketgan tugun

    // yangi tugun yaratamiz
    BTreeNode* z = new BTreeNode(y->leaf);

    // o‘ng tomondagi elementlar z ga o‘tadi
    z->n = T - 1;

    for (int j = 0; j < T-1; j++)
        z->keys[j] = y->keys[j+T]; // o‘ng qismini olish

    // agar barg bo‘lmasa farzandlarni ham ko‘chiramiz
    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j+T];
    }

    // y da faqat chap qismi qoladi
    y->n = T - 1;

    // parentda joy ochamiz
    for (int j = parent->n; j >= i+1; j--)
        parent->children[j+1] = parent->children[j];

    // yangi tugunni ulaymiz
    parent->children[i+1] = z;

    // parentga o‘rtadagi elementni qo‘shamiz
    for (int j = parent->n-1; j >= i; j--)
        parent->keys[j+1] = parent->keys[j];

    parent->keys[i] = y->keys[T-1]; // middle element
    parent->n++;
}
```

---

# 📘 8. 5-qadam: Keyingi qo‘shish

### Amal:

`12` ni qo‘shamiz

---

### Qanday ishlaydi?

```text
        [10]
       /    \
   [5,6]   [20]
```

👉 12 > 10 → o‘ngga boradi

👉 `[20]` ga qo‘shiladi

---

### Natija:

```text
        [10]
       /    \
   [5,6]   [12,20]
```

---

### Kod

```cpp
// qaysi childga borishni aniqlaymiz
if (k > node->keys[i])
    i++;

// recursive insert
insertNonFull(node->children[i], k);
```

---

# 📘 9. To‘liq insert ishlash jarayoni

```cpp
void insertNonFull(BTreeNode* node, int k) {
    int i = node->n - 1;

    if (node->leaf) {
        // barg bo‘lsa oddiy qo‘shamiz
        while (i >= 0 && k < node->keys[i]) {
            node->keys[i+1] = node->keys[i]; // surish
            i--;
        }

        node->keys[i+1] = k;
        node->n++;
    } else {
        // qaysi childga boramiz
        while (i >= 0 && k < node->keys[i])
            i--;

        i++;

        // agar child to‘la bo‘lsa bo‘lamiz
        if (node->children[i]->n == 2*T-1) {
            splitChild(node, i, node->children[i]);

            // splitdan keyin yo‘nalishni tekshiramiz
            if (k > node->keys[i])
                i++;
        }

        insertNonFull(node->children[i], k);
    }
}
```

---

# 📘 10. Hayotiy tushuncha (eng oddiy)

B-daraxtni quyidagiga o‘xshatish mumkin:

### 📂 Kutubxona katalogi

* oddiy daraxt → har javonda 1 ta kitob
* B-daraxt → har javonda **bir nechta kitob**

👉 natija:

* kamroq yuriladi
* tez topiladi

---

# 📘 11. Nima uchun tez?

Oddiy daraxt:

```text
1 → 2 → 3 → 4 → 5 → 6
```

B-daraxt:

```text
[1,2,3] → [4,5,6]
```

👉 balandlik kichik → tez ishlaydi

---

# 📘 12. Amaliy topshiriqlar

### 1-topshiriq

Quyidagi ketma-ketlikni qo‘shib chiqing:

```
10, 20, 5, 6, 12
```

Har bosqichda daraxtni chizing.

---

### 2-topshiriq

t = 2 uchun:

```
1,2,3,4,5,6,7
```

qanday daraxt hosil bo‘ladi?

---

### 3-topshiriq

Kodga kommentariya qo‘shing:

* qayerda split bo‘ladi?
* qayerda recursion ishlaydi?

---

### 4-topshiriq

Search funksiyasini yozing:

```cpp
// element bor yoki yo‘q tekshiradi
```

---

### 5-topshiriq

Daraxt balandligini toping

---

# 📘 13. Xulosa

* B-daraxt — ko‘p qiymatli tugunli daraxt
* asosiy operatsiya — **split**
* har doim balanslangan
* DB va fayl tizimlarida ishlatiladi

---
