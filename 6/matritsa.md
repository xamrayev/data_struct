# 📘 Topshiriq: Adjacency Matrix (Matritsa) usulida graf

## 🎯 Masala: 5 ta talaba (0–4)

Talabalar orasidagi do‘stlik bog‘lanishlari (yo‘naltirilmagan graf):

```
0 – 1
0 – 2
1 – 3
2 – 3
3 – 4
```

---

## 🔷 1. Graf ko‘rinishi

---

## 🔷 2. Vazifa talablari

Talaba quyidagilarni bajarishi kerak:

1. 5x5 o‘lchamdagi adjacency matrix yaratish.
2. Qirralarni matritsaga kiritish.
3. Matritsani to‘liq chop etish.
4. Har bir tugunning qo‘shnilarini alohida chiqarish:

   ```
   0 -> 1 2
   1 -> ...
   ```
5. 0 va 4 o‘rtasida to‘g‘ridan-to‘g‘ri bog‘lanish bor-yo‘qligini tekshirish.

---

# 💻 C++ Yechim (Faqat Matrix usuli)

```cpp
#include <iostream>
using namespace std;

int main() {
    const int V = 5;
    int matrix[V][V] = {0};   // Barcha qiymatlar 0

    // Qirralarni qo‘shish (undirected)
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 1;
    matrix[1][3] = matrix[3][1] = 1;
    matrix[2][3] = matrix[3][2] = 1;
    matrix[3][4] = matrix[4][3] = 1;

    // 1️⃣ Matritsani chop etish
    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nQo‘shnichilik ro‘yxati:\n";

    // 2️⃣ Qo‘shnilarni chop etish
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(int j = 0; j < V; j++) {
            if(matrix[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    // 3️⃣ 0 va 4 orasida bog‘lanish bormi?
    if(matrix[0][4] == 1)
        cout << "\n0 va 4 orasida bog‘lanish mavjud.\n";
    else
        cout << "\n0 va 4 orasida to‘g‘ridan-to‘g‘ri bog‘lanish yo‘q.\n";

    return 0;
}
```

---

# 🖨 Kutiladigan natija

### Matritsa:

```
0 1 1 0 0
1 0 0 1 0
1 0 0 1 0
0 1 1 0 1
0 0 0 1 0
```

### Qo‘shnichilik:

```
0 -> 1 2
1 -> 0 3
2 -> 0 3
3 -> 1 2 4
4 -> 3
```

---

# 🧠 Tahliliy savollar

1. Bu graf zichmi yoki siyrakmi?
2. Agar talabalar soni 1000 ta bo‘lsa, matrix usuli samaralimi?
3. Matritsa xotira murakkabligi qanday?

---

