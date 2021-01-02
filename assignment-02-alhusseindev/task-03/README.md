# task-03

This program will simulate the physics of a cannonball being launched through the air.

## Task

Our first simulation in this class is a really basic one of a cannonball. When implementing a new model, it is a good exercise to think about what the simulation needs and what it does not need. We want to start simple and add the complexities later. Consider all of the things that could be happening when a cannonball is blasted into the sky:

* force of gravity is pulling the ball down
* aerodynamic drag is slowing the ball down
* aerodynamic lift could be reducing the downward acceleration
* rotational dynamics of the ball could be causing it curve in a 3rd dimension
* air density, temperature, and humidity could have an effect on the trajectory
* wind could have an effect on the trajectory
* if the ball is launched sufficiently far, coriolis forces become apparent

There is much more to consider, but just by looking at that list it become clear that designing a realistic simulation can be very difficult! To start we need to greatly simplify this list and simply *assume* that the other effects are not relevant. So, here is our new list of things to consider:

* force of gravity is pulling the ball down

*That is it.* That is all we want to start with, and later on we can work on adding these other effects. We do not care about anything else other than gravity pulling the cannonball back down to Earth. We can use the kinematic equation detailed in task-01 to compute the movement of the cannonball.

```
d = v*t + 0.5*a*t^2
```

We can use this equation to figure out where the cannonball will be at any moment in time. If we compute where the cannonball is repeatedly at time intervals, then we can sort of trace the path of the cannonball through space. This means more specifically that given a velocity, acceleration, and a constantly changing time, we can figure out the trajectory of the cannonball!

Our program needs to ask the user for the launch speed and angle of the cannonball. These represent the hypotenuse and angle in a right-triangle. As we saw in task-02, we can take a hypotenuse (or in this model, a velocity vector) and break it into an x and a y component (x-velocity and y-velocity). Since our displacement equation is 1-dimensional, but our problem is 2-dimensional, we need to use our displacement function twice: once with the x-velocity and once with the y-velocity.

### Psuedo Code

```text
1) ask for speed and angle
2) convert angle to radians
3) compute x_veloxity and y_velocity
4) initialize time
5) while time < 10
6)     compute x
7)     compute y
8)     print x y
9)     increment time by 0.25
```

### The Simulation

Begin by creating a new file named `main.cpp` here in the task folder. We need the following *headers*:

```
#include <cmath>
#include <iostream>
#include <vector>
#include <ruc-sci-comp/plot.hpp>
```

* `cmath` gives us access to `M_PI` and trigonometric functions `std::sin` and `std::cos`.

* `ruc-sci-comp/plot.hpp` give us access to custom data visualization code, specifically a function named `plot_trajectory`. This function returns `void` and accepts two `std::vector<double>` objects as input. These vectors are the x and y time series data of the cannonball.

#### Main

Your program should make use of both `std::cout` and `std::cin` to ask the user for a launch speed and then a launch angle. When writing our code we want the program to very specifically ask the following questions:

```text
What is your launch speed?
```

```text
What is your launch angle?
```

The spelling, capitalization, and punctuation are all very specific, so copy and paste that text as your output! You can store these pieces of data as `double` variables named `speed` and `angle_deg` respectively.

The speed represents the collective speed of the cannonball and so we need to break it down into x and y components. This becomes a basic trigonometry problem, given we have a speed (hypotenuse) and a launch angle (angle).

We need to fix the launch angle though because the trigonometric functions we are going to use expect *radians* and we have *degrees*. Convert to radians as we did in task-02; create a new variable named `angle` equal to the degrees multiplied by pi and divided by 180.0.

With our new angle in radians, we can use the exact same equations from task-02 to compute the x-velocity and y-velocity; we can call these variables `x_velocity` and `y_velocity`. *Now* we can actually do some physics.

For this assignment we only want to calculate about 10 seconds of the simulation. This means that we need to keep track of time; we can do this using a `double` named `time` that is initialized to `0.0`. We are going to use a while loop to check if our time variable is less than `10.0`. So long as the time is less than 10 we want to continue producing data and we also want to *increment the time by 0.25*.

Let us go back and revisit our kinematic equation:

```
d = v*t + 0.5*a*t^2
```

First think about this equation in the context of vertical movement. It should be clear that in this context that `v` is just `y_velocity`, but what about `a`? If `a` is the vertical acceleration, then it can really only be one thing (since we greatly simplified everything): it must be acceleration due to gravity. In case you do not remember, on Earth the acceleration due to gravity is approximately `-9.81 meters per second per second`. Therefore we have both `v` and `a` for the vertical movement and we can compute `y` at any given moment in time!

What about in the context of horizontal movement? It should be clear that in this context that `v` is just `x_velocity`, but what about `a`? The not so obvious answer to that question is actually quite simple: it is `0.0 meters per second per second`! Because we took out all of the aerodynamics of the problem, the horizontal acceleration is zero! Therefore we have both `v` and `a` for the horizontal movement and we can compute `x` at any given moment in time!

This means that we can form the following equations:

* x = x_velocity * time
* y = y_velocity * time + 0.5 * -9.81 * time * time

#### Putting it All Together

To put all of this together we want to write a while-loop that is checking if our `time` variable is less than 10. While it is less than 10 we want to calculate `x` and `y` as described above and print them out on a single line with a single space between them. The last thing we need to do inside of the while-loop is overwrite the `time` variable with *itself plus 0.25*.

At this point in time you can try building and running the program with:

```shell
make
```

```shell
./main.exe
```

This will just generate a ton of data though, all of which is not easy to understand. We need to graph it!

#### Visualizing

At this point in time, we need to simply take the same data we are printing and accumulate it in vectors. Before the while-loop, we want to create two vectors of doubles named `x_data` and `y_data`. Both of these vectors should just be empty to start. *Inside* of the while loop, we want to `push_back` the newly calculated `x` and `y` into their respective vectors.

By doing this, we are accumulating the position of the cannonball after each iteration of the system. When the while loop ends, the vectors will be filled with the complete 10-second trajectory. Now we just need to plot the data using:

```cpp
plot_trajectory(x_data, y_data);
```

All in all, you code should be about 40 lines long. This is not a requirement, just a guideline.

Try building the program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe
```

This wil dump a ton of numbers out, and for now this means a lot of nothing! But what it also does it produce a file named `trajectory.html`. We can open this file with our web browser to see what it looks like.

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-03 directory will be a file named `trajectory.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-02-Lnk2past\task-03\trajectory.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```
http://clam.rutgers.edu/~NETID/trajectory.html
```

## Testing

Try testing the program with:

```shell
make test
```
