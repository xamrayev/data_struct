# 📘 ICHKI SARALASH (INTERNAL SORTING)

## 1. Ichki saralash nima?

**Ichki saralash** — bu **barcha ma’lumotlar operativ xotirada (RAM)** joylashgan holda bajariladigan saralash jarayonidir.

📌 Ya’ni:

* Ma’lumotlar **to‘liq xotiraga sig‘adi**
* Disk (fayl) bilan ishlash talab etilmaydi
* Algoritmlar tez va sodda bo‘ladi

---

## 2. Ichki va tashqi saralash farqi

| Belgisi       | Ichki saralash    | Tashqi saralash  |
| ------------- | ----------------- | ---------------- |
| Ma’lumot joyi | RAM               | Disk / Fayl      |
| Hajm          | Kichik–o‘rtacha   | Juda katta       |
| Tezlik        | Tez               | Sekin            |
| Misol         | Bubble, Selection | Merge (External) |

---

## 3. Ichki saralash algoritmlari

Eng ko‘p ishlatiladigan ichki saralashlar:

1️⃣ Bubble Sort
2️⃣ Selection Sort
3️⃣ Insertion Sort
4️⃣ Quick Sort
5️⃣ Merge Sort

---

# 4. Bubble Sort (Pufakcha saralash)

## G‘oya

Yonma-yon elementlar solishtiriladi, **katta element oxiriga “suzib chiqadi”**.

### Qanday ishlaydi?

```
[5, 1, 4, 2]
→ [1, 5, 4, 2]
→ [1, 4, 5, 2]
→ [1, 4, 2, 5]
→ [1, 2, 4, 5]
```

### Murakkablik

* Eng yomon: **O(n²)**
* Afzalligi: juda sodda

### C++ kodi

```cpp
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}
```

---

# 5. Selection Sort (Tanlab saralash)

## G‘oya

Har safar **eng kichik element topilib**, boshiga qo‘yiladi.

### Misol

```
[64, 25, 12, 22]
→ [12, 25, 64, 22]
→ [12, 22, 64, 25]
→ [12, 22, 25, 64]
```

### Murakkablik

* Har doim **O(n²)**
* Kam almashish (swap)

### C++ kodi

```cpp
void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}
```

---

# 6. Insertion Sort (Joylab saralash)

## G‘oya

Har bir element o‘zidan oldingi **saralangan qismga joylashtiriladi**.

### Kundalik analogiya

Kartalarni qo‘lda saralash.

### Misol

```
[5, 2, 4, 6]
→ [2, 5, 4, 6]
→ [2, 4, 5, 6]
```

### Murakkablik

* Eng yaxshi holat: **O(n)**
* Eng yomon: **O(n²)**

### C++ kodi

```cpp
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
```

---

# 7. Quick Sort (Tezkor saralash)

## G‘oya

* Bitta **tayanch element (pivot)** tanlanadi
* Kichiklar chapga, kattalar o‘ngga
* Rekursiv bo‘linadi

### Murakkablik

* O‘rtacha: **O(n log n)**
* Eng yomon: **O(n²)**

📌 Amalda juda tez ishlaydi.

---

# 8. Merge Sort (Birlashtirib saralash)

## G‘oya

* Massiv **bo‘linadi**
* Har bo‘lak saralanadi
* So‘ng **birlashtiriladi**

### Murakkablik

* Har doim **O(n log n)**
* Qo‘shimcha xotira talab qiladi

---

## 9. Qaysi ichki saralashni qachon tanlash?

| Holat              | Tavsiya            |
| ------------------ | ------------------ |
| Kichik massiv      | Bubble / Selection |
| Deyarli saralangan | Insertion          |
| Katta hajm         | Quick              |
| Barqarorlik muhim  | Merge              |

---

## 10. Talabalar uchun AMALIY MISOLLAR

### 🟢 1-misol (oson)

5 ta sonni **Bubble Sort** bilan saralang.

---

### 🟡 2-misol (o‘rtacha)

Massivni **Insertion Sort** bilan saralang va har qadamni chiqaring.

---

### 🔴 3-misol (qiyin)

Quick Sort yordamida:

```
[9, 3, 7, 1, 8]
```

ni saralang.

---

## 11. Talaba uchun xulosa

> **Ichki saralash — bu xotiradagi ma’lumotlarni tartiblash.
> Algoritm tanlash — samaradorlikni belgilaydi.**

---

