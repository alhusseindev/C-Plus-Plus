# task-03

This basic program will take a temperature and a user supplied unit (Fahrenheit or Celsius) and then convert the input temperature to the other unit.

## Task

```text
C = (F - 32.0) * 5.0 / 9.0
```

In order to convert Celsius to Fahrenheit, we use the following formula:

```text
F = C * 9.0 / 5.0 + 32.0
```

The first equation converts some temperature `F` in *Fahrenheit* to `C` in *Celsius*, and the second does the reverse. We want to write a program that prompts the user for a temperature and a unit to convert to. The program will then perform the necessary conversion, determining what to do using a _conditional-statement_.

When writing our code we want the program to very specifically ask the following question:

```text
What is your temperature?
```

The spelling, capitalization, and punctuation are all very specific, so copy and paste that text as your output! Our program should use a `double` for storing our temperature, and a `std::string` for storing the initial unit, and the result should be printed out on its own line, and **nothing more**.

After you read the data for the temperature and unit, you will need to use a `conditional statement` to check if our unit (say, called `u`) is equal to `"f"` for Fahrenheit or `"c"` for Celsius. If `u` is equal to `"f"` then you would convert the temperature (say, called `t`) to Celsius, and if it is equal to `"c"` then you would convert it to Fahrenheit.

Try building the program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

Your program will ask for a temperature. Give it something like `100c` (to denote 100 degrees Celsius), and your program should output `212f` (to denote 212 degrees Fahrenheit).

## Testing

Try testing the program with:

```shell
make test
```
