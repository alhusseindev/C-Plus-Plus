# task-01

For this task we are going to produce a simple animation of randomly colored pixels.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will update and move the `malen`, `malen-bokeh`, and `fmt` libraries into place.

## Task

In order for us to produce an animation we need to understand what makes up an animation. An animation is made up of a sequence of many *frames* - as we transition from one frame to the next quickly, we can observe the differences between the frames. A frame in this case is just an image, which has a height and a width. We can break an image down into individual and equally sized pixels that when arranged in a matrix/grid/lattice make up the image itself. Our goal in this assignment is to create randomly generated images, and then stack them together to create an animation.

Start by creating a new file `main.cpp`; we will need the following includes:

```cpp
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <ruc-sci-comp/animate.hpp>
#include <ruc-sci-comp/serialize.hpp>
```

You may use `using namespace std;` if you would like to do so. We will also be utilizing `type aliases` to make our code a little more expressive:

```cpp
using Line = std::vector<int>;
using Frame = std::vector<Line>;
using Animation = std::vector<Frame>;
```

Here we are creating aliases for existing types, making them a bit easier to use! A `Line` is just a vector of numbers, a `Frame` is a collection of `Lines`, and `Animation` is a collection of `Frames`.

Now we can start our `main` function. We want our program to take in a parameter from the command line to seed the random number generator we will use, so we want to `write` main like this:

```cpp
int main(int argc, char **argv)
```

Recall that `argc` repesents the total number of arguments passed to the program (including the name of the program) and that `argv` represents the actual arguments passed into the program (including the name of the program) as strings. The first thing we want to do inside of `main` is define our seed, and then check whether or not a seed was passed. If a seed was passed, convert it to an `int` and set it.

```cpp
int seed = 0;

if (argc == 2)
{
    seed = std::stoi(argv[1]);
}
```

This means that if the program is run without any input, the seed will default to 0. We next want to hardcode the dimensions (height/width) of the frames to 10. While this *could* be dynamic, it is not required for this assignment.

```cpp
int size = 10;
```

With our seed and size, we can move to generating our frame data. We need to create our `Animation` container:

```cpp
Animation animation;
```

We will iteratively push images into the animation, and once we are done we can produce our "video". Now we want set up our random number generation: create a 64-bit bit Mersenne Twister object seeded with our `seed` variable from before, and create a uniform integer distribution from 0 to 10. With this we can now start producing `Frames` (i.e. images) for the animation!

We want to produce an animation of 90 frames (approximately 3 seconds worth of video in production, but not necessarily here), so let's create a typical for-loop that iterates some counter `frame_index` from `0` to `90`. Inside of this for-loop, we need to do the following:

1) create a `Frame` with `size` `Lines`, with each `Line` containing `size` pixels.
    a) `Frame frame(size, Line(size));`
2) use a pair of nested for-range loops with references to set each pixel to some random number using our distribution and engine.
3) push the frame back into our `animation`

Once done with generating all of your frames, let's produce the video! Use:

```cpp
animate(animation);
```

And lastly, we want to serialize the frame data (for us this is for testing, but this might be better in practical solutions than saving an encoded video). Use:

```cpp
auto s = serialize(animation, seed);
std::cout << "Frame data saved: " << s << std::endl;
```

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe 1337
```

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-01 directory will be a file named `colors.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-06-Lnk2past\task-01\colors.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```
http://clam.rutgers.edu/~NETID/colors.html
```

## Testing

Try testing the program with:

```shell
make test
```
