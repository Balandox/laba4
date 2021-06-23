#include <stdio.h>
int skipp_word(char* arr, int* i) {
	int k = *i;
	while ((arr[k] >= 'A' && arr[k] <= 'Z') || (arr[k] >= 'a' && arr[k] <= 'z'))
		k++;
	return k;
}
int strchr(char* arr, int* i, int* j, int* f) { // проверяет наличие пары у символа
	int count = 0;
	for (int k = *f; k < *f + *j; k++) {
		if (arr[*i] == arr[k])
			count++;
	}
	return count;
}
void print_word(char* arr, int* j, int* f) { // печатает слова, в которых каждая буква повторяется не менее двух раз
	for (int k = *f; k < *f + *j; k++) {
		printf("%c", arr[k]);
	}
}
int word_len(char* arr, int* i) { // считает длину каждого слова, чтобы потом составить с помощью него норм цикл
	int k = *i;
	int j = 0;
	while ((arr[k] >= 'A' && arr[k] <= 'Z') || (arr[k] >= 'a' && arr[k] <= 'z')) {
		j++;
		k++;
	}
	return j;
}
