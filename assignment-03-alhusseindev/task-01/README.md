# task-01

This program will use simple control structures to compute some data.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

## Task

The purpose of this task is to compute some basic statistics specifically *without* using the STL algorithms. We want to do the following for a set of data:

* tranform the data, dividing all elements by 100.0
* compute the mean of the data
* compute the minimum element (element with the smallest value)
* compute the maximum element (element with the largest value)

Begin by creating a new file named `main.cpp` here in the task folder. You need to include the following headers:

* `#include <iostream>`
* `#include <vector>`
* `#include <ruc-sci-comp/data.hpp>`
* `#include <ruc-sci-comp/plot.hpp>`

Do not forget `using namespace std`!

Start your `main` function; the first thing we want to do call the function `generate_data`, which is defined in the header `ruc-sci-comp/data.hpp`. This function asks the user for a number of random elements to create, and then returns a presorted vector containing that many random numbers, bounded between `0.0` and `100.0`. As the function returns a `std::vector<double>`, you need to create a variable to hold onto the return value. *Hint, you can use `auto`!*

With this vector, we want to first transform its data using a `for-range` loop. This `for-range` loop needs to use a reference so that we can modify the elements of the vector, and not copies of the elements. Inside the loop, divide the element by 100.0. Now that our data is transformed, we want to compute the mean, min, and max

 Recall that the mean is the sum of the elements divided by the total number of elements. You can use a `for-range` loop to sum the elements, and then divide by the size of the vector. Once you have the mean, print it out on its own line.

Computing the min and max are simple, but less obvious. To compute the minimum element, we create a new variable named `min` with an initial value of `2.0.0`, and a new variable named `max` with an initial value of `-1.0` . We know that all of our elements were between `0.0` and `100.0`, and we have divided all of the elements by `100.0`, and therefore we know that `-1.0` and `2.0` sufficiently bound our data.

We want to start another `for-range` loop, and in it we want two separate conditionals. The first conditional will check if the element is less than our `min`; if it is then we overwrite `min` with the element. The second conditional will check if the element is greater than our `max`; if it is then we overwrite `max` with the element. Once you have the min and max, print them each on their own line (min, then max).

Lastly, we want to plot the data using the following:

```cpp
plot_data(data, mean, min, max);
```

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

It will ask you `"Generate how many random numbers?"`, enter `100`. It will then print the mean, the min, and max.

```shell
~/home/turtleshell/cpp-assignment-03-statistics-simple/task-01# ./main.exe 
Generate how many random numbers?
100
0.530659
0.00275445
0.977195
```

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-01 directory will be a file named `random_data_1.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-03-Lnk2past\task-01\random_data_1.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```text
http://clam.rutgers.edu/~NETID/random_data_1.html
```

## Testing

Try testing the program with:

```shell
make test
```
