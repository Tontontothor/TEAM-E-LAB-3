#include "mbed.h"

DigitalOut myled_green(D6);

InterruptIn button(USER_BUTTON);

void test()
{
	static int i = 0;
	
	if (i == 9) {
		myled_green = 1;
	}
	i++;
}

int main() {
		button.rise(&test);
		while(1) {}
}
