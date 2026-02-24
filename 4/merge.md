# Merge Sort Algoritmi – To‘liq Qayta Tushuntirilgan Konspekt (C++)

---

# 1. Merge Sort ishlash texnikasi (nazariy qism)

Merge Sort — bu "Divide and Conquer" (Bo‘lib tashla va hukmronlik qil) paradigmasiga asoslangan saralash algoritmi.

Algoritm 3 bosqichda ishlaydi:

1. Divide (Bo‘lish)
   Massiv teng ikkiga bo‘linadi.

2. Conquer (Saralash)
   Har bir qism rekursiv tarzda yana bo‘linadi, oxirida 1 elementli qismlarga ajraladi.
   1 elementli massiv doimo saralangan hisoblanadi.

3. Merge (Birlashtirish)
   Ikkita saralangan qism o‘zaro solishtirilib, tartib buzilmagan holda qayta yig‘iladi.

---

## 1.1 Nega ishlaydi?

Faraz qiling:

[8, 3, 5, 4]

1-qadam:
[8,3]   [5,4]

2-qadam:
[8] [3] [5] [4]

Endi har biri saralangan deb qaraymiz.

Birlashtiramiz:
[3,8]   [4,5]

Oxiri:
[3,4,5,8]

Muhim g‘oya:
Ikki tartiblangan massivni birlashtirish har doim chiziqli vaqt oladi.

---

# 2. Algoritm murakkabligi

Vaqt murakkabligi:
O(n log n)

Sababi:

* Har bo‘linishda elementlar soni 2 baravar kamayadi
* Bo‘linishlar soni log2(n)
* Har darajada birlashtirish uchun n vaqt kerak

Xotira murakkabligi:
O(n)

Sababi: qo‘shimcha vaqtinchalik massiv kerak.

---

# 3. To‘liq C++ kodi (funksiyalarsiz, main ichida)

Quyidagi kod to‘liq Merge Sort algoritmini bitta main funksiyasi ichida bajaradi.

```cpp
#include <iostream>
using namespace std;

int main() {

    // Saralanadigan massiv
    int arr[] = {8, 3, 5, 4, 7, 6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Vaqtinchalik yordamchi massiv
    int temp[100]; // maksimal 100 element uchun

    // size - birlashtiriladigan blok o'lchami
    // Avval 1 elementli bloklar, keyin 2, 4, 8...
    for (int size = 1; size < n; size = size * 2) {

        // left - har bir blokning boshlanish indeksi
        for (int left = 0; left < n; left = left + 2 * size) {

            int mid = left + size;         // chap blok tugash joyi
            int right = left + 2 * size;   // o'ng blok tugash joyi

            // Chegaradan chiqmaslik uchun
            if (mid > n) mid = n;
            if (right > n) right = n;

            int i = left;   // chap blok indeksi
            int j = mid;    // o'ng blok indeksi
            int k = left;   // temp massiv indeksi

            // Ikkala blokni taqqoslab birlashtirish
            while (i < mid && j < right) {

                // Agar chap kichik bo'lsa
                if (arr[i] <= arr[j]) {
                    temp[k] = arr[i];  // chapni yozamiz
                    i++;               // chap indeksni oshiramiz
                }
                else {
                    temp[k] = arr[j];  // o'ngni yozamiz
                    j++;               // o'ng indeksni oshiramiz
                }
                k++; // natija indeksini oshiramiz
            }

            // Agar chap blokda element qolgan bo'lsa
            while (i < mid) {
                temp[k] = arr[i];
                i++;
                k++;
            }

            // Agar o'ng blokda element qolgan bo'lsa
            while (j < right) {
                temp[k] = arr[j];
                j++;
                k++;
            }
        }

        // Har bir bosqichdan so'ng temp ni asosiy massivga ko'chiramiz
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }

    // Natijani chiqarish
    cout << "Saralangan massiv:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---

# 4. Ishlash mexanizmi qisqacha

1-bosqich (size=1)
Har bir element juft-juft solishtiriladi.

2-bosqich (size=2)
2 ta elementli bloklar birlashtiriladi.

3-bosqich (size=4)
4 ta elementli bloklar birlashtiriladi.

Oxirida butun massiv saralanadi.

---

# 5. Afzalliklari

* Har doim O(n log n)
* Stable (teng elementlar o‘rin almashmaydi)
* Katta ma'lumotlar uchun samarali

---

# 6. Kamchiliklari

* Qo‘shimcha massiv talab qiladi
* In-place emas

---

# 7. Xulosa

Merge Sort deterministik va ishonchli algoritmdir.
Uning asosiy kuchi — tartiblangan qismlarni tez birlashtirish mexanizmi.

Bu algoritm katta hajmdagi ma'lumotlar bilan ishlashda juda samarali hisoblanadi.
