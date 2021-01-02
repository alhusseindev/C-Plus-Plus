# task-01

For this task we are going to use a random number generator to produce random points on the coordinate plane, print them, and plot them.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will move the `malen`, `malen-bokeh`, and `fmt` libraries into place.

## Task

Begin by creating a new file named `main.cpp` here in the task folder. You need the following headers:

* `#include <iostream>`
* `#include <random>`
* `#include <vector>`
* `#include <fmt/format.h>`
* `#include <ruc-sci-comp/plot.hpp>`

Do not forget `using namespace std;`! We want the number of points we randomly generate to be input by the user, but **we do not want to use `std::cin`**! Rather than using a stream input (`std::cin`, or `std::ifstream`), we want to rely on command-line arguments. This means that instead of having our program ask us for information, we want to set it up to just accept the information when we run it. We want to be able to do something like:

```shell
./main.exe 100
```

Where `100` is the input to our program. We can easily change our input by rerunning our program with a different input:

```shell
./main.exe 100
./main.exe 1337
./main.exe 9001
```

We achieve this by changing how we set up our `main` function. Instead we need to write it like this:

```cpp
int main(int argc, char **argv)
```

This alternative way allows us to interact with the *command line arguments* of our program (the arguments passed to it on the command line...). Here `argc` tells us how many inputs we gave our program when we run it, and `argv` is the list of those arguments (as *C-style strings*). We can use `argc` to determine if our program was executed properly (e.g. did the user pass the right number of arguments), and then we can access each argument from `argv` as if it were a vector.

The first thing we will want to do inside of our `main` function is inspect `argc` and then convert the content of `argv` to the needed variables:

```cpp
if (argc < 2)
{
    std::cerr << "Invalid number of arguments - you must specify how many random points to generate!" << std::endl;
    return 1;
}

auto max_count = std::stoi(argv[1]);
if (max_count < 1)
{
    std::cerr << "Invalid number of points specified - you must provide a positive integer!" << std::endl;
    return 2;
}
```

Copy and paste this code directly into your `main` function. The first block of code makes sure that the user is supplying at least 2 arguments. The first argument is *always the name of the program*, and so `argc` is always at least equal to `1`. We want to make sure the user gives us an argument, so we check to make to `argc` is at least `2`.

The second block starts with:

```cpp
auto max_count = std::stoi(argv[1]);
```

The function `std::stoi` converts the input `string` to an `int`, hence the name **s**tring **to** **i**nt. As `argv` is essentially like a `vector`, and the first argument is always the name of the program, we want to access the first user input, which would start at index `1`. We convert it to an `int`, and that is what we will use in the rest of our program. Therefore, the variable `max_count` is the number of point we will generate!

With the above code in place we can really begin! We want to create a random number generator engine and distribution. The engine we will use is the `std::mt19937_64` engine, and the distribution we will use is the `std::uniform_real_distribution<double>` distribution. We will need the following:

* The engine should be *seeded* with the value `1337`
* The distribution should be over the range `0.0` to `100.0`.

Now we need to construct vector objects to act as plotting buffers for the plotting routines. Create two `std::vector<double>` objects named `xs` and `ys`, and reserve both of them for `max_count` elements.

We now need a normal *for-loop* that iterates from `0` to `max_count`. In this for-loop we need to generate two random doubles from our engine and distribution - our `x` and `y` values for the random point on the coordinate plane (you can name them `x` and `y`). Once we generate them, we can push them into their respective vectors, and then print them out using the following line:

```cpp
std::cout << fmt::format("<{0:.2f},{1:.2f}>", x, y) << std::endl;
```

This concludes the for-loop, and the only thing left to do is plot the data:

```cpp
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

It will simply print out 10 random coordinates:

```shell
~/home/turtleshell/cpp-assignment-05-approximate-pi/task-01# ./main.exe 10
<70.00,57.00>
<68.57,71.27>
<32.35,27.59>
<2.67,55.97>
<29.95,79.87>
<97.96,62.31>
<86.24,75.02>
<90.02,44.16>
<55.30,84.76>
<92.28,32.00>
```

Try running it a few more times, omitting a number altogther, or giving it a negative number, or giving it a number like 1000!

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-01 directory will be a file named `scatter.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-05-Lnk2past\task-01\scatter.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```
http://clam.rutgers.edu/~NETID/scatter.html
```

## Testing

Try testing the program with:

```shell
make test
```
