# SimpleBencher

**SimpleBencher** is a lightweight benchmarking tool written in C that calculates prime numbers and measures the performance of the process. It displays the time taken for execution and calculates a performance score based on the speed.

## Features

- Finds and counts prime numbers up to a specified limit.
- Measures the execution time and displays a performance score.
- Shows the time taken in seconds.

## Installation

### Debian Package Installation

1. **Download the `.deb` file** from this repository (make sure to include the compiled `.deb` file in your repo).
2. Install using the following commands:

   ```bash
   sudo dpkg -i SimpleBencher.deb
   sudo apt-get install -f   # To resolve dependencies, if needed
   ```

3. **Run the program**:

   ```bash
   simplebencher
   ```

### Compile from Source

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/SimpleBencher.git
   cd SimpleBencher
   ```

2. Compile the program with GCC:

   ```bash
   gcc -o simplebencher simplebencher.c
   ```

3. Run the program:

   ```bash
   ./simplebencher
   ```

## Example Output

When running the program, you’ll see output like this:

```
Primes: 40000
Score: 13.92
Time: 57.135 Seconds
```

- **Primes**: The number of primes found.
- **Score**: A performance score based on execution time.
- **Time**: Total execution time in seconds.

## Contributing

Feel free to open an issue or submit a pull request if you find bugs or have suggestions for improvements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
