#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }

  struct stat sb;
  if (stat(argv[1], &sb) == -1) {
    perror("stat error");
    return 1;
  }

  printf("=== File Attributes for: %s ===\n", argv[1]);

  const char *type = "Unknown";
  switch (sb.st_mode & S_IFMT) {
    case S_IFREG:  type = "Regular File";     break;
    case S_IFDIR:  type = "Directory";        break;
    case S_IFCHR:  type = "Character Device"; break;
    case S_IFBLK:  type = "Block Device";     break;
    case S_IFIFO:  type = "FIFO/Pipe";        break;
    case S_IFLNK:  type = "Symlink";          break;
    case S_IFSOCK: type = "Socket";           break;
  }

  printf("%-22s%s\n", "File Type:", type);
  printf("%-22s%04o\n", "Permissions:", sb.st_mode & 07777);
  printf("%-22s%lld bytes\n", "File Size:", (long long)sb.st_size);
  printf("%-22s%ld\n", "Hard Links Count:", (long)sb.st_nlink);
  printf("%-22s%u\n", "Owner (UID):", sb.st_uid);
  printf("%-22s%u\n", "Group (GID):", sb.st_gid);

  printf("%-22s%s", "Last Access Time:", ctime(&sb.st_atime));
  printf("%-22s%s", "Last Modification:", ctime(&sb.st_mtime));
  printf("%-22s%s", "Status Change Time:", ctime(&sb.st_ctime));

  return 0;
}
