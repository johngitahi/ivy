/*
  This program written by John Gitahi. February 2024
 */

#include "datura.h"

int main(int argc, char* argv[]) {
  sanity_checks(argc, argv); // checks file supplied for file extensions, etc

  char* file_contents = read_datura_file(argv[1]);
  printf("%s", file_contents);
  free(file_contents);
  return (0);
}

/**
 * usage - return usage message to the stdout
 * @level: char used to determine the message to print out
 * Returns: nada
 */
void usage(char level) {
  switch (level) {
      case 's':
	printf("Usage:\n");
	printf("\t datura <input.dt>");
	break;

      case 'f':
	printf("No input files specified\n");
	printf("Compilation terminated\n");
	printf("Usage: datura <input.dt>\n");
	break;

      case 'i':
	printf("Invalid filename\n");
	printf("datura only works with files ending in .dt\n");
	break;
    
      default:
	printf("Invalid use. Compilation terminated.\n");
    }
}

/**
 * sanity_checks - checks file extensions and compatibility
 * @argc - argument count from the main function
 * @argv - pointer to the array containing the arguments supplied
 * Returns: an integer value representing the error/success  given
 */
int sanity_checks(int argc, char** argv) {
  if (argc < 2) {
    usage('f');
    exit(1);
  }
  else if (argc > 2) {
    usage('a'); /* goes straight to default. no support for flags still*/
    exit(2);
  }

  // printf("%s\n", argv[1]);
  /* check whether the file ends in .dt */
  if (strchr(argv[1], '.') != NULL) {
    char* file_ext = strchr(argv[1], '.');
      
    if (strcmp(file_ext, ".dt") != 0) {
      usage('i');
      exit(4);
    }
  }
}
