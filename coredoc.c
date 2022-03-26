#include "coredoc.h"
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
  markdownToHtml("index.md", "index.html");
}
