# Lab: Kindergarten Fruit Distribution

**Group work assignment — Object-Oriented Programming in C++**

A kindergarten receives a box of mixed fruit containing apples, pears, and bananas. Each type of fruit must be divided equally among the children.

The fruit must not be cut. Each child must receive the same number of whole apples, the same number of whole pears, and the same number of whole bananas.

Employees buy all the remaining fruit at the following prices:

| Fruit | Price per piece |
|---|---:|
| Apple | 1 kr |
| Pear | 3 kr |
| Banana | 4 kr |

Your task is to develop a C++ program using **a class, an object, private data members, a constructor, and public member functions**.

## 1. Program Input and Output

Ask the user to enter:

- Number of children.
- Number of delivered apples.
- Number of delivered pears.
- Number of delivered bananas.

Your program must calculate and display:

1. How many fruits of each type every child receives.
2. How many apples, pears, and bananas the employees buy.
3. How much employees pay for each type of fruit.
4. The total amount paid by the employees.

**Input rules:**

- The number of children must be greater than zero.
- Fruit quantities must be zero or positive.
- A fruit quantity may be smaller than the number of children. In that case, each child receives **zero** of that fruit, and employees buy all the pieces of that type.

## 2. Plan Your Solution

Before writing the program, describe your solution step by step.

Discuss the following questions with your group:

- Which variables do you need?
- Which data should belong to the object?
- Which calculations require integer division `/`?
- Which calculations require the remainder operator `%`?
- Which methods should the class provide?
- What should the program print?

Show your procedure to another group and check whether they can follow it.

## 3. Object-Oriented Design

Create a class named `Kindergarten`.

### Private Data Members

Store the following information inside the class:

| Suggested name | Type | Purpose |
|---|---|---|
| `numberOfChildren` | `int` | Number of children |
| `numberOfApples` | `int` | Delivered apples |
| `numberOfPears` | `int` | Delivered pears |
| `numberOfBananas` | `int` | Delivered bananas |

Use named constants for the three fruit prices.

Making the data members `private` means that code outside the class cannot access them directly. The class provides public methods to work with its data.

### Constructor

Create a constructor that receives the four input values and initializes the object.

For example, after validating the input, you should be able to create an object like this:

```cpp
Kindergarten kindergarten(children, apples, pears, bananas);
```

### Public Member Functions

Implement methods with the following responsibilities:

| Suggested method | Responsibility |
|---|---|
| `getApplesPerChild()` | Return the number of apples each child receives |
| `getPearsPerChild()` | Return the number of pears each child receives |
| `getBananasPerChild()` | Return the number of bananas each child receives |
| `getRemainingApples()` | Return the number of leftover apples |
| `getRemainingPears()` | Return the number of leftover pears |
| `getRemainingBananas()` | Return the number of leftover bananas |
| `getAppleCost()` | Return the cost of the leftover apples |
| `getPearCost()` | Return the cost of the leftover pears |
| `getBananaCost()` | Return the cost of the leftover bananas |
| `getTotalCost()` | Return the total cost |
| `displayReport()` | Display the results with clear labels |

The calculation methods should return their results. `displayReport()` should print the report.

**Design requirement:** Calculate results from the stored input values rather than storing unnecessary copies of every result. Methods that do not modify the object should be declared `const`.

## 4. Dry Run — Calculate by Hand

A dry run means working through the calculations manually before implementing the program.

Use these example inputs:

| Input | Value |
|---|---:|
| Children | 32 |
| Apples | 45 |
| Pears | 49 |
| Bananas | 65 |

### Step 1: Determine How Much Each Child Receives

Use integer division:

```cpp
fruitPerChild = numberOfFruit / numberOfChildren;
```

| Fruit | Calculation | Each child receives |
|---|---|---:|
| Apples | `45 / 32` | 1 |
| Pears | `49 / 32` | 1 |
| Bananas | `65 / 32` | 2 |

Because the operands are integers, C++ discards the fractional part.

### Step 2: Calculate the Leftover Fruit

Use the remainder operator `%`:

```cpp
remainingFruit = numberOfFruit % numberOfChildren;
```

| Fruit | Calculation | Remaining pieces |
|---|---|---:|
| Apples | `45 % 32` | 13 |
| Pears | `49 % 32` | 17 |
| Bananas | `65 % 32` | 1 |

### Step 3: Calculate the Cost of Each Type

Multiply the remaining quantity by its price:

```cpp
cost = remainingFruit * pricePerPiece;
```

| Fruit | Calculation | Employees pay |
|---|---|---:|
| Apples | `13 * 1` | 13 kr |
| Pears | `17 * 3` | 51 kr |
| Bananas | `1 * 4` | 4 kr |

### Step 4: Calculate the Total Cost

Add the three costs:

```cpp
totalCost = appleCost + pearCost + bananaCost;
```

**Total: 13 + 51 + 4 = 68 kr**

### Step 5: Check Your Results

For each type of fruit, verify:

```text
Delivered quantity = (quantity per child × number of children) + remainder
```

For example, for apples:

```text
45 = (1 × 32) + 13
```

## 5. Create Your Visual Studio Project

Create a C++ Console App project named **Kindergarten**.

Organize your program into:

| File | Contents |
|---|---|
| `Kindergarten.h` | Class declaration |
| `Kindergarten.cpp` | Constructor and method implementations |
| `main.cpp` | Console input, validation, object creation, and report call |

Your `main()` function should:

1. Read the four inputs using `std::cin`.
2. Validate the inputs before creating the object.
3. Create a `Kindergarten` object.
4. Call its `displayReport()` method.

Use `std::cout` for console output.

## 6. Expected Output

For the dry-run inputs, the report should contain:

```text
KINDERGARTEN FRUIT DISTRIBUTION

Number of children: 32

Each child receives:
Apples:  1
Pears:   1
Bananas: 2

Employees purchase:
Apples:  13 pieces - 13 kr
Pears:   17 pieces - 51 kr
Bananas:  1 piece  -  4 kr

Total amount paid: 68 kr
```

## 7. Test Your Program

Test at least the following situations:

| Test | Expected behaviour |
|---|---|
| 32 children, 45 apples, 49 pears, 65 bananas | Total cost is 68 kr |
| Every fruit quantity is divisible by the number of children | No leftovers; total cost is 0 kr |
| A fruit quantity is smaller than the number of children | Each child receives zero of that type; employees buy the remainder |
| All fruit quantities are zero | All calculated results are zero |
| Number of children is zero or negative | Reject the input before performing division |
| A fruit quantity is negative | Reject the input |
| User enters text instead of a number | Display an error and handle the invalid input |

## 8. Group Discussion and Submission

Submit your source files, dry run, and test results.

Be ready to explain:

- What is the difference between the `Kindergarten` class and a `Kindergarten` object?
- What does the constructor do?
- Why are the data members private?
- How do public methods provide access to the object's functionality?
- What is the difference between `/` and `%`?
- Why must the number of children be greater than zero?
- How does dividing the work into methods make the program easier to understand?
