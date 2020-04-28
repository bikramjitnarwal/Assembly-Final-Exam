// ADDRESS FOR LED
volatile int * LED = (int *)0xFF200000;
// ADDRESS FOR KEY
volatile int * KEY = (int *)0xFF200050;

unsigned int value = 1;
int dir = 1;

void show() {
    *LED = value;
}

void moveLeft() {
  value = value * 2;
  if (value == 1024)
    value = 1;
}

void moveRight() {
  if (value == 1)
    value = 1024;
  value = value / 2;
}

int main() {
	LED = 3;
	int PrevKey;
    while(1) {
		show();
    int doChange = 0;
	for (int i = 0; i < 3001000; i++) {
		if (~PrevKey && KEY)
        doChange = 1;
      	PrevKey = *KEY;
    }
		
    if (doChange)
     	dir = -1 * dir;
		
    if (dir == 1)
      moveRight();
    else
      moveLeft();
    }
}
