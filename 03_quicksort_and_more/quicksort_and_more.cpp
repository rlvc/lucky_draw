#include <iostream>
#include<vector>
#include <cmath>

#define ERROR_UNDEFINED			  0x80000000
#define ERROR_INVALID_PARAM		  0x80000001

typedef unsigned short ElemType;
/***********************************/
//01 Linked Node related definition
/***********************************/

struct LinkedNode {
	LinkedNode() :_val(0), _next(NULL) {}
	ElemType _val;
	LinkedNode* _next;
};

void printLinkedList(LinkedNode *node, const char* message)
{
	if (NULL != message) {
		std::cout << message << ": ";
	}
	while (node != NULL)
	{
		std::cout << node->_val<< " ";
		node = node->_next;
	}
	std::cout << std::endl;
}

LinkedNode *createLinkedList(ElemType arr[], size_t length)
{
	LinkedNode* head = NULL;
	LinkedNode* pindex = NULL;
	for (size_t i = 0; i < length; i++)
	{
		LinkedNode* pcurrent = new LinkedNode;
		if (NULL != pindex)
			pindex->_next = pcurrent;
		if (NULL == head)
			head = pcurrent;
		pcurrent->_val = arr[i];
		pcurrent->_next = NULL;
		pindex = pcurrent;
	}
	return head;
}
void destroyLinkedList(LinkedNode* list)
{
	LinkedNode* phead = list;
	LinkedNode* pindex = list;
	while (NULL != phead) {
		pindex = phead->_next;
		delete phead;
		phead = pindex;
	}
	list = NULL;
}
LinkedNode *getTail(LinkedNode *cur)
{
	while (cur != NULL && cur->_next != NULL)
		cur = cur->_next;
	return cur;
}
/***********************************/
//02 linked list quick sort 
/***********************************/
class LinkedListQuickSort {
public:
	LinkedNode *partition(LinkedNode *head, LinkedNode *end,
		LinkedNode **newHead, LinkedNode **newEnd)
	{
		LinkedNode *pivot = end;
		LinkedNode *prev = NULL, *cur = head, *tail = pivot;

		while (cur != pivot)
		{
			if (cur->_val < pivot->_val)
			{
				if ((*newHead) == NULL)
					(*newHead) = cur;

				prev = cur;
				cur = cur->_next;
			}
			else
			{
				if (prev)
					prev->_next = cur->_next;
				LinkedNode *tmp = cur->_next;
				cur->_next = NULL;
				tail->_next = cur;
				tail = cur;
				cur = tmp;
			}
		}

		if ((*newHead) == NULL)
			(*newHead) = pivot;

		(*newEnd) = tail;

		return pivot;
	}

	LinkedNode *quickSort(LinkedNode *head, LinkedNode *end)
	{
		if (!head || head == end)
			return head;

		LinkedNode *newHead = NULL, *newEnd = NULL;

		LinkedNode *pivot = partition(head, end, &newHead, &newEnd);

		if (newHead != pivot)
		{
			LinkedNode *tmp = newHead;
			while (tmp->_next != pivot)
				tmp = tmp->_next;
			tmp->_next = NULL;

			newHead = quickSort(newHead, tmp);

			tmp = getTail(newHead);
			tmp->_next = pivot;
		}

		pivot->_next = quickSort(pivot->_next, newEnd);

		return newHead;
	}

	void sortLinkedList(LinkedNode **headRef)
	{
		(*headRef) = quickSort(*headRef, getTail(*headRef));
		return;
	}
};
/***********************************/
//03 linked list quick sort with zeros
/***********************************/
class LinkedListQuickSortDuplicatedZero {
public:
	LinkedNode *partition(LinkedNode *head, LinkedNode *end,
		LinkedNode **newHead, LinkedNode **newEnd, LinkedNode **pure_zero_list)
	{
		LinkedNode *pivot = end;
		LinkedNode *prev = NULL, *cur = head, *tail = pivot;

		while (cur != pivot)
		{
			if (cur->_val == 0) {
				if (prev)
					prev->_next = cur->_next;

				LinkedNode *after_zero = cur->_next;
				cur->_next = NULL;
				if ((*pure_zero_list) == NULL)
					(*pure_zero_list) = cur;
				else
					getTail(*pure_zero_list)->_next = cur;

				cur = after_zero;

			}
			else if (cur->_val < pivot->_val)
			{
				if ((*newHead) == NULL)
					(*newHead) = cur;

				prev = cur;
				cur = cur->_next;
			}
			else
			{
				if (prev)
					prev->_next = cur->_next;
				LinkedNode *tmp = cur->_next;
				cur->_next = NULL;
				tail->_next = cur;
				tail = cur;
				cur = tmp;
			}
		}

		if ((*newHead) == NULL)
			(*newHead) = pivot;

		(*newEnd) = tail;

		return pivot;
	}

	LinkedNode *quickSort(LinkedNode *head, LinkedNode *end, LinkedNode **pure_zero_list)
	{
		if (!head || head == end)
			return head;

		LinkedNode *newHead = NULL, *newEnd = NULL;

		LinkedNode *pivot = partition(head, end, &newHead, &newEnd, pure_zero_list);

		if (newHead != pivot)
		{
			LinkedNode *tmp = newHead;
			while (tmp->_next != pivot)
				tmp = tmp->_next;
			tmp->_next = NULL;

			newHead = quickSort(newHead, tmp, pure_zero_list);

			tmp = getTail(newHead);
			tmp->_next = pivot;
		}

		pivot->_next = quickSort(pivot->_next, newEnd, pure_zero_list);

		return newHead;
	}

	void sortLinkedList(LinkedNode **headRef)
	{
		LinkedNode *pure_zero_list = NULL;
		(*headRef) = quickSort(*headRef, getTail(*headRef), &pure_zero_list);
		getTail(pure_zero_list)->_next = *headRef;
		*headRef = pure_zero_list;
		return;
	}
};

/***********************************/
//04 linked list quick sort with pdf
/***********************************/
class LinkedListQuickSortWithPDF {
public:
	LinkedNode *partition(LinkedNode *head, LinkedNode *end,
		LinkedNode **newHead, LinkedNode **newEnd, LinkedNode **pure_zero_list)
	{
		LinkedNode *pivot = end;
		LinkedNode *prev = NULL, *cur = head, *tail = pivot;

		while (cur != pivot)
		{
			if (cur->_val == 0) {
				if (prev)
					prev->_next = cur->_next;

				LinkedNode *after_zero = cur->_next;
				cur->_next = NULL;
				if ((*pure_zero_list) == NULL)
					(*pure_zero_list) = cur;
				else
					getTail(*pure_zero_list)->_next = cur;

				cur = after_zero;

			}
			if (cur->_val < pivot->_val)
			{
				if ((*newHead) == NULL)
					(*newHead) = cur;

				prev = cur;
				cur = cur->_next;
			}
			else
			{
				if (prev)
					prev->_next = cur->_next;
				LinkedNode *tmp = cur->_next;
				cur->_next = NULL;
				tail->_next = cur;
				tail = cur;
				cur = tmp;
			}
		}

		if ((*newHead) == NULL)
			(*newHead) = pivot;

		(*newEnd) = tail;

		return pivot;
	}

	LinkedNode *quickSort(LinkedNode *head, LinkedNode *end, LinkedNode **pure_zero_list)
	{
		if (!head || head == end)
			return head;

		LinkedNode *newHead = NULL, *newEnd = NULL;

		LinkedNode *pivot = partition(head, end, &newHead, &newEnd, pure_zero_list);

		if (newHead != pivot)
		{
			LinkedNode *tmp = newHead;
			while (tmp->_next != pivot)
				tmp = tmp->_next;
			tmp->_next = NULL;

			newHead = quickSort(newHead, tmp, pure_zero_list);

			tmp = getTail(newHead);
			tmp->_next = pivot;
		}

		pivot->_next = quickSort(pivot->_next, newEnd, pure_zero_list);

		return newHead;
	}

	void sortLinkedList(LinkedNode **headRef)
	{
		LinkedNode *pure_zero_list = NULL;
		(*headRef) = quickSort(*headRef, getTail(*headRef), &pure_zero_list);
		getTail(pure_zero_list)->_next = *headRef;
		*headRef = pure_zero_list;
		return;
	}
};
/***********************************/
//05 test function
/***********************************/
void shuffle_data(ElemType* data, size_t length);

int main()
{
	/*******************prob 1*********************/
	ElemType data_prob1[] = { 4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64, 11 };
	size_t length = sizeof(data_prob1) / sizeof(ElemType);
	shuffle_data(data_prob1, length);
	LinkedNode * list = createLinkedList(data_prob1, length);
	printLinkedList(list, "Prob1, Original Link");
	LinkedListQuickSort solution_prob1;
	solution_prob1.sortLinkedList(&list);
	printLinkedList(list, "Prob1, Sorted Link");
	destroyLinkedList(list);
	/*******************prob 2*********************/
	ElemType data_prob2[] = { 4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64, 11 , 0, 0, 0, 0 };
	length = sizeof(data_prob2) / sizeof(ElemType);
	shuffle_data(data_prob2, length);
	list = createLinkedList(data_prob2, length);
	printLinkedList(list, "Prob2, Original Link");
	LinkedListQuickSortDuplicatedZero solution_prob2;
	solution_prob2.sortLinkedList(&list);
	printLinkedList(list, "Prob2, Sorted Link");
	destroyLinkedList(list);
	/*******************prob 2*********************/

	/*******************prob 3*********************/
	return 0;
}

#include <algorithm> 
#include <random>
#include <chrono>
void shuffle_data(ElemType* data, size_t length) {
	std::vector<ElemType> shuffle_buffle(data, data + length);
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(shuffle_buffle.begin(), shuffle_buffle.end(), std::default_random_engine(seed));
	for (size_t i = 0; i < length; i++) {
		data[i] = shuffle_buffle[i];
	}
}