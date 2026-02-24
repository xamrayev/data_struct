# 📘 Quick Sort (Tezkor saralash)

## 1\. Quick Sort nima?

**Quick Sort** — bu **bo‘lib-tashla va hukmronlik qil (Divide & Conquer)** tamoyiliga asoslangan, **eng samarali ichki saralash algoritmlaridan biri**.

📌 Asosiy g‘oya:

> Bitta **tayanch element (pivot)** tanlanadi,  
> undan **kichiklar chapga**, **kattalar o‘ngga** joylashtiriladi,  
> so‘ng jarayon **rekursiv** davom ettiriladi.

---

## 2\. Kundalik hayotdagi analogiya

📚 **Kitoblarni tartiblash**:

*   Bitta kitobni mezon qilib olasiz (pivot)
*   Undan ingichkaroqlari chapga
*   Qalinroqlari o‘ngga
*   Har ikki tomonni yana alohida tartiblaysiz

👉 Bu aynan **Quick Sort**.

---

## 3\. Qachon Quick Sort ishlatiladi?

✔ Katta hajmli massivlar uchun  
✔ Tezlik muhim bo‘lganda  
✔ Xotira tejamkor bo‘lishi kerak bo‘lsa

❌ Agar massiv **allaqachon saralangan** va pivot noto‘g‘ri tanlansa — sekinlashadi

---

## 4\. Quick Sort g‘oyasi (oddiy tilda)

1.  Massivdan **pivot** tanlanadi
2.  Pivotdan kichik elementlar chapga, kattalari o‘ngga o‘tkaziladi (**partition**)
3.  Pivot o‘z **yakuniy joyiga** tushadi
4.  Chap va o‘ng qismlar uchun **rekursiv** Quick Sort chaqiriladi
5.  Qismlar bitta elementli bo‘lguncha davom etadi

---

## 5\. Qadamlar bilan ishlash (misol)

### Berilgan massiv:

```
[9, 3, 7, 1, 8]
```

### 1-bosqich

*   Pivot = **8**

```
[3, 7, 1]  8  [9]
```

### 2-bosqich (chap qism)

*   Pivot = **1**

```
[]  1  [3, 7]
```

### 3-bosqich

*   `[3, 7]` → pivot = 7

```
[3] 7 []
```

👉 Natija:

```
[1, 3, 7, 8, 9]
```

---

## 6\. Psevdokod

```
QuickSort(A, low, high):
    agar low < high bo‘lsa
        p = Partition(A, low, high)
        QuickSort(A, low, p-1)
        QuickSort(A, p+1, high)
```

---

## 7\. Partition (bo‘lish) jarayoni

📌 Eng muhim qism — **partition**.

### G‘oya:

*   Pivotni oxirgi element deb olamiz
*   Kichik elementlarni chap tomonga yig‘amiz

---

## 8\. C++ da Quick Sort (to‘liq namuna)

```cpp
#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[high]; // pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[] = {9, 3, 7, 1, 8};
    int n = 5;

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
```

### Natija:

```
1 3 7 8 9
```

---

## 9\. Murakkablik (Time Complexity)

| Holat | Murakkablik |
| --- | --- |
| Eng yaxshi | **O(n log n)** |
| O‘rtacha | **O(n log n)** |
| Eng yomon | **O(n²)** |

📌 Eng yomon holat — pivot har safar eng kichik yoki eng katta bo‘lsa.

---

## 10\. Xotira murakkabligi

*   **O(log n)** — rekursiya steki
*   In-place algoritm (qo‘shimcha massiv yo‘q)

---

## 11\. Afzallik va kamchiliklar

### Afzalliklar

✔ Juda tez  
✔ Amaliyotda eng ko‘p ishlatiladi  
✔ Xotira tejamkor

### Kamchiliklar

❌ Rekursiv  
❌ Noto‘g‘ri pivot tanlansa sekinlashadi

---

## 12\. Quick Sort’ni yaxshilash usullari (eslatma)

*   **Random pivot**
*   **Median-of-three**
*   Kichik massivlarda → Insertion Sort

---

## 13\. Talabalar uchun AMALIY MISOLLAR

### 🟢 1-misol (oson)

Quyidagi massivni Quick Sort bilan saralang:

```
[6, 2, 9, 1]
```

---

### 🟡 2-misol (o‘rtacha)

Quick Sort’da:

*   har bir **pivotni**
*   chap va o‘ng qismlarni

ekranga chiqarib boring.

---

### 🔴 3-misol (qiyin)

Quick Sort yordamida massivni  
**kamayish (descending) tartibida** saralang.

---

## 14\. Talaba uchun yodda qoladigan xulosa

> **Quick Sort — tezlik va samaradorlik muhim bo‘lgan holatlarda**  
> **eng to‘g‘ri tanlovlardan biridir.**

---