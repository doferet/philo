/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doferet <doferet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:23:16 by doferet           #+#    #+#             */
/*   Updated: 2024/08/30 15:34:46 by doferet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

fonction void *je_mange;
fonction void *je_pense;
fonction void *je_dors;
a donner a la routine des threads 

/*void *print_message_function(void *ptr)
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
     return(NULL);
}

int main()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2;

    // Create independent threads each of which will execute function

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

     // Wait till threads are complete before main continues. Unless we
     // wait we run the risk of executing an exit which will terminate   
     // the process and all threads before the threads have completed.

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
}*/
nubers_of_philosophers = nb de thread est-ce qu'il faut faire une fonction de creation de threads et tant qu'il n'y a pas le bon nom de thread on continue ?'

int main(int ac, char **av)
{
     1 thread par philo 
     1 fourchette par philo
     if(numbers_of_philosophers > 200)
          return(0);
}

