#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "deck.h"
#include "helperFxns.h"

char helpBox[1000] = "********************************* \n"
        			 "* Commands:\n"
        			 "* 'Help' - prints out the current commands and descriptions\n"
        			 "* 'Draw' - draws a card, can only happen once per turn, then \n"
        			 "*          has the option to play a card.\n"
        			 "* 'Pass' - draws a card if player hasn't already, player\n" 
        			 "*          skips his/her turn without playing a card.\n" 
        			 "* 'Uno' - idk if this is a thing yet.\n"
        			 "* 'Sort' - sorts your hand alphabetically \n"
        			 "*********************************";



char ** playable( char **origHand, char *playedCard ){
	//your part:
	//replaces currCard
	//write to playedCards
	printf("playedCard: %s\n", playedCard);
	char **newHand = (char **)malloc(sizeof(char *) * 1000);
	int boolean = 0; 
	int origIndex = 0;
	int newIndex = 0;
	memset(newHand, '\0', sizeof(newHand));
	while (origHand[origIndex] != 0){
			if (strcmp(origHand[origIndex],playedCard) == 0){
				printf("FOUND THE CARD!! \n");
				origIndex++;
				boolean = 1;
			}
		printf("orig index: %d\n", origIndex);
		printf("new index: %d\n", newIndex);
		newHand[newIndex] = origHand[origIndex];
		printf("newHand[newIndex]: %s\n", newHand[newIndex]);
		newIndex++;
		origIndex++;
	}
	printf("last index: %d\n", newIndex);
	newHand[newIndex] = 0;

	printf("printing out hand from fxn:\n");
	int j;
	for (j = 0; j < newIndex; j++){printf("|| %s ",newHand[j]);}  
    printf("||\n\n");
	return newHand;
}

//leave the handling of the array one size bigger in the main conditional 
void drawCard(char * HAND[]) { //input the player's hand who you want the card to be added to
    char * toBeAdded = draw(1,1); 
    int count = 0;
    while (HAND[count]) { 
        count++;           
    }
    HAND[count] = toBeAdded; 
    HAND[count + 1] = NULL;
}


//JUST COMMENTED OUT TESTING CODE FROM HERE ON OUT!!!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* PLAYABLE TESTING PURPOSES ---------------------------------------
int main(){
	char ** hand = (char **)calloc(1,sizeof(char *) * 1000 );

	int x =0;
	for(; x< 10;x++){
		char * s = (char *)calloc(1,sizeof(char) * 1000);
		sprintf(s, "%dd",x);
		hand[x] = s;
	}
	
	hand = playable(hand, "3d");

	int i;
	for (i = 0; i < 10; i++){
		printf("%s ",hand[i]);
	}
	printf("\n");

	return 0;
}
*/

