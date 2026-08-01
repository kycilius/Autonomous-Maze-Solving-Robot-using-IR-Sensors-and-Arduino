# System Architecture

## Overview

This project implements an Arduino-based autonomous maze-solving and line-following robot using a five-channel IR sensor array and a dual H-bridge motor driver. The firmware continuously samples the IR sensors, classifies the current line or maze condition, and commands the left and right DC motors through PWM-capable Arduino pins.

## Hardware Block Diagram

```mermaid
flowchart LR
    Surface[Black-Line Maze Surface] --> IR[5-Channel IR Sensor Array]
    IR -->|Digital signals A0-A4| Arduino[Arduino Uno/Nano]
    Arduino -->|PWM/Digital D5-D6| LeftDriver[Left H-Bridge Channel]
    Arduino -->|PWM/Digital D9-D10| RightDriver[Right H-Bridge Channel]
    LeftDriver --> LeftMotor[Left DC Motor]
    RightDriver --> RightMotor[Right DC Motor]
    Arduino -->|9600 baud debug logs| SerialMonitor[Arduino Serial Monitor]
    Power[Power Supply TODO: specify voltage/current] --> Arduino
    Power --> LeftDriver
    Power --> RightDriver
```

## Data Flow

```mermaid
flowchart TD
    ReadSensors[Read S1-S5 with digitalRead] --> PrintDebug[Print sensor state over Serial]
    PrintDebug --> Classify[Classify line condition]
    Classify --> Command[Select motion primitive]
    Command --> PWM[Write motor PWM outputs]
    PWM --> Motion[Robot motion]
    Motion --> ReadSensors
```

## Control Flow

The control loop is implemented in `loop()` and runs continuously without an explicit scheduler. Decision priority is encoded by the order of conditional checks in the firmware.

1. Read five IR sensor channels.
2. Emit sensor readings to the serial monitor for debugging.
3. Match the sensor pattern against known cases: centered line, slight corrections, hard turns, cross junction, dead end, or default forward motion.
4. Update motor-driver outputs using `analogWrite()` and short blocking delays for hard turns, turn-around behavior, and cross-junction traversal.

## State Machine

```mermaid
stateDiagram-v2
    [*] --> ReadSensors
    ReadSensors --> Centered: HIGH HIGH LOW HIGH HIGH
    ReadSensors --> SlightRight: C and R1 detect line
    ReadSensors --> SlightLeft: C and L1 detect line
    ReadSensors --> HardRight: R1 and R2 detect line
    ReadSensors --> HardLeft: L2 and L1 detect line
    ReadSensors --> CrossJunction: all sensors LOW
    ReadSensors --> TurnAround: all sensors HIGH
    ReadSensors --> DefaultForward: unmatched pattern
    Centered --> ReadSensors
    SlightRight --> ReadSensors
    SlightLeft --> ReadSensors
    HardRight --> ReadSensors
    HardLeft --> ReadSensors
    CrossJunction --> ReadSensors
    TurnAround --> ReadSensors
    DefaultForward --> ReadSensors
```

## Communication Protocols

- USB serial debug output at 9600 baud.
- TODO: Document any external communication protocol if added later.

## Timing, Interrupts, and Timers

- The provided firmware does not configure custom interrupts.
- The provided firmware uses Arduino `analogWrite()`, which relies on board timer peripherals for PWM generation.
- The provided firmware uses blocking `delay()` calls during hard turns, turnaround, and cross-junction traversal.

## ADC Pipeline

The current firmware reads the IR sensor pins with `digitalRead()`. Although the sensors are connected to Arduino analog-capable pins A0-A4, the provided implementation treats each channel as a digital thresholded input. No explicit ADC pipeline is implemented.
