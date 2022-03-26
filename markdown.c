#include "markdown.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <lowdown.h>

void markdownToHtml(char* inputFile, char* outputFile) {
  // read data in from file
  

  FILE *fp;
  long lSize;
  char *buffer;
  fp = fopen (inputFile, "rb"); // open the file

  if( !fp ) perror(inputFile),exit(1);
  fseek( fp , 0L , SEEK_END);
  lSize = ftell( fp );
  rewind( fp );
  // allocate memory for the file
  buffer = calloc( 1, lSize+1 );
  if( !buffer ) fclose(fp),fputs("memory alloc failed",stderr),exit(1);
  // copy the file into the buffer
  if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read failed",stderr),exit(1);
  fclose(fp);
  // structs
  struct lowdown_buf *out;
  struct lowdown_doc *doc;
  struct lowdown_node *n;
  void *rndr;
  if ((doc = lowdown_doc_new(NULL)) == NULL)
      exit(1);
  if ((n = lowdown_doc_parse(doc, NULL, buffer, strlen(buffer), NULL)) == NULL)
      exit(1);
  if ((out = lowdown_buf_new(256)) == NULL)
      exit(1);
  if ((rndr = lowdown_html_new(NULL)) == NULL)
     exit(1);
  if (!lowdown_html_rndr(out, rndr, n))
      exit(1);
  // write converted data to the output file
  FILE *outfile;
  outfile = fopen(outputFile, "w");
  fwrite(out->data, 1, out->size, outfile);
  fclose(outfile);
  // free memory
  lowdown_html_free(rndr);
  lowdown_buf_free(out);
  lowdown_node_free(n);
  lowdown_doc_free(doc);
  free(buffer);

}
