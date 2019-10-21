# modest-engine

A small game engine about studying game architecture. This engine is used with my courses at my applied university of science to implement physics, AI, etc.

This uses Jason Gregory's "Game Engine Architecture" book as foundation and red thread.
And makes excensive use of Robert Nystorm's "Game Programming Patterns".

## Downloads

- CMake <https://cmake.org/download/> (download "cmake-3.14.3-win64-x64.msi")

- download make at <http://gnuwin32.sourceforge.net/packages/make.htm>

- SFML <https://www.sfml-dev.org/download/sfml/2.5.1/> (GCC 7.3.0 MinGW (DW2) - 32-bit | MinGW 7.3.0 has to be installed!!!)

## Workflow

1. Open git bash or cmd.exe (or whatever console you prefer)

2. Open the build directory in the modest-engine folder

3. Optional: Generate CMakeLists.txt: with php ./../../cmakelistmaker/cmakeListMaker.php -r -t modest-engine ./../engine (script available [here](https://git.bosstrowski.de/flo/cmakelistmaker))

4. Make: cmake -G "MinGW Makefiles" ..

5. Make: mingw32-make

6. Execute: ./modest-engine.exe

## Useful links

### Recommended VS Code Extensions

- C/C++ IntelliSense, debugging, and code browsing. <https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools>

- markdownlint <https://marketplace.visualstudio.com/items?itemName=DavidAnson.vscode-markdownlint>

- Material Theme <https://marketplace.visualstudio.com/items?itemName=Equinusocio.vsc-material-theme>

- Material Icon Theme <https://marketplace.visualstudio.com/items?itemName=PKief.material-icon-theme>

- EasyZoom <https://marketplace.visualstudio.com/items?itemName=NabeelValley.easyzoom>

- CMake Tools <https://marketplace.visualstudio.com/items?itemName=vector-of-bool.cmake-tools>

### For CMake amateurs (like me)

- <https://gitlab.kitware.com/cmake/cmake/blob/master/Tests/Tutorial/Step1/CMakeLists.txt>

- <https://cmake.org/cmake-tutorial/>

- <https://preshing.com/20170511/how-to-build-a-cmake-based-project/>

- <https://www.johnlamp.net/cmake-tutorial-3-gui-tool.html>

### For SFML CMake adventures

- <https://github.com/SFML/SFML/blob/master/cmake/SFMLConfig.cmake.in> (forum: <https://en.sfml-dev.org/forums/index.php?topic=24070.0>)
