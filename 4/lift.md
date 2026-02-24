
* 5 ta buyurtma olinadi
* 2 ta `list` ga ajratiladi
* `bubble sort` bilan saralanadi
* `queue` ga joylanadi
* Lift bosqichma-bosqich harakat qiladi

---

# ✅ C++ (Real qavatma-qavat harakat)

```cpp
#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Bubble sort (list uchun)
void bubbleSort(list<int>& lst, bool ascending = true) {
    if (lst.empty()) return;

    for (auto i = lst.begin(); i != lst.end(); i++) {
        for (auto j = lst.begin(); next(j) != lst.end(); j++) {
            auto k = next(j);

            if (ascending) {
                if (*j > *k)
                    swap(*j, *k);
            } else {
                if (*j < *k)
                    swap(*j, *k);
            }
        }
    }
}

// Liftni qavatma-qavat harakatlantirish
void moveLift(int& current, int target) {

    while (current < target) {
        current++;
        cout << "Lift yuqoriga: " << current << endl;
    }

    while (current > target) {
        current--;
        cout << "Lift pastga: " << current << endl;
    }

    cout << "Lift to'xtadi: " << current << endl << endl;
}

int main() {

    list<int> requests;
    int from, to;

    cout << "5 ta buyurtma kiriting (from to):\n";
    for (int i = 0; i < 5; i++) {
        cin >> from >> to;
        requests.push_back(from);   // faqat from kerak
    }

    int currentFloor;
    cout << "Lift qaysi qavatda turibdi?\n";
    cin >> currentFloor;

    list<int> yuqori;
    list<int> past;

    // 2 ta listga ajratish
    for (int floor : requests) {
        if (floor >= currentFloor)
            yuqori.push_back(floor);
        else
            past.push_back(floor);
    }

    // Bubble sort
    bubbleSort(yuqori, true);   // kichikdan kattaga
    bubbleSort(past, false);    // kattadan kichikka

    // Queue
    queue<int> q;

    for (int f : yuqori)
        q.push(f);

    for (int f : past)
        q.push(f);

    cout << "\n--- Lift harakati boshlandi ---\n\n";
    cout << "Boshlanish qavati: " << currentFloor << endl << endl;

    // Harakat
    while (!q.empty()) {
        int target = q.front();
        q.pop();
        moveLift(currentFloor, target);
    }

    cout << "--- Barcha buyurtmalar bajarildi ---" << endl;

    return 0;
}
```

---

# 🔎 Ishlash misoli

### Input

```
2 8
9 1
4 10
7 0
1 5
5
```

### Chiqish (real harakat)

```
Boshlanish qavati: 5

Lift yuqoriga: 6
Lift yuqoriga: 7
Lift to'xtadi: 7

Lift yuqoriga: 8
Lift yuqoriga: 9
Lift to'xtadi: 9

Lift pastga: 8
Lift pastga: 7
Lift pastga: 6
Lift pastga: 5
Lift pastga: 4
Lift to'xtadi: 4
...
```

---
