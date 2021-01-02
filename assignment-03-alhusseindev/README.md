# cpp-assignment-03-statistics-simple

For this assignment we will compute some basic statistics on some data, and then do it again using the STL algorithms.

* task-01: computing some basic statistics **without** using the STL
* task-02: computing some basic statistics using the STL

## Setup

Accept the assignment from GitHub Classroom. You can find the link to the assignment from the [Student Discussion](https://github.com/orgs/ruc-sci-comp/teams/students) on GitHub.

Ensure that `turtleshell` is running via Docker on your PC and attach VS Code to it. Then clone this repository into `/root/home/turtleshell`. It is important to clone it to that directory, as that is where all of your saved data must go!

If you are using `Turtleshell`, then you are ready to begin. If you are using `Clamshell` see below:

### Clamshell Users

Log into Clamshell and update the following Git projects using the following 2 commands.

```shell
pushd ~/malen && git pull && popd
```

```shell
pushd ~/malen-bokeh && git pull && popd
```

Now you are ready to begin!

## Submit

Once you have all tests passing you are done with the assignment, and you just need to submit it. Run the following commands:

```shell
git add .
git commit -m "Finished tasks"
git push
```

The command `git add .` stages all of your changed files. Staging just means to identify which files we want to submit.

The command `git commit -m "Finished tasks"` takes the staged files and commits them to your project *local on your PC*. This creates an official record in git that the files have changed.

The command `git push` sends that official record to GitHub, which is where your

The message "Finished tasks" is the commit message. This is just informational and you can make it anything you want. Once you `git push` **check on your GitHub assignment repository** to ensure that your changes were submitted.
