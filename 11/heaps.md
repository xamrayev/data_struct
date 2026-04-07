## Mavzu: Uyumlarni saralash (Heap Sort) va C++ da realizatsiya qilish

---

## 1. Darsning maqsadi

Talabalar:

* uyum (heap) tushunchasini o‘rganadi;
* max-heap va min-heap farqini tushunadi;
* heap sort algoritmini bosqichma-bosqich anglaydi;
* C++ da oddiy heap sort yozishni o‘rganadi;
* real hayotdagi qo‘llanilishini biladi.

---

## 2. Nazariy qism

### 2.1. Uyum (Heap) nima?

**Heap** — bu **to‘liq ikkilik daraxt** bo‘lib, unda maxsus tartib mavjud.

---

### 2.2. Turlari

#### 🔹 Max-Heap

* Har tugun **farzandlaridan katta yoki teng**

```text
        50
       /  \
     30    40
    / \   /
   10 20 35
```

---

#### 🔹 Min-Heap

* Har tugun **farzandlaridan kichik yoki teng**

```text
        10
       /  \
     20    30
    / \   /
   40 50 35
```

---

## 3. Heap Sort g‘oyasi

### Asosiy fikr:

1. Massivdan **max-heap** quriladi
2. Eng katta element (root) oxiriga qo‘yiladi
3. Qolgan qism yana heap qilinadi
4. Shu jarayon takrorlanadi

---

### Misol:

```text
Massiv: 4 10 3 5 1
```

---

## 4. Heap daraxtni massivda ifodalash

Agar indeks `i` bo‘lsa:

* chap farzand: `2*i + 1`
* o‘ng farzand: `2*i + 2`
* ota: `(i-1)/2`

---

# 📘 5. C++ realizatsiya (oddiy va tushunarli)

---

## 🔹 5.1. Heapify funksiyasi

👉 Bu funksiya tugunni “heap” holatiga keltiradi

```cpp
#include <iostream>
using namespace std;

// Heapify funksiyasi
void heapify(int arr[], int n, int i) {
    int largest = i;        // eng katta element indeks
    int left = 2*i + 1;     // chap farzand
    int right = 2*i + 2;    // o‘ng farzand

    // chap farzand katta bo‘lsa
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // o‘ng farzand katta bo‘lsa
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // agar o‘zgarish bo‘lsa
    if (largest != i) {
        swap(arr[i], arr[largest]); // almashtiramiz

        // rekursiv davom ettiramiz
        heapify(arr, n, largest);
    }
}
```

---

## 🔹 5.2. Heap Sort funksiyasi

```cpp
void heapSort(int arr[], int n) {

    cout << "\n[1] Max-heap qurilmoqda...\n";

    // 1. Heap qurish
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Heap: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\n[2] Saralash boshlanmoqda...\n";

    // 2. Birma-bir chiqarish
    for (int i = n-1; i > 0; i--) {

        cout << "\nEng katta element oxiriga o‘tkazildi: " << arr[0] << endl;

        swap(arr[0], arr[i]); // rootni oxiriga

        cout << "Hozirgi massiv: ";
        for (int j = 0; j < n; j++) cout << arr[j] << " ";
        cout << endl;

        heapify(arr, i, 0); // qolgan qismini heap qilish
    }
}
```

---

## 🔹 5.3. Main dastur

```cpp
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    cout << "Boshlang‘ich massiv: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "\nSaralangan massiv: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
```

---

# 📘 6. Bosqichma-bosqich tushunish

### 🔹 1-bosqich: Heap qurish

```text
4 10 3 5 1 → 10 5 3 4 1
```

---

### 🔹 2-bosqich: Eng kattani oxirga qo‘yish

```text
10 → oxirga → 1 5 3 4 | 10
```

---

### 🔹 3-bosqich: Qolganini heap qilish

```text
5 4 3 1 | 10
```

---

### 🔹 Yakuniy natija:

```text
1 3 4 5 10
```

---

# 📘 7. Afzalliklari va kamchiliklari

### ✅ Afzalliklari

* O(n log n)
* qo‘shimcha xotira talab qilmaydi
* barqaror ishlaydi

### ❌ Kamchiliklari

* implementatsiya tushunish qiyinroq
* cache uchun unchalik optimal emas

---

# 📘 8. Hayotda ishlatilish sohalari

### 🔹 1. Priority Queue (navbatlar)

Masalan:

* eng muhim vazifani birinchi bajarish

---

### 🔹 2. Real-time tizimlar

Masalan:

* OS scheduler
* server requestlar

---

### 🔹 3. O‘yinlar va AI

* eng yaxshi yurishni tanlash
* qaror daraxtlari

---

### 🔹 4. Tarmoq (networking)

* paketlarni prioritet bilan yuborish

---

# 📘 9. Amaliy topshiriqlar

### 1-topshiriq

Kodni ishga tushiring va chiqishni yozing.

---

### 2-topshiriq

Quyidagi massivni saralang:

```
15, 3, 17, 10, 84, 19, 6, 22, 9
```

---

### 3-topshiriq

Heapify funksiyasiga `cout` qo‘shing:

👉 qachon swap bo‘lyapti ko‘rsin

---

### 4-topshiriq

Min-heap asosida sort yozing

---

### 5-topshiriq

Foydalanuvchidan N ta son olib saralang

---

### 6-topshiriq

Massivdagi eng katta 3 ta elementni toping

---

# 📘 10. Savollar

1. Heap nima?
2. Max-heap va Min-heap farqi nima?
3. Heap sort qanday ishlaydi?
4. Nima uchun O(n log n)?
5. Qaysi hollarda heap sort ishlatiladi?

---

# 📘 11. Uyga vazifa

* Priority Queue ni C++ da yozing
* Heap daraxtni chizuvchi dastur yozing
* Heap sortni vizual qilib tushuntiring

---

# 📘 12. Xulosa

Heap sort — samarali va ishonchli saralash algoritmi. U massivni daraxt sifatida ko‘rib chiqadi va eng katta elementni bosqichma-bosqich oxiriga chiqaradi. Bu algoritm real tizimlarda (OS, serverlar, AI) keng qo‘llaniladi.

---


