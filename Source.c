#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* readLine()
{
	char* line = NULL;
	int n = 0;
	char c;
	do
	{
		c = getchar();
		line = (char*)realloc(line, (n + 1) * sizeof(char));
		if (line == NULL) {
			printf("Allocation error!");
				exit(1);
		}
		line[n] = c;
		n++;
	} while (c != '\n');
	line[n - 1] = '\0';
	return line;
}
int skipp_word(char* arr, int* i) {
	int k = *i;
	while ((arr[k] >= 'A' && arr[k] <= 'Z') || (arr[k] >= 'a' && arr[k] <= 'z'))
		k++;
	return k;
}
int strchr(char* arr, int* i, int* j, int* f) {
	int count = 0;
	for (int k = *f; k < *f + *j; k++) {
		if (arr[*i] == arr[k])
			count++;
	}
	return count;
}
int letter_chk(char* arr, int* i) {
		if ((arr[*i] >= 'A' && arr[*i] <= 'Z') || (arr[*i] >= 'a' && arr[*i] <= 'z'))
			return 1;
		else
			return 0;
	}

void print_word(char* arr, int* j, int* f) {
	for (int k = *f; k < *f + *j; k++) {
		printf("%c", arr[k]);
	}
	printf(" ");
}
int word_len(char* arr, int* i) {
	int k = *i;
	int j = 0;
	while ((arr[k] >= 'A' && arr[k] <= 'Z') || (arr[k] >= 'a' && arr[k] <= 'z')) {
		j++;
		k++;
	}
	return j;
}
int main() {
	int count = 0, k = 0;
	printf("Input string: ");
	char* p= readLine();
	int i = 0;
	int j = 0;
	int start_w = 0;
	while (p[i - 1] != '\0') {
		if (letter_chk(p, &i) == 1) {
			j = word_len(p, &i);
			start_w = i;
		}
		while (letter_chk(p, &i) == 1) {
			if (strchr(p, &i, &j, &start_w) >= 2) {
				count++;
			}
			else {
				i = skipp_word(p, &i);
				break;
			}
			i++;
		}
		if (count == j) {
			print_word(p, &j, &start_w);
		}
		j = 0;
		count = 0;
		i++;
	}
	free(p);
	return 0;
}