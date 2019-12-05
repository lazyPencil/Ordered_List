#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Element;

typedef struct listnode {
	Element data;
	struct listnode* next;
} Listnode;

typedef struct list {
	int cnt;
	Listnode* pos;
	Listnode* head;
} List;

List* CreateList() { // := Create an "Head" list
	List* ptr = (List*)malloc(sizeof(List));
	if (ptr == NULL) return NULL;
	ptr->cnt = 0;
	ptr->head = NULL;
	ptr->pos = NULL;
	return ptr;
}
bool TraverseList(List* list, int fromWhere, Element* output) { // := Provide next data to traverse list. else return false.
	if (list->pos == NULL || fromWhere == 0) {
		list->pos = list->head;
	}
	else {
		list->pos = list->pos->next;
	}
	if (list->pos != NULL) {
		*output = list->pos->data;
		return true;
	}
	else {
		*output = 0; 
		return false;
	}
}
bool IsEmptyList(List * list) { // Empty : true // Not : false
	if (list->head == NULL)
		return true;
	else
		return false;
}
bool IsFullList(List * list) {  // Full  : true // Not : false
	Listnode* testptr = (Listnode*)malloc(sizeof(Listnode));
	if (testptr == NULL)
		return true;
	else {
		free(testptr);
		return false;
	}
}
bool SearchList(List * list, Element find, Listnode** ppPre, Listnode** ppLoc) { // := 데이터 있다 없다만 확인 / current, past into "pPre,pLoc"
	for (*ppPre = NULL, *ppLoc = list->head; *ppLoc!=NULL; *ppPre = *ppLoc, *ppLoc = (*ppLoc)->next) {
		if ((*ppLoc)->data == find)
			return true;
		else if ((*ppLoc)->data > find) // data=50 find=10 이면 멈추고 앞node와 지금node 사이에 넣기. data(5) < find(10) 면 반복문 계속 돌기
			break;
	}
	return false;
}
void Insertion(List * list, Element item, Listnode* pPre) { 
	Listnode* pNew = (Listnode*)malloc(sizeof(Listnode));
	if (pNew == NULL) return;
	if (pPre == NULL) { // case1 : First Node
		pNew->next = list->head;
		list->head = pNew;
	}
	else {				// case2,3 : Middle, Last
		pNew->next = pPre->next;
		pPre->next = pNew;
	}
	pNew->data = item;
	list->cnt++;
}
void Deletion(List* list, Listnode* pPre) {
	Listnode* pDel = NULL;
	if (pPre == NULL) { // case1 : First Node
		pDel = list->head;
		list->head = list->head->next;
	}
	else {					// case2,3 : Middle, Last
		pDel = pPre->next;
		pPre->next = pDel->next;
	}
	list->cnt--;
	free(pDel);
}
void AddNode(List * list, Element item) { // := search + insertion
	Listnode* pPre = NULL, * pLoc = NULL;
	bool Found;

	if (IsFullList(list)) {
		printf("Full List\n");
		return;
	}
	Found = SearchList(list, item, &pPre, &pLoc); // 포인터의 주소->변동된 주소를 사용가능 / like 변수의 주소->변동된 값을 사용가능
	if (!Found)
		Insertion(list, item, pPre);
	else
		printf("Mylist already has %d\n", item);
}
void RemoveNode(List * list, Element item) { 
	Listnode* pPre = NULL, * pLoc = NULL;
	bool Found;

	if (IsEmptyList(list)) {
		printf("Empty List\n");
		return;
	}
	Found = SearchList(list, item, &pPre, &pLoc);
	if (Found)
		Deletion(list, pPre);
	else
		printf("Mylist does have such data(%d)\n", item);
}
void ClearList(List* list) {
	Listnode* pFree = list->head;
	while (list->cnt < 1) {
		pFree = list->head;
		while (pFree->next == NULL)
			pFree = pFree->next;
		free(pFree);
		list->cnt--;
	}
	list->head = NULL;
}
void DestroyList(List * list) {
	ClearList(list);
	free(list);
}
int ListCount(List * list) { 
	return list->cnt;
}