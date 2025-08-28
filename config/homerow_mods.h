// Copyright 2024 TBK Mini ZMK Config
// Home Row Mods Header - inspired by Miryoku

#pragma once

// Miryoku-style Home Row Mod Macro
// Usage: HRM(MOD, TAP) - creates a mod-tap behavior
// Example: HRM(LGUI, A) creates a key that acts as LGUI when held, A when tapped
// This matches Miryoku's U_MT(MOD, TAP) approach exactly
#define HRM(MOD, TAP) &hrm MOD TAP
