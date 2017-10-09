#include <stdio.h>

double findMaxInt(int id, ...) {
	double sum;
	int *ptr = &id;
	//проход по всему списку параметров, до тех пор пока не встретим признак окончания последовательности 0
	for (sum = 0; (*ptr) != 0;) {
		switch (*ptr++) {
			case 1:
				sum += *ptr;
				ptr++;
				break;
			case 2:
				sum += *((long*)ptr);
				ptr++;
				break;
			case 3:
				sum += *((double*)ptr);
				ptr++;
				break;
			default:
				break;
		}
	}
	return sum;
}

void test() {
	printf("test1: %f == 3\n", findMaxInt(1, 3, 1, 1, 1, -1, 0) ); //3
	printf("test2: %f == 315\n", findMaxInt(2, 5, 2, 506, 2, -196, 0, 1, 2)); //315
	printf("test3: %f == 22.1\n", findMaxInt(3, 2.0, 3, 1.4, 3, 15.8, 3, 2.9, 0)); //22.1
	printf("test4: %f == 156.4\n", findMaxInt(1, 5, 3, 1.4, 2, 150, 0)); //156.4
}

int main() {
	test();
	return 0;
}
