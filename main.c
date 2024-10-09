#include "common.h"
#include "flag.h"

static long port_number = 8080;

void help(char *_){
  printf("usage: ./webserver [flags] [flag arguments]\n");
  printf("\t-h, --help\tShow this help screen\n");
  printf("\t-d, --debug\tShow debug logs\n");
  printf("\t-p, --port\tChange default port from 8080\n");
  exit(0);
}

void port(char *port){
  char *endptr;
  long port_num = strtol(port, &endptr, 10);
  if (endptr == port
    || *endptr != '\0' 
    || port_num < 0
    || port_num > 65535
  ) {
    fprintf(stderr, "ERROR: Please provide a valid port number to -p/--port.\n");
    exit(-1);
  }
  port_number = port_num;
}

int main(int argc, char **argv){
  // Bit list corresponding to each flag, 1 << n where n is the index
  registerFlag("-h", "--help", false, help);
  registerFlag("-d", "--debug", false, NULL);
  registerFlag("-p", "--port", true, port);

  int flags = handleArguments(argc, argv);
  #define DEBUG (flags & (1 << 1))
  if (DEBUG){ 
    printf("Flag bitset: ");
    for (int i = 0; i < 8; ++i)
      printf((flags & (1 << i)) ? "1" : "0");
    printf("\n");
  }

  return 0;
}
