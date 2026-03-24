Keling, AVL daraxt ishlashini **6 ta son** bilan to‘liq va tushunarli qilib ko‘rib chiqamiz.

---

## 🔢 Ketma-ketlik:

`10 → 20 → 30 → 40 → 50 → 25`

---

## 1️⃣ 10

```
10
```

---

## 2️⃣ 20

```
10
  \
   20
```

Balans OK.

---

## 3️⃣ 30 → ❌ (RR holat)

```
10
  \
   20
     \
      30
```

🔁 **Left rotation (10 da):**

```
   20
  /  \
10    30
```

---

## 4️⃣ 40

```
   20
  /  \
10    30
          \
           40
```

Balans OK.

---

## 5️⃣ 50 → ❌ (RR holat 30 da)

```
   20
  /  \
10    30
          \
           40
             \
              50
```

🔁 **Left rotation (30 da):**

```
   20
  /  \
10    40
      / \
    30   50
```

---

## 6️⃣ 25 → ❌ (RL holat 20 da)

```
   20
  /  \
10    40
      / \
    30   50
   /
 25
```

Bu yerda:

*   20 → o‘ng tomoni og‘ir
*   40 → chap tomoni og‘ir  
    👉 **Right-Left (RL)** holat

---

## 🔁 2 bosqichli rotatsiya

### 1\. Right rotation (40 da)

```
   20
  /  \
10    30
      / \
    25   40
            \
             50
```

### 2\. Left rotation (20 da)

```
      30
     /  \
   20    40
  / \      \
10  25      50
```

---

## ✅ Yakuniy AVL daraxt

```
      30
     /  \
   20    40
  / \      \
10  25      50
```

---

## 🧠 Xulosa

Har qo‘shishda balans tekshirildi

3 marta rotatsiya bo‘ldi:

*   RR (10 da)
*   RR (30 da)
*   RL (20 da)

---