#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coredoc.h"
#include "utils.h"


int main(int argc, char *argv[]){
  if (argc == 1){
    printHelp();
    exit(1);
  } else if (argc == 2 && strcmp(argv[1], "build") == 0){
    buildProject();
  } else if (argc == 2 && strcmp(argv[1], "version") == 0) {
    printf("Coredoc build info:\n");
    printf("Package Name: %s\n", getName());
    printf("Package Webstie: %s\n", getWebsite());
    printf("Package Bug Report Email: %s\n", getBugReportEmail());
    printf("Package Version: %s\n", getVersion());
    exit(0);
  } else {
    printf("coredoc: Invalid command\n");
    exit(1);
  }
}
