# task-01

This basic program will take a user-supplied side length and compute both the surface area and volume of a cube with sides that long.

## Task

Surface area and volume are, respectively, calculated as such:

```text
SA = L * L * 6
```

```text
V = L * L * L
```

These are simple enough as is! Begin by creating a new file named `main.cpp` here in the task folder. Your program should make use of both `std::cout` and `std::cin` to ask the user for a side length. Then your program should calculate the surface area and then print it out, and then the same for volume.

When writing our code we want the program to very specifically ask the following question:

```text
What is your side length?
```

The spelling, capitalization, and punctuation are all very specific, so copy and paste that text as your output! Our program should use `double`s for storing our variables, and the result should be printed out on its own line, and **nothing more**.

Try building the program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

Your program will ask for a side-length. Give it any number and observe the numbers that it produces.

## Testing

Try testing the program with:

```shell
make test
```
