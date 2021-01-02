# task-02

For this task we are going to build off of task-01 to approximate the value of pi using a Monte Carlo method.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will move the `malen`, `malen-bokeh`, and `fmt` libraries into place.

## Task

Begin by creating a new file named `main.cpp` here in the task folder. We want the same headers and starter code (the new way to write `main` and the code for inspecting `argc`), but also want to make sure we include the `cmath` header.

This program will be nearly identical to the one from `task-01`, but we need to make some changes to accomodate the problem we are trying to solve. In order to approximate pi using a Monte Carlo method, we need to understand why this works. The idea is relatively simple. We want to inscribe the unit circle into a square with vertices (1, 1), (-1, 1), (-1, -1), (1, -1). Thus the circle has radius 1 and the square has side length of 2.

The area of the circle is `pi*r*r` = `pi*1*1` = `pi`, and the area of the sqaure is `l*l` = `2 * 2` = `4`. The ratio of these areas is `pi/4`. If we can approximate the area of the circle and the area of the square, then the ratio of these approximations would be an approximation for `pi/4`, simply multiplying the approximation by `4` would yield and approximation for `pi`.

So how do we approximate the area of the circle and square? We want to generate random points on the coordinate plane, restricted to the boundary of the square. These random points are like grains of sand - with enough of them dumped into the square we would be able to fill the square. Assuming no grains of sand are stacked on top of one another (i.e. we have a single layer of sand) then the sum of those grains of sand would give us the area of the square. We can determine which of those grains of sand *are also* within the circle by checking their distance from the origin. If the distance to the origin is `1.0` or less (the distance is shorter than the radius of the circle), then we know the grain of sand is in the circle.

Counting the total number of grains of sand gives us the approximate area of the square, and counting the total number of grains of sand within the circle gives us the approximate area of the circle. We can get the ratio and multiply it by 4 to find our approximation of pi.

We need to do all of the same things from task-01:

* create two vectors `xs` and `ys` for our `x` and `y` data, and reserve them memory for `max_count` elements.
* start a traditional for-loop to iterate between `0` and `max_count`
* within the for-loop, randomly generate the `x` and `y` and push them into their respective vectors.

However, we do have more we need to do. Every time we randomly generate a point, we need to check its distance from the origin to determine if it is within the circle. Before the for-loop create an `int` named `count` and initialize it to `0`. We will use this as a counter to measure how many points are in the circle.

After we have pushed `x` and `y` into their vectors, we want to check the distance from the origin; conventiently we can use the function `std::hypot` which computes Pythagoreas for us (since the distance from the origin here is just the hypotenuse of a triangle with sides `x` and `y`).

We can compute the hypotenuse, and if it is less than or equal to 1.0, and then we can increment `count` by 1. This concludes our for-loop, and that is left is to print our approximation and plot the results:


```cpp
std::cout << fmt::format("pi ~ {:.10f}",  4.0  * count / max_count) << std::endl;
plot_data(xs, ys);
```

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe 10
```

This will print out a poor approximation of pi:

```shell
~/home/turtleshell/cpp-assignment-05-approximate-pi/task-02# ./main.exe 10
4.0000000000
```

Let's try running it with a large number of points:

```shell
~/home/turtleshell/cpp-assignment-05-approximate-pi/task-02# ./main.exe 10000
pi ~ 3.1404000000
```

Better, but not great...

```shell
~/home/turtleshell/cpp-assignment-05-approximate-pi/task-02# DISABLE_MALEN= ./main.exe 5000000
pi ~ 3.1421128000
```

Obviously these approximations are not great, and adding more iterations does not improve the approximation much, and the runtime starts to skyrocket! Theoretically with enough iterations we would get a good approximation of pi, but with this method it simply is not worth it!

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-01 directory will be a file named `pi.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-05-Lnk2past\task-02\pi.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```
http://clam.rutgers.edu/~NETID/pi.html
```

## Testing

Try testing the program with:

```shell
make test
```
