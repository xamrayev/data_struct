## 🔷 C++ da Graflarni Yaratish

**Mavzu:** Ma’lumotlar tuzilmasi va algoritmlar
**Usullar:**

1. Adjacency Matrix (Qo‘shnichilik matritsasi)
2. Adjacency List (Vector asosida qo‘shnichilik ro‘yxati)

---

# 1️⃣ Adjacency Matrix (Matritsa usuli)

### 📌 Nazariya

Agar grafda `V` ta tugun bo‘lsa, biz `V x V` o‘lchamdagi matritsa yaratamiz.

* `matrix[i][j] = 1` → i va j orasida qirra bor
* `matrix[i][j] = 0` → bog‘lanish yo‘q
* Og‘irlikli grafda → qiymat vazn bo‘ladi

**Murakkablik:**

* Xotira: `O(V²)`
* Qidirish: `O(1)`

---

### 🎯 Misol (Bog‘lanmagan, yo‘naltirilmagan graf)

Tugunlar: 0,1,2,3
Qirralar:
0–1
0–2
1–2
2–3

---

### 💻 C++ kodi

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    // Qirralar qo‘shish (undirected)
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 1;
    matrix[1][2] = matrix[2][1] = 1;
    matrix[2][3] = matrix[3][2] = 1;

    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

### 🖨 Natija

```
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0
```

---

### 🔎 Qo‘shnichilikni chop etish

```cpp
for(int i = 0; i < V; i++) {
    cout << i << " -> ";
    for(int j = 0; j < V; j++) {
        if(matrix[i][j] == 1)
            cout << j << " ";
    }
    cout << endl;
}
```

---

# 2️⃣ Adjacency List (Vector usuli)

### 📌 Nazariya

Bu usulda har bir tugun uchun qo‘shnilar ro‘yxati saqlanadi.

```cpp
vector<vector<int>> adj;
```

**Murakkablik:**

* Xotira: `O(V + E)`
* Qo‘shnilarni ko‘rish: tez
* Kam qirrali graflar uchun optimal

---

### 💻 C++ kodi

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Qirralar qo‘shish
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    cout << "Adjacency List:\n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

### 🖨 Natija

```
0 -> 1 2
1 -> 0 2
2 -> 0 1 3
3 -> 2
```

---

# 3️⃣ Directed (Yo‘naltirilgan) graf farqi

Agar graf yo‘naltirilgan bo‘lsa:

Matrixda:

```cpp
matrix[u][v] = 1;
```

(lekin `matrix[v][u]` qo‘shilmaydi)

Listda:

```cpp
adj[u].push_back(v);
```

---

# 4️⃣ Weighted (Og‘irlikli) graf

### Matrix:

```cpp
matrix[u][v] = weight;
```

### List:

```cpp
vector<vector<pair<int,int>>> adj;
adj[u].push_back({v, weight});
```

---

# 5️⃣ Qachon qaysi usul?

| Holat                             | Matrix | List |
| --------------------------------- | ------ | ---- |
| Tugun ko‘p, qirra kam             | ❌      | ✅    |
| Graf zich                         | ✅      | ❌    |
| Qirra mavjudligini tez tekshirish | ✅      | ❌    |
| Xotira tejash                     | ❌      | ✅    |

---

# 🔥 Xulosa

Grafni yaratishning 2 asosiy usuli bor:

* **Adjacency Matrix** → sodda, lekin xotira ko‘p ishlatadi
* **Adjacency List (vector)** → samarali va amaliy

Agar siz algoritmlar (BFS, DFS, Dijkstra, Prim, Kruskal) o‘rganmoqchi bo‘lsangiz — **vector usuli professional standart hisoblanadi**.

---
