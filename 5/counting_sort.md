# 📊 Counting Sort — To‘liq Konspekt (C++ + Psevdokod + Misol)

## 1. Ta’rif

**Counting Sort** — bu *taqqoslashsiz* (non-comparison) saralash algoritmi.
U sonlarning qiymat oralig‘i kichik bo‘lganda juda samarali ishlaydi.

> Asosiy g‘oya: elementlarni taqqoslab emas, balki **nechta marta uchraganini sanab** saralaydi.

---

# 2. Qachon ishlatiladi?

✔ Elementlar butun son (integer) bo‘lsa
✔ Qiymatlar oralig‘i kichik bo‘lsa
✔ Masalan: 0–100 oralig‘idagi ballar

❌ Juda katta sonlar oralig‘ida (masalan 1 dan 10^9 gacha) samarali emas

---

# 3. Ishlash printsipi

Massiv:

```text
[4, 2, 2, 8, 3, 3, 1]
```

### 1-qadam: Maksimal qiymatni topish

max = 8

### 2-qadam: Count massiv yaratish

Indekslar: 0 dan 8 gacha

```
count = [0,1,2,2,1,0,0,0,1]
```

Ma’nosi:

* 1 → 1 marta
* 2 → 2 marta
* 3 → 2 marta
* 4 → 1 marta
* 8 → 1 marta

### 3-qadam: Natija massivini tuzish

```
[1,2,2,3,3,4,8]
```

---

# 4. Psevdokod

```
SANASH_SARALASH(A)
    k = A dagi eng katta qiymatni topish

    C[0...k] o‘lchamdagi sanoq massivini yaratish
    barcha elementlarini 0 ga tenglash

    // Elementlarni sanash
    A dagi har bir x elementi uchun
        C[x] = C[x] + 1

    indeks = 0

    // Saralangan massivni qayta tuzish
    i = 0 dan k gacha takrorla
        C[i] > 0 bo‘lganda
            A[indeks] = i
            indeks = indeks + 1
            C[i] = C[i] - 1
```

---

# 5. C++ Sodda Kod

```cpp
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();

    // Maksimal elementni topish
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // Count massiv
    vector<int> count(maxVal + 1, 0);

    // Nechta marta uchraganini sanash
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Natijani qayta yozish
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    cout << "Saralangan massiv:\n";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
```

---

# 6. Murakkablik Tahlili

| Parametr          | Qiymat   |
| ----------------- | -------- |
| Vaqt murakkabligi | O(n + k) |
| Xotira            | O(k)     |

Bu yerda:

* n — elementlar soni
* k — maksimal qiymat

Agar k ≈ n bo‘lsa → juda tez ishlaydi
Agar k >> n bo‘lsa → samarasiz

---

# 7. Stable Versiya (Muhim!)

Agar obyektlarni saralayotgan bo‘lsak (masalan talaba: ball + ism),
Counting Sortni **stable** qilish mumkin.

Stable versiyada:

* Prefix sum ishlatiladi
* Orqadan joylashtiriladi

Agar xohlasangiz, stable versiyasini ham yozib beraman.

---

# 8. Hayotiy Misol

Tasavvur qiling:

Imtihon ballari 0–100 oralig‘ida.

Siz:

* Har bir ball nechta marta olinganini sanaysiz
* Keyin 0 dan 100 gacha tartib bilan chiqarasiz

Hech qanday taqqoslash yo‘q.

---

# 9. Quick Sort bilan farqi

| QuickSort               | Counting Sort           |
| ----------------------- | ----------------------- |
| Taqqoslashga asoslangan | Taqqoslashsiz           |
| O(n log n)              | O(n + k)                |
| In-place                | Qo‘shimcha xotira kerak |
| Har qanday son          | Faqat kichik oralig‘    |


