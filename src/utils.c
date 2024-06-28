#include "../include/ivy.h"


/**
 * read_file - reads the entire contents of a file
 * @filename: filename
 * Returns: a pointer to a string array containing the contents of input arg
 * Remember to: free the allocated memory
 */
char* read_file(const char* filename) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    fprintf(stderr, "Error: Can't find  %s\n", filename);
    exit(0);
  }

  // Determine the file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  // Allocate memory for the string
  char* buffer = null_checker((char*)malloc(size + 1));

  // Read file contents into the string buffer
  size_t bytesRead = fread(buffer, 1, size, file);
  if (bytesRead != size) {
    fprintf(stderr, "Error reading file\n");
    free(buffer);
    fclose(file);
    exit(7);
  }

  buffer[size] = '\0'; // null terminator to the string buffer

  fclose(file);
  return buffer;
}


void write_file(const char* content, const char* filename) {
  FILE* file = fopen(filename, "w");

  if (file == NULL) {
    fprintf(stderr, "Error opening asm file!\n");
    exit(9);
  }

  // write the content to the file
  fprintf(file, "%s", content);
  fclose(file);
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
	printf("\t datura <program.ivy>");
	break;

      case 'f':
	printf("No input files specified\n");
	printf("Usage: datura <program.ivy>\n");
	break;

      case 'i':
	printf("Invalid filename\n");
	printf("datura only works with files ending in .ivy\n");
	break;
    
      default:
	printf("Invalid use. Compilation terminated.\n");
    }
}

/**
 * sanity_checks - checks file compatibility with the ivy compiler
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
  /* check whether the file ends in .ivy */
  if (strchr(argv[1], '.') != NULL) {
    char* file_ext = strchr(argv[1], '.');
      
    if (strcmp(file_ext, ".ivy") != 0) {
      usage('i');
      exit(4);
    }
  }

}
