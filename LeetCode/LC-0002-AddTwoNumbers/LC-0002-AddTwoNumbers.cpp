/*
	LC 2 Add Two numbers represented by linked lists

	You are given two non-empty linked lists representing two non-negative integers. 
	The digits are stored in reverse order, and each of their nodes contains a single digit. 
	Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Input: l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.

*/


#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



ListNode* create_list(const std::string str) 
{
    ListNode* list = NULL;
    
    for (int i = 0; i < str.size(); i++)
    {
        int val = str[i] - '0';
        list = new ListNode(val, list);
    }
    
    return list;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *result = NULL, *last = NULL;

    int reminder = 0;
    while (l1 || l2 || reminder)
    {
        int sum = reminder;

        if (l1)
            sum += l1->val;

        if (l2)
            sum += l2->val;

        reminder = sum / 10;
        
        auto tmp = new ListNode(sum % 10);
        if (last)
        {
            last->next = tmp;
            last = tmp;
        }
        else
        {
            result = last = tmp;
        }

        if(l1)
            l1 = l1->next;
        
        if(l2)
            l2 = l2->next;
    }

    return result;
}



int main()
{

    while (1)
    {
        std::string line;
        std::string sum;

        std::cout << "Enter two numbers e.g.342 465\n";
        printf("> ");
        std::getline(std::cin, line);

        std::vector<std::string> tokens;
        boost::split(tokens, line, boost::is_any_of(" "));

        if (tokens.size() != 2)
            continue;

        ListNode* list1 = create_list(tokens[0]);
        ListNode* list2 = create_list(tokens[1]);

        auto result = addTwoNumbers(list1, list2);

        printf("Result:\n");
        for (auto p = result; p != NULL; p = p->next)
            printf("%d ", p->val);

        printf("\n");
    }

}

