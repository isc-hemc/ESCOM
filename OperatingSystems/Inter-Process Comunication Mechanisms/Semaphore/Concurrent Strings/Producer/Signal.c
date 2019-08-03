#include "Library.h"

void Signal ( struct sembuf *argument, int semaphoreNumber ) {

  argument->sem_num = semaphoreNumber;
  argument->sem_op = 1;
  argument->sem_flg = SEM_UNDO;

  semop ( semaphoreID, argument, 1 );

} /* End of Signal function. */
