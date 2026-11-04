/* This file is part of the dynarmic project.
 * SPDX-License-Identifier: 0BSD
 */
#pragma once

#include <string_view>

#if defined(_WIN32) && (defined(_M_X64) || defined(__x86_64__))
namespace Dynarmic::Backend::X64 {
// Optional process-lifetime diagnostic sinks. Install before creating a Jit.
// Sinks must not throw, retain the name view, or re-enter Dynarmic. No callbacks
// are installed by default; Linux's existing perf-map behavior is unchanged.
using JitMapRegisterCallback = void (*)(const void*, const void*, std::string_view);
using JitMapClearCallback = void (*)();
void SetJitMapCallbacks(JitMapRegisterCallback registration, JitMapClearCallback clear);
}  // namespace Dynarmic::Backend::X64
#endif
