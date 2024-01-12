# `CommonLibSSE/CommonLibVR`

[![C++20](https://img.shields.io/static/v1?label=standard&message=C%2B%2B20&color=blue&logo=c%2B%2B&&logoColor=white&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
[![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat)](#)
[![Scripted maintenance](https://github.com/alandtse/CommonLibVR/actions/workflows/maintenance.yml/badge.svg?branch=vr)](https://github.com/alandtse/CommonLibVR/actions/workflows/maintenance.yml)

This a version of CommonLibVR that is based off of the latest CommonLibSSE after the cmake migration. It is meant to also work in SSE.

## Build Dependencies

- [binary_io](https://github.com/Ryan-rsm-McKenzie/binary_io)
- [spdlog](https://github.com/gabime/spdlog)
- [fmt](https://github.com/fmtlib/fmt)
- [Visual Studio Community 2022](https://visualstudio.microsoft.com/vs/preview/) (or later)
  - Desktop development with C++

## Development

- [Visual Studio Community 2019 16.10.0 Preview 3.0](https://visualstudio.microsoft.com/vs/preview/)
  - Desktop development with C++
- [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
- [VR Address Library for SKSEVR Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/58101)
- [VR Address Tools](https://github.com/alandtse/vr_address_tools)
  - For checking VR known addresses.
- [clang-format 12.0.0](https://github.com/llvm/llvm-project/releases)
- [CMake](https://cmake.org/)
- [vcpkg](https://github.com/microsoft/vcpkg)
  - Complete [quick start guide](https://github.com/microsoft/vcpkg#quick-start-windows)
  - Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg

## Building

**Ensure Development requirements are completed.**

```
git clone https://github.com/alandtse/CommonLibVR.git
cd CommonLibVR
git checkout vr

# Install dependencies (may be skipped if cmake integrated with vcpkg)
vcpkg install
git submodule init
git submodule update

# Skyrim SE
cmake --preset vs2022-windows-vcpkg
cmake --build build --config Release

# Skyrim VR
cmake --preset vs2022-windows-vcpkg-vr
cmake --build buildvr --config Release
```

## End User Dependencies SSE

- [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
- [SKSE64](https://skse.silverlock.org/)

## End User Dependencies VR

- [VR Address Library for SKSEVR Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/58101)
- [SKSEVR](https://skse.silverlock.org/)

## Notes

- CommonLibSSE/VR is incompatible with SKSE/SKSEVR and is intended to replace it as a static dependency. However, you will still need the runtime component.

## Credits

- Thanks to Ryan McKenzie for original code
- Thanks to RollingRock & po3 for important contributions
- Thanks to lfrazer for [commonlibvr](https://github.com/lfrazer/CommonLibVR) port which is the source of Exit-9B recombination; also thanks for all the support in discord.
- Thanks to Exit-9B for recombination of [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE) and [CommonLibVR](https://github.com/lfrazer/CommonLibVR)
- Thanks to powerof3 for maintaing a SSE branch of [CommonLibSSE](https://github.com/powerof3/CommonLibSSE/tree/dev)

## Tutorial

Learn how to build your very first SKSE plugin using CommonLib by following [this video tutorial](https://www.youtube.com/watch?v=FLRhsrQ8mqw).
