# TBK Mini ZMK Configuration

A professional-grade ZMK firmware configuration for the **TBK Mini**, a 42-key split columnar-staggered ergonomic keyboard. This setup is optimized for productivity, gaming, and multi-OS workflows using **nice!nano v2** controllers.

---

## 🚀 Features at a Glance

- **Miryoku-Inspired Layout:** 3x5+3 design that keeps your hands on the home row.
- **Advanced Home Row Mods (HRM):** Custom behaviors with **Bilateral Triggers** and **Typing Streak** protection.
- **Dual-OS Support:** Dedicated base layers for **Windows/Linux** and **macOS** with ergonomic modifier swapping.
- **Gaming Mode:** Zero-latency alpha layer without modifiers for uninterrupted WASD movement.
- **Auto-Repeat Thumb Taps:** Custom `lt_hp` behavior allowing thumb keys to auto-repeat on tap-then-hold.
- **ZMK Studio Ready:** Real-time keymap editing without reflashing.
- **Integrated Mouse Control:** Full mouse movement and clicking via `zmk-pointing`.
- **Eager Debouncing:** 1ms press debouncing for maximum responsiveness.
- **RGB Underglow:** Full support for WS2812 underglow LEDs.

---

## 🧠 Advanced Firmware Logic

This configuration goes beyond standard keymaps by implementing specialized behaviors to eliminate common small-keyboard pain points.

### 1. Bilateral Home Row Mods (`hrm_l` / `hrm_r`)
To prevent "accidental rolls" from triggering modifiers while typing quickly, these mods use **Bilateral Triggers**.
- **How it works:** A modifier on the left hand will *only* activate if the key you are modifying is on the *right* hand. 
- **Typing Streak Protection:** Uses `require-prior-idle-ms = <150>`, meaning if you are typing in a fast burst, the keyboard stays in "tap mode" and won't trigger modifiers until you pause briefly.

### 2. Hold-Preferred Layer Taps (`lt_hp`)
Standard ZMK `lt` (layer-tap) behavior prevents a key from auto-repeating (e.g., holding Backspace to delete a sentence). Our `lt_hp` behavior fixes this:
- **Tap:** Sends the key (e.g., `BSPC`, `DEL`, `SPACE`).
- **Hold:** Switches to the designated layer.
- **Tap-then-Hold:** Triggers the native **auto-repeat** of the key while staying on the current layer.

---

## ⌨️ Layer Architecture

The keyboard utilizes a 10-layer stack designed for logical grouping and minimal reach.

| Layer | Name | Description | Key Bindings |
| :--- | :--- | :--- | :--- |
| **0** | **Base** | Win/Linux Alpha | **CAGS** (Ctrl, Alt, Gui, Shift) modifiers. |
| **1** | **Mac** | macOS Alpha | **GACS** (Gui, Alt, Ctrl, Shift) modifiers for Mac ergonomics. |
| **2** | **Navigation** | Nav | Arrow keys, Home/End, and Page Up/Down on the right hand. |
| **3** | **Media** | Media | Volume control, Play/Pause, and Track skipping. |
| **4** | **Numbers** | Numbers | A full Numpad layout on the right hand. |
| **5** | **Functions** | Functions | F1-F12 keys and system keys like Print Screen. |
| **6** | **Symbols** | Symbols | Quick access to brackets, math symbols, and punctuation. |
| **7** | **Mouse** | Mouse | Mouse movement, scrolling, and clicks. |
| **8** | **Gaming** | Gaming | Disables all modifiers on the left hand for WASD games. |
| **9** | **Adjust** | System | Bluetooth management, OS switching, and Macros. |

### ⚡ Conditional Layer (Adjust)
The **Adjust** layer is automatically activated whenever you hold both the **Media** (Left Thumb) and **Mouse** (Right Thumb) keys simultaneously, providing quick access to system controls.

---

## 🛠️ Build & Installation

### GitHub Actions (Recommended)
This repo is set up with a `build.yml` workflow. Every time you push a change:
1. GitHub builds the firmware automatically.
2. Download the `.uf2` artifacts from the **Actions** tab.
3. Put your nice!nano into bootloader mode (double-tap reset).
4. Drag and drop the `left` and `right` files onto the respective drives.

### Local Development
```bash
# Initialize the workspace
west init -l config
west update

# Build the Left Half
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=tbk_mini_left

# Build the Right Half
west build -s zmk/app -b nice_nano_v2 -- -DSHIELD=tbk_mini_right
```

---

## 📝 Hardware Configuration
- **Controller:** nice!nano v2
- **Display:** (Optional) SSD1306 OLED support via ZMK.
- **Battery:** Optimized for Li-Po battery management via ZMK's power management features.

---
*Maintained by [ed_arias](https://github.com/ed_arias)*
