  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "parser.tab.h"
  #define GET_FILE_NAME_LENGTH(filename) strlen(filename) + 5
int main (int argc, char **argv)
{
  extern FILE *yyin; /* defined by flex */
  char *sourceFileName;
  char *fileType;
  char targetFileName[GET_FILE_NAME_LENGTH(argv[1])];
  
  if (argc != 2) {
     fprintf (stderr, "Usage: %s <input-file-name>\n", argv[0]);
	 return 1;
  }
  yyin = fopen (argv [1], "r");
  if (yyin == NULL) {
       fprintf (stderr, "failed to open %s\n", argv[1]);
	   return 2;
  }

  sourceFileName = strtok(argv[1],".");
  fileType = strtok(NULL,"");
  if(strcmp(fileType,"ou")){
    fprintf(stderr,"failed to open %s.%s, file name have to end with ou\n", argv[1],fileType);
    return 3;
  } 

  yyparse ();

/*print the list*/
  strcpy(targetFileName,sourceFileName);
  strcpy(targetFileName+strlen(sourceFileName),".qud");
  wirteCPLtoFile(targetFileName);
  fclose (yyin);
  return 0;
}
