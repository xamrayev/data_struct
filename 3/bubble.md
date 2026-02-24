Quyida **Bubble Sort (Pufakcha saralash)** algoritmi bo‘yicha **to‘liq, darslik-uslubidagi konspekt** keltiriladi:  
**nazariya → ishlash g‘oyasi → qadamlar → C++ namuna kodlar → talabalar uchun mashqlar**.

---

# 📘 Bubble Sort (Pufakcha saralash)

## 1\. Bubble Sort nima?

**Bubble Sort** — bu **eng sodda saralash algoritmlaridan biri** bo‘lib, massivdagi **yonma-yon elementlarni solishtirish va kerak bo‘lsa almashtirish** tamoyiliga asoslanadi.

📌 Algoritm nomi shundan kelib chiqqan:

> **Katta elementlar pufakcha kabi oxiriga “suzib chiqadi”**.

---

## 2\. Qachon Bubble Sort ishlatiladi?

✔ Algoritmni **o‘rganish va tushuntirish** uchun  
✔ **Kichik hajmli** massivlar uchun  
✔ Dastlabki **algoritmik fikrlashni** shakllantirishda

❌ Katta hajmli ma’lumotlar uchun **tavsiya etilmaydi**

---

## 3\. Bubble Sort g‘oyasi (oddiy tilda)

1.  Massiv boshidan oxirigacha yuriladi
2.  Yonma-yon elementlar solishtiriladi
3.  Agar tartib noto‘g‘ri bo‘lsa — **almashtiriladi**
4.  Har bir to‘liq o‘tishda **eng katta element oxiriga joylashadi**
5.  Jarayon massiv to‘liq saralanguncha takrorlanadi

---

## 4\. Qadamlar bilan ishlash (misol)

### Berilgan massiv:

```
[5, 1, 4, 2]
```

### 1-o‘tish:

*   5 > 1 → almashtir → `[1, 5, 4, 2]`
*   5 > 4 → almashtir → `[1, 4, 5, 2]`
*   5 > 2 → almashtir → `[1, 4, 2, 5]`

👉 Eng katta element **5** oxiriga chiqdi

### 2-o‘tish:

*   1 \< 4 → o‘zgarmaydi
*   4 > 2 → almashtir → `[1, 2, 4, 5]`

👉 Massiv saralandi

---

## 5\. Psevdokod

```
for i = 0 dan n-2 gacha
    for j = 0 dan n-i-2 gacha
        agar a[j] > a[j+1] bo‘lsa
            almashtir(a[j], a[j+1])
```

---

## 6\. C++ da Bubble Sort (oddiy namuna)

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    int a[] = {5, 1, 4, 2};
    int n = 4;

    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
```

### Natija:

```
1 2 4 5
```

---

## 7\. Yaxshilangan Bubble Sort (optimallashtirilgan)

Agar massiv **oldindan saralangan** bo‘lsa, bekor aylanishlarni to‘xtatish mumkin.

```cpp
void bubbleSortOptimized(int a[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // allaqachon saralangan
    }
}
```

📌 Eng yaxshi holatda murakkablik: **O(n)**

---

## 8\. Murakkablik (Time Complexity)

| Holat | Murakkablik |
| --- | --- |
| Eng yaxshi | O(n) _(optimallashtirilgan)_ |
| O‘rtacha | O(n²) |
| Eng yomon | O(n²) |

📌 Xotira murakkabligi: **O(1)** (in-place)

---

## 9\. Afzallik va kamchiliklar

### Afzalliklar

✔ Juda sodda  
✔ Kodlash oson  
✔ Ta’lim uchun qulay

### Kamchiliklar

❌ Juda sekin  
❌ Katta massivlar uchun yaroqsiz

---

## 10\. Talabalar uchun AMALIY MISOLLAR

### 🟢 1-misol (oson)

Quyidagi massivni Bubble Sort bilan **o‘sish tartibida** saralang:

```
[7, 3, 9, 1, 5]
```

---

### 🟡 2-misol (o‘rtacha)

Massivni Bubble Sort bilan saralang va  
**har bir tashqi sikldan keyingi holatini** chiqaring.

---

### 🔴 3-misol (qiyin)

Bubble Sort yordamida massivni  
**kamayish (descending) tartibida** saralang.

---

## 11\. Talaba uchun yodda qoladigan xulosa

> **Bubble Sort — algoritmlarni tushunish uchun eng yaxshi boshlanish.**  
> **Ammo real tizimlarda kam qo‘llaniladi.**

---