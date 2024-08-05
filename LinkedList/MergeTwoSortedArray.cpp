
// NULL Ptr handle properly

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list3 = new ListNode(-1);
        ListNode *dummy = list3;
        //   dummy->next = list3;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                list3->next = list1;
                list1 = list1->next;
            }
            else
            {
                list3->next = list2;

                list2 = list2->next;
            }
            list3 = list3->next;
        }
        list2 != NULL ? list3->next = list2 : list3->next = list1;
        return dummy->next;
    }
};