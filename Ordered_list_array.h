#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Element;

typedef struct list {
	Element* data;
	int size;
	int cnt;
} List;

List* CreateList(int size) { // := Create an empty List which has its own size.
	List* ptr = (List*)malloc(sizeof(List));

	if (ptr == NULL) return NULL;
	ptr->data = (Element*)malloc(sizeof(Element) * size);
	if (ptr->data == NULL) {
		free(ptr);
		return NULL;
	}

	ptr->size = size;
	ptr->cnt = 0;
	return ptr;
}
bool TraverseList(List* list, int fromWhere, Element* output) { // := Provide next data to traverse list. else return false.
	if (fromWhere == list->cnt) // cnt : 3 �ε� data[3] �� ���� NO
		return false;
	*output = list->data[fromWhere];
	return true;
}
bool IsEmptyList(List* list) { // Empty : true // Not : false
	if (list->cnt == 0)
		return true;
	else
		return false;
}
bool IsFullList(List * list) {  // Full  : true // Not : false
	if (list->cnt == list->size)
		return true;
	else
		return false;
}
int SearchList(List* list, Element find, int* Found) { // := Find a data // return right index
	int n = 0;
	Element output;
	while (1) {
		if (TraverseList(list, n++, &output) == false) { // ���� ����. ��, ã�� ���߰�, ���� �޸� �ȴ�.
			*Found = 0;
			break;
		}
		if (output == find) {
			*Found = 1;
			break;
		}
		else if (output > find) {
			*Found = 0;
			break;
		}
	}
	return n - 1;
}
void Insertion(List * list, int index, Element item) { // := Insert a data in an index place / ���� ���� �Ÿ� memcpy �ʿ�x
	int cpylen = list->cnt - index;
	Element* cpy = (Element*)malloc(sizeof(Element) * cpylen);
	if (index != list->cnt) { // �߰� ����
		memcpy(cpy, list->data + index, cpylen * sizeof(Element));
		memcpy(list->data + index + 1, cpy, cpylen * sizeof(Element));
		free(cpy);
	}
	list->data[index] = item;
	list->cnt++;
}
void Deletion(List* list, int index) {
	int cpylen = list->cnt - index;
	Element* cpy = (Element*)malloc(sizeof(Element) * cpylen);

	printf("list->data[%d]=%d�� ������� �մϴ�.\n", index, list->data[index]);
	if (index != list->cnt) { // �߰� ����
		memcpy(cpy, list->data + index + 1, (cpylen-1)* sizeof(Element));
		memcpy(list->data + index, cpy, (cpylen-1) * sizeof(Element));
		free(cpy);
	}
	list->cnt--;
}

void AddNode(List* list, Element item) { // := Add a new data element // Search + Insert
	int index, Found;
	if (IsFullList(list)==true) {
		printf("Full List\n");
		return;
	}
	index = SearchList(list, item, &Found);
	if (Found!=1) // Not Found
		Insertion(list, index, item);
	else {
		printf("There is a same data\n");
	}
}
void RemoveNode(List* list, Element item) { // := Remove an element // Search + Delete
	int index, Found;
	if (IsEmptyList(list) == true) {
		printf("Empty List\n");
		return;
	}
	index = SearchList(list, item, &Found);
	if (Found != 1) {// Not Found
		printf("There isn't such data\n");
		return;
	}
	else
		Deletion(list, index);
}
void DestroyList(List* list) {  // := Destroy a List
	free(list->data);
	free(list);
}
int ListCount(List* list) { // := return number of elements
	return list->cnt;
} 

