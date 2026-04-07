# 📘 MAVZU: Uyumlarni saralash (Heap Sort) va ASCII daraxt bilan vizualizatsiya (C++)

---

# 🎯 1. Dars maqsadi

Talaba:

* heap tushunchasini o‘rganadi
* heap sort algoritmini tushunadi
* massiv → daraxt bog‘lanishini ko‘radi
* ASCII daraxt orqali vizual tushunadi
* interaktiv dastur yaratadi

---

# 🧩 2. Yondashuv (qanday ishlaymiz)

Dastur quyidagi bosqichlarda yoziladi:

1. Kutubxonalar va asosiy strukturani yozish
2. Massivni chiqarish funksiyasi
3. ASCII daraxt chizish funksiyasi
4. Heapify funksiyasi
5. Heap qurish funksiyasi
6. Heap Sort funksiyasi
7. Menu (interaktiv boshqaruv)

👉 Har bosqichni **copy–paste qilib qo‘shib borasiz**

---

# 🧱 3. 1-QADAM: Asosiy skelet

📌 Shu kodni yozing:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Heap Sort Dasturi Ishga Tushdi\n";
    return 0;
}
```

✅ Tekshirib ishga tushiring

---

# 🧱 4. 2-QADAM: Massivni chiqarish

📌 `main` dan yuqoriga qo‘shing:

```cpp
void printArray(int arr[], int n) {
    cout << "Massiv: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
```

---

# 🧱 5. 3-QADAM: ASCII daraxt chizish

📌 Qo‘shing:

```cpp
void printTree(int arr[], int n) {
    if (n == 0) return;

    int height = log2(n) + 1;
    int maxWidth = pow(2, height);

    int index = 0;

    cout << "\nASCII Daraxt:\n";

    for (int level = 0; level < height; level++) {
        int nodes = pow(2, level);
        int space = maxWidth / (nodes + 1);

        for (int s = 0; s < space; s++) cout << " ";

        for (int i = 0; i < nodes && index < n; i++) {
            cout << arr[index++];

            for (int s = 0; s < space; s++) cout << " ";
        }

        cout << "\n\n";
    }
}
```

---

# 🧱 6. 4-QADAM: Heapify (eng muhim qism)

📌 Qo‘shing:

```cpp
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    cout << "\n[Heapify] i = " << i << endl;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        cout << "Swap: " << arr[i] << " <-> " << arr[largest] << endl;

        swap(arr[i], arr[largest]);

        printArray(arr, n);
        printTree(arr, n);

        heapify(arr, n, largest);
    }
}
```

---

# 🧱 7. 5-QADAM: Heap qurish

📌 Qo‘shing:

```cpp
void buildHeap(int arr[], int n) {
    cout << "\n[Heap qurilmoqda...]\n";

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "\n[Heap tayyor]\n";
    printTree(arr, n);
}
```

---

# 🧱 8. 6-QADAM: Heap Sort

📌 Qo‘shing:

```cpp
void heapSort(int arr[], int n) {

    buildHeap(arr, n);

    for (int i = n-1; i > 0; i--) {

        cout << "\nROOT oxiriga o‘tdi: " << arr[0] << endl;

        swap(arr[0], arr[i]);

        cout << "Qolgan daraxt:\n";
        printTree(arr, i);

        heapify(arr, i, 0);
    }

    cout << "\n[Saralash tugadi]\n";
}
```

---

# 🧱 9. 7-QADAM: Interaktiv MENU

📌 `main()` ni quyidagiga almashtiring:

```cpp
int main() {
    int arr[100];
    int n = 0;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Massiv kiritish\n";
        cout << "2. Heap qurish\n";
        cout << "3. Heap Sort\n";
        cout << "4. Massivni ko‘rish\n";
        cout << "0. Chiqish\n";
        cout << "Tanlov: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Element soni: ";
            cin >> n;

            cout << "Elementlarni kiriting:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;

        case 2:
            buildHeap(arr, n);
            break;

        case 3:
            heapSort(arr, n);
            break;

        case 4:
            printArray(arr, n);
            printTree(arr, n);
            break;

        case 0:
            cout << "Dastur tugadi\n";
            break;

        default:
            cout << "Xato tanlov!\n";
        }

    } while (choice != 0);

    return 0;
}
```

---

# 🧪 10. Test qilish

📌 Kiritish:

```text
5
4 10 3 5 1
```

📌 Natija:

* heap quriladi
* daraxt chiziladi
* har swap ko‘rinadi

---

# 📊 11. Talaba nimani o‘rganadi

* massiv va daraxt bog‘liqligi
* heapify qanday ishlaydi
* recursion
* vizual debugging

---

# 📝 12. Amaliy topshiriqlar

### 🔹 1

ASCII daraxtni yaxshilang:

```
/   \
```

branch qo‘shing

---

### 🔹 2

Swap sonini hisoblang

---

### 🔹 3

Min-heap versiya yozing

---

### 🔹 4

Eng katta 3 elementni ajrating

---

# 📌 13. Xulosa

Bu qo‘llanma orqali talaba:

✅ noldan dastur yozadi
✅ algoritmni ko‘radi
✅ daraxtni tushunadi
✅ real tizimga yaqin ishlaydi

---

Agar xohlasangiz, keyingi bosqich:

👉 GUI versiya (visual app)
👉 animatsiya (step delay bilan)
👉 STL bilan professional variant

ham tayyorlab beraman.
