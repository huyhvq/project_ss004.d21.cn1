# Snake Game

This is a simple implementation of the classic Snake Game in C++. The game is developed using the Windows API for console applications.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Installation

This project uses CMake for building. To install and run the game, follow these steps:

1. Clone the repository: `git clone https://github.com/username/snake-game.git`
2. Navigate to the project directory: `cd snake-game`
3. Create a build directory and navigate to it: `mkdir build && cd build`
4. Run CMake: `cmake ..`
5. Build the project: `cmake --build .`

## Usage

After building the project, you can run the game with the following command:

```bash
./snake_game
```

## Project Structure
The project has the following structure:

- `src/`: This directory contains all the source files.
  - `main.cpp`: This is the entry point of the application.
  - `config.cpp` and `config.h`: These files contain the configuration settings for the game.
  - `animation.cpp` and `animation.h`: These files handle the game's animations.
  - `ui_screen.cpp` and `ui_screen.h`: These files contain the implementation of the game's UI.
- `CMakeLists.txt`: This file contains the CMake configuration for building the project.
- `.github/workflows/`: This directory contains the GitHub Actions workflow for CI.
- `.gitignore`: This file specifies the files and directories to be ignored by Git.

Remember to replace the placeholders with the actual descriptions of what each file and directory does in your project.

## Contributing
Contributions are welcome!
## License
This project is licensed under the MIT License. See the LICENSE file for details.