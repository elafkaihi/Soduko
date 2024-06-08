# Sudoku Solver and Generator

![Sudoku Puzzle](https://sudoku-puzzles.net/wp-content/puzzles/center-dot-sudoku/easy/1.png)

## Overview
This project is a Sudoku solver and generator written in C++. It provides functionalities to create Sudoku puzzles, solve them, and validate the solutions. 

## Features
- Generate Sudoku puzzles of varying difficulty levels.
- Solve Sudoku puzzles using a backtracking algorithm.
- Validate Sudoku solutions.
- Interactive user interface using Qt.

## Installation
To compile and run this project, follow these steps:

1. **Clone the repository**
    ```bash
    git clone https://github.com/elafkaihi/Soduko.git
    cd Soduko
    ```

2. **Install dependencies**
    Ensure you have Qt installed on your system. You can download it from [Qt Downloads](https://www.qt.io/download).

3. **Build the project**
    ```bash
    qmake Sudoku.pro
    make
    ```

4. **Run the executable**
    ```bash
    ./Sudoku
    ```

## Usage
Once the application is running, you can:
- Generate a new Sudoku puzzle.
- Input your own Sudoku puzzle.
- Solve the puzzle.
- Validate your solution.

## File Structure
- `constdef.cpp` / `constdef.h`: Contains constant definitions used in the project.
- `extrawnd.cpp` / `extrawnd.h`: Additional window functionalities.
- `inputcell.cpp` / `inputcell.h`: Handles input cell operations.
- `soduko.ui`: User interface design file.
- `sudoku.cpp` / `sudoku.h`: Core Sudoku logic and functionalities.

## Contributing
Contributions are welcome! Please follow these steps to contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For any questions or inquiries, please contact the repository owner.

