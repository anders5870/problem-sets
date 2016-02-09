/**
 * Game of luck: Implementation of the Gamemaster
 *
 * Course: Operating Systems and Multicore Programming - OSM lab
 * assignment 1: game of luck.
 *
 * Author: Nikos Nikoleris <nikos.nikoleris@it.uu.se>
 *
 * History
 *
 * 2016-01-31 (Mahdad Davari)
 *
 * Added more annotations and fine-grained TODO lists 
 *
 */

#include <stdio.h> /* I/O functions: printf() ... */
#include <stdlib.h> /* rand(), srand() */
#include <unistd.h> /* read(), write() calls */
#include <assert.h> /* assert() */
#include <time.h>   /* time() */
#include <signal.h> /* kill(), raise() and SIG???? */

#include <sys/types.h> /* pid */
#include <sys/wait.h> /* waitpid() */

#include "common.h"

int main(int argc, char *argv[])
{
	int i, seed;

	// TODO 1: Un-comment the following variables to use them in the 
	//         exec system call. Using the function sprintf and the arg1 
	//         variable you can pass the id parameter to the children 

	char arg0[] = "shooter";
	char arg1[10];
	char *args[] = {arg0, arg1, NULL};
	

	// TODO 2: Declare pipe variables
	//         - Of which data type should they be?
	//         - How many pipes are needed?
	//         - Try to choose self-explanatory variable names, e.g. seedPipe, scorePipe

        int seedPipes[NUM_PLAYERS][2];
        int scorePipes[NUM_PLAYERS][2];



	// TODO 3: initialize the communication with the players, i.e. create the pipes

	for (i = 0; i < NUM_PLAYERS; i++) {
          if (pipe(seedPipes[i]) == -1) {
               perror("seedpipe");
               exit(EXIT_FAILURE);
           }
          if (pipe(scorePipes[i]) == -1) {
               perror("scorepipe");
               exit(EXIT_FAILURE);
           }
   	}



	// TODO 4: spawn/fork the processes that simulate the players
	//         - check if players were successfully spawned
	//         - is it needed to store the pid of the players? Which data structure to use for this?
	//         - re-direct standard-inputs/-outputs of the players
	//         - use execv to start the players
	//         - pass arguments using args and sprintf
        
        
        pid_t pid[NUM_PLAYERS];int j; int k=0; ;
        
        for (i = 0; i < NUM_PLAYERS; i++){
          pid[i] = fork();
          if (pid[i] == -1){
            perror("fork");
            exit(EXIT_FAILURE);
          }
          if (pid[i] == 0){
            pid[i] = getpid();

            close(seedPipes[i][1]);
            close(scorePipes[i][0]);
            for(j = 0; j<NUM_PLAYERS;j++){
              if(j!=i){
                close(seedPipes[j][0]);
                close(seedPipes[j][1]);
                close(scorePipes[j][0]);
                close(scorePipes[j][1]);
              }
            }

            if (dup2(seedPipes[i][0], STDIN_FILENO) == -1) {
              perror("seedpipe");
              exit(EXIT_FAILURE);
            }
            if (dup2(scorePipes[i][1], STDOUT_FILENO) == -1) {
              perror("scorepipe");
              exit(EXIT_FAILURE);
            }
            sprintf(arg1, "%d", i);
            execvp(args[0], args);
          }
          
        }
        for (k = 0; k<NUM_PLAYERS;k++){
          close(seedPipes[k][0]);
          close(scorePipes[k][1]);
        }

	seed = time(NULL);
        
	for (i = 0; i < NUM_PLAYERS; i++) {
		seed++;
		// TODO 5: send the seed to the players (write using pipes)

                while(write(seedPipes[i][1],&seed, sizeof(int)) < (short)sizeof(int)){}
	}


	// TODO 6: read the dice results from the players via pipes, find the winner

        int score = 0; int highestScore = 0;int winid= 0;
	for (i = 0; i < NUM_PLAYERS; i++) {

           while(read(scorePipes[i][0], &score, sizeof(int)) < (short)sizeof(int)){}
           if (score > highestScore) {
             winid = i;
             highestScore = score;
           }
	}


	printf("master: player %d WINS\n", winid);


	// TODO 7: signal the winner
	//         - which command do you use to send signals?
	//         - you will need the pid of the winner

	kill(pid[winid], SIGUSR1);

	// TODO 8: signal all players the end of game
	//         - you will need the pid of all the players

	for (i = 0; i < NUM_PLAYERS; i++) {
          kill(pid[i], SIGUSR2);
	}


	printf("master: the game ends\n");


	// TODO 9: cleanup resources and exit with success
	//         wait for all the players/children to exit
	//         before game master exits 
        pid_t ret[NUM_PLAYERS];
       
	for (i = 0; i < NUM_PLAYERS; i++) {
          ret[i] = wait(NULL);

	}

        /* for (i = 0; i< NUM_PLAYERS; i++){ */
        /*   printf("ID%d=%d\n", i, ret[i]); */
        /* } */
        for (i = 0; i<NUM_PLAYERS;i++){
          printf("player %d with id %d\n",i, pid[i]);
        }
        exit(EXIT_SUCCESS);


	return 0;
}
