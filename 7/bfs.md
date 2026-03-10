## Graf strukturasida qidirish: **BFS (Breadth-First Search)**

**Fan:** Ma’lumotlar tuzilmalari va algoritmlar
**Dasturlash tili:** C++

---

# 1. BFS haqida tushuncha

**BFS (Breadth-First Search)** — grafni **kenglik bo‘yicha qidirish algoritmi** hisoblanadi.

Algoritm quyidagi tamoyil asosida ishlaydi:

* Avval **boshlang‘ich tugun (vertex)** olinadi.
* Shu tugunning **barcha qo‘shni tugunlari** tekshiriladi.
* Keyin ularning qo‘shnilari tekshiriladi.
* Shu tarzda graf **qatlam (level)** bo‘yicha aylanib chiqiladi.

BFS algoritmi **queue (navbat)** ma’lumotlar tuzilmasidan foydalanadi.

---

# 2. BFS qayerda ishlatiladi

BFS quyidagi masalalarda keng qo‘llaniladi:

* Grafda **eng qisqa yo‘lni topish** (unweighted graph)
* **Ijtimoiy tarmoqlar** analizida
* **Yo‘l topish algoritmlarida** (GPS, robot navigatsiyasi)
* **Tarmoqlarni tekshirish**
* **O‘yin algoritmlarida**

Misol:

Agar graf quyidagicha bo‘lsa:

```
    0
   / \
  1   2
  |   |
  3   4
```

0 dan BFS ishlasa:

```
0 → 1 → 2 → 3 → 4
```

---

# 3. BFS algoritmi ishlash bosqichlari

1. Boshlang‘ich tugunni tanlash
2. Uni **queue** ga qo‘shish
3. Tugunni **visited** qilib belgilash
4. Queue dan element olish
5. Uning qo‘shnilarini tekshirish
6. Agar qo‘shni hali ko‘rilmagan bo‘lsa:

   * queue ga qo‘shiladi
   * visited qilinadi
7. Queue bo‘shaguncha davom etadi

---

# 4. BFS algoritmining murakkabligi

| Ko‘rsatkich         | Qiymat       |
| ------------------- | ------------ |
| Vaqt murakkabligi   | **O(V + E)** |
| Xotira murakkabligi | **O(V)**     |

Bu yerda:

* **V** — tugunlar soni
* **E** — qirralar soni

---

# 5. C++ da BFS algoritmi

Quyidagi kod:

* **Adjacency Matrix** ishlatadi
* **Funksiyasiz**
* **Oddiy BFS**
* Har qator **kommentariya bilan tushuntirilgan**

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n = 5; // grafdagi tugunlar soni

    // Grafni adjacency matrix ko‘rinishida beramiz
    int graph[5][5] = {
        {0,1,1,0,0}, // 0 tugun 1 va 2 bilan bog‘langan
        {0,0,0,1,0}, // 1 tugun 3 bilan bog‘langan
        {0,0,0,0,1}, // 2 tugun 4 bilan bog‘langan
        {0,0,0,0,0}, // 3 tugunning qo‘shnisi yo‘q
        {0,0,0,0,0}  // 4 tugunning qo‘shnisi yo‘q
    };

    bool visited[5]; // tugunlar ko‘rilganligini saqlash

    // barcha tugunlarni boshida ko‘rilmagan deb belgilaymiz
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    queue<int> q; // BFS uchun navbat (queue)

    int start = 0; // boshlang‘ich tugun

    visited[start] = true; // boshlang‘ich tugunni ko‘rilgan deb belgilaymiz

    q.push(start); // boshlang‘ich tugunni queue ga qo‘shamiz

    cout << "BFS natijasi: ";

    while(!q.empty()){ // queue bo‘sh bo‘lmaguncha davom etadi

        int v = q.front(); // navbat boshidagi elementni olamiz

        q.pop(); // uni queue dan olib tashlaymiz

        cout << v << " "; // tugunni ekranga chiqaramiz

        // v tugunning barcha qo‘shnilarini tekshiramiz
        for(int i=0;i<n;i++){

            // agar v dan i ga qirra bo‘lsa va u hali ko‘rilmagan bo‘lsa
            if(graph[v][i] == 1 && visited[i] == false){

                visited[i] = true; // tugunni ko‘rilgan deb belgilaymiz

                q.push(i); // queue ga qo‘shamiz

            }
        }
    }

    return 0;
}
```

---

# 6. Kod ishlash jarayoni

Graf:

```
0 → 1
0 → 2
1 → 3
2 → 4
```

Boshlanish:

```
Queue: 0
```

1-qadam

```
0 chiqadi
Queue: 1 2
```

2-qadam

```
1 chiqadi
Queue: 2 3
```

3-qadam

```
2 chiqadi
Queue: 3 4
```

4-qadam

```
3 chiqadi
Queue: 4
```

5-qadam

```
4 chiqadi
Queue: bo‘sh
```

Natija:

```
0 1 2 3 4
```

---

# 7. Talabalar uchun mashqlar

### 1-masala

6 ta tugundan iborat graf tuzing va BFS yordamida chiqaring.

```
0 → 1
0 → 2
1 → 3
1 → 4
2 → 5
```

---

### 2-masala

Boshlang‘ich tugun **2** bo‘lgan BFS yozing.

---

### 3-masala

Grafni **adjacency matrix** o‘rniga **adjacency list** yordamida yozing.

---

### 4-masala

BFS yordamida **eng qisqa masofani topish** dasturini yozing.

---
