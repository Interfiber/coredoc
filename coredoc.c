#include "coredoc.h"
#include <string.h>
#include "utils.h"
#include "markdown.h"
#include <stdlib.h>
#include <stdio.h>

void printHelp(){
  printf("coredoc - Static documentation generator written in C\n");
  printf("Author: Interfiber<webmaster@interfiber.dev>\n");
  printf("Commands:\n");
  printf("   build        Build the current project\n");
}

void buildProject(){
  printf("coredoc: starting project build...\n");
  printf("coredoc: loading coredoc_files.list...\n");
  // loop over every line in the coredoc_files.list file
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  
  // open the file
  fp = fopen("coredoc_files.list", "r");
  if (fp == NULL) {
      printf("Failed to read from coredoc_files.list\n");
      exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, fp)) != -1) {
      line[strcspn(line, "\n")] = 0;
      markdownToHtml(line, str_replace(line, ".md", ".html"));
  }
  // close the file
  fclose(fp);
  if (line) {
      // free memory
      free(line);
  }
}
