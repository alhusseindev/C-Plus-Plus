# task-01

This program will compute the displacement of an object using basic kinematic equations and user input.

## Task

One of Newton's kinematic equations states that the displacement of an object in one dimension is given by:

```
d = v*t + 0.5*a*t^2
```

Here we have the following:

* `d` is the displacement (in meters)
* `v` is the initial velocity of the object in that dimension (meters per second)
* `a` is the acceleration of the object in that dimension(meters per second per second)
* `t` is the time elapsed since the object started moving (seconds)

We can use this equation to figure out where an will be at any moment in time, given we know `v`, `a`, and `t`. Begin by creating a new file named `main.cpp` here in the task folder. Your program should make use of both `std::cout` and `std::cin` to ask the user for a velocity, acceleration, and time elapsed. With this information use the equation above to compute displacement.

When writing our code we want the program to very specifically ask the following question:

```text
What is your velocity, acceleration, and time elapsed?
```

The spelling, capitalization, and punctuation are all very specific, so copy and paste that text as your output! Our program should use `double`s for storing our variables. Compute the displacement, and then print it out on its own line; **nothing more**.

Try building the program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

Your program will ask for a side-length. Give it the numbers 10, 1, and 100; you should see the following output:

```shell
~/home/turtleshell/cpp-assignment-02-cannonball-simple/task-01# ./main.exe 
What is your velocity, acceleration, and time elapsed?
10
1 
100
6000
```

## Testing

Try testing the program with:

```shell
make test
```
