# ASCII Function Plotter

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Area](https://img.shields.io/badge/Area-Mathematics-pink.svg)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A lightweight CLI (Command Line Interface) tool written in C that visualizes various mathematical functions directly in the terminal using ASCII characters, for educational purpouses.



## 📖 About

This project allows users to input coefficients for standard mathematical functions (linear, quadratic, trigonometric, etc.) and generates a plot using ASCII characters. It handles coordinate mapping to fit the terminal window and includes basic color coding for better user experience.


### ⚠️ Context & Legacy Code
**Note:** This project was originally developed during my **first semester of Computer Science**. To preserve the history of my learning curve, I have kept the original code structure (including the use of global variables and procedural design) mostly intact, with only minor logic fixes applied for stability.



## 🚀 Features

* **Wide Range of Functions:**
    * Affine ($ax + b$)
    * Modular ($|ax + b|$)
    * Quadratic ($ax^2 + bx + c$)
    * Cubic ($ax^3 + bx^2 + cx$)
    * Trigonometric (Sine, Cosine, Tangent)
    * Exponential ($a \cdot e^x$)
    * Logarithmic ($a \cdot \log_{10}(x)$ )
* **Zoom Capabilities:** Simulate zoom in/out by adjusting the plane dimensions (constants `A` and `L`) in the source code.
* **Automatic Scaling:** Maps mathematical coordinates to the terminal grid.
* **Color Output:** Uses ANSI escape codes to colorize the menu and inputs.
* **Safety Checks:** Includes domain validation for logarithmic functions to prevent calculation errors.



## 🛠️ Installation & Compilation

You will need a C compiler (like `gcc`).

1.  **Clone the repository:**
      ```bash
      git clone https://github.com/vitor-rodovalho/c-terminal-function-plotter.git
      cd c-terminal-function-plotter
      ```

2.  **Compile the code:**
    * **Linux/macOS:** (Requires linking the math library with `-lm`)
        ```bash
        gcc function_plotter.c -o plotter -lm
        ```
    * **Windows:**
        ```cmd
        gcc function_plotter.c -o plotter.exe
        ```


## 💻 Usage

Run the compiled executable:

```bash
./plotter
```

Follow the on-screen menu to select a function and input the required coefficients.


### Example

To plot a sine wave:

1. Select option `5` (Sine function).
2. Enter the amplitude coefficient `a`.
3. The graph will be simulated in the terminal.



## 📸 Screenshots

Below is an example of the program in action.
The image shows a **Sine wave** with an amplitude of 5 (Function: `f(x) = 5 * sin(x)`), demonstrating how the ASCII characters form the curve on the terminal grid.

![Sine Wave Example](assets/FunctionPlotter.png)


---

## ⚠️ Language Note

Please note that the code comments are currently in **Portuguese**, as this project was originally developed for a university assignment.

## 📄 Author

Developed by **Vitor Hugo Rodovalho**.

---

**License**: MIT License
