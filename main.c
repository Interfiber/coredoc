#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coredoc.h"


int main(int argc, char *argv[]){
  if (argc == 1){
    printHelp();
    exit(1);
  } else if (argc == 2 && strcmp(argv[1], "build") == 0){
    buildProject();
  } else {
    printf("coredoc: Invalid command\n");
    exit(1);
  }
}
