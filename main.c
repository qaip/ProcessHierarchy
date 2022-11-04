#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int n = 1;

int newChild(int N) {
  pid_t pid = fork();
  switch(pid) {
    case -1:
      printf ("Ошибка: ребёнок не создан\n");
      return 0;
    case 0:
      printf("%d -> %d | Александр %d " GREEN "рождён" RESET " Александром %d\n", getppid(), getpid(), N, n);
      n = N;
      return 1;
    default:
      wait(0);
      return 0;
  };
}


int main () {
  printf("%d -> %d | Александр %d " GREEN "создан" RESET " вселенной\n", getppid(), getpid(), n);

  if (newChild(2)) {
    if (newChild(4)) {} else
    if (newChild(5)) {
      if (newChild(6)) {
        if (newChild(7)) {}
      }
    }
  } else
  if (newChild(3)) {
    execl("/bin/pwd", "", NULL);
  }

  printf("%d -> %d | Александр %d " RED "погиб" RESET " от страсти\n", getppid(), getpid(), n);
  return 0;
}

// 
// 1 2 3 4 5 6 7
// 0 1 1 2 2 5 6
//
