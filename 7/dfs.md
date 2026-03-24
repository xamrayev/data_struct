## Graf strukturasida qidirish: **DFS (Depth-First Search)**

**Fan:** Ma’lumotlar tuzilmalari va algoritmlar  
**Dasturlash tili:** C++

---

# 1\. DFS haqida tushuncha

**DFS (Depth-First Search)** — grafni **chuqurlik bo‘yicha qidirish algoritmi** hisoblanadi.

Algoritm quyidagi tamoyil asosida ishlaydi:

*   Boshlang‘ich tugundan boshlanadi
*   Eng birinchi qo‘shni tugunga o‘tadi
*   Keyin yana uning qo‘shnisiga o‘tadi
*   Shu tarzda **oxirigacha chuqurlashib boradi**
*   Agar davom etish mumkin bo‘lmasa, **orqaga qaytadi (backtracking)**

DFS ko‘pincha **stack** yoki **rekursiya** yordamida ishlaydi.

---

# 2\. DFS qayerda ishlatiladi

DFS quyidagi masalalarda ishlatiladi:

*   Grafdagi **barcha tugunlarni aylanib chiqish**
*   **Yo‘l mavjudligini tekshirish**
*   **Topologik saralash**
*   **Cycle (halqa) aniqlash**
*   **Connected componentlarni topish**
*   **Labirint yoki yo‘l topish masalalari**

Misol graf:

```
    0
   / \
  1   2
  |   |
  3   4
```

0 dan DFS ishlasa:

```
0 → 1 → 3 → 2 → 4
```

---

# 3\. DFS algoritmi ishlash bosqichlari

Boshlang‘ich tugunni tanlash

Uni **visited** deb belgilash

Tugunni ekranga chiqarish

Uning qo‘shnilarini tekshirish

Agar qo‘shni hali ko‘rilmagan bo‘lsa:

*   unga o‘tish

Agar davom etish mumkin bo‘lmasa:

*   oldingi tugunga qaytish

---

# 4\. DFS algoritmining murakkabligi

| Ko‘rsatkich | Qiymat |
| --- | --- |
| Vaqt murakkabligi | **O(V + E)** |
| Xotira murakkabligi | **O(V)** |

Bu yerda:

*   **V** — tugunlar soni
*   **E** — qirralar soni

---

# 5\. C++ da DFS algoritmi

```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {

    int n = 5; // grafdagi tugunlar soni

    // grafni adjacency matrix ko‘rinishida beramiz
    int graph[5][5] = {
        {0,1,1,0,0}, // 0 tugun 1 va 2 bilan bog‘langan
        {0,0,0,1,0}, // 1 tugun 3 bilan bog‘langan
        {0,0,0,0,1}, // 2 tugun 4 bilan bog‘langan
        {0,0,0,0,0}, // 3 tugunning qo‘shnisi yo‘q
        {0,0,0,0,0}  // 4 tugunning qo‘shnisi yo‘q
    };

    bool visited[5]; // tugunlar ko‘rilganligini saqlaydi

    // boshida barcha tugunlarni ko‘rilmagan deb belgilaymiz
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    stack<int> s; // DFS uchun stack

    int start = 0; // boshlang‘ich tugun

    s.push(start); // stack ga boshlang‘ich tugunni qo‘shamiz

    cout << "DFS natijasi: ";

    while(!s.empty()){ // stack bo‘sh bo‘lmaguncha ishlaydi

        int v = s.top(); // stack tepasidagi elementni olamiz

        s.pop(); // stack dan olib tashlaymiz

        // agar tugun hali ko‘rilmagan bo‘lsa
        if(visited[v] == false){

            cout << v << " "; // tugunni chiqaramiz

            visited[v] = true; // tugunni ko‘rilgan deb belgilaymiz

            // v tugunning barcha qo‘shnilarini tekshiramiz
            for(int i=n-1;i>=0;i--){

                // agar qirra mavjud va tugun hali ko‘rilmagan bo‘lsa
                if(graph[v][i] == 1 && visited[i] == false){

                    s.push(i); // stack ga qo‘shamiz

                }
            }

        }

    }

    return 0;
}
```

---

# 6\. Kod ishlash jarayoni

Graf:

```
0 → 1
0 → 2
1 → 3
2 → 4
```

Boshlanish:

```
Stack: 0
```

1-qadam

```
0 chiqadi
Stack: 2 1
```

2-qadam

```
1 chiqadi
Stack: 2 3
```

3-qadam

```
3 chiqadi
Stack: 2
```

4-qadam

```
2 chiqadi
Stack: 4
```

5-qadam

```
4 chiqadi
Stack: bo‘sh
```

Natija:

```
0 1 3 2 4
```

---

# 7\. BFS va DFS farqi

| Xususiyat | BFS | DFS |
| --- | --- | --- |
| Qidirish usuli | kenglik bo‘yicha | chuqurlik bo‘yicha |
| Data structure | Queue | Stack |
| Eng qisqa yo‘l | topadi | har doim emas |
| Ishlash usuli | Level | Deep |

---

# 8\. Talabalar uchun mashqlar

### 1-masala

Quyidagi graf uchun DFS yozing:

```
0 → 1
0 → 2
1 → 3
1 → 4
2 → 5
```

---

### 2-masala

Boshlang‘ich tugun **2** bo‘lgan DFS yozing.

---

### 3-masala

DFS algoritmini **adjacency list** yordamida yozing.

---

### 4-masala

DFS yordamida grafda **cycle mavjudligini aniqlovchi dastur** yozing.

---