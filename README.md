 # UNIX Signal Communication Project
* This project implements communication between a server and client using only UNIX signals (SIGUSR1 and SIGUSR2) for data exchange.

## Project Goal:

* Develop a server program that:
** Prints its process ID (PID) upon launch.
** Continuously listens for incoming signals.
** Handles multiple client connections concurrently.
** Processes received strings efficiently (ideally under 1 second for 100 characters).

* Bonus: 
** Acknowledge received messages with a signal back to the client.
** send unix code characters (emojis, etc...)

* Design a client program that:
* Takes two arguments: server PID and a string message.
* Sends the message to the server using signals.
* Optionally Bonus: Handle acknowledgement signals from the server.
Technical Specifications:

* Communication Protocol: Utilizes SIGUSR1 and SIGUSR2 exclusively.
* Data Transfer: Each character within the message is encoded and sent as separate signals.

## Bonus Features:

Message Acknowledgement: Server sends a signal back to the client upon successful message reception.
Unicode Support: Enables transmission and processing of Unicode characters.
Running the Project:

Compile both server and client programs using your preferred C/C++ compiler.
Start the server first. It will print its PID to the console.
Run the client program, providing the server PID and the message string as arguments.
The server should display the received message promptly.
___

## Example Usage:

* server &  # Start the server in the background
./server_pid  # Print the server's PID

* ./client <server_pid> "Hello from the client!"  # Send a message

## Note:

### This project prioritizes efficiency in receiving and processing messages. Aim for minimal processing time per character (ideally under 10ms for 100 characters).

# Getting Started:

Clone this repository: git clone https://github.com/HYYPNNOSS/unix-signal-communication
Implement the server and client programs based on the provided specifications.
Test your implementation thoroughly.
This project provides a foundation for exploring inter-process communication using low-level mechanisms like UNIX signals. Feel free to experiment and enhance the code further!
