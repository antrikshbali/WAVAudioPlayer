WAV Audio Player Starter Code

Just some code to get started with audio in C++. Basic audio functions like Play, Stop, Pause etc. + Pitch-Shift & primitive lowpass filter
Work in Progress.

##Build Dependencies##
- [CMAKE](http://www.cmake.org/)
- [SDL2](http://www.libsdl.org/)

##Build Toolchains##
- Linux -> make/g++/gcc + CodeBlocks
- Mac -> make/g++/gcc + Xcode/CodeBlocks
- Windows -> Visual Studio / CodeBlocks
- BUILD TOOLCHAIN (Can be any one of the following, doesn't need to be all of them)
	- Linux
		- make, gcc, g++ ( Install with your package manager )
		- [CodeBlocks](http://www.codeblocks.org/)
	- Mac OS X
		- make, gcc, g++ ( Install with preferred package manager like [HOMEBREW](http://brew.sh/) )
		- Xcode ( Download from Mac AppStore )
		- [CodeBlocks](http://www.codeblocks.org/)
	- WINDOWS
		- [Visual Studio](http://www.visualstudio.com/)
		- [CodeBlocks](http://www.codeblocks.org/)

###NOTES for Dependencies###
On Unix/Linux/Mac you can likely install CMAKE and SDL2 with your package manager
```shell
# On ubuntu just run
sudo apt-get install cmake libsdl2-dev

# On Mac with HomeBrew just run
brew install cmake sdl2
```

##Build Instructions##
###Mac OSX/Linux/Unix###
- Open a Terminal and run:
```Shell
# install dependencies

./Unix-Build.sh [Build Target, Debug or Release (Optional)] [Any arguments for CMake (Optional)]

#For instance, you can use the CMake argument -G "Xcode" to generate an Xcode project during build,
#or you can use -G "CodeBlocks - Unix Makefiles" to generate a CodeBlocks Project.
#See http://www.cmake.org/ for more details about CMake arguments
```

###Windows###
- Make sure CMake is both installed and added to the system PATH.
- Run "Windows-GenVisualStudioProject.bat" If this fails for any reason, try using the Manual Build Instructions below.
- Go to the build folder, and open 3DEngineCpp.sln with Visual Studio 2012 or newer (For older versions of Visual Studio, use manual build instructions)
- Right click on the AudioProject project, and select "Set as start up project"
- Build and Run
