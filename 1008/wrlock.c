#include <stdio.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
   int fd, id;
   struct student record;
   struct flock lock;

   if (argc < 2) {
      fprintf(stderr, "���� : %s ���� \n", argv[0]);
      exit(1);
   }


  if ((fd = open(argv[1], O_RDWR)) == -1) {
     perror(argv[1]);
     exit(2);
  }

  printf("\n������ �л��� �й� �Է�:");
  while (scanf("%d", &id) == 1) {
     lock.l_type = F_WRLCK;
     lock.l_whence = SEEK_SET;
     lock.l_start = (id-START_ID)*sizeof(record);
     lock.l_len = sizeof(record);
     if (fcntl(fd,F_SETLKW, &lock) == -1) { /* ���� ��� */
        perror(argv[1]);
        exit(3);
     }

     lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
     if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
        printf("�̸�:%s\t �й�:%d\t ����:%d\n",
                  record.name, record.id, record.score);

     else printf("���ڵ� %d ����\n", id);
     printf("���ο� ����: ");
     scanf("%d", &record.score);
     lseek(fd, (long) -sizeof(record), SEEK_CUR);
     write(fd, (char *) &record, sizeof(record));
     lock.l_type = F_UNLCK;
     fcntl(fd, F_SETLK, &lock);    /* ��� ���� */
     printf("\n������ �л��� �й� �Է�:");
  }
  close(fd);
  exit(0);
}


