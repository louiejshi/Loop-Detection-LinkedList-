//
//  main.cpp
//  LoopDetection
//
//  Created by Louie Shi on 7/31/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode* LoopDetection(ListNode* ln)
{
    ListNode* slow = ln;
    ListNode* fast = ln;
    
    while((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        
        if(slow == fast)
        {
            break;
        }
    }
    
    // Error checking: Not a loop
    if(fast == NULL || fast->getNext() == NULL)
    {
        return NULL;
    }
    
    slow = ln; //Head of the LinkedList
    while(slow != fast)
    {
        slow = slow->getNext();
        fast = fast->getNext();
    }
    
    return fast;
}

int main(int argc, const char * argv[])
{
    LinkedList* ls = new LinkedList();
    ListNode* result;
    
    ListNode* ln1 = new ListNode(1);
    ListNode* ln2 = new ListNode(2);
    ListNode* ln3 = new ListNode(3);
    ListNode* ln4 = new ListNode(4);
    ListNode* ln5 = new ListNode(5);
    
    //Build the circular linked list
    ls->insertEnd(ln1);
    ls->insertEnd(ln2);
    ls->insertEnd(ln3);
    ls->insertEnd(ln4);
    ls->insertEnd(ln5);
    ls->insertEnd(ln3);
    
    //ls->print();
    
    result = LoopDetection(ls->head);
    
    cout << "Value of the Beginning of the loop is: " << result->getData() << endl;
    
    return 0;
}
