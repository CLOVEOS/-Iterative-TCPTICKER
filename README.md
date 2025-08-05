# TCP Client-Server Project in C

This is a simple TCP-based client-server application written in C. The server listens on a specified port and sends the current time to any client that connects. The client connects to the server and displays the received message.

## 🛠 Features

- Basic socket programming in C
- Uses IPv4 and TCP protocol
- Iterative server: handles one client at a time
- Sends system time from server to client

## 📁 Project Structure

```

.
├── client.c        # TCP client implementation
├── server.c        # TCP server implementation
├── unp.h           # Header file with utility macros and functions
├── configure.h     # Additional config/header if needed
├── CMakeLists.txt  # CLion/CMake project file
└── README.md       # You're here!

````

## 🧪 How to Compile

Make sure you have GCC or Clang installed. From the terminal:

```bash
# Compile server
gcc server.c -o server

# Compile client
gcc client.c -o client
````

Or use CLion with the provided CMake setup.

## 🚀 How to Run

**First, start the server:**

```bash
./server
```

**Then, in a new terminal, run the client:**

```bash
./client
```

You should see the current time printed on the client side.

## 📌 Notes

* Server binds to `127.0.0.1` (localhost) on port `8080`
* Ensure the port is not blocked or already in use
* This project uses iterative (not concurrent) server logic

## 📖 Learn More

* [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
* [Unix Network Programming by W. Richard Stevens](https://en.wikipedia.org/wiki/Unix_Network_Programming)


