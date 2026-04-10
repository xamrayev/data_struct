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

class BTreeNode {  // B-daraxt tuguni sinfini aniqlash
public:
    vector<int> keys;              // Tugundagi kalitlarni saqlash uchun vektor
    vector<BTreeNode*> children;   // Tugunning farzand tugunlariga pointerlar
    bool isLeaf;                   // Tugun barg tugunmi yoki ichki tugunmi
    int t;                         // B-daraxtning darajasi (degree)

    BTreeNode(int t, bool isLeaf) {  // Konstruktor: yangi tugun yaratish
        this->t = t;                   // Darajani o'rnatish
        this->isLeaf = isLeaf;         // Barg ekanligini belgilash
    }
};
```

---

# 🔹 4.2. Daraxtni chiqarish (inorder + log)

```cpp
void printTree(BTreeNode* root) {  // Daraxtni ekranga chiqarish funksiyasi
    if (root == NULL) return;  // Agar ildiz null bo'lsa, hech narsa qilmaymiz

    cout << "[Node: ";  // Tugun boshlanishini ko'rsatish
    for (int k : root->keys)  // Tugundagi barcha kalitlarni chiqarish
        cout << k << " ";  // Kalitni probel bilan ajratib chiqarish
    cout << "]\n";  // Tugun oxirini yopish

    for (int i = 0; i < root->children.size(); i++) {  // Barcha farzandlarni aylanib chiqish
        cout << " -> child " << i << ":\n";  // Farzand indeksini ko'rsatish
        printTree(root->children[i]);  // Rekursiv ravishda farzandni chiqarish
    }
}
```

---

# 🔹 4.3. SPLIT — eng muhim qism (to‘liq log bilan)

```cpp
void splitChild(BTreeNode* parent, int i) {  // Tugunni bo'lish funksiyasi
    BTreeNode* y = parent->children[i];  // Bo'linadigan farzand tugunni olish

    cout << "\n[SPLIT BOSHLANDI]\n";  // Split boshlanishini loglash
    cout << "Parent node: ";  // Ota tugunni ko'rsatish
    for (int k : parent->keys) cout << k << " ";  // Ota tugun kalitlarini chiqarish
    cout << "\nSplit qilinayotgan child: ";  // Bo'linadigan farzandni ko'rsatish
    for (int k : y->keys) cout << k << " ";  // Farzand kalitlarini chiqarish
    cout << endl;

    BTreeNode* z = new BTreeNode(y->t, y->isLeaf);  // Yangi tugun yaratish (o'ng qism uchun)

    // o‘ng qismini olish
    for (int j = y->t; j < y->keys.size(); j++)  // O'ng qismdagi kalitlarni yangi tugunga ko'chirish
        z->keys.push_back(y->keys[j]);

    int middle = y->keys[y->t - 1];  // O'rtadagi kalitni olish

    // chap qismini saqlab qolamiz
    y->keys.resize(y->t - 1);  // Chap tugunni qisqartirish

    // agar barg bo‘lmasa farzandlarni ham bo‘lamiz
    if (!y->isLeaf) {  // Agar ichki tugun bo'lsa
        for (int j = y->t; j < y->children.size(); j++)  // O'ng farzandlarni ko'chirish
            z->children.push_back(y->children[j]);

        y->children.resize(y->t);  // Chap farzandlarni qisqartirish
    }

    // parentga qo‘shamiz
    parent->children.insert(parent->children.begin() + i + 1, z);  // Yangi farzandni qo'shish
    parent->keys.insert(parent->keys.begin() + i, middle);  // O'rtadagi kalitni ota tugunga qo'shish

    cout << "O‘rtadagi element yuqoriga chiqdi: " << middle << endl;  // Log

    cout << "Chap child: ";  // Chap tugunni ko'rsatish
    for (int k : y->keys) cout << k << " ";
    cout << "\nO‘ng child: ";  // O'ng tugunni ko'rsatish
    for (int k : z->keys) cout << k << " ";
    cout << "\n[SPLIT TUGADI]\n";  // Split tugashini loglash
}
```

---

# 🔹 4.4. Insert (log bilan)

```cpp
void insertNonFull(BTreeNode* node, int k) {  // To'lmagan tugunga element qo'shish
    cout << "\n[INSERT NON FULL] k = " << k << endl;  // Log

    int i = node->keys.size() - 1;  // Oxirgi indeksni olish

    // Agar barg bo‘lsa
    if (node->isLeaf) {  // Agar barg tugun bo'lsa
        cout << "Barg tugun. Oddiy qo‘shish...\n";  // Log

        node->keys.push_back(0); // joy ochamiz  // Vaqtinchalik joy ochish

        while (i >= 0 && k < node->keys[i]) {  // Joy topish uchun siljitish
            node->keys[i+1] = node->keys[i];  // Elementni o'ngga siljitish
            i--;  // Indeksni kamaytirish
        }

        node->keys[i+1] = k;  // Yangi elementni qo'shish

        cout << "Natija: ";  // Natijani ko'rsatish
        for (int x : node->keys) cout << x << " ";  // Tugun kalitlarini chiqarish
        cout << endl;

    } else {  // Agar ichki tugun bo'lsa
        cout << "Ichki tugun. Qaysi childga tushishini aniqlaymiz...\n";  // Log

        while (i >= 0 && k < node->keys[i])  // Qaysi farzandga tushishni aniqlash
            i--;

        i++;  // Indeksni oshirish

        cout << "Tanlangan child index: " << i << endl;  // Log

        // agar child to‘la bo‘lsa
        if (node->children[i]->keys.size() == 2*node->t - 1) {  // Agar farzand to'lgan bo'lsa
            cout << "Child to‘la → split qilamiz\n";  // Log

            splitChild(node, i);  // Split qilish

            if (k > node->keys[i]) {  // Agar k katta bo'lsa
                i++;  // O'ng farzandga o'tish
                cout << "O‘ng childga o‘tdi\n";  // Log
            }
        }

        insertNonFull(node->children[i], k);  // Rekursiv qo'shish
    }
}
```

---

# 🔹 4.5. Asosiy insert (log bilan)

```cpp
BTreeNode* insert(BTreeNode* root, int k, int t) {  // Asosiy insert funksiyasi

    cout << "\n=========================\n";  // Log ajratish
    cout << "INSERT: " << k << endl;  // Qo'shilayotgan elementni loglash

    // agar daraxt bo‘sh bo‘lsa
    if (root == NULL) {  // Agar daraxt bo'sh bo'lsa
        cout << "Yangi root yaratilmoqda\n";  // Log

        root = new BTreeNode(t, true);  // Yangi barg tugun yaratish
        root->keys.push_back(k);  // Elementni qo'shish

        return root;  // Yangi ildizni qaytarish
    }

    // root to‘la bo‘lsa
    if (root->keys.size() == 2*t - 1) {  // Agar ildiz to'lgan bo'lsa
        cout << "Root to‘la → yangi root + split\n";  // Log

        BTreeNode* s = new BTreeNode(t, false);  // Yangi ichki tugun yaratish
        s->children.push_back(root);  // Eski ildizni farzand qilish

        splitChild(s, 0);  // Split qilish

        int i = 0;  // Indeks
        if (k > s->keys[0])  // Qaysi farzandga tushish
            i++;  // O'ngga

        insertNonFull(s->children[i], k);  // Rekursiv qo'shish

        return s;  // Yangi ildizni qaytarish
    } else {  // Agar ildiz to'lmagan bo'lsa
        insertNonFull(root, k);  // Oddiy qo'shish
        return root;  // Eski ildizni qaytarish
    }
}
```

---

# 🔹 4.6. MAIN (to‘liq jarayonni ko‘rish)

```cpp
int main() {  // Asosiy funksiya
    int t = 2;  // Daraja
    BTreeNode* root = NULL;  // Daraxt ildizi

    int arr[] = {10, 20, 5, 6, 12, 30, 7, 17};  // Qo'shiladigan elementlar

    for (int i = 0; i < 8; i++) {  // Har bir element uchun
        root = insert(root, arr[i], t);  // Insert qilish

        cout << "\n--- HOZIRGI DARAxt ---\n";  // Daraxt holatini ko'rsatish
        printTree(root);  // Daraxtni chiqarish
        cout << "----------------------\n";  // Ajratish
    }

    return 0;  // Dasturni tugatish
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

