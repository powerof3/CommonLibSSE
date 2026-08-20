# `CommonLibSSE`
[![C++23](https://img.shields.io/static/v1?label=standard&message=C%2B%2B23&color=blue&logo=c%2B%2B&&logoColor=white&style=flat)](https://en.cppreference.com/w/cpp/compiler_support)
[![Platform](https://img.shields.io/static/v1?label=platform&message=windows&color=dimgray&style=flat)](#)
[![License: GPL-3.0-or-later](https://img.shields.io/static/v1?label=license&message=GPL-3.0-or-later&color=blue&style=flat)](#license)
[![Main CI](https://github.com/dann1/CommonLibSSE/actions/workflows/main_ci.yml/badge.svg?branch=dev)](https://github.com/dann1/CommonLibSSE/actions/workflows/main_ci.yml?branch=dev)


## Build Dependencies
* [spdlog](https://github.com/gabime/spdlog)
* [Visual Studio Community 2019 16.10.0 Preview 3.0](https://visualstudio.microsoft.com/vs/preview/)
	* Desktop development with C++

## End User Dependencies
* [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
* [SKSE64](https://skse.silverlock.org/)

## Development
* [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)
* [clang-format 12.0.0](https://github.com/llvm/llvm-project/releases)
* [CMake](https://cmake.org/)
* [vcpkg](https://github.com/microsoft/vcpkg)

## Notes
* CommonLib is incompatible with SKSE and is intended to replace it as a static dependency. However, you will still need the runtime component.

## License

[GPL-3.0-or-later](COPYING) WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS.md).
Specifically, the Modded Code includes:

- Skyrim (and its variants)
- Hardware drivers to enable additional functionality provided via proprietary SDKs, such as [Nvidia DLSS/Streamline](https://developer.nvidia.com/rtx/dlss/get-started) and [AMD FidelityFX FSR3](https://gpuopen.com/fidelityfx-super-resolution-3/)

The Modding Libraries include:

- [SKSE](https://skse.silverlock.org/)
- Windows

> [!IMPORTANT]
> This is a breaking change from the previous MIT license. The Modding Exception only covers interoperation with
> Skyrim itself and proprietary hardware SDKs (like DLSS/Streamline or FSR3) that neither we nor plugin authors have
> the right to relicense -- it does **not** cover plugin/mod code. A plugin that statically links CommonLibSSE
> forms a combined work with it and must itself be licensed under the GPL-3.0-or-later (or a GPL-compatible
> license); see [EXCEPTIONS.md](EXCEPTIONS.md) for the exact terms.

Originally based on code under [MIT](LICENSE).
