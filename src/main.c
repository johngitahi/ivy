/*
 * Ivy Compiler
 * Copright (c) 2024 John Gitahi
 * This code is licensed under the WFPL - https://wfpl.net/
 */

#include "../include/ivy.h"

int main(int argc, char* argv[]) {
  sanity_checks(argc, argv); // checks file sanity

  char* filename = null_checker(strdup(argv[1])); // use argv[1] for absolute file
  char* last_dot = strrchr(filename, '.');
  if (last_dot != NULL) *last_dot = '\0';

  char* file_contents = read_file(argv[1]);

  // assmebly template
  static char* asm_template =
    "section .text\n"
    "\tglobal _start\t; program entry point\n\n"
    "_start:\n"
    "\tmov rax, 60\n"
    "\tmov rdi, %d\n"
    "\tsyscall\n";

  char* asm_code = null_checker(malloc(strlen(asm_template) + 10));

  // replace the format specifier with contents of the ivy file
  char* value = strrchr(file_contents, ' ');
  long yield_value = strtol(value + 1, NULL, 10);
  sprintf(asm_code, asm_template, yield_value);

  // generate the assembly filename
  char* ivy_file_asm =  null_checker(malloc((strlen(filename)) + 5));
  strcpy(ivy_file_asm, filename);
  strcat(ivy_file_asm, ".asm");

  // generate linked file name
  char* ivy_linked_file = null_checker(malloc(strlen(filename) + 3));
  strcpy(ivy_linked_file, filename);  
  strcat(ivy_linked_file, ".o");

  // open file to write to it the asm generated
  write_file(asm_code, ivy_file_asm);

  // generate executable(assembly and linking)
  char* cnasm = "nasm -felf64 %s";
  char* nasm = null_checker(malloc(strlen(ivy_file_asm) + strlen(cnasm)));
  sprintf(nasm, cnasm, ivy_file_asm);
  system(nasm);

  char* clink = "ld -o %s %s";
  char* link = null_checker(malloc(strlen(ivy_linked_file) + strlen(clink) + strlen(filename)));
  sprintf(link, clink, filename, ivy_linked_file);
  system(link);
  char* rmoasm_files = "rm %s %s";
  char* rm = null_checker(malloc(strlen(ivy_linked_file) + strlen(ivy_file_asm) + strlen(rmoasm_files)));
  sprintf(rm, rmoasm_files, ivy_linked_file, ivy_file_asm);
  system(rm);
  
  // get the value of yield in the ivy source file
  free(asm_code);
  free(ivy_file_asm);
  free(ivy_linked_file);
  free(file_contents);
  free(nasm);
  free(link);
  free(rm);
  return (0);
}
