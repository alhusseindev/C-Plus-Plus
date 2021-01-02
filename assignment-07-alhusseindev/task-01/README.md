# task-01

For this task we are going to develop a basic (if unrealistic) automated defense system.

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will update and move the `malen`, `malen-bokeh`, `nlohmann`, and `fmt` libraries into place.

## Task

Follow along in class! We want to implement the following:

* Utilities and helpers
* Basic environment model to use in aerodynamic drag calculations
* Basic radar model using an **Alpha-Beta-Gamma Filter**
* Basic weapon model

With the starter code and newly implemented pieces for the above, we can create a simple automated defense system simulation. When it is all said and done, we should have something like this: http://crab.rutgers.edu/~nesan/defense.html. An object is launched with an extremely high speed; after traveling a few kilometers it enters within range of a radar system, which starts to track the object. The object then enters within range of a weapon system which uses readings from the radar to engare the object with its own high-speed projectiles. It launches a defensive projectile every 0.5 seconds until the object lands or is intercepted.

## Building

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe data/configuration.json
```

Try tweaking some of the values in `data/configuration.json`, our simple model can be tuned to perform better or worse!

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-01 directory will be a file named `defense.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-07-Lnk2past\task-01\defense.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```
http://clam.rutgers.edu/~NETID/defense.html
```
