// LeetCode Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// ------------------------------------------------------------------------

/* Approach [In One Pass]
1.  To remove the node in one pass, we first need to have a dummy node and add it to our LinkedList.
2.  Next we use 2-pointers Slow and Fast and make them point to the dummy node initially.
3.  After that we run our Fast pointer for N times.
4.  Next, we run till our Fast pointer reaches the Last Node and we move both Fast and Slow by one node at a time.
5. Slow will end up at the node, just previous to the Node to be deleted. Thus, we arrange the connections accordingly.
6. We make Slow -> next = Slow -> next -> next. This ensures that our N-th Node from the End of LinkedList is disconnected from the rest.
*/

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)    // function to remove Kth node from Linked list
{
    Node *dummy = new Node(-1) ;    // Initialize dummy node

    dummy -> next = head ;    // Link the dummy node with head

    Node *fast = dummy ;  Node *slow = dummy ;    // Initialize fast and slow pointers

    for(int i = 1 ; i <= K ; i++)  fast = fast -> next ;    // Increment fast pointer K times

    while(fast -> next != NULL)    // loop till fast pointer reaches end of linked list
    {
        slow = slow -> next ;    // Increment slow pointer

        fast = fast -> next ;    // Increment fast pointer
    }

    slow -> next = slow -> next -> next ;    // Remove Kth node

    return dummy -> next ;    // Return the head of the linked list

}


// Time Complexity:  O(N)
// Space Complexity: O(1)