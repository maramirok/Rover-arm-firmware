# Rover Arm Firmware

Motor control firmware for the Space Concordia Mars rover robotic arm. Runs on an STM32G030 with an MCP25625 CAN controller, driving five independent motors over a single CAN bus.

## Features

- Custom 29-bit extended CAN ID protocol with field-based dispatch (device ID, instruction, severity)
- Independent control of 5 motors over one CAN bus
- 10 kHz PWM generation with signed velocity (direction handling)
- MCP25625 SPI driver (raw SPI primitives, protocol layer, public API)
- Fault handling for CAN bus-off and RX overflow, with LED indicators
- IWDG watchdog refresh

## Hardware

- MCU: STM32G030C8T6
- CAN controller/transceiver: MCP25625
- Target: Custom 5-motor control PCB (designed in KiCad)

## Build

Developed in STM32CubeIDE. Open the `.ioc` file in STM32CubeMX or import the project directly into STM32CubeIDE.
