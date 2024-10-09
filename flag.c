#include "flag.h"

// DOD sucks balls
#define FLAG_CAPACITY 8
static size_t flag_count = 0; 
static char short_flags[8][3];
static char long_flags[8][9];
static bool takes_argument[8];
static Callback callbacks[8];

void registerFlag(
  const char *short_flag,
  const char *long_flag,
  bool takes_arg,
  Callback callback
) {
  strncpy(short_flags[flag_count], short_flag, 2);
  short_flags[flag_count][2] = '\0';

  strncpy(long_flags[flag_count], long_flag, 8);
  long_flags[flag_count][8] = '\0';
  
  takes_argument[flag_count] = takes_arg;
  callbacks[flag_count] = callback;
  ++flag_count;
}

int handleArguments(int argc, char **argv){
  // Get list of all flags
  int result = 0;
  if (argc <= 1)
    return 0;
  for (int i = 0; i < flag_count; ++i){
    for (int j = 1; j < argc; ++j){
      if (strncmp(short_flags[i], argv[j], 2) == 0
        || strncmp(long_flags[i], argv[j], 8) == 0){
        result |= (1 << i);
        if (callbacks[i] == NULL)
          continue;
          
        if (!takes_argument[i]){
          callbacks[i](NULL);
        } else if (j + 1 < argc){
          callbacks[i](argv[j + 1]);
        } else {
          fprintf(stderr, "ERROR: No argument provided to flag '%s'.\n", argv[j]);
          exit(-1);
        }
        continue;
      }
    }
  }
  return result;
}
