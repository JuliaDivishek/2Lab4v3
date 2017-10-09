#include <stdio.h>


double findMaxInt(int id, ...) {
	double sum;
	//проход по всему списку параметров, до тех пор пока не встретим признак окончания последовательности
	int *ptr = &id;
	for (sum = 0; (*ptr) != 0;) {
		switch (*ptr++) {
			case 1:
				sum += *ptr++;
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
	printf("%f\n", findMaxInt(1, 3, 1, 1, 1, -1, 0)); //3
	printf("%f\n", findMaxInt(2, 3, 2, 1, 2, -1, 0));
	printf("%f\n", findMaxInt(3, 2.0, 3, 1.4, 3, 15.8, 0));
	printf("%f\n", findMaxInt(1, 2, 3, 1.4, 2, 15, 0));
}

int main() {
	test();
	return 0;
}
