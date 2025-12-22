# Plan - Garage Control MVP

## Phase 1: Hardware Integration & Basic Communication
- [ ] Task: Project Scaffolding - Initialize PlatformIO project and install TinyGSM library.
- [ ] Task: Basic UART Communication - Implement code to communicate with SIM800L via AT commands.
- [ ] Task: Network Registration - Implement logic to wait for GSM network registration and signal strength check.
- [ ] Task: Conductor - User Manual Verification 'Phase 1' (Protocol in workflow.md)

## Phase 2: Call Handling & Relay Control
- [ ] Task: Incoming Call Detection - Monitor serial for RING alerts and extract Caller ID.
- [ ] Task: Auto-Reject Logic - Implement immediate hang-up upon ring detection.
- [ ] Task: Relay Triggering - Implement GPIO control logic for 1-second pulse.
- [ ] Task: Conductor - User Manual Verification 'Phase 2' (Protocol in workflow.md)

## Phase 3: Whitelist & SMS Management
- [ ] Task: Persistent Storage - Implement Preferences-based whitelist management.
- [ ] Task: SMS Command Parsing - Implement logic to handle "ADD", "REMOVE", and "STATUS" commands from Admins.
- [ ] Task: Startup Notification - Implement SMS alert on system boot.
- [ ] Task: Conductor - User Manual Verification 'Phase 3' (Protocol in workflow.md)

## Phase 4: Final Integration & Testing
- [ ] Task: Integration - Combine call detection with whitelist verification and relay triggering.
- [ ] Task: Stress Testing - Verify system stability under repeated calls and network loss scenarios.
- [ ] Task: Conductor - User Manual Verification 'Phase 4' (Protocol in workflow.md)
