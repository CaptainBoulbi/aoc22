#include <iostream>

int vHand(char l){
	switch (l){
		case 'A':
		case 'X':
			return 1;
		case 'B':
		case 'Y':
			return 2;
		case 'C':
		case 'Z':
			return 3;
	}
	return 0;
}

int ptsWin(char l[256]){
	int p1 = vHand(l[0]);
	int p2 = vHand(l[2]);

	if (p1 == p2){
		return 3;
	}

	switch (p1*10+p2){
		case 12:
		case 23:
		case 31:
			return 6;
		case 13:
		case 21:
		case 32:
			return 0;
	}
	return 0;
}

int part2(line){
	if (line[2] == 'Y'){ return line[0]; }

	switch (line[2]){
		case 'X':
			switch (line[0]){
				case 'A':
					return 3;
				case 'B':
					return 1;
				case 'C':
					return 2;
			}
		case 'Y':
			switch (line[0]){
				case 'A':
					return 2;
				case 'B':
					return 3;
				case 'C':
					return 1;
			}
	}
}

int main(){
	char line[3];
	FILE *file = fopen("input", "r");
	int res = 0;

	if (file == NULL) {
        printf("file can't be opened\n");
		return 1;
    }

	while (fgets(line, sizeof(line), file)) {
		//res += vHand(line[2]) + ptsWin(line);
		res += part2(line);
	}

	printf("%d\n", res);

	return 0;
}
