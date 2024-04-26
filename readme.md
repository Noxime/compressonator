
# Compressonator for WASM

This is a fork of [compressonator](https://github.com/GPUOpen-Tools/compressonator) hacked to compile for Emscripten
targets. This fork is based on version V4.2.5185 as it is the last version that supported ASTC.

## To build
I have added a new script `/emscripten.bat` to compile CMP_Core and CMP_compressonator into `build/libs/` together with
an example `project.html` which converts a texture (`wasm-target.cpp`)


