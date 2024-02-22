#include <stdio.h>
#include <string.h>

void usage(char);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    usage('f');
    return (1);
  }
  else if (argc > 2) {
    usage('a'); /* goes straight to default. no support for flags still*/
    return (2);
  }

  // printf("%s\n", argv[1]);
  /* check whether the file ends in .dt */
  {
    if (strchr(argv[1], '.') != NULL) {
      char* file_ext = strchr(argv[1], '.');
      
      if ((file_ext + 1) != ".dt") {
	printf("%s\n", file_ext + 1);
	return (4);
      }
      
    } else { return (3); }
  }
  
  printf("we good\n");
  return (0);
}


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
