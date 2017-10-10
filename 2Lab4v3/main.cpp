#include <stdio.h>
#include <stdarg.h>

long double sumOfRange(int arg, ...) {
	long double sum;
	va_list valist; //структура, хранящая в себе список аргументов
	va_start(valist, arg); //инициализация списка аргументов
	int i = arg; 
	//проход по всему списку параметров, до тех пор пока не встретим признак окончания последовательности 0
	for (sum = 0; i != 0; i = va_arg(valist, int)) {
		switch (i) {
			case 1:
				sum += va_arg(valist, int); //макрос берет дополнительный аргумент из списка (1-ый параметр), приводя его к необходимому типу (2-й параметр)
				break;
			case 2:
				sum += va_arg(valist, long);
				break;
			case 3:
				sum += va_arg(valist, double);
				break;
			default:
				break;
		}
	}
	va_end(valist); //очистка памяти списка аргументов
	return sum;
}

void test() {
	printf("test1: %Lf == 3\n", sumOfRange(1, 3, 1, 1, 1, -1, 0) ); //3
	printf("test2: %Lf == 315\n", sumOfRange(2, 5, 2, 506, 2, -196, 0, 1, 2)); //315
	printf("test3: %Lf == 22.1\n", sumOfRange(3, 2.0, 3, 1.4, 3, 15.8, 3, 2.9, 0)); //22.1
	printf("test4: %Lf == 156.4\n", sumOfRange(1, 5, 3, 1.4, 2, 150, 0)); //156.4
	printf("test5: %Lf == -10.0\n", sumOfRange(1, 3, 3, -3.0, 3, -1.0, 3, -9.0, 0)); //-10
	printf("test6: %Lf == -10.3\n", sumOfRange(1, 3, 3, -3.2, 3, -1.1, 3, -9.0, 0)); //-10.3
}

int main() {
	test();
	return 0;
}
