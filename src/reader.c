#include "datura.h"

/**
 * read_datura_file - reads the entire contents of a datura file
 * @input: Datura file to be read
 * Returns: a pointer to a string array containing the contents of input arg
 *
 * Comment: with this function alone, i am thinking of turning this to a
 * interpreter project as i do not see the need to write a parser
 * to write assembly code for every line in the datura file.
 * let me see how it goes though!
 *
 * Remember to: free the allocated memeory
 */
char* read_datura_file(const char* input) {
  FILE* file = fopen(input, "r");

  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", input);
    exit(5);
  }

  // Determine the file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  // Allocate memory for the string
  char* buffer = (char*)malloc(size + 1);
  if (buffer == NULL) {
    fprintf(stderr, "Memory allocation for the buffer failed\n");
    exit(6);
  }

  // Read file contents into the string buffer
  size_t bytesRead = fread(buffer, 1, size, file);
  if (bytesRead != size) {
    fprintf(stderr, "Error reading file\n");
    exit(7);
  }

  buffer[size] = '\0'; // null terminator to the string buffer

  fclose(file);
  return buffer;
}
