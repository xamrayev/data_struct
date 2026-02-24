
## 1. Stek (Stack) nima?

**Stek (Stack)** — bu **chiziqli ma’lumotlar tuzilmasi** bo‘lib, u **LIFO** tamoyiliga asoslanadi:

> **LIFO (Last In – First Out)**
> Oxirgi kiritilgan element — birinchi bo‘lib chiqariladi.

### Kundalik hayotdagi analogiya

* Kitoblar taxlami
* Likopchalar (idishlar) ustma-ust qo‘yilishi
* Brauzerdagi **Back** tugmasi

---

## 2. Stekning asosiy xususiyatlari

* Stekda **faqat bitta uch** bilan ishlanadi — **TOP**
* Elementlar:

  * **tepaga qo‘shiladi**
  * **tepadan olinadi**
* O‘rtadan yoki pastdan to‘g‘ridan-to‘g‘ri murojaat **yo‘q**

---

## 3. Stekning asosiy amallari

| Amal      | Tavsif                         |
| --------- | ------------------------------ |
| `push(x)` | Stek tepasiga element qo‘shish |
| `pop()`   | Tepasidagi elementni o‘chirish |
| `top()`   | Tepasidagi elementni ko‘rish   |
| `empty()` | Stek bo‘shligini tekshirish    |
| `size()`  | Elementlar soni                |

---

## 4. Stekning ishlash prinsipi (qadamlar bilan)

Boshlang‘ich holat: **bo‘sh stek**

1️⃣ `push(10)`

```
TOP → [10]
```

2️⃣ `push(20)`

```
TOP → [20]
        [10]
```

3️⃣ `push(30)`

```
TOP → [30]
        [20]
        [10]
```

4️⃣ `pop()`

```
TOP → [20]
        [10]
```

---

## 5. C++ tilida stek (STL orqali)

### 5.1 Oddiy misol

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(5);
    st.push(10);
    st.push(15);

    cout << "Top element: " << st.top() << endl; // 15

    st.pop(); // 15 o‘chirildi

    cout << "New top: " << st.top() << endl; // 10
    return 0;
}
```

---

## 6. Talabalar uchun MUHIM misol

### Qavslarning to‘g‘riligini tekshirish

### Masala

Berilgan qator to‘g‘ri yozilganmi?

```
( ( a + b ) * c )
```

### Yechish g‘oyasi

* Ochiluvchi qavs → `push`
* Yopiluvchi qavs → `pop`
* Oxirida stek bo‘sh bo‘lsa → **to‘g‘ri**

### C++ kodi

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "((a+b)*c)";
    stack<char> st;

    for (char c : s) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (st.empty()) {
                cout << "Noto‘g‘ri qavslar";
                return 0;
            }
            st.pop();
        }
    }

    if (st.empty())
        cout << "Qavslar to‘g‘ri";
    else
        cout << "Qavslar noto‘g‘ri";
}
```

---

## 7. Stekning real dasturiy qo‘llanilishi

| Soha               | Izoh                         |
| ------------------ | ---------------------------- |
| Funksiya chaqiruvi | Call Stack                   |
| Kompilyator        | Qavs va sintaksis tekshirish |
| Matematika         | Postfix ifodalar             |
| Dasturlar          | Undo / Redo                  |
| Algoritmlar        | DFS                          |

---

## 8. Talabalar uchun AMALIY TOPSHIRIQLAR

### 1-topshiriq (oson)

Berilgan sonlar ketma-ketligini **teskari tartibda** chiqarish.

👉 **Maslahat:** `stack<int>`

---

### 2-topshiriq (o‘rtacha)

Postfix ifodani hisoblang:

```
5 3 + 2 *
```

---

### 3-topshiriq (qiyin)

Brauzer tarixini modellashtiring:

* `visit`
* `back`
* `forward`

👉 **Ikki stek ishlating**

---

## 9. Qachon stek tanlanadi?

✔ Oxirgi amal birinchi bekor qilinishi kerak bo‘lsa
✔ Rekursiya ishlatilsa
✔ Qavslar yoki tarix bilan ishlansa

---

## 10. Xulosa (talaba uchun eslab qolish)

> **Stek — bu faqat tepa bilan ishlaydigan tuzilma.
> Oxirgi kirgan — birinchi chiqadi (LIFO).**


---

# 🧠 Hayotiy masala: **Brauzerda “Orqaga (Back)” tugmasi qanday ishlaydi?**

### Vaziyat (real hayotdan)

Siz internet brauzerda quyidagi sahifalarni ketma-ket ochdingiz:

```
google.com → wikipedia.org → cppreference.com → stackoverflow.com
```

So‘ngra **Back** tugmasini bosasiz.

👉 Qaysi sahifaga qaytasiz?
👉 Keyin yana Back bossangiz-chi?

### To‘g‘ri javob

> **Eng oxirgi ochilgan sahifa birinchi bo‘lib yopiladi**
> Bu aynan **LIFO** tamoyili — **Stack**.

---

## 1. Masalani Stack bilan yechish g‘oyasi

### Fikrlash modeli

* Har yangi sahifa → **stack.push()**
* Back bosilsa → **stack.pop()**
* Hozirgi sahifa → **stack.top()**

---

## 2. Masala sharti (talabalar uchun)

### Shart

Brauzer tarixini modellashtiring:

* Foydalanuvchi sahifa ochadi
* Back tugmasini bosadi
* Joriy sahifa ekranga chiqariladi

---

## 3. Algoritm (oddiy tilda)

1. Bo‘sh `stack<string>` yaratamiz
2. Sahifa ochilsa → `push`
3. Back bosilsa → `pop`
4. Agar stack bo‘sh bo‘lsa → `"Bosh sahifa"`

---

## 4. C++ da to‘liq YECHIM KODI

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;

    // Sahifalar ochilishi
    history.push("google.com");
    history.push("wikipedia.org");
    history.push("cppreference.com");
    history.push("stackoverflow.com");

    cout << "Hozirgi sahifa: " << history.top() << endl;

    // Back tugmasi bosildi
    history.pop();
    cout << "Back bosildi..." << endl;
    cout << "Hozirgi sahifa: " << history.top() << endl;

    history.pop();
    cout << "Back yana bosildi..." << endl;
    cout << "Hozirgi sahifa: " << history.top() << endl;

    return 0;
}
```

### 📌 Natija (ekranda):

```
Hozirgi sahifa: stackoverflow.com
Back bosildi...
Hozirgi sahifa: cppreference.com
Back yana bosildi...
Hozirgi sahifa: wikipedia.org
```

---

## 5. Shu masaladan olinadigan XULOSA

✔ Nima uchun **stack** ishlatildi?
→ Chunki **oxirgi sahifa birinchi bekor qilinadi**

✔ Qanday tamoyil?
→ **LIFO**

---

# 🔁 2-hayotiy masala (qo‘shimcha): **Undo / Redo**

### Vaziyat

Matn muharririda yozdingiz:

```
A → AB → ABC → ABCD
```

Undo bossangiz:

```
ABCD → ABC → AB → A
```

👉 Bu ham **stack**.

### Mini kod (Undo)

```cpp
stack<string> undo;

undo.push("A");
undo.push("AB");
undo.push("ABC");

undo.pop(); // Undo
cout << undo.top(); // AB
```

---

## 6. Talabalar uchun MUSTAQIL TOPSHIRIQLAR

### 🟢 1-topshiriq (oson)

Foydalanuvchi kiritgan 5 ta so‘zni stack yordamida **teskari tartibda** chiqaring.

---

### 🟡 2-topshiriq (o‘rtacha)

Qavslarning to‘g‘riligini tekshiring:

```
((a+b)*c)
```

---

### 🔴 3-topshiriq (qiyin)

Undo/Redo tizimini **ikki stack** yordamida yozing.

---

