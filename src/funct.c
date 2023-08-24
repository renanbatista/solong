
#define BIG_NUMBER ULONG_MAX / 100000
void *funct() {
	for (size_t i = 0; i < BIG_NUMBER; i++)
		;
	return NULL;
}

