//加一
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int i = digitsSize - 1;
	for (i; i >= 0; i--)
	{
		if (digits[i] < 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
	digits[i] = 0;
	}
	int* new = (int*)malloc((digitsSize + 1) * sizeof (int));
	new[0] = 1;
	for (i = 1; i < digitsSize + 1; i++)
		new[i] = 0;
	*returnSize = digitsSize+1;
	return new;

}
//移除元素
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (!head)
		return NULL;

	struct ListNode *p, *pre;

	p = head;
	pre = p;
	while (p)
	{
		if (p->val == val)
		{
			if (p == head)
			{
				head = head->next;
				p = head;

			}
			else{
				p = p->next;
				pre->next = p;
			}
		}
		else
		{
			pre = p;
			p = p->next;
		}
		

	}
	return head;

}
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_head = NULL, *temp = NULL;
    if (!head || !head->next)
    {
        return head;
    }
    while (head != NULL)
    {
        temp = head->next;     // 临时记录指针一直指向当前节点的下一个结点，防止断链找不到
        head->next = new_head; // 当前节点的next指针链到新节点上
        new_head = head;       // 新节点移动到刚才节点上，使得下次能够倒序链接节点
        head = temp;           // 当前节点移动到一开始保存的下一个结点
    }
    return new_head;
}

