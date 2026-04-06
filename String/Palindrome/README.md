# 🔁 Palindrome Checker

## 📌 What is a Palindrome?

A **Palindrome** is a word, phrase, or sequence that reads the **same forwards and backwards**.

> Examples: `racecar`, `madam`, `level`, `noon`, `civic`  
> Not palindromes: `hello`, `world`, `apple`

Your program checks if a given word is a palindrome using the **two-pointer technique** — and handles both uppercase and lowercase letters! ✅

---

## 🧠 How It Works

```
Word: "racecar"

start →  r  a  c  e  c  a  r  ← end
         ✅ r == r

start →  r  a  c  e  c  a  r  ← end
            ✅ a == a

start →  r  a  c  e  c  a  r  ← end
               ✅ c == c

start >= end → STOP ✅ Palindrome!
```

```
Word: "hello"

start →  h  e  l  l  o  ← end
         ❌ h != o → return false immediately
```

---

## 💡 Key Concept — Two Pointer Technique

Your code uses two pointers — `start` and `end` — that move **towards each other**:

```cpp
int start = 0;
int end = str.length() - 1;

while (start < end)
{
    // compare str[start] and str[end]
    start++;
    end--;
}
```

> If all pairs match → Palindrome ✅  
> If any pair mismatches → Not a Palindrome ❌  
> Pointers meet in the middle → done, no need to check further

---

## ⭐ Case-Insensitive Check

Your code uses `tolower()` from `<cctype>` to handle mixed case:

```cpp
if (tolower(str[start]) != tolower(str[end]))
```

```
"RaceCar" → tolower → "racecar" → ✅ Palindrome
"Madam"   → tolower → "madam"   → ✅ Palindrome
"Hello"   → tolower → "hello"   → ❌ Not Palindrome
```

> Without `tolower()`, `'R'` and `'r'` would be treated as different characters — giving wrong results!

---

## 💻 Code — `palindrome.cpp`

```cpp
#include <iostream>
#include <cctype>
using namespace std;

bool Palindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        // Case-insensitive comparison using tolower()
        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;      // Mismatch found → not a palindrome
        }
        start++;               // Move left pointer right
        end--;                 // Move right pointer left
    }
    return true;               // All pairs matched → palindrome
}

int main()
{
    string str;
    cout << "Enter word: ";
    getline(cin, str);         // Reads full line including spaces

    if (Palindrome(str))
    {
        cout << "This word is Palindrome: " << str << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                        |
|------------------|-----------------|----------------------------------------------------|
| **Best Case**    | `O(1)`          | First and last characters don't match — exit immediately |
| **Average Case** | `O(n/2)` → `O(n)` | Pointers meet halfway                            |
| **Worst Case**   | `O(n/2)` → `O(n)` | All characters match (is a palindrome)           |
| **Space**        | `O(1)`          | Only two integer pointers used                     |

> `n` = length of the string. At most **n/2 comparisons** are made since both pointers move inward simultaneously.

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Palindrome(string str)` | Checks if string is palindrome using two pointers, returns `true` or `false` |
| `main()` | Takes input with `getline()`, calls `Palindrome()`, prints result |

---

## 🔑 Why `getline()` instead of `cin`?

```cpp
getline(cin, str);    // ✅ Reads entire line including spaces
cin >> str;           // ❌ Stops at first space — "race car" becomes "race"
```

> Using `getline()` means your program can also check phrases like `"race car"` or `"never odd or even"` — not just single words!

---

## 🖥️ Sample Run

```
Enter word: racecar
This word is Palindrome: racecar
```

```
Enter word: RaceCar
This word is Palindrome: RaceCar
```

```
Enter word: hello
Not Palindrome
```

```
Enter word: Madam
This word is Palindrome: Madam
```

---

## 🌍 Famous Palindromes

| Word / Phrase     | Type    |
|-------------------|---------|
| `racecar`         | Word    |
| `madam`           | Word    |
| `level`           | Word    |
| `noon`            | Word    |
| `civic`           | Word    |
| `A man a plan a canal Panama` | Phrase |
| `Never odd or even`           | Phrase |

---

## ✅ Edge Cases Handled

| Input | Result | Reason |
|---|---|---|
| `"a"` | ✅ Palindrome | Single character is always a palindrome |
| `""` | ✅ Palindrome | Empty string — `start < end` is false immediately |
| `"Racecar"` | ✅ Palindrome | `tolower()` handles mixed case |
| `"hello"` | ❌ Not Palindrome | `h != o` on first check |

---

## 📝 Key Takeaways

- A palindrome reads the **same forwards and backwards**.
- The **two-pointer technique** is the most efficient way to check — only `n/2` comparisons needed.
- `tolower()` from `<cctype>` makes the check **case-insensitive**.
- `getline()` allows checking **phrases with spaces**, not just single words.
- Returns a clean `bool` — `true` for palindrome, `false` otherwise.
- This is a classic **string + two-pointer** problem — a pattern that appears in many other DSA problems!

---

*Part of the [DSA Learning Repository](../README.md) — Strings Section* 🧠