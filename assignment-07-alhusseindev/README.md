# cpp-assignment-07-defense-system

## Setup

### Turtleshell

All `turtleshell` users will need to update to the latest image. Follow these steps:

* Open a terminal/shell
* Execute `docker rm --force turtleshell`
* Execute `docker pull lnk2past/turtleshell:latest` (this will take a few minutes to download)
* Open VS Code
* Open any folder (it does not matter which)
* Go to Terminal -> Run Build Task... (or press CTRL + Shift + B)
* Run the build task to run turtleshell for your system
* Go to the Docker menu from the left (Whale shaped icon)
* Under the `Containers` window on the left, right click on `lnk2pst/turtleshell` and select `Attach Visual Studio Code`

### Clamshell

All `clamshell` users will need to update their dependencies and download a new one. Run the following commands one at a time:

* `cd ~/malen && git pull`
* `cd ~/malen-bokeh && git pull`
* `cd ~ && git clone --depth 1 --branch v3.9.1 git@github.com:nlohmann/json.git`
