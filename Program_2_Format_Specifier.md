# 🌈 Format Specifiers in C Programming

## 🎯 Learning Objectives

After this lesson, you should be able to:

- Understand what a **format specifier** is
- Use format specifiers with `printf()`
- Use format specifiers with `scanf()`
- Match C data types with the correct format specifier
- Control decimal precision
- Avoid common format-specifier mistakes

---

# 🔹 What Is a Format Specifier?

A **format specifier** tells C what type of data should be **printed or read**.

A format specifier begins with:

```text
%
```

For example:

```c
int age = 25;

printf("Age = %d", age);
```

Here:

```text
%d
```

means:

> 📌 Treat the value as an integer.

Output:

```text
Age = 25
```

---

# 🧠 Basic Concept

Consider:

```c
int age = 25;
printf("Age = %d", age);
```

Visual explanation:

```text
int age = 25
     │
     ▼
Integer Variable
     │
     ▼
    %d
     │
     ▼
printf("Age = %d", age)
     │
     ▼
Age = 25
```

So we can think of `%d` as a **placeholder**.

```text
Age = %d
      │
      ▼
Place integer value here
```

---

# 📋 Common Format Specifiers

| Format | Data Type | Example |
|---|---|---|
| `%d` | `int` | `25` |
| `%u` | `unsigned int` | `100` |
| `%f` | Floating-point output | `23.50` |
| `%c` | `char` | `A` |
| `%s` | String | `Hello` |
| `%ld` | `long int` | `100000` |
| `%lld` | `long long int` | `9000000000` |
| `%x` | Hexadecimal | `ff` |
| `%o` | Octal | `377` |
| `%p` | Pointer/address | Memory address |
| `%zu` | `size_t` | Used with `sizeof()` |

For beginners, the four most important are:

```text
%d     %f     %c     %s
```

---

# 🟢 1. `%d` — Integer

Use `%d` when printing a signed integer.

```c
int age = 25;

printf("Age = %d", age);
```

Output:

```text
Age = 25
```

Another example:

```c
int temperature = -5;

printf("Temperature = %d", temperature);
```

Output:

```text
Temperature = -5
```

### 🔍 Concept

```text
%d
 │
 ▼
Integer
 │
 ▼
25
```

---

# 🔵 2. `%f` — Floating-Point Number

Use `%f` with `printf()` to display decimal numbers.

```c
float temperature = 25.5f;

printf("Temperature = %f", temperature);
```

Output:

```text
Temperature = 25.500000
```

By default, `%f` normally displays **six digits after the decimal point**.

---

## 🎨 Controlling Decimal Places

We can control the number of digits after the decimal point.

### Two decimal places

```c
printf("%.2f", temperature);
```

Output:

```text
25.50
```

### One decimal place

```c
printf("%.1f", temperature);
```

Output:

```text
25.5
```

### Three decimal places

```c
printf("%.3f", temperature);
```

Output:

```text
25.500
```

Visual explanation:

```text
%.2f
 │ │
 │ └──── 2 digits after decimal point
 │
 └────── Floating-point format
```

---

# 🟣 3. `%c` — Character

Use `%c` for a single character.

```c
char grade = 'A';

printf("Grade = %c", grade);
```

Output:

```text
Grade = A
```

Remember:

```c
'A'
```

is a **character**.

But:

```c
"A"
```

is a **string**.

---

# 🟠 4. `%s` — String

Use `%s` for a string.

```c
char name[] = "Ali";

printf("Name = %s", name);
```

Output:

```text
Name = Ali
```

Visual:

```text
%s
 │
 ▼
String
 │
 ▼
"Ali"
```

---

# 🟡 5. `%u` — Unsigned Integer

Use `%u` for an `unsigned int`.

```c
unsigned int score = 100;

printf("Score = %u", score);
```

Output:

```text
Score = 100
```

Unsigned integers represent values starting from:

```text
0
```

and do not represent negative values.

---

# 🧩 Using Multiple Format Specifiers

A single `printf()` statement can contain several format specifiers.

```c
char name[] = "Ali";
int age = 25;
float average = 87.5f;
char grade = 'A';

printf("Name: %s\nAge: %d\nAverage: %.2f\nGrade: %c\n",
       name, age, average, grade);
```

Output:

```text
Name: Ali
Age: 25
Average: 87.50
Grade: A
```

The values are matched from **left to right**:

```text
%s       %d       %.2f       %c
 │        │         │          │
 ▼        ▼         ▼          ▼
name     age     average      grade
```

---

# ⌨️ Format Specifiers with `scanf()`

Format specifiers are also used to read information from the keyboard.

Example:

```c
int age;

printf("Enter your age: ");
scanf("%d", &age);

printf("Your age is %d", age);
```

If the user enters:

```text
25
```

the program stores:

```text
age = 25
```

---

## 🔄 Input Flow

```text
Keyboard
   │
   ▼
User enters 25
   │
   ▼
scanf("%d", &age)
   │
   ▼
age = 25
   │
   ▼
printf("%d", age)
   │
   ▼
25
```

---

# ⚠️ `float` and `double` with `scanf()`

This is very important.

For a `float` variable:

```c
float temperature;

scanf("%f", &temperature);
```

For a `double` variable:

```c
double temperature;

scanf("%lf", &temperature);
```

Therefore:

| Variable Type | `scanf()` |
|---|---|
| `float` | `%f` |
| `double` | `%lf` |
| `long double` | `%Lf` |

---

# 💻 Complete Example

```c
#include <stdio.h>

int main(void)
{
    char name[] = "Ali";
    int age = 22;
    float average = 87.5f;
    char grade = 'A';

    printf("===== Student Information =====\n\n");

    printf("Name    : %s\n", name);
    printf("Age     : %d\n", age);
    printf("Average : %.2f\n", average);
    printf("Grade   : %c\n", grade);

    return 0;
}
```

### 🖥️ Output

```text
===== Student Information =====

Name    : Ali
Age     : 22
Average : 87.50
Grade   : A
```

This program uses:

```text
%s     → String
%d     → Integer
%.2f   → Decimal with 2 places
%c     → Character
```

---

# 🤖 Real-World Example: Robot Status

Format specifiers are useful in robotics and embedded systems.

```c
#include <stdio.h>

int main(void)
{
    char robot[] = "TurboPi";
    int battery = 85;
    float distance = 42.75f;
    char status = 'A';

    printf("===== ROBOT STATUS =====\n\n");

    printf("Robot    : %s\n", robot);
    printf("Battery  : %d%%\n", battery);
    printf("Distance : %.2f cm\n", distance);
    printf("Status   : %c\n", status);

    return 0;
}
```

Output:

```text
===== ROBOT STATUS =====

Robot    : TurboPi
Battery  : 85%
Distance : 42.75 cm
Status   : A
```

Notice:

```c
%%
```

prints one:

```text
%
```

---

# 🔍 Other Useful Format Specifiers

## `%ld` — Long Integer

```c
long population = 500000L;

printf("%ld", population);
```

---

## `%lld` — Long Long Integer

```c
long long bigNumber = 9000000000LL;

printf("%lld", bigNumber);
```

---

## `%x` — Hexadecimal

```c
int number = 255;

printf("%x", number);
```

Output:

```text
ff
```

---

## `%o` — Octal

```c
int number = 8;

printf("%o", number);
```

Output:

```text
10
```

---

## `%p` — Memory Address

```c
int number = 10;

printf("%p", (void *)&number);
```

This displays the memory address of the variable.

---

## `%zu` — `size_t`

Frequently used with `sizeof()`.

```c
printf("%zu", sizeof(int));
```

Possible output:

```text
4
```

Meaning:

```text
int uses 4 bytes
```

on that particular system.

---

# ⚠️ Common Mistakes

## ❌ Wrong Format Specifier

Incorrect:

```c
float temperature = 25.5f;

printf("%d", temperature);
```

`%d` expects an integer.

Correct:

```c
printf("%f", temperature);
```

---

## ❌ String with `%c`

Incorrect:

```c
char name[] = "Ali";

printf("%c", name);
```

Correct:

```c
printf("%s", name);
```

---

## ❌ Forgetting `&` with `scanf()`

Incorrect:

```c
int age;

scanf("%d", age);
```

Correct:

```c
scanf("%d", &age);
```

Think of:

```text
&age
```

as:

> 📍 The address where `scanf()` should store the value.

---

# 📌 Quick Reference

```text
┌─────────┬───────────────────────┐
│ Format  │ Meaning               │
├─────────┼───────────────────────┤
│ %d      │ Integer               │
│ %u      │ Unsigned integer      │
│ %f      │ Floating-point        │
│ %c      │ Character             │
│ %s      │ String                │
│ %ld     │ Long integer          │
│ %lld    │ Long long integer     │
│ %x      │ Hexadecimal           │
│ %o      │ Octal                 │
│ %p      │ Pointer/address       │
│ %zu     │ size_t                │
└─────────┴───────────────────────┘
```

---

# 🧠 Easy Memory Trick

Remember:

```text
%d  → Decimal Integer

%f  → Floating-point

%c  → Character

%s  → String

%u  → Unsigned Integer
```

For beginners, concentrate first on:

```text
%d
%f
%c
%s
```

---

# 🏫 Small Classroom Exercise

Create variables for:

- Student name
- Age
- Grade
- Average score

Your program should display:

```text
===== STUDENT RESULT =====

Name    : Ali
Age     : 22
Grade   : A
Average : 87.50
```

Use:

```text
%s
%d
%c
%.2f
```

---

# 🎯 Summary

A **format specifier** tells C how a value should be interpreted when using functions such as:

```c
printf()
```

and:

```c
scanf()
```

For example:

```c
int age = 25;

printf("Age = %d", age);
```

Visualized:

```text
Variable
   │
   ▼
age = 25
   │
   ▼
%d
   │
   ▼
Integer value
   │
   ▼
Age = 25
```

---

# 🔑 Final Takeaway

When you see:

```text
%
```

inside a `printf()` or `scanf()` format string, think:

> 🚦 **A value must be formatted or interpreted here.**

The four most important beginner format specifiers are:

```text
%d  → Integer

%f  → Decimal number

%c  → Character

%s  → String
```

Mastering these four gives you a strong foundation for working with **input, output, variables, sensors, robotics, and embedded C programming**.
