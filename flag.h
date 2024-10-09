#ifndef FLAG_H
#define FLAG_H

#include "common.h"

typedef void (*Callback)(char*);

// Registers flag that can be provided as a parameter to this program.
// -- short_flag: shorthand flag
// -- long_flag: longhand flag
// -- takes_arg: whether or not the following parameter should be stored as an argument
// -- callback: function to pass arguments to
void registerFlag(
  const char *short_flag,
  const char *long_flag,
  bool takes_arg,
  Callback callback
);

// Checks through parameters passed to program, handling all flags
// -- Remember that flags are registered at the top of main
// Returns bitset of parameters passed
// 1 << 0 : Halt execution, send help message
// 1 << 1 : Turn on debug logging
// 1 << 2 : Set port to host on (default is 8080)
// 1 << 3 : TBD
// 1 << 4 : TBD
// 1 << 5 : TBD
// 1 << 6 : TBD
// 1 << 7 : TBD
int handleArguments(int argc, char **argv);

#endif
