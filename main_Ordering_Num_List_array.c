#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Ordered_list_array.h"

int main(void) {
	int menu, num, i, Found;
	List* pList = CreateList(10);
	Element output;
	while (1) {
		printf("In (0), Search (1), Out (2), Exit (3) :");
		scanf("%d", &menu);

		if (menu == 3) {
			printf("Bye\n");
			break;
		}
		switch (menu) {
		case 0:
			printf("In : ");
			scanf("%d", &num);
			AddNode(pList, num);
			break;
		case 1:
			printf("Search : ");
			scanf("%d", &num);
			SearchList(pList, num, &Found);
			if (Found)
				printf("My List has %d.\n", num);
			else
				printf("My List does not have %d.\n", num);
			break;
		case 2:
			printf("Out : ");
			scanf("%d", &num);
			RemoveNode(pList, num);
			break;
		}
		printf("The current status of List : ");
		for (i = 0; i < pList->cnt; i++) {
			TraverseList(pList, i, &output);
			if (i == pList->cnt - 1) {
				printf("%d", output);
				continue; // ¹Ø¿¡ printf¸¦ °Ç³Ê¶ÙÀÚ?!¸Â´Ù.
			}
			printf("%d, ", output);
		}
		printf("\n\n\n");
	}
	DestroyList(pList);
	return 0;
}