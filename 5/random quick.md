# 🎯 Random Quick Sort (Tasodifiy pivotli QuickSort)

## 1. G‘oya

Oddiy QuickSort’da pivot noto‘g‘ri tanlansa (masalan, massiv oldindan saralangan bo‘lsa), algoritm **O(n²)** ga tushib ketadi.

**Random QuickSort** da esa pivot tasodifiy tanlanadi.
Bu:

* Eng yomon holat ehtimolini juda kamaytiradi
* O‘rtacha murakkablikni barqaror **O(n log n)** qiladi
* Amaliyotda ancha xavfsiz ishlaydi

---

# 2. Ishlash printsipi

1. `[low, high]` oralig‘idan random indeks tanlanadi
2. O‘sha element pivot sifatida oxirgi element bilan almashtiriladi
3. Oddiy partition bajariladi
4. Rekursiya davom etadi

---

# 3. Psevdokod

```
TASODIFIY_TEZ_SARALASH(A, past, yuqori)
    agar past < yuqori bo‘lsa

        r = TASODIFIY_SON(past, yuqori)   // [past, yuqori] oralig‘idan tasodifiy indeks

        A[r] va A[yuqori] ni joyini almashtir   // Tasodifiy elementni pivot qilish

        pi = BO‘LISH(A, past, yuqori)

        TASODIFIY_TEZ_SARALASH(A, past, pi - 1)
        TASODIFIY_TEZ_SARALASH(A, pi + 1, yuqori)
```

---

# 4. C++ Sodda Kod (To‘liq, Izohli)

```cpp
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()
using namespace std;

// Partition funksiyasi
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Random pivot tanlash
int randomPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // Pivotni oxiriga olib kelish
    return partition(arr, low, high);
}

// Random QuickSort
void randomQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);

        randomQuickSort(arr, low, pi - 1);
        randomQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));  // Random seed

    int arr[] = {9, 4, 7, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    randomQuickSort(arr, 0, n - 1);

    cout << "Saralangan massiv:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

---

# 5. Murakkablik

| Holat               | Murakkablik |
| ------------------- | ----------- |
| Eng yaxshi          | O(n log n)  |
| O‘rtacha            | O(n log n)  |
| Eng yomon (nazariy) | O(n²)       |

Lekin amalda eng yomon holat ehtimoli juda kichik.

---

# 6. Nima uchun Random QuickSort kuchli?

Agar massiv quyidagicha bo‘lsa:

```
[1,2,3,4,5,6,7]
```

Oddiy QuickSort (oxirgi pivot bilan) yomon ishlaydi.

Random pivot esa bo‘linishni muvozanatli qiladi.

---

# 7. Hayotiy Analogiya

Tasavvur qiling:

Talabalarni saralashda har safar tasodifiy bitta talabani tanlaysiz va unga qarab guruhlarga ajratasiz.

Shunda bir tomonga haddan tashqari ko‘p odam tushib qolish ehtimoli kamayadi.

---

# 8. Professional Eslatma

Competitive programming va real tizimlarda:

* Random pivot ishlatish tavsiya qilinadi
* Yoki `std::sort` ishlatiladi (introsort)
