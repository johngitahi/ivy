#ifndef IVY_H
#define IVY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage(char);
int sanity_checks(int argc, char** argv);
char* read_file(const char* filename);
void write_file(const char* content, const char* filename);

static inline void* null_checker(void* o) {
  if (o == NULL) {
    perror("oom\n");
    exit(1);
  }
}

#endif /* IVY_H */
