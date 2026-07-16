_This project has been created as part of the 42 curriculum by **esttina**_

# Minitalk

## Description
Minitalk is a project from the 42 curriculum that introduces the concept of inter-process communication (IPC) in UNIX environments. The primary goal is to create a simple client-server architecture where a client sends a string of characters to a server, which then prints the string to the standard output. 

The core challenge of this project is that communication must be handled exclusively using UNIX signals: `SIGUSR1` and `SIGUSR2`. This requires encoding every character of the string into binary (0s and 1s), transmitting them sequentially across processes, and decoding them on the server side back into printable characters.

## Features & Technical Choices
* **Robust Signal Handling:** Utilizes `sigaction` instead of `signal` to ensure safer, more reliable handling of incoming signals without interruption issues.
* **Bitwise Operations:** Characters are transmitted bit by bit. A `SIGUSR1` signal represents a binary `1`, while a `SIGUSR2` signal represents a binary `0`.
* **Custom Library Integration:** The project incorporates a custom implementation of `ft_printf` to handle all standard output formatting cleanly and efficiently.

---

## Project Structure

```text
.
├── Makefile
├── minitalk.h
├── server.c
├── client.c
└── ft_printf/
    ├── Makefile
    ├── ft_printf.c
    ├── ft_printf.h
    ├── char_specifier.c
    ├── hex_specifier.c
    └── num_specifier.c
```

---

## Instructions

**1. Compilation**  
First, compile the project using the provided `Makefile`. This will build both the `server` and `client` executables, along with the included `ft_printf` library.
```bash
make
```

**2. Start the Server**  
You must start the server first. Upon execution, the server will display its assigned Process ID (PID) and wait in an infinite loop for incoming signals.
```bash
./server
```
*(Example output: `Server PID: 12345`)*

**3. Run the Client**  
Open a second terminal window. Execute the client by passing the server's PID as the first argument and the message you want to send as the second argument.
```bash
./client 12345 "Hello, 42!"
```
The server will receive the bits, reconstruct the characters, and print "Hello, 42!" to its terminal.

---

## Visualizing `handle_signal` Bitwise Logic

To understand how the server reconstructs a character from individual signals, let's trace the transmission of the letter **'A'**.
* The ASCII decimal value of 'A' is **65**.
* The 8-bit binary representation is **`01000001`**.

In this implementation, the client sends these 8 bits one by one, starting from the Least Significant Bit (LSB, far right) to the Most Significant Bit (MSB, far left). We define our signal rules as:
* `SIGUSR2` = Bit `1`
* `SIGUSR1` = Bit `0`

In the server's `handle_signal` function, we reconstruct the character using a static variable `current_char` initialized to `0` (binary `00000000`). Since it already consists of zeros, we only need to take action when a `1` is received.
If we receive `SIGUSR2`, we use the bitwise left shift (`<<`) to move a `1` to the current `bit_index` position, and then use the bitwise OR assignment (`|=`) to set that specific bit in `current_char`. If we receive `SIGUSR1`, we simply do nothing and let the index increment.

| Step (bit_index) | Received Signal | Bit Value | Bitwise Operation (if `SIGUSR2`) | Resulting Byte (Binary) |
| :--- | :--- | :---: | :--- | :--- |
| 0 (LSB) | `SIGUSR2` | `1` | `current_char \|= (1 << 0)` | `00000001` |
| 1 | `SIGUSR1` | `0` | *(None, bit remains 0)* | `00000001` |
| 2 | `SIGUSR1` | `0` | *(None, bit remains 0)* | `00000001` |
| 3 | `SIGUSR1` | `0` | *(None, bit remains 0)* | `00000001` |
| 4 | `SIGUSR1` | `0` | *(None, bit remains 0)* | `00000001` |
| 5 | `SIGUSR1` | `0` | *(None, bit remains 0)* | `00000001` |
| 6 | `SIGUSR2` | `1` | `current_char \|= (1 << 6)` | `01000001` |
| 7 (MSB) | `SIGUSR1` | `0` | *(None, bit remains 0)* | `01000001` (65 = 'A') |

Once 8 bits (1 byte) are received, the server prints the character and resets the variables to process the next incoming character.

---

## Resources

**Documentation & References:**
* `man 2 sigaction` – Examining and changing signal actions safely.
* `man 2 kill` – Sending signals to processes.
* `man 2 getpid` – Retrieving the current process ID.
* `man 3 pause` – Suspending the process until a signal is caught.
* [Bitwise Operations in C (Wikipedia)](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)

**AI Usage:**
* Generative AI (LLM) was used to structure and format this `README.md` file based on provided requirements.
* AI served as an educational assistant to clarify the logic of bitwise shifting (`<<` and `|`) and to create the step-by-step visualization table illustrating how signals are converted back into ASCII characters inside the handler function.