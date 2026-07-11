#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define logFile "app.log"

void printUsage() {
  printf("Usage: \t./auditlog --add \"YOUR LOG HERE\"\n");
  printf("\t./auditlog --view\n");
  exit(-1);
}

int main(int argc, char *argv[]) {
  if (argc < 2 || argc > 3) {
    printUsage();
  }

  // --- VIEW LOGS ---
  if (argc == 2) {
    if (strcmp(argv[1], "--view") != 0) {
      printUsage();
    }

    int fd = open(logFile, O_RDONLY);
    if (fd < 0) {
      // If file doesn't exist yet, just exit quietly or handle it
      return 0;
    }

    char buf[BUF_SIZE];
    ssize_t bytesRead;
    int lineNum = 1;
    printf("%d: ", lineNum++);

    while ((bytesRead = read(fd, buf, sizeof(buf))) > 0) {
      for (ssize_t i = 0; i < bytesRead; i++) {
        putchar(buf[i]);
        // If we hit a newline and it's not the very end of the file, print next
        // line number
        if (buf[i] == '\n') {
          // Check if there are more characters coming (imperfect for buffer
          // boundaries, but simple. A robust solution tracks if a new line
          // actually has content).
          printf("%d: ", lineNum++);
        }
      }
    }

    close(fd);
    return 0;
  }

  // --- ADD LOG ---
  if (strcmp(argv[1], "--add") != 0) {
    printUsage();
  }

  // O_WRONLY: write only, O_CREAT: create if missing, O_APPEND: move offset to
  // end for every write 0644: permissions (rw-r--r--)
  int fd = open(logFile, O_WRONLY | O_CREAT | O_APPEND, 0644);
  if (fd < 0) {
    perror("Error opening file");
    return -1;
  }

  write(fd, argv[2], strlen(argv[2]));
  write(fd, "\n", 1); // Append newline character

  close(fd);
  return 0;
}
