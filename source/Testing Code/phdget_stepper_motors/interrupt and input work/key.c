#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
	
    struct termios old,new;
	int key;
	int i;
    tcgetattr(fileno(stdin),&old);
    tcgetattr(fileno(stdin),&new);
    cfmakeraw(&new);
    tcsetattr(fileno(stdin),TCSANOW,&new);
    //fputs("Press any key to continue.",stdout);
    printf("start\n");
	//fflush(NULL);
    while (1){
	i++;
	key=fgetc(stdin);
	//printf("\n\n<%i>\n",key);
	//if (key==27) printf("ESCAPE\n");
	if (key==13) {
		tcsetattr(fileno(stdin),TCSANOW,&old);
		return;}
	else if(key!=0){
		//printf(" %i",i);
		printf("<%i> ",key);
				}
	}
    tcsetattr(fileno(stdin),TCSANOW,&old);
	printf("\n");
	
    return 0;
}