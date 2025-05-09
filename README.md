# 🔐 Embedded Password Home Lock System (8051 + I²C)

## 📘 Overview
This project is a **microcontroller-based smart home lock system** built using two **8051 (AT89C51)** microcontrollers that communicate via the **I²C protocol**. It features secure password entry, real-time feedback through an LCD display, and relay control for locking mechanisms. Designed for embedded systems learners and hobbyists, the project integrates both hardware and software design principles.

---

## 🔩 System Components

### 🧠 Microcontrollers
- **AT89C51 (x2)**
  - **Master (Outside Unit)**: Handles user input and display.
  - **Slave (Inside Unit)**: Stores and verifies passwords, controls hardware.

### 📡 Communication
- **I²C Protocol** for reliable data transfer between master and slave.

### 🔧 Peripherals
- **4x4 Keypad** – Password input
- **16x2 LCD** – Displays status messages
- **Relay/Motor Driver** – Controls the door lock
- **Buzzer** – Alerts for wrong password or breach
- **LEDs** – Visual indicators

---

## 🚀 How It Works

1. **User Input**: User enters a 4-digit password via the keypad.
2. **Master Processing**: Master displays the password on the LCD and sends it via I²C to the slave.
3. **Password Verification**: Slave compares the password with the stored one.
4. **Access Decision**:
   - ✅ Correct password: Unlocks door, activates green LED.
   - ❌ Incorrect password: Triggers buzzer, activates red LED.

---

## 💻 Tools & Technologies

- **Keil µVision** – Embedded C development
- **Proteus 8** – Circuit design and simulation
- **C Language** – Firmware development

---

## 🧪 Simulation & Testing

Use **Proteus** with the provided `.pdsprj` file to:
- Test password entry
- Observe LCD output
- Simulate locking/unlocking
- Visualize I²C data flow

[Simulation](simulation.jpg)

---

## 👨‍💻 Team

- Nourhan Farag Mohamed
- Malak Mounir Abdellatif
- Farida Waheed Abdelbary
- Nour Hesham Elsayed
- Razan Ahmed Fawzi
- Raneem Ahmed Refaat
- Lujain Ahmed Youssef
