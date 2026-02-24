# ⚡ Quick Sort — To‘liq va Tizimli Konspekt (C++)

## 1. Ta’rif

**Quick Sort** — bu *Divide and Conquer* (bo‘lib tashla va hukmronlik qil) usuliga asoslangan rekursiv saralash algoritmi.

### Asosiy bosqichlar:

1. **Pivot tanlash**
2. **Partition (bo‘lish)**
3. **Chap va o‘ng qismlarni rekursiv saralash**

---

# 2. Ishlash mexanizmi (bosqichma-bosqich)

Misol:

```
[9, 3, 7, 1, 6]
```

Pivot = 6

Partitiondan so‘ng:

```
[3, 1] 6 [9, 7]
```

Keyin:

Chap → `[3,1]` → `[1,3]`
O‘ng → `[9,7]` → `[7,9]`

Natija:

```
[1, 3, 6, 7, 9]
```

---

# 3. Psevdokod

```
TEZ_SARALASH(A, past, yuqori)
    agar past < yuqori bo‘lsa
        pi = BO‘LISH(A, past, yuqori)

        TEZ_SARALASH(A, past, pi - 1)
        TEZ_SARALASH(A, pi + 1, yuqori)

BO‘LISH(A, past, yuqori)
    pivot = A[yuqori]          // Oxirgi element tayanch (pivot)
    i = past - 1               // Kichik elementlar uchun indeks

    j = past dan yuqori - 1 gacha takrorla
        agar A[j] <= pivot bo‘lsa
            i = i + 1
            A[i] va A[j] ni joyini almashtir

    A[i + 1] va A[yuqori] ni joyini almashtir

    qaytar i + 1
```

---

# 4. C++ Sodda Kod (Izohli)

```cpp
#include <iostream>
using namespace std;

// Partition funksiyasi
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Oxirgi element pivot
    int i = low - 1;         // Kichik elementlar uchun indeks

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort funksiyasi
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Chap qism
        quickSort(arr, pi + 1, high); // O‘ng qism
    }
}

int main() {
    int arr[] = {9, 3, 7, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Saralangan massiv:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

---

# 5. Murakkablik Tahlili

| Holat      | Vaqt       |
| ---------- | ---------- |
| Eng yaxshi | O(n log n) |
| O‘rtacha   | O(n log n) |
| Eng yomon  | O(n²)      |

### Nima sababdan O(n²) bo‘ladi?

Agar pivot har doim eng kichik yoki eng katta element bo‘lsa (masalan massiv oldindan saralangan bo‘lsa).

---

# 6. Pivot Tanlash Usullari

1. Birinchi element
2. Oxirgi element
3. O‘rtadagi element
4. Random pivot (eng xavfsiz)
5. Median-of-three (optimallashtirilgan)

Amaliyotda `std::sort` — introsort ishlatadi (QuickSort + HeapSort kombinatsiyasi).

---

# 7. Afzalliklari

✔ Juda tez
✔ In-place (qo‘shimcha massiv kerak emas)
✔ Katta datasetlar uchun samarali

---

# 8. Kamchiliklari

✖ Eng yomon holat O(n²)
✖ Rekursiya stack chuqurligi oshishi mumkin

---

# 9. Hayotiy Analogiya

Tasavvur qiling:

Imtihon natijalarini saralayapsiz.

* Bitta talabani tanlaysiz (pivot).
* Undan past ball olganlar chapga.
* Yuqori olganlar o‘ngga.
* Har ikki guruh ichida yana shunday qilasiz.

Natijada hamma tartibda chiqadi.


