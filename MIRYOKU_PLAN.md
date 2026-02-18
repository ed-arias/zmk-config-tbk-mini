# TBK Mini Miryoku Evolution Plan

This document outlines the proposed architectural and functional upgrades for the TBK Mini ZMK configuration, integrating core Miryoku principles with custom enhancements for gaming and OS switching.

## 1. Core Behavioral Enhancements

### Home Row Mods (HRM) Optimization
We will implement "Bilateral Combinations" and "Typing Streak" protection to significantly reduce misfires.
- **Bilateral Trigger:** Modifiers will only activate when a key on the *opposite* hand is pressed. This prevents "same-hand rolling" errors.
- **Typing Streak:** A `require-prior-idle-ms` setting will ensure that if you are typing quickly (a "streak"), mods won't trigger until you pause briefly.
- **Balanced Flavor:** Switching from `tap-preferred` to `balanced` for more predictable hold/tap detection.
- **Global Parameters:** Use `#define` constants for easy tuning:
  - `HRM_TERM`: 280ms (standard hold time)
  - `HRM_QUICK_TAP`: 175ms (prevents mod activation on double taps)
  - `HRM_PRIOR_IDLE`: 150ms (streak timeout)

### Thumb Key Auto-Repeat
To solve the issue where holding `DEL` or `BSPC` switches layers but prevents repeat-erasing:
- **`lt_hp` (Layer-Tap Hold-Preferred):** A custom behavior where:
  - **Tap:** Sends the key (e.g., Backspace).
  - **Hold:** Switches to the assigned layer.
  - **Tap-then-Hold:** Enables the native auto-repeat of the key (Backspace/Delete) while staying on the current layer.

## 2. Layer Architecture

### OS Switching (Windows/Linux vs. macOS)
We will implement OS-specific base layers using ZMK's layer stack.
- **`BASE` (Layer 0):** Configured for Windows/Linux. HRM Order: `LGUI`, `LALT`, `LCTRL`, `LSHFT`.
- **`MAC` (Layer 1):** Configured for macOS. HRM Order: `LALT`, `LGUI`, `LCTRL`, `LSHFT` (Swapping GUI/ALT for Command/Option ergonomics).
- **Mechanism:**
  - We use the `&to` behavior. `&to MAC` deactivates the current base and sets macOS as the foundation.
  - All other layers (NAV, NUM, etc.) are transparent (`&trans`) for the alpha keys, so they work perfectly regardless of which base layer is active underneath.
- **Control:** Dedicated keys in the `ADJ` layer:
  - `&to BASE` (Label: WIN)
  - `&to MAC` (Label: MAC)

### Gaming Layer (`GME`)
A "clean" layer for low-latency gaming.
- **Function:** Disables all Home Row Mods on the left hand (WASD area).
- **Access:** Toggled via the `ADJ` layer or a specific combo.

### Refined Layer Map
1. `BASE` (Win/Linux)
2. `MAC` (macOS)
3. `NAV` (Navigation)
4. `MED` (Media)
5. `NUM` (Numbers)
6. `FUN` (Functions)
7. `SYM` (Symbols)
8. `MSE` (Mouse)
9. `GME` (Gaming)
10. `ADJ` (Adjust/System)

## 3. Implementation Steps

1. **Header Updates:** Define new layers and global timing constants.
2. **Behavior Definitions:** Implement `hrm_l`, `hrm_r`, and the new `lt_hp` behavior.
3. **Layer Expansion:** 
   - Create the `MAC` base layer.
   - Create the `GME` gaming layer.
   - Update `ADJ` with OS toggle and Gaming toggle.
4. **Keymap Refinement:** Update all `lt` (Layer-Tap) calls on thumb keys to use the new `lt_hp` behavior for auto-repeat support.
5. **Validation:** Ensure index 5 is included in `LEFT_HAND_KEYS` to cover the full hand for bilateral triggers.

---
*Prepared by Gemini CLI for TBK Mini Project*
