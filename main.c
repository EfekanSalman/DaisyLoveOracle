#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void clearScreen() {
	
	#ifdef _WIN32
	system("cls");
	#else
	system("Clear");
	#endif
}


int main(int argc, char *argv[]) {
	
	char *maleStatuses[2] = {"He loves me!", "He loves me not :("};
	char *femaleStatuses[2] = {"She loves me!", "She loves me not :( "};
	char *statuses[2];
	char gender;
	int petalCount, i;
	
	printf("1) Male\n");
	printf("2) Female\n");
	printf("Select your partner's gender: ");
	scanf("%d", &gender);
	
	switch(gender) {
		case 1:
			statuses[0] = maleStatuses[0];
			statuses[1] = maleStatuses[1];
			break;
		case 2:
			statuses[0] = femaleStatuses[0];
			statuses[1] = femaleStatuses[1];
			break;
		default:
			printf("Invalid gender input");
			return 1;		
	}

	printf("Enter the number of petals: ");
	scanf("%d", &petalCount);
	
	if(petalCount < 1) {
		
		printf("Invalid number of petals");
		return 1;	
	}
	
	srand(time(NULL));
	int start = rand() % 2;
	
	for(i = 0; i < petalCount; i++) {
		
		clearScreen();
		printf("Petal %d: %s\n", i + 1, statuses[(start + i) % 2]);
		fflush(stdout);
		sleep(1);

	}
	
	clearScreen();
	printf("Result: %s!\n", statuses[(start + petalCount - 1) % 2 ]);
	

	return 0;
}
