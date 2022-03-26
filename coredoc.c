#include "coredoc.h"
#include "html.h"
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>
#include "utils.h"
#include "markdown.h"
#include <stdlib.h>
#include <stdio.h>

void printHelp(){
  printf("coredoc - Static documentation generator written in C\n");
  printf("Author: Interfiber<webmaster@interfiber.dev>\n");
  printf("Commands:\n");
  printf("   build        Build the current project\n");
  printf("   version      Print version and build info\n");
}

void buildProject(){
  printf("coredoc: starting project build...\n");
  printf("coredoc: loading coredoc_files.list...\n");
  // loop over every line in the coredoc_files.list file
  struct dirent *de;  // Pointer for directory entry
  DIR *dr = opendir("src");
  if (dr == NULL) {
    printf("Failed to open src directory\n");
    exit(1);
  }
  char *fileName;
  while ((de = readdir(dr)) != NULL) {
    if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, "..")){
      // do nothing
    } else {
       fileName = de->d_name;
       printf("coredoc: building file %s\n", fileName);
       char* outputFile = str_replace(fileName, ".md", ".html");
       markdownToHtml(str_merge("src/", fileName), outputFile, false);
       printf("coredoc: built file to %s\n", outputFile);
    }
  }
  closedir(dr);
}
