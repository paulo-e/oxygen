// touch made by @paulo-e, @pauloe
// paulo-e.gitlab.io

// TODO add --version
// TODO add --help
// TODO add (change only access time)
// TODO add (parse STRING and use it instead of current time)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool hasEnoughArgs(int);

bool hasEnoughArgs(int argc) {
  if (argc == 1) {
    return false;
  } else {
    return true;
  }
}

int main(int argc, char *argv[]) {
  bool enoughArgs = hasEnoughArgs(argc);
  FILE *filePointer;

  if (enoughArgs) {
    // if the command has enough arguments, loop through all of them
    for (int i = 1; i < argc; i++) {
      filePointer = fopen(argv[i], "w");
      if (filePointer == NULL) {
        printf("Unable to create file.\n");
        return 1;
      }
      fclose(filePointer);
    }
    return 0;
  } else {
    printf("Usage: %s file1 [file2 file3 ...]\n", argv[0]);
    printf("Use %s --help for more information\n", argv[0]);
    return 1;
  }
}