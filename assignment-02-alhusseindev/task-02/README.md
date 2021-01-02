# task-02

This program will compute the 2 sides of a right-triangle given the hypotenuse and an angle between it and one other side.

## Task

Consider the following right-triangle:

```
                /|
               / |
              /  |
             /   |
hypotenuse  /    |
           /     |
          /      |
         /       |
        /        | opposite (y)
       /         |
      /          |
     /           |
    /            |
   /            _|
  /0___________|_|
      adjacent (x)
```

and remembering *SOHCAHTOA* from trigonometry, we can recall two equations:

* cos(angle) = adjacent / hypotenuse
* sin(angle) = opposite / hypotenuse

More importantly we can rearrange them and get:

* adjacent = cos(angle) * hypotenuse
* opposite = sin(angle) * hypotenuse

We can use these equations to figure out the adjacent (x) and the opposite (y) of the triangle. Begin by creating a new file named `main.cpp` here in the task folder. Your program should make use of both `std::cout` and `std::cin` to ask the user for a hypotenuse and angle. With this information use the equations above to compute the side lengths. Note that the user will likely be entering their angle in degrees, but C++'s trigonometric functions work in radians. This means we need to convert our angle to radians before using it! Here is the conversion formula for degrees-to-radians

```text
r = d * 180 / pi
```

In C++ we do not have `pi`, instead it is called `M_PI`. You should use this! When writing our code we want the program to very specifically ask the following question:

```text
What is your hypotenuse length and angle?
```

The spelling, capitalization, and punctuation are all very specific, so copy and paste that text as your output! Our program should use `double`s for storing our variables. Compute the adjacent and opposite sides, and then print the results each on their own line; **nothing more**.

Try building the program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

Your program will ask for a hypotenuse and angle. Give it the numbers 1 and 45; you should see the following output:

```shell
~/home/turtleshell/cpp-assignment-02-cannonball-simple/task-02# ./main.exe 
What is your hypotenuse length and angle?
1
45
0.707107
```

## Testing

Try testing the program with:

```shell
make test
```
