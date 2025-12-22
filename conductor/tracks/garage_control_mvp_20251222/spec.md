# Specification - Garage Control MVP

## Overview
This track implements the core functionality of the Automated Garage Door System. The system will use an ESP32 to interface with a SIM800L GSM module to detect incoming calls, verify the caller against a whitelist, and trigger a relay to open the garage door.

## Functional Requirements
- **Call Detection:** Monitor SIM800L for incoming calls.
- **Auto-Hangup:** Immediately reject (busy signal) incoming calls to avoid charges.
- **Authorization:** Check caller ID against a whitelist stored in non-volatile memory (Preferences).
- **Relay Control:** Pulse a GPIO pin for 1 second to trigger the garage motor.
- **Admin Management:** Support SMS commands from designated Admin numbers to add/remove users from the whitelist.
- **Startup Notification:** Send an SMS to Admins when the system boots up.

## Technical Constraints
- **Hardware:** ESP32, SIM800L (UART), 5V Relay Module.
- **Language:** C++ (Arduino Framework).
- **Library:** TinyGSM for SIM800L communication.
- **Storage:** ESP32 `Preferences` library for persistent storage.

## Security
- Whitelist-only access.
- SMS commands restricted to Admin numbers.
