# cpp-assignment-00-getting-connected

Getting connected and completing your first assignment.

## Setup

Some things you will need to get started:

* GitHub Account
* Visual Studio Code
* Docker
* SSH Enabled PC (highly preferred, but not required)
  * Mac and Linux machines by default should be OK.
  * Windows 10 users may need to see this [link for instructions](https://docs.microsoft.com/en-us/windows-server/administration/openssh/openssh_install_firstuse).

The purpose of this assignment is to configure our development environment, connect to GitHub, and learn workflow basics for assignments and assessments.

### SSH Keys

The purpose of this section is to configuring a SSH key that will allow us to automatically authenticate with GitHub while we do our work. This might seem like overkill, but this will make downloading and uploading code to GitHub much easier.

The first thing we need to do is create a key on our PC; if you have done this in the past for other reasons, you may skip ahead to the next section dealing with Docker. Otherwise, from a terminal run the following:

```shell
ssh-keygen
```

You will see the following:

```shell
Generating public/private rsa key pair.
Enter file in which to save the key (C:\Users\Lnk2past/.ssh/id_rsa):
```

Do not input any information here, just hit Enter a few times until you see something like the following:

```shell
The key fingerprint is:
SHA256:Rzr8Ewp7ed0qt3xnUFk0OsxXbhwC3kTemJO7IwGEVX4 lnk2past@meridian
The key's randomart image is:
+---[RSA 2048]----+
|        oo.oo+ +o|
|       .. o * Bo=|
|         ..o E o*|
|       . o. . =o.|
|      . S o. . . |
|       o * o..o  |
|      . + +..o.. |
|       . ..oo.o o|
|           o+o o |
+----[SHA256]-----+
```

This will have created a public/private key pair of files, named `id_rsa.pub` and `id_rsa` respectively, that you can use to identify your PC. These files will be located in your user directory in a new directory named `.ssh`. E.g. on my Windows PC, I can find them at:

```shell
C:\Users\Lnk2past\.ssh
```

With these files we are now ready to configure Github, Docker, and Visual Studio Code. From within VS Code, open the `id_rsa.pub` file, we will need its content.

### GitHub

This first bit will allow us to bypass inputting our username and password constantly when downloading and uploading code to GitHub (something you will do for every assignments and assessment!). From GitHub, go to your account settings (click your user icon in the top right and select `Settings`). This will bring you to your account settings; you want to go to the `SSH and GPG keys` submenu. Select the `New SSH key` button (green button) at the top of the screen. Input anything for the title (e.g. personal-pc) and then copy and paste the entirety of the `id_rsa.pub` file from the last section into the `Key` box. Then select the `Add SSH key`; you will be prompted to log in to confirm. Then you are done!

### Docker

Docker is a powerful operation system virtualization product that lets us easily create virtual computing environments. We will be using Docker for a few primary reasons:
* consistency: everyone will be using the same exact computing environment and tools regardless of whether you have a Windows, Mac, or Linux computer.
* offline: previously this course utilized Rutgers cloud servers, but these cannot be access without an internet connection. Docker runs locally right on your computer.
* modern tooling: Docker is an industry standard tool that anyone remotely interested in software should know.

#### Installation

Download and install Docker [from here](https://docs.docker.com/get-docker/). This is likely the most difficult part of getting set up and ready for this course. If your computer is not capable of installing and running Docker, **you must contact me immediately**!

#### Computing Environment

Once your system is setup with Docker, you need to download the course computing environment (called an "image" in Docker world). Our environment is called `turtleshell` and it is [maintained here](https://github.com/Lnk2past/turtleshell). It is a Debian system with C++, Python, and a number of other things baked in. So now we need to download it. Open a terminal and run the command:

```shell
docker pull lnk2past/turtleshell:latest
```

This should download the computing environment; once this is done then you are set up with Docker for now! Throughout the semester `turtleshell` will be updated. Simply rerun the `pull` command above to get the updates.

### Visual Studio Code

*VS Code* (as we will call it) is a fantastic tool for software development. It is not developed with a single language or software stack in mind, and so it is highly configurable so that it may suit all if your needs.

#### VS Code Extensions

Extensions are the primary way in which can we can add functionality to VS Code. To start, we will install the following two extensions (The sub bullets are extension IDs that you can search for).

* **Docker** by Microsoft
  * `ms-azuretools.vscode-docker`
* **Remote Development** by Microsoft
  * `ms-vscode-remote.vscode-remote-extensionpack`

These extensions allow us to use Docker and remote facilities more readily from within VS Code. Once these are installed, you may be asked to restart VS Code or Reload the Window... do it!

#### Configure Tasks

Now we need a way for VS Code to readily launch the computing environment. This requires us to add a task configuration file to our computer for VS Code to read. [This](https://vscode.readthedocs.io/en/latest/getstarted/settings/#settings-file-locations) details the locations, but in case you dont want to read through:

* Windows `%APPDATA%\Code\User\`
* Mac `$HOME/Library/Application Support/Code/User/`
* Linux `$HOME/.config/Code/User/`

Got to the approprirate folder per your system, and create a new text file named 'tasks.json' (**do not name it** `tasks.json.txt`!). Copy and paste the content [from here](https://raw.githubusercontent.com/Lnk2past/turtleshell/master/.vscode/tasks.json) into the file and save.

You can test that the task configuration is done in VS Code by going to `Terminal -> Run Build Task...` and simply *seeing* the two options:

* `turtleshell-run`
* `turtleshell-run-windows`

#### Launching and Connecting to `turtleshell`

In VS Code by go to `Terminal -> Run Build Task...` and select the appropriate task (Windows users will select `turtleshell-run-windows` and all other usres will select `turtleshell-run`). This will start running the `turtleshell` system. A window within VS Code should open and look something like this:

```shell
> docker run -dt -P --name "turtleshell" --label "com.microsoft.created-by=visual-studio-code" -v "%USERPROFILE%/.ssh:/tmp/.ssh" -v "%USERPROFILE%/turtleshell:/root/home/turtleshell" "lnk2past/turtleshell:latest" bash <

aa5c4caaffd722244f0f9281732bf5d59c1ab6c877914515968f263273bfa440

Terminal will be reused by tasks, press any key to close it.
```

If you see something like this (there will be variations between Windows, Mac, and Linux), then that means `turtleshell` is successfully running! Now we need to attach VS Code to it. In VS Code by go to `View -> Command Pallete...` (or press `CTRL` + `Shift` + `p`) and search for the command `Remote Containers: Attach to Running Container...`. Select it, and from the list select `/turtleshell`. A new VS Code Window should open, and you are now connected to `turtleshell`!

You are done for now, and can run the Makefile to test!
