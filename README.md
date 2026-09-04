# 📅 Calendar Application (C)

A lightweight, dependency-free calendar utility written in pure C. It generates monthly and yearly calendars, detects leap years, and calculates the day of the week for any given Gregorian date.

## Features

- **Monthly View**: Pretty-prints a single month with a cleanly aligned day grid.
- **Yearly View**: Displays a full 12-month calendar layout.
- **Leap-Year Detection**: Correctly handles Gregorian calendar divisibility rules (100 / 400 years).
- **Weekday Calculation**: Returns the exact weekday name for any valid date input.
- **Zero Dependencies**: Uses only the standard C library, ensuring seamless compatibility across Linux, macOS, and Windows.

## Requirements

- A C compiler (like `gcc`, `clang`, or `MinGW`).
- A terminal or command prompt.

## Build and Run

Compile the program using your preferred C compiler:

```bash
gcc main.c -o calendar
```
