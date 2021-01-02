# cpp-assignment-02-cannonball-simple

In this assignment we want to create a really simple simulation of a cannonball being launched in 2 dimensions.

* task-01: displacement calculator
* task-02: triangle calculator
* task-03: simple cannonball simulator

## Setup

Accept the assignment from GitHub Classroom. You can find the link to the assignment from the [Student Discussion](https://github.com/orgs/ruc-sci-comp/teams/students) on GitHub.

Ensure that `turtleshell` is running via Docker on your PC and attach VS Code to it. Then clone this repository into `/root/home/turtleshell`. It is important to clone it to that directory, as that is where all of your saved data must go!

If you are using `Turtleshell`, then you are ready to begin. If you are using `Clamshell` see below:

### Clamshell Users

Log into Clamshell and download the following Git projects using the following 2 commands.

```shell
cd ~ && git clone git@github.com:Lnk2past/malen.git
```

```shell
cd ~ && git clone git@github.com:Lnk2past/malen-bokeh.git
```

If you have downloaded these previously, then run the following 2 commands:

```shell
pushd ~/malen && git pull && popd
```

```shell
pushd ~/malen-bokeh && git pull && popd
```

Now you are ready to bgein!

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
