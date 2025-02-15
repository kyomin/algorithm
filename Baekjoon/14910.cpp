#include <stdio.h>

int main(void) {
	int current, next;
	scanf("%d", &current);
	while (scanf("%d", &next) != EOF) {
		if (current > next) {
			printf("Bad\n");
			return 0;
		}
		else current = next;
	}

	printf("Good\n");
	return 0;
}