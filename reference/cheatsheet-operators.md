# LPC Operators — Quick Reference

## Arithmetic

| Operator | Description    | Example          |
|----------|----------------|------------------|
| `+`      | Addition       | `x + 5`          |
| `-`      | Subtraction    | `x - 3`          |
| `*`      | Multiplication | `x * 2`          |
| `/`      | Division       | `x / 4`          |
| `%`      | Modulo         | `x % 3`          |

## Compound Assignment

| Operator | Equivalent     |
|----------|----------------|
| `+=`     | `x = x + y`   |
| `-=`     | `x = x - y`   |
| `*=`     | `x = x * y`   |
| `/=`     | `x = x / y`   |
| `%=`     | `x = x % y`   |
| `++`     | `x = x + 1`   |
| `--`     | `x = x - 1`   |

## Comparison

| Operator | Description          | Example          |
|----------|----------------------|------------------|
| `==`     | Equal                | `x == 5`         |
| `!=`     | Not equal            | `x != 0`         |
| `<`      | Less than            | `x < 10`         |
| `>`      | Greater than         | `x > 0`          |
| `<=`     | Less or equal        | `x <= 100`       |
| `>=`     | Greater or equal     | `x >= 1`         |

## Logical

| Operator | Description | Example              |
|----------|-------------|----------------------|
| `&&`     | AND         | `x > 0 && x < 10`   |
| `\|\|`   | OR          | `x == 0 \|\| x == 1`|
| `!`      | NOT         | `!stringp(val)`      |

## Bitwise

| Operator | Description | Example       |
|----------|-------------|---------------|
| `&`      | AND         | `flags & 0x01`|
| `\|`     | OR          | `flags \| 0x04`|
| `^`      | XOR         | `flags ^ mask`|
| `~`      | NOT         | `~flags`      |
| `<<`     | Left shift  | `1 << n`      |
| `>>`     | Right shift | `flags >> 2`  |

## Ternary

```lpc
string result = (x > 0) ? "positive" : "non-positive";
```

## String Operators

```lpc
string s = "hello" + " " + "world";  // concatenation
s += "!";                              // append
// Strings compare with == != < > (lexicographic)
```

## Array Operators

```lpc
int *a = ({ 1, 2, 3 });
int *b = ({ 3, 4, 5 });
int *c = a + b;       // ({ 1, 2, 3, 3, 4, 5 }), concatenation
int *d = a - b;       // ({ 1, 2 }), subtraction (removes matches)
int *e = a & b;       // ({ 3 }), intersection
a += ({ 6 });         // append
```

## Mapping Operators

```lpc
mapping m1 = ([ "a": 1 ]);
mapping m2 = ([ "b": 2 ]);
mapping m3 = m1 + m2;   // ([ "a": 1, "b": 2 ]), merge (m2 wins on conflicts)
```

## Operator Precedence (high to low)

1. `()` `->` grouping, call
2. `!` `~` `++` `--` unary
3. `*` `/` `%`
4. `+` `-`
5. `<<` `>>`
6. `<` `<=` `>` `>=`
7. `==` `!=`
8. `&` then `^` then `|`
9. `&&`
10. `||`
11. `?:`
12. `=` `+=` `-=` etc.

When in doubt, use parentheses.
