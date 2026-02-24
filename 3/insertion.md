# 📘 Insertion Sort (Joylab saralash)

## 1. Insertion Sort nima?

**Insertion Sort** — bu **oddiy saralash algoritmi** bo‘lib, u massiv elementlarini **birma-bir olib**, ularni **oldingi saralangan qism ichidagi to‘g‘ri joyiga qo‘yish** tamoyiliga asoslanadi.

📌 Algoritm nomining ma’nosi:

> Har bir element o‘z joyiga **joylab (insert)** qo‘yiladi.

---

## 2. Kundalik hayotdagi analogiya

🃏 **Kartalarni qo‘lda saralash**:

* Bitta karta olasiz
* Uni qo‘lingizdagi kartalar orasida to‘g‘ri joyiga qo‘yasiz
* Har safar tartibli qism kengayib boradi

👉 Bu aynan **Insertion Sort** ishlash prinsipi.

---

## 3. Qachon Insertion Sort ishlatiladi?

✔ **Kichik massivlar** uchun
✔ **Deyarli saralangan** ma’lumotlar uchun
✔ Oddiy va tushunarli algoritm kerak bo‘lsa

❌ Juda katta massivlar uchun samarali emas

---

## 4. Insertion Sort g‘oyasi (oddiy tilda)

1. Birinchi element **saralangan** deb olinadi
2. Keyingi element olinadi (`key`)
3. U oldingi elementlar bilan solishtiriladi
4. Kattalar o‘ngga suriladi
5. `key` o‘z joyiga qo‘yiladi
6. Jarayon oxirigacha davom etadi

---

## 5. Qadamlar bilan ishlash (misol)

### Berilgan massiv:

```
[5, 2, 4, 6]
```

### 1-bosqich

* Saralangan qism: `[5]`
* `key = 2`

```
[2, 5, 4, 6]
```

### 2-bosqich

* Saralangan qism: `[2, 5]`
* `key = 4`

```
[2, 4, 5, 6]
```

### 3-bosqich

* `key = 6`
* O‘z joyida qoladi

👉 Massiv saralandi

---

## 6. Psevdokod

```
for i = 1 dan n-1 gacha
    key = a[i]
    j = i - 1
    while j >= 0 va a[j] > key
        a[j+1] = a[j]
        j--
    a[j+1] = key
```

---

## 7. C++ da Insertion Sort (oddiy namuna)

```cpp
#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[] = {5, 2, 4, 6};
    int n = 4;

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
```

### Natija:

```
2 4 5 6
```

---

## 8. Insertion Sort xususiyatlari

### ⏱ Vaqt murakkabligi (Time Complexity)

| Holat                   | Murakkablik |
| ----------------------- | ----------- |
| Eng yaxshi (saralangan) | **O(n)**    |
| O‘rtacha                | **O(n²)**   |
| Eng yomon (teskari)     | **O(n²)**   |

---

### 💾 Xotira murakkabligi

* **O(1)** — qo‘shimcha xotira talab qilinmaydi
* **In-place** algoritm

---

## 9. Afzallik va kamchiliklar

### Afzalliklar

✔ Juda tushunarli
✔ Deyarli saralangan massivlarda tez
✔ Barqaror (stable) algoritm

### Kamchiliklar

❌ Katta massivlar uchun sekin
❌ Ko‘p siljitish (shift) talab etiladi

---

## 10. Bubble va Selection bilan taqqoslash

| Algoritm  | Eng yaxshi holat | Xususiyati            |
| --------- | ---------------- | --------------------- |
| Bubble    | O(n)             | Yonma-yon almashish   |
| Selection | O(n²)            | Eng kichikni tanlaydi |
| Insertion | **O(n)**         | Joylab qo‘yadi        |

---

## 11. Talabalar uchun AMALIY MISOLLAR

### 🟢 1-misol (oson)

Quyidagi massivni Insertion Sort bilan saralang:

```
[8, 3, 5, 2]
```

---

### 🟡 2-misol (o‘rtacha)

Massivni Insertion Sort bilan saralang va
**har bir bosqichdan keyingi holatini** chiqarib boring.

---

### 🔴 3-misol (qiyin)

Insertion Sort yordamida massivni
**kamayish (descending) tartibida** saralang.

---

## 12. Talaba uchun yodda qoladigan xulosa

> **Insertion Sort — “ol va joyiga qo‘y” tamoyiliga asoslangan,
> deyarli saralangan ma’lumotlar uchun eng qulay oddiy algoritm.**

---
