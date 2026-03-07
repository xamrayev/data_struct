# 📘 Topshiriq: Adjacency List (Vector) usulida graf

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

1. `vector<vector<int>>` orqali graf yaratish.
2. Qirralarni qo‘shish.
3. Har bir tugunning qo‘shnilarini chop etish.
4. 0 va 4 o‘rtasida to‘g‘ridan-to‘g‘ri bog‘lanish borligini tekshirish.
5. Har bir tugunning darajasini (degree) aniqlash.

---

# 💻 C++ Yechim (Faqat Vector / Adjacency List)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int V = 5;
    vector<vector<int>> adj(V);

    // Qirralarni qo‘shish (undirected graf)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // 1️⃣ Qo‘shnichilikni chop etish
    cout << "Adjacency List:\n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // 2️⃣ 0 va 4 orasida bog‘lanish bormi?
    bool connected = false;
    for(int neighbor : adj[0]) {
        if(neighbor == 4) {
            connected = true;
            break;
        }
    }

    if(connected)
        cout << "\n0 va 4 orasida bog‘lanish mavjud.\n";
    else
        cout << "\n0 va 4 orasida to‘g‘ridan-to‘g‘ri bog‘lanish yo‘q.\n";

    // 3️⃣ Har bir tugunning darajasi
    cout << "\nTugun darajalari:\n";
    for(int i = 0; i < V; i++) {
        cout << "Degree(" << i << ") = " << adj[i].size() << endl;
    }

    return 0;
}
```

---

# 🖨 Kutiladigan natija

```
Adjacency List:
0 -> 1 2
1 -> 0 3
2 -> 0 3
3 -> 1 2 4
4 -> 3

0 va 4 orasida to‘g‘ridan-to‘g‘ri bog‘lanish yo‘q.

Tugun darajalari:
Degree(0) = 2
Degree(1) = 2
Degree(2) = 2
Degree(3) = 3
Degree(4) = 1
```

---

# 🧠 Tahliliy savollar

1. Qaysi tugun eng ko‘p bog‘langan?
2. Bu graf siyrakmi yoki zichmi?
3. Agar talabalar soni 10 000 bo‘lsa, nega vector usuli samaraliroq?

---

