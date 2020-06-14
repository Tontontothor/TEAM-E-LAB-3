#include "mbed.h"

DigitalOut myled_green(D6);
DigitalOut myled_red(D7);
DigitalOut myled_blue(D8);

InterruptIn button(USER_BUTTON);

void toggle_led(DigitalOut *main, DigitalOut *other, DigitalOut *second_other)
{
		*main = 1;
		*other = 0;
		*second_other = 0;
}

void test()
{
	static int i = 0;
	
	if (i == 0) {
		toggle_led(&myled_red, &myled_blue, &myled_green);
	}
	else if (i == 1) {
		toggle_led(&myled_blue, &myled_red, &myled_green);
	}
	else if (i == 2) {
		toggle_led(&myled_green, &myled_red, &myled_blue);
	}
	else if (i == 3) {
		myled_red = 1;
		myled_blue = 1;
		myled_green = 1;
	}
	else {
		i = 0;
		return test();
	}
	i++;
}

int main() {
		button.rise(&test);
		while(1) {}
}
