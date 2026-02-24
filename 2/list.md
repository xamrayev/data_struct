
---

# 1. Ro‘yxat (List) nima?

**Ro‘yxat (List)** — bu **bog‘langan ma’lumotlar tuzilmasi (Linked List)** bo‘lib, unda elementlar **xotirada ketma-ket joylashmaydi**, balki **ko‘rsatkichlar (pointer)** orqali bir-biriga bog‘lanadi.

📌 C++ STL’da `list` — bu **ikki tomonlama bog‘langan ro‘yxat (Doubly Linked List)**.

---

## 2. Oddiy tushuntirish (talaba uchun)

### Massiv (array) bilan farqi:

* Massivda:

  ```
  [10][20][30][40]
  ```
* List’da:

  ```
  10 → 20 → 30 → 40
  ```

Har bir element:

* **ma’lumot**
* **oldingi elementga ko‘rsatkich**
* **keyingi elementga ko‘rsatkich**

---

## 3. Ro‘yxatning asosiy xususiyatlari

✔ Elementlar xotirada **ixtiyoriy joylashadi**
✔ O‘rtadan qo‘shish va o‘chirish **juda tez (O(1))**
❌ Indeks orqali (`[i]`) murojaat **yo‘q**
❌ Qidirish sekinroq (`O(n)`)

---

## 4. Ro‘yxatning asosiy amallari (STL)

| Amal            | Izoh                      |
| --------------- | ------------------------- |
| `push_back(x)`  | Oxiriga qo‘shish          |
| `push_front(x)` | Boshiga qo‘shish          |
| `pop_back()`    | Oxiridan o‘chirish        |
| `pop_front()`   | Boshidan o‘chirish        |
| `remove(x)`     | Qiymatni o‘chirish        |
| `insert()`      | O‘rtaga qo‘shish          |
| `erase()`       | Iterator orqali o‘chirish |
| `size()`        | Elementlar soni           |

---

## 5. C++ da oddiy `list` misoli

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_front(5);

    for (int x : lst) {
        cout << x << " ";
    }
    return 0;
}
```

📌 Natija:

```
5 10 20
```

---

## 6. List qanday ishlaydi? (qadamlar bilan)

1️⃣ `push_back(10)`

```
10
```

2️⃣ `push_back(20)`

```
10 → 20
```

3️⃣ `push_front(5)`

```
5 → 10 → 20
```

---

# 7. Hayotiy masala: **Pleylist (Music Playlist)**

### Vaziyat

Musiqa pleylistida qo‘shiqlar bor:

```
Song1 → Song2 → Song3
```

* O‘rtadan qo‘shish mumkin
* O‘rtadan o‘chirish mumkin
* Oldinga va orqaga yurish mumkin

👉 Bu aynan **list**.

---

## 8. Hayotiy masala uchun C++ YECHIM

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> playlist;

    playlist.push_back("Song1");
    playlist.push_back("Song2");
    playlist.push_back("Song3");

    // O‘rtaga qo‘shish
    auto it = playlist.begin();
    advance(it, 1); // Song2 oldiga
    playlist.insert(it, "NewSong");

    // Natijani chiqarish
    for (string song : playlist) {
        cout << song << endl;
    }
    return 0;
}
```

📌 Natija:

```
Song1
NewSong
Song2
Song3
```

---

## 9. List qachon tanlanadi?

✔ Ko‘p **qo‘shish/o‘chirish** bo‘lsa
✔ Ma’lumotlar tez-tez o‘zgarib tursa
✔ Indeks muhim bo‘lmasa

❌ Tez qidirish kerak bo‘lsa → `vector`
❌ LIFO yoki FIFO bo‘lsa → `stack` / `queue`

---

## 10. Vector va List taqqoslash

| Xususiyat          | Vector    | List     |
| ------------------ | --------- | -------- |
| Xotira             | Ketma-ket | Tarqoq   |
| Indeks             | Bor       | Yo‘q     |
| O‘rtadan o‘chirish | Sekin     | Tez      |
| Iteratsiya         | Tez       | Sekinroq |

---

## 11. Talabalar uchun AMALIY TOPSHIRIQLAR

### 🟢 1-topshiriq (oson)

5 ta sonni `list` ga joylang va chiqarib ko‘rsating.

---

### 🟡 2-topshiriq (o‘rtacha)

Ro‘yxatdan **juft sonlarni o‘chiring**.

---

### 🔴 3-topshiriq (qiyin)

Pleylist dasturi yozing:

* qo‘shiq qo‘shish
* qo‘shiq o‘chirish
* oldinga/orqaga o‘tish

---

## 12. Talaba uchun yodda qoladigan jumla

> **Agar ma’lumotlar ko‘p o‘zgarsa va o‘rtadan ishlash kerak bo‘lsa — bu LIST.**


---

# 🎧 Hayotiy misol: **Musiqa pleylistini boshqarish (Playlist)**

### Vaziyat (real hayotdan)

Sizda musiqiy pleylist bor:

```
Song1 → Song2 → Song3
```

Foydalanuvchi quyidagilarni qila olishi kerak:

* qo‘shiqni **oxiriga qo‘shish**
* qo‘shiqni **o‘rtadan o‘chirish**
* qo‘shiqlarni **ketma-ket ko‘rish**

👉 Bu vaziyatda **massiv (array)** noqulay,
👉 **List (Linked List)** esa juda qulay.

---

## 1. Nima uchun bu yerda LIST ishlatiladi?

✔ Qo‘shiqlar soni o‘zgaradi
✔ O‘rtadan qo‘shish va o‘chirish tez
✔ Oldinga va orqaga yurish mumkin

📌 **STL `list` — bu doubly linked list**

---

## 2. Masala sharti (talabalar uchun)

**Shart:**
Musiqa pleylistini modellashtiring:

1. Dastlab 3 ta qo‘shiq bor
2. Yangi qo‘shiq **o‘rtaga qo‘shilsin**
3. Bitta qo‘shiq **nomi bo‘yicha o‘chirilsin**
4. Yakuniy pleylist ekranga chiqarilsin

---

## 3. Algoritm (oddiy tilda)

1. `list<string>` yaratamiz
2. `push_back()` bilan qo‘shiqlarni qo‘shamiz
3. `insert()` bilan o‘rtaga qo‘shamiz
4. `remove()` bilan qo‘shiqni o‘chiramiz
5. `for` orqali chiqaramiz

---

## 4. C++ da TO‘LIQ YECHIM KODI

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> playlist;

    // 1. Boshlang‘ich qo‘shiqlar
    playlist.push_back("Song1");
    playlist.push_back("Song2");
    playlist.push_back("Song3");

    // 2. O‘rtaga yangi qo‘shiq qo‘shish
    auto it = playlist.begin();
    advance(it, 1); // Song2 oldiga
    playlist.insert(it, "NewSong");

    // 3. Bitta qo‘shiqni o‘chirish
    playlist.remove("Song3");

    // 4. Yakuniy pleylist
    cout << "Yakuniy playlist:\n";
    for (string song : playlist) {
        cout << song << endl;
    }

    return 0;
}
```

---

## 5. Dastur natijasi (ekranda)

```
Yakuniy playlist:
Song1
NewSong
Song2
```

---

## 6. Bu masalada LIST qanday ishladi?

| Amal             | List afzalligi |
| ---------------- | -------------- |
| O‘rtaga qo‘shish | O(1), tez      |
| O‘chirish        | Indekssiz      |
| Tartib           | Saqlanadi      |
| Xotira           | Dinamik        |

---

## 7. Talaba uchun muhim xulosa

> **Agar real tizimda elementlar tez-tez qo‘shilib/o‘chib tursa
> va o‘rtadan ishlash kerak bo‘lsa — LIST eng to‘g‘ri tanlov.**

---

## 8. Mustaqil mashq (uyga vazifa)

🔹 Pleylistga:

* qo‘shiq qo‘shish
* qo‘shiq o‘chirish
* barcha qo‘shiqlar sonini chiqarish

funksiyalarini qo‘shing.

---
