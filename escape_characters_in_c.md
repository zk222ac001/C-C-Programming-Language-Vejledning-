# 🌈 Escape Characters in C Programming

## 🎯 Learning Goal

After this lesson, you should understand:

- What escape characters are
- Why they are used
- The most important escape sequences in C
- How to use them with `printf()`

---

# 🔹 What Is an Escape Sequence?

An **escape sequence** is a special combination of characters beginning with a backslash:

```text
\
```

It tells C that the next character has a **special meaning**.

For example:

```c
printf("Hello\nWorld");
```

Here:

```text
\n
```

means:

> Move to a new line.

Output:

```text
Hello
World
```

### Visual Explanation

```text
"Hello\nWorld"
       │
       ▼
      \n
       │
       ▼
   New Line
```

---

# 🔹 Most Important Escape Sequences

| Escape Sequence | Meaning | Example |
|---|---|---|
| `\n` | New line | `"Hello\nWorld"` |
| `\t` | Tab | `"Name\tAge"` |
| `\"` | Double quote | `"Say \"Hello\""` |
| `\\` | Backslash | `"C:\\Users"` |
| `\'` | Single quote | `'\''` |
| `\0` | Null character | End of a C string |

These are the escape sequences beginners will use most frequently.

---

# 🟢 1. New Line — `\n`

`\n` moves the cursor to the next line.

### Example

```c
#include <stdio.h>

int main(void)
{
    printf("C Programming\nPython Programming\nJava Programming");

    return 0;
}
```

### Output

```text
C Programming
Python Programming
Java Programming
```

Think of `\n` as pressing:

```text
ENTER
```

---

# 🔵 2. Horizontal Tab — `\t`

`\t` adds horizontal spacing.

### Example

```c
printf("Name\tAge\tCity\n");
printf("Ali\t25\tCopenhagen\n");
```

Possible output:

```text
Name    Age     City
Ali     25      Copenhagen
```

This is useful for creating simple tables.

---

# 🟣 3. Double Quote — `\"`

Strings in C use double quotation marks.

For example:

```c
printf("Hello");
```

Suppose we want to print:

```text
He said "Hello"
```

This is incorrect:

```c
printf("He said "Hello"");
```

❌ The compiler thinks the string ends before `Hello`.

Use:

```text
\"
```

Correct:

```c
printf("He said \"Hello\"");
```

Output:

```text
He said "Hello"
```

---

# 🟠 4. Backslash — `\\`

Because `\` starts an escape sequence, we need two backslashes when we actually want to print one.

### Example

```c
printf("C:\\Users\\Student\\Documents");
```

Output:

```text
C:\Users\Student\Documents
```

### Simple Rule

```text
C Code        Output

\\      →       \
```

This is especially useful for Windows paths.

---

# 🟡 5. Single Quote — `\'`

Characters in C use single quotes:

```c
char grade = 'A';
```

If we want to store the quotation mark itself:

```c
char symbol = '\'';
```

Example:

```c
printf("%c", symbol);
```

Output:

```text
'
```

---

# 🔴 6. Null Character — `\0`

`\0` is very important when learning **strings in C**.

It represents the:

> Null character

C uses it to mark the **end of a string**.

For example:

```c
char word[] = "CAT";
```

C actually stores:

```text
C     A     T     \0
│     │     │      │
▼     ▼     ▼      ▼
┌───┬───┬───┬────┐
│ C │ A │ T │ \0 │
└───┴───┴───┴────┘
                │
                ▼
          End of String
```

Therefore `"CAT"` has:

```text
3 visible characters
+
1 null character
=
4 memory positions
```

---

# ⚠️ `'0'` and `'\0'` Are Different

Students often confuse these two.

```c
'0'
```

means the visible character:

```text
0
```

But:

```c
'\0'
```

means:

```text
Null Character
```

Comparison:

| Code | Meaning | Numeric Value |
|---|---|---:|
| `'0'` | Character zero | 48 in ASCII |
| `'\0'` | Null character | 0 |

So:

```text
'0'  ≠  '\0'
```

---

# 🧠 How Escape Sequences Work

The basic idea is:

```text
Backslash + Character
        │
        ▼
  Escape Sequence
        │
        ▼
   Special Meaning
```

Examples:

```text
\ + n   →   \n   →   New Line

\ + t   →   \t   →   Tab

\ + "   →   \"   →   Double Quote

\ + \   →   \\   →   Backslash
```

---

# 💻 Complete Example

```c
#include <stdio.h>

int main(void)
{
    printf("===== Student Information =====\n\n");

    printf("Name:\tAli\n");
    printf("Age:\t25\n");
    printf("Course:\t\"C Programming\"\n\n");

    printf("Folder:\n");
    printf("C:\\Students\\CProgramming\n");

    return 0;
}
```

### Output

```text
===== Student Information =====

Name:   Ali
Age:    25
Course: "C Programming"

Folder:
C:\Students\CProgramming
```

This example combines:

```text
\n
\t
\"
\\
```

---

# ⚠️ Common Mistakes

### ❌ Wrong Slash

Incorrect:

```c
printf("Hello/nWorld");
```

Correct:

```c
printf("Hello\nWorld");
```

Escape sequences use:

```text
\
```

not:

```text
/
```

---

### ❌ Incorrect Windows Path

Incorrect:

```c
printf("C:\Users\Student");
```

Correct:

```c
printf("C:\\Users\\Student");
```

---

### ❌ Quotes Inside a String

Incorrect:

```c
printf("Welcome to "C Programming"");
```

Correct:

```c
printf("Welcome to \"C Programming\"");
```

---

# 📌 Quick Reference

```text
┌──────────┬──────────────────────┐
│ Sequence │ Meaning              │
├──────────┼──────────────────────┤
│   \n     │ New Line             │
│   \t     │ Horizontal Tab       │
│   \"     │ Double Quote         │
│   \\     │ Backslash            │
│   \'     │ Single Quote         │
│   \0     │ Null Character       │
└──────────┴──────────────────────┘
```

---

# 🏫 Small Exercise

Write a C program that displays:

```text
===== Student =====

Name:       Ali
Course:     "C Programming"

Project Folder:
C:\Programming\Project1
```

Try to use:

```text
\n
\t
\"
\\
```

---

# 🎯 Summary

Escape sequences allow us to include **special characters and formatting** inside C strings.

The most important ones are:

```text
\n  → New Line

\t  → Tab

\"  → Double Quote

\\  → Backslash

\'  → Single Quote

\0  → End of String
```

## 🔑 Key Idea

Whenever you see:

```text
\
```

inside a C string, think:

> **Something special is coming next.**

For example:

```c
printf("Hello\nWorld");
```

means:

```text
Print Hello
    ↓
Go to next line
    ↓
Print World
```

Output:

```text
Hello
World
```

---

## 🚀 Final Takeaway

Escape sequences are small, but they are very important in C programming.

You will use them regularly when working with:

- Console output
- Strings
- File paths
- Formatted tables
- Text files
- Embedded systems
- Raspberry Pi
- Robotics
