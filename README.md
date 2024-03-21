## C++ Expression Evaluator
A simple expression evaluator that evaluates a given expression.

### Examples
> [!NOTE]
> The scripts check for valid characters, like numbers or symbols.

Input: `10 + 2 * 6`<br>
Output: `22`

Input: `100 * (2 + 12) / 14`<br>
Output: `100`

> [!CAUTION]
> Any expression wth an invalid character (like a letter or unhandled symbol) have an error of `-1` returned.

Input: `l0 + 2 * 6 OR 100 * ((2 + 12)`<br>
Output: `-1`
