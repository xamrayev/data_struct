# 📘 Selection Sort (Tanlab saralash)

## 1\. Selection Sort nima?

**Selection Sort** — bu **oddiy saralash algoritmi** bo‘lib, u har bir bosqichda **eng kichik (yoki eng katta) elementni topib**, uni massivning **boshi bilan almashtirish** tamoyiliga asoslanadi.

📌 Algoritm nomining ma’nosi:

> Har safar bitta element **tanlab olinadi (select)** va o‘z joyiga qo‘yiladi.

---

## 2\. Qachon Selection Sort ishlatiladi?

✔ Algoritmlarni **o‘rganish va tushuntirish** uchun  
✔ **Kichik hajmli** massivlar uchun  
✔ **Almashishlar (swap) soni kam bo‘lishi** kerak bo‘lganda

❌ Katta hajmli massivlar uchun **samarasiz**

---

## 3\. Selection Sort g‘oyasi (oddiy tilda)

1.  Massiv boshidan boshlab yuriladi
2.  Qolgan elementlar ichidan **eng kichigi topiladi**
3.  U **joriy pozitsiyadagi element bilan almashtiriladi**
4.  Keyingi pozitsiyaga o‘tiladi
5.  Jarayon oxirigacha davom etadi

---

## 4\. Qadamlar bilan ishlash (misol)

### Berilgan massiv:

```
[64, 25, 12, 22]
```

### 1-bosqich

*   Eng kichik: **12**
*   64 bilan almashtiriladi

```
[12, 25, 64, 22]
```

### 2-bosqich

*   Qolganlardan eng kichik: **22**
*   25 bilan almashtiriladi

```
[12, 22, 64, 25]
```

### 3-bosqich

*   Eng kichik: **25**
*   64 bilan almashtiriladi

```
[12, 22, 25, 64]
```

👉 Massiv saralandi

---

## 5\. Psevdokod

```
for i = 0 dan n-2 gacha
    minIndex = i
    for j = i+1 dan n-1 gacha
        agar a[j] < a[minIndex]
            minIndex = j
    almashtir(a[i], a[minIndex])
```

---

## 6\. C++ da Selection Sort (oddiy namuna)

```cpp
#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

int main() {
    int a[] = {64, 25, 12, 22};
    int n = 4;

    selectionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
```

### Natija:

```
12 22 25 64
```

---

## 7\. Selection Sort xususiyatlari

### ⏱ Murakkablik (Time Complexity)

| Holat | Murakkablik |
| --- | --- |
| Eng yaxshi | O(n²) |
| O‘rtacha | O(n²) |
| Eng yomon | O(n²) |

📌 **Eslatma:** Selection Sort har doim massivni to‘liq ko‘zdan kechiradi.

---

### 💾 Xotira murakkabligi

*   **O(1)** (in-place algoritm)

---

## 8\. Afzallik va kamchiliklar

### Afzalliklar

✔ Juda sodda va tushunarli  
✔ Almashishlar soni kam  
✔ Xotira talab qilmaydi

### Kamchiliklar

❌ Juda sekin  
❌ Oldindan saralangan massivda ham tezlashmaydi

---

## 9\. Bubble Sort bilan qisqa taqqoslash

| Xususiyat | Bubble Sort | Selection Sort |
| --- | --- | --- |
| Taqqoslashlar | Ko‘p | Ko‘p |
| Swap | Ko‘p | Kam |
| Tezlashish | Bor (optimallashtirish) | Yo‘q |
| O‘rganish | Oson | Oson |

---

## 10\. Talabalar uchun AMALIY MISOLLAR

### 🟢 1-misol (oson)

Quyidagi massivni Selection Sort bilan **o‘sish tartibida** saralang:

```
[7, 3, 9, 1, 5]
```

---

### 🟡 2-misol (o‘rtacha)

Massivni Selection Sort bilan saralang va  
**har bir bosqichdan keyin massiv holatini** chiqaring.

---

### 🔴 3-misol (qiyin)

Selection Sort yordamida massivni  
**kamayish (descending) tartibida** saralang.

---

## 11\. Talaba uchun yodda qoladigan xulosa

> **Selection Sort — “top va joyiga qo‘y” tamoyiliga asoslangan**  
> **eng sodda saralash algoritmlaridan biridir.**

---