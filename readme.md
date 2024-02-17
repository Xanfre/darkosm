# DarkOSM

DarkOSM is a minimalistic implementation of an object script module,
providing the interfaces necessary to write scripts for all released Dark Engine
games (Thief 1/Gold, Thief 2, and System Shock 2). Using all script services is
supported. The ANSI C implementation can be found in `csrc` and the ISO C++98
implementation can be found in `cppsrc`. Both implementations are independent of
each other and employ a common API.

### libosm

libOSM consists of only the `api.h` header in combination with the service
headers. The API provides all interfaces and supplemental types necessary for a
script module to work with the target game. The service headers provide the
interfaces necessary to use a particular game's script services and are the
primary means of interaction.

`IScript` is the script interface. It is used by scripts for handling messages.

`IScriptManager` is the script manager interface. It is used for managing script
state, initializing services, working with messages, and several more common
tasks.

`IScriptModule` is the script module interface. It is used by the script module
for initializing individual scripts.

### Building

Makefiles for MinGW-w64 (GNU Make) and Visual C++ 9 (NMAKE) are provided for
both the C and C++ implementations. Using the requisite make utility from the
source directory will generate complete binaries. No additional dependencies are
required.

### Usage

A complete script module implementation is located in `csrc/module.c` and
`cppsrc/module.cpp`. For an example script, see `csrc/script.c` and
`cppsrc/script.cpp`, respectively. The included script, `TestScript`, simply
responds to a `FrobWorldEnd` message by printing to mono. More complex scripts
can be constructed by handling additional messages and using additional service
routines.
