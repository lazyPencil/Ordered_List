#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Ordered_list_linked.h"

int main(void) {
	int menu, num, i=0;
	List* pList = CreateList();
	Element output;
	Listnode* pPre, * pLoc = NULL;
	bool Found;

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
			if(Found = SearchList(pList, num, &pPre, &pLoc))
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
		while (TraverseList(pList, i++, &output))
			printf("%d, ", output);
		printf("\b\b  ");
		printf("\n\n\n");
	}
	DestroyList(pList);
	return 0;
}