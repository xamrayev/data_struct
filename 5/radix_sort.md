# 🚀 Radix Sort — To‘liq Konspekt (C++ + Psevdokod + Misol)

## 1. Ta’rif

**Radix Sort** — bu *taqqoslashsiz* (non-comparison) saralash algoritmi bo‘lib, sonlarni **raqamlar bo‘yicha (digit-by-digit)** saralaydi.

U odatda **Counting Sort** yordamida har bir raqam bo‘yicha saralash qiladi.

---

# 2. Asosiy g‘oya

Sonlarni:

* birlar xonasi
* o‘nlar xonasi
* yuzlar xonasi
* ...

bo‘yicha ketma-ket saralaydi.

> Muhim: har bosqichdagi saralash **stable** bo‘lishi kerak.

---

# 3. Ishlash mexanikasi (LSD versiya)

LSD = Least Significant Digit (eng kichik razryaddan boshlash)

Misol:

```text
[170, 45, 75, 90, 802, 24, 2, 66]
```

### 1-qadam: Birlar xonasi bo‘yicha

```text
[170, 90, 802, 2, 24, 45, 75, 66]
```

### 2-qadam: O‘nlar xonasi bo‘yicha

```text
[802, 2, 24, 45, 66, 170, 75, 90]
```

### 3-qadam: Yuzlar xonasi bo‘yicha

```text
[2, 24, 45, 66, 75, 90, 170, 802]
```

Natija: Saralandi ✅

---

# 4. Psevdokod

```text
RADIX_SORT(A)
    max = maximum element in A

    for exp = 1; max/exp > 0; exp *= 10
        COUNTING_SORT_BY_DIGIT(A, exp)
```

---

# 5. C++ Kod (To‘liq, Izohli)

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Raqam bo‘yicha Counting Sort
void countingSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);  // 0-9 raqamlar uchun

    // Raqamlarni sanash
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Prefix sum (pozitsiyalarni aniqlash)
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Stable joylashtirish (orqadan)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Natijani qaytarish
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxVal = arr[0];
    for (int x : arr)
        if (x > maxVal)
            maxVal = x;

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortByDigit(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    cout << "Saralangan massiv:\n";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
```

---

# 6. Murakkablik Tahlili

| Parametr | Qiymat         |
| -------- | -------------- |
| Vaqt     | O(d × (n + k)) |
| Xotira   | O(n + k)       |

Bu yerda:

* n — elementlar soni
* d — raqamlar soni
* k — baza (decimalda 10)

Agar d kichik bo‘lsa → deyarli **O(n)**

---

# 7. Qachon ishlatish kerak?

✔ Katta miqdordagi butun sonlar
✔ Sonlar uzunligi cheklangan bo‘lsa
✔ Stringlarni ham saralash mumkin

❌ Juda katta raqamlar uzunligi bo‘lsa
❌ Floating point uchun mos emas (maxsus moslashtirish kerak)

---

# 8. QuickSort vs RadixSort

| QuickSort               | RadixSort                  |
| ----------------------- | -------------------------- |
| O(n log n)              | O(d × n)                   |
| Taqqoslashga asoslangan | Taqqoslashsiz              |
| In-place                | Qo‘shimcha xotira kerak    |
| Har qanday ma’lumot     | Faqat raqamlar yoki string |

---

# 9. Hayotiy Misol

Tasavvur qiling:

Talabalarning ID raqamlari bor.

Siz ularni:

* avval oxirgi raqamiga qarab,
* keyin keyingi raqamiga qarab,
* va hokazo

saralaysiz.

Oxirida to‘liq tartib hosil bo‘ladi.

---

# 10. Professional Eslatma

RadixSort:

* Database indekslashda
* GPU parallel sortingda
* Katta ma’lumotlarni tez saralashda ishlatiladi

