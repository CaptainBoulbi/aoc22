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

int part2(char line[256]){
	int ptsH = 0;
	int ptsW = 0;

	if (line[2] == 'Y'){ return vHand(line[0]) + 3; }

	switch (line[2]){
		case 'X':
			switch (line[0]){
				case 'A':
					ptsH = 3;
					break;
				case 'B':
					ptsH = 1;
					break;
				case 'C':
					ptsH = 2;
					break;
			}
			ptsW = 0;
			break;

		case 'Z':
			switch (line[0]){
				case 'A':
					ptsH = 2;
					break;
				case 'B':
					ptsH = 3;
					break;
				case 'C':
					ptsH = 1;
					break;
			}
			ptsW = 6;
			break;
	}

	return ptsH + ptsW;
}

int main(){
	char line[256];
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
