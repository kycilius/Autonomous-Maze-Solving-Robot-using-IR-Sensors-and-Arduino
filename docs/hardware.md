# Hardware Documentation

## Components Identified from Provided Project

| Subsystem | Component |
|---|---|
| Controller | Arduino Uno/Nano |
| Motor driver | L293D or L298N dual H-bridge motor driver |
| Actuators | Two DC motors: left and right |
| Sensors | Five IR sensors connected to A0-A4 |
| Mechanical | Chassis and wheels |
| Power | TODO: specify battery chemistry, voltage, current capability, and regulator details |

## Pin Map

| Signal | Arduino Pin | Purpose |
|---|---:|---|
| `LM_FWD` | D5 | Left motor forward PWM command |
| `LM_BWD` | D6 | Left motor reverse PWM command |
| `RM_FWD` | D9 | Right motor forward PWM command |
| `RM_BWD` | D10 | Right motor reverse PWM command |
| `S1` | A0 | Left-most IR sensor (L2) |
| `S2` | A1 | Left IR sensor (L1) |
| `S3` | A2 | Center IR sensor (C) |
| `S4` | A3 | Right IR sensor (R1) |
| `S5` | A4 | Right-most IR sensor (R2) |

## Power Supply

TODO: Add measured or design power details, including:

- Battery voltage and chemistry.
- Motor supply voltage.
- Logic supply voltage.
- Regulator module, if used.
- Grounding strategy between Arduino, sensor board, and motor driver.
- Motor stall-current margin and thermal considerations.

## Schematic and PCB Status

- Schematics: TODO; place source files or exported PDFs in `hardware/schematics/`.
- PCB design: TODO; place design files, Gerbers, drill files, and fabrication notes in `hardware/pcb/`.

## Validation Methodology

TODO: Add validation evidence when available, such as continuity checks, motor-driver thermal observations, sensor threshold checks, and battery runtime observations.
