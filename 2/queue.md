

## 1. Navbat (Queue) nima?

**Navbat (Queue)** — bu **chiziqli ma’lumotlar tuzilmasi** bo‘lib, u **FIFO** tamoyiliga asoslanadi:

> **FIFO (First In – First Out)**
> Birinchi kiritilgan element — birinchi bo‘lib chiqariladi.

### Kundalik hayotdagi analogiya

* Bankdagi navbat
* Printerda hujjatlarning chop etilishi
* Avtobus bekatidagi navbat

---

## 2. Navbatning asosiy xususiyatlari

* Navbatda **ikki uch** mavjud:

  * **FRONT** — xizmat ko‘rsatiladigan element
  * **REAR (BACK)** — yangi element qo‘shiladigan joy
* Elementlar:

  * **oxiridan qo‘shiladi**
  * **boshidan olinadi**
* O‘rtadan ishlash yo‘q

---

## 3. Navbatning asosiy amallari

| Amal      | Tavsif                              |
| --------- | ----------------------------------- |
| `push(x)` | Navbat oxiriga element qo‘shish     |
| `pop()`   | Navbat boshidan elementni o‘chirish |
| `front()` | Birinchi elementni ko‘rish          |
| `back()`  | Oxirgi elementni ko‘rish            |
| `empty()` | Navbat bo‘shligini tekshirish       |
| `size()`  | Elementlar soni                     |

---

## 4. Navbat qanday ishlaydi? (qadamlar bilan)

Boshlang‘ich holat: **bo‘sh navbat**

1️⃣ `push(10)`

```
FRONT → [10] ← REAR
```

2️⃣ `push(20)`

```
FRONT → [10] [20] ← REAR
```

3️⃣ `push(30)`

```
FRONT → [10] [20] [30] ← REAR
```

4️⃣ `pop()`

```
FRONT → [20] [30] ← REAR
```

---

## 5. C++ tilida navbat (STL orqali)

### 5.1 Oddiy misol

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);

    cout << "Front element: " << q.front() << endl; // 5
    cout << "Back element: " << q.back() << endl;   // 15

    q.pop(); // 5 chiqarildi

    cout << "New front: " << q.front() << endl; // 10
    return 0;
}
```

---

## 6. Talabalar uchun MUHIM misol

### Printer navbatini modellashtirish

### Masala

3 ta hujjat printerga yuborilgan:

```
Doc1 → Doc2 → Doc3
```

Printer ularni **ketma-ket** chop etadi.

### C++ kodi

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> printer;

    printer.push("Doc1");
    printer.push("Doc2");
    printer.push("Doc3");

    while (!printer.empty()) {
        cout << "Printing: " << printer.front() << endl;
        printer.pop();
    }
}
```

---

## 7. Navbatning real dasturiy qo‘llanilishi

| Soha             | Izoh                   |
| ---------------- | ---------------------- |
| Operatsion tizim | CPU scheduling         |
| Tarmoqlar        | Paketlar navbati       |
| Algoritmlar      | BFS                    |
| Qurilmalar       | Printer                |
| Serverlar        | So‘rovlarni boshqarish |

---

## 8. Navbat turlari (talabalar bilishi shart)

### 1️⃣ Oddiy navbat (Queue)

— faqat FIFO

### 2️⃣ Aylana navbat (Circular Queue)

— xotiradan samarali foydalanadi

### 3️⃣ Ikki tomonlama navbat (Deque)

— boshidan ham, oxiridan ham ishlash mumkin

```cpp
#include <deque>
deque<int> dq;
dq.push_front(10);
dq.push_back(20);
```

### 4️⃣ Ustuvor navbat (Priority Queue)

— ustuvorligi yuqori element birinchi chiqadi

```cpp
#include <queue>
priority_queue<int> pq;
```

---

## 9. Talabalar uchun AMALIY TOPSHIRIQLAR

### 1-topshiriq (oson)

5 ta sonni navbatga joylang va chiqarib ko‘rsating.

---

### 2-topshiriq (o‘rtacha)

Do‘kondagi mijozlar navbatini modellashtiring
(kelish va xizmat ko‘rsatish).

---

### 3-topshiriq (qiyin)

Grafda BFS algoritmini **queue** yordamida yozing.

---

## 10. Stack va Queue taqqoslash

| Xususiyat   | Stack    | Queue           |
| ----------- | -------- | --------------- |
| Tartib      | LIFO     | FIFO            |
| Uchlar soni | 1        | 2               |
| Amal        | push/pop | enqueue/dequeue |

---

## 11. Xulosa (talaba uchun eslab qolish)

> **Navbat — bu xizmat ko‘rsatish tartibini saqlovchi tuzilma.
> Birinchi kelgan — birinchi chiqadi (FIFO).**


---

# 🧠 Hayotiy masala: **Bankdagi mijozlar navbati**

### Vaziyat (real hayotdan)

Bankka quyidagi mijozlar ketma-ket keladi:

```
Ali → Vali → Hasan → Husan
```

Bank xodimi mijozlarga **kelgan tartibda** xizmat ko‘rsatadi.

👉 Birinchi bo‘lib kim xizmat oladi?
👉 Keyingi mijoz kim?

### To‘g‘ri javob

> **Birinchi kelgan — birinchi xizmat oladi**
> Bu **FIFO** tamoyili — **Queue (Navbat)**.

---

## 1. Masalani Queue bilan yechish g‘oyasi

### Fikrlash modeli

* Mijoz kelishi → `queue.push()`
* Xizmat ko‘rsatish → `queue.pop()`
* Hozir xizmat olinayotgan mijoz → `queue.front()`

---

## 2. Masala sharti (talabalar uchun)

**Shart:**
Bank navbatini modellashtiring:

1. Mijozlar navbatga qo‘shiladi
2. Bank xodimi ularni **kelish tartibida** qabul qiladi
3. Har bir qadamda qaysi mijoz xizmat olayotgani chiqarilsin

---

## 3. Algoritm (oddiy tilda)

1. Bo‘sh `queue<string>` yaratiladi
2. Har bir kelgan mijoz navbatga qo‘shiladi
3. Navbat bo‘sh bo‘lmaguncha:

   * Oldingi mijoz xizmat oladi (`front`)
   * Navbatdan chiqariladi (`pop`)

---

## 4. C++ da TO‘LIQ YECHIM KODI

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> bankQueue;

    // Mijozlar kelmoqda
    bankQueue.push("Ali");
    bankQueue.push("Vali");
    bankQueue.push("Hasan");
    bankQueue.push("Husan");

    cout << "Bank xizmat ko‘rsatishni boshladi:\n";

    // Xizmat ko‘rsatish jarayoni
    while (!bankQueue.empty()) {
        cout << "Xizmat olayotgan mijoz: "
             << bankQueue.front() << endl;
        bankQueue.pop();
    }

    cout << "Barcha mijozlarga xizmat ko‘rsatildi.";
    return 0;
}
```

### 📌 Dastur natijasi:

```
Bank xizmat ko‘rsatishni boshladi:
Xizmat olayotgan mijoz: Ali
Xizmat olayotgan mijoz: Vali
Xizmat olayotgan mijoz: Hasan
Xizmat olayotgan mijoz: Husan
Barcha mijozlarga xizmat ko‘rsatildi.
```

---

## 5. Nima uchun aynan Queue?

✔ Chunki **tartib buzilmaydi**
✔ Har kim o‘z navbatida xizmat oladi
✔ FIFO muammolar uchun eng to‘g‘ri tuzilma

---

# 🖨️ 2-hayotiy masala (qo‘shimcha): **Printer navbati**

### Vaziyat

Bir nechta hujjat printerga yuborildi:

```
Report.pdf → Homework.docx → Photo.jpg
```

Printer ularni **ketma-ket** chop etadi.

### Mini C++ kod

```cpp
queue<string> printer;

printer.push("Report.pdf");
printer.push("Homework.docx");
printer.push("Photo.jpg");

while (!printer.empty()) {
    cout << "Printing: " << printer.front() << endl;
    printer.pop();
}
```

---

## 6. Talabalar uchun MUSTAQIL TOPSHIRIQLAR

### 🟢 1-topshiriq (oson)

5 ta sonni navbatga joylang va ularni chiqarib ko‘rsating.

---

### 🟡 2-topshiriq (o‘rtacha)

Do‘kondagi mijozlar navbatini modellashtiring
(kelish va xizmat ko‘rsatish vaqtini hisobga olib).

---

### 🔴 3-topshiriq (qiyin)

Grafda **BFS algoritmini queue yordamida** yozing.

---

