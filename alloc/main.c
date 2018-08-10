#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	struct plastic{
		double eps_old[6];
		double alpha_old;
	};

	struct plastic *ptr_plastic;

	int n = 3;

	void **ptr = malloc(n * sizeof(void));

	// alloc
	printf("sizeof(void) = %d\n", sizeof(void));
	printf("sizeof(struct plastic) = %d\n", sizeof(struct plastic));
	int i, j;
	for (i = 0; i < n; ++i) {
		ptr[i] = malloc(sizeof(struct plastic));
	}

	// initialization
	ptr_plastic = ptr[0];
	ptr_plastic->alpha_old = 0.0;
	for (i = 0; i < 6; ++i)
		ptr_plastic->eps_old[i] = 0.0;

	ptr_plastic = ptr[1];
	for (i = 0; i < 6; ++i)
		ptr_plastic->eps_old[i] = 1.0;
	ptr_plastic->alpha_old = 1.0;

	ptr_plastic = ptr[2];
	for (i = 0; i < 6; ++i)
		ptr_plastic->eps_old[i] = 2.0;
	ptr_plastic->alpha_old = 2.0;

	// show result
	for (i = 0; i < n; ++i) {
		ptr_plastic = ptr[i];
		printf("ptr[%d]  alpha_old = %lf  eps_old = ", i, ptr_plastic->alpha_old); 
		for (j = 0; j < 6; ++j)
			printf("%lf%s", ptr_plastic->eps_old[j], (j == 5) ? "\n" : " ");
	}

	return 0;
}
