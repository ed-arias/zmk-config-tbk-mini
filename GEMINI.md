# GEMINI.md - TBK Mini ZMK Configuration

## Project Overview
This project contains the ZMK firmware configuration for a **TBK Mini**, a split columnar-staggered ergonomic keyboard. It is designed to run on **nice!nano v2** controllers.

### Key Technologies
- **Firmware:** [ZMK Firmware](https://zmk.dev/)
- **Hardware:** TBK Mini (split 42-key layout), nice!nano v2
- **Configuration:** Devicetree (DTS) for keymaps and Kconfig for system settings.

## Core Features & Architecture
- **Miryoku-Inspired Layout:** Optimized 3x5+3 design.
- **Advanced Behaviors:** 
  - `hrm_l`/`hrm_r`: Custom hold-tap behaviors with bilateral trigger and typing streak protection.
  - `lt_hp`: Layer-tap behavior with hold-preferred auto-repeat on tap-then-hold.
- **Layer Stack:** 10 layers including Base, Mac, Navigation, Media, Numbers, Functions, Symbols, Mouse, Gaming, and Adjust.
- **OS Switching:** Seamless switching between Windows/Linux and macOS layouts using `&to`.
- **Gaming Mode:** Dedicated layer (`GME`) without Home Row Mods for low-latency input.

## Building and Running

### GitHub Actions (Recommended)
This repository is configured to build automatically via GitHub Actions whenever changes are pushed.
- **Output:** Firmware `.uf2` files for left and right halves are available in the Actions artifacts.

### Local Build (West)
To build locally, ensure you have the [ZMK development environment](https://zmk.dev/docs/development/setup) installed.
```bash
# Initialize west if not already done
west init -l config
west update

# Build Left Half
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=tbk_mini_left

# Build Right Half
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=tbk_mini_right
```

## Development Conventions
- **Keymap File:** `config/tbk_mini.keymap` is the primary source of truth for the layout.
- **Config File:** `config/tbk_mini.conf` contains Kconfig flags (e.g., RGB, Mouse, ZMK Studio).
- **Home Row Mods:** 
  - **Base (Win/Linux):** CAGS order (Ctrl, Alt, GUI, Shift) from pinky to index.
  - **Mac:** GACS order (GUI, Alt, Ctrl, Shift) from pinky to index.
- **Bilateral Combinations:** Modifiers only trigger when the opposite hand's key is pressed.
- **Documentation:** Refer to `README.md` for a user-facing overview.

## Key Files
- `README.md`: Comprehensive user guide and feature summary.
- `config/tbk_mini.keymap`: The Devicetree keymap definition.
- `config/tbk_mini.conf`: System-level configuration.
- `build.yaml`: Defines the build matrix for GitHub Actions.

---
*Updated by Gemini CLI - Saturday, February 21, 2026*
