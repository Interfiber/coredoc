#include "markdown.h"
#include "html.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <stdbool.h>
#include <lowdown.h>

void markdownToHtml(char* inputFile, char* outputFile, bool format) {
  // read data in from file
  FILE *mdfile;
  mdfile = fopen(inputFile, "r"); // open the file
  // convert
  struct lowdown_opts opts;
  char *buf;
  size_t bufsz;
  memset(&opts, 0, sizeof(struct lowdown_opts));
  opts.type = LOWDOWN_HTML;
  opts.feat = LOWDOWN_FOOTNOTES |
                   LOWDOWN_AUTOLINK |
                   LOWDOWN_TABLES |
                   LOWDOWN_SUPER |
                   LOWDOWN_STRIKE |
                   LOWDOWN_FENCED |
                   LOWDOWN_COMMONMARK |
                   LOWDOWN_DEFLIST |
                   LOWDOWN_IMG_EXT |
                   LOWDOWN_METADATA;
  opts.oflags = LOWDOWN_HTML_HEAD_IDS |
                   LOWDOWN_HTML_NUM_ENT |
                   LOWDOWN_HTML_OWASP |
                   LOWDOWN_SMARTY |
                   LOWDOWN_STANDALONE;
   if (!lowdown_file(&opts, mdfile, &buf, &bufsz, NULL))
      printf("lowdown_file failed to complete\n");
   // write the converted data to disk
   fclose(mdfile);
   FILE *outfile;
   outfile = fopen(outputFile, "w"); // open the outputfile
   fwrite(buf, 1, bufsz, outfile);
   // cleanup
   fclose(outfile); // close the output file
   free(buf); // free the buffer
}
