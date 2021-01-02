# task-02

This program will use STL algorithms to compute some data.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

## Task

The purpose of this task is to compute some basic statistics specifically *with* the STL algorithms. Repeat `task-01`, but do not use any loops (for, for-range, nor while). You need to use `std::transform`, `std::accumulate`, `std::min_element`, and `std::max_element`.

Begin by creating a new file named `main.cpp` here in the task folder. **In addition** to the headers in `task-01`, you need the following headers:

* `#include <algorithm>`
* `#include <numeric>`

Again, repeat `task-01`, but using STL algorithms instead of loops. **No loops are allowed here!** Plotting here is optional, but recommended.

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
~/home/turtleshell/cpp-assignment-03-statistics-simple/task-02# ./main.exe 
Generate how many random numbers?
100
0.530659
0.00275445
0.977195
```

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-02 directory will be a file named `random_data_2.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-03-Lnk2past\task-02\random_data_2.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```text
http://clam.rutgers.edu/~NETID/random_data_2.html
```

## Testing

Try testing the program with:

```shell
make test
```
