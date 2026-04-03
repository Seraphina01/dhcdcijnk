#include<stdlib.h>
#include"model.h"
#include<string.h>
#include"global.h"

Card aCard[50];  //卡信息结构体数组
int nCount = 0;  //卡信息实际个数
lpCardNode cardList = NULL;

//初始化链表
int initCardList() {
	lpCardNode head = NULL;
	head = (lpCardNode)malloc(sizeof(CardNode));

	if (head != NULL) {
		head->next = NULL;
		cardList = head;
		return TRUE;
	}
	return FALSE;
}

int addCard(Card card) {
	lpCardNode cur = NULL;
	lpCardNode pTemp = cardList;

	if (cardList == NULL) {
		if (!initCardList()) {
			return FALSE;
		}
		pTemp = cardList;
	}
    if (pTemp == NULL) {
		return FALSE;
	}

	 //将数据保存到节点
	cur = (lpCardNode)malloc(sizeof(CardNode));
	if (cur != NULL) {
		cur->data = card;
		cur->next = NULL;
		//遍历链表找到最后一个节点
		while (pTemp->next != NULL) {
			pTemp = pTemp->next;
		}
		pTemp->next = cur;
		return TRUE;
	}
	return FALSE;
}

void releaseCardList() {
	lpCardNode cur;
	if (cardList != NULL) {
		while (cardList->next != NULL) {
			cur = cardList->next;
			free(cur);
			cur = NULL;
		}
	}
}


Card* queryCards(const char* pName, int* pIndex) {
	*pIndex = 0;
	Card* pCard = NULL;

	//链表为空直接返回NULL
	if (cardList == NULL || cardList->next == NULL) {
		return NULL;
	}
	//统计匹配的卡数量
    lpCardNode pTemp = cardList->next;
	while (pTemp != NULL) {
		if (strstr(pTemp->data.aName, pName)!= NULL) {
			(*pIndex)++;
		}
		pTemp = pTemp->next;
    }
    //无匹配卡，返回NULL
	if (*pIndex == 0) {
		return NULL;
	}
   //分配内存存储所有匹配卡
	pCard = (Card*)malloc(*pIndex * sizeof(Card));
	if (pCard == NULL) {
		*pIndex = 0;
		return NULL;
	}
	//填充匹配卡信息
	pTemp = cardList->next;
    int i = 0;
    while (pTemp != NULL && i < *pIndex) {
        if (strstr(pTemp->data.aName, pName) != NULL) {
            pCard[i] = pTemp->data;
            i++;
        }
        pTemp = pTemp->next;
    }

	return pCard;//返回多卡数组，实现模糊查询
	
}