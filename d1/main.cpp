#include <iostream>
#include "termCtrl.h"

int somme(int arr[], int n){
	int res = 0;
	for (int i=0; i<n; i++){
		res += arr[i];
	}
	return res;
}

int getLower(int arr[]){
	int l = arr[0] < arr[1] ? 0 : 1;
	return arr[l] < arr[2] ? l : 2;
}

void top(int arr[], int v){
	int i = getLower(arr);
	if (arr[i] < v){ arr[i] = v; }
}

int main(){

	char line[256];
	int cal[256];
	int ical = 0;
	int res[3];
	FILE *file = fopen("input", "r");

	if (file == NULL) {
        printf("file can't be opened\n");
		return 1;
    }

	while (fgets(line, sizeof(line), file)) {
		if (strlen(line) == 1){
			top(res, somme(cal, ical));
			ical=0;
		}else{
			cal[ical] = atoi(line);
			ical++;
		}
    }

	for (int i=0; i<3; i++){
		printf("%d\n", res[i]);
	}
	printf("somme :\n%d\n", somme(res, 3));

	fclose(file);

	return 0;
}
