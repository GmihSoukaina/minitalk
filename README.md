# Minitalk
![Ajouter un titre](https://github.com/user-attachments/assets/9555e708-b501-4753-a2ee-d2c341ca29af)

## Introduction
The **Minitalk** project aims to develop a simple program that enables communication between processes using a custom communication protocol called **minitalk**.

## Overview
The **minitalk** protocol facilitates message exchange between two processes using a series of signals over a single wire. It consists of:

- **Speaker (Client):** Sends messages by transmitting a sequence of signals.
- **Listener (Server):** Receives and interprets these signals as messages.

I am a visual person, so I tried to make this diagram for you to understand better:
![image](https://github.com/user-attachments/assets/b43a914c-63b8-489a-87a8-46bc6ce49ef2)

As we can see, we have a client that wants to send a message to the server. The "Hello" (message) cannot be sent directly to the server. The client has to encrypt the message and the server has to decrypt/interpret it before it can be displayed.

## 🔄 Processes & Signals
Processes and signals are the most important terms to know in this project. I've already explained a bit about them above, but you may not have fully understood them yet - let's take another simple example to understand these new concepts.

As I said before, in computer science, a signal is a message that is sent to a process to indicate a particular event has occurred or to request a particular action to be taken. A process is a program that is being executed by the computer. Let's take a simple example:

Imagine you have a program that is running on your computer. This program is Google Chrome running in the background on your computer. When you have multiple windows open on your browser, you have multiple programs running. These programs are called processes.

Now, suppose that you want to stop these programs. You can do this by simply closing the browser window in question. Easy. Or by sending a signal to the process. Remember: a signal is just telling a process to do a certain thing!

Here, we want to close the windows. That will be the signal that we want to send to the processes.

For this, you might use the "kill" command in a terminal window to send a signal to the processes. This signal tells the process to terminate itself. So in this example, the signal (the "kill" command) is used to request a particular action (termination of the process) to be taken.

To send a signal to a certain process you need the PID of it. They will be useful, because that's how you will know which signal to send to which process. It's like a computerized version of our passports. Example on how to do it:

```sh
kill <PID>
```

If you use the above command you will have to kill one process after the other. As they are all part of Chrome, you could also use a single command instead, which will close all running programs (processes) related to Chrome.

```sh
killall chrome
```

## Features
- Process-to-process communication.
- Custom signaling mechanism for message transmission.
- Implementation of a server to listen and decode messages.
- Implementation of a client to send messages.

## Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/yourusername/minitalk.git
   cd minitalk
   ```
2. Compile the program using `Makefile`:
   ```sh
   make
   ```

## Usage
1. Start the server:
   ```sh
   ./server
   ```
   The server will output its process ID (PID), which is needed by the client.
2. Send a message using the client:
   ```sh
   ./client <server_pid> "Your message here"
   ```

## License
This project is licensed under the MIT License.
