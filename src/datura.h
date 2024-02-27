#ifndef DATURA_H
#define DATURA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage(char);

int sanity_checks(int argc, char** argv);

char* read_datura_file(const char* input);


#endif /* DATURA_H */
