# Autonomous Maze-Solving Robot

This project is a 5-sensor line-following robot capable of navigating mazes and making decisions at junctions using an Arduino and IR sensor array.

## 🧠 Features

- Follows black line using 5 IR sensors (L2, L1, C, R1, R2)
- Detects and navigates cross junctions, dead ends, and turns
- Custom logic for smooth turns and directional corrections
- Debugging via Serial Monitor for real-time sensor feedback

## 🔧 Hardware Requirements

- Arduino Uno/Nano
- L293D or L298N Motor Driver
- 2 DC Motors (Left, Right)
- 5 IR Sensors (connected to A0–A4)
- Chassis, Wheels, Power Supply

## 🗂️ Pin Configuration

| Component | Arduino Pin |
|----------|--------------|
| LM Forward | D5 |
| LM Backward | D6 |
| RM Forward | D9 |
| RM Backward | D10 |
| IR Sensors | A0–A4 |

## 🚀 How It Works

- IR sensors read surface data.
- Motor directions are updated in real-time based on logic:
  - Perfect centering = move forward
  - Misalignment = slight/hard left or right
  - Dead-end = turnaround
  - All black = cross junction

## 📜 License

Open-source for educational and personal use. Feel free to fork and improve!

