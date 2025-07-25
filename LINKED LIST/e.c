void reverseList(int k) {
    if (head == NULL || k <= 1) return;

    struct Node* current = head;
    struct Node* newHead = NULL;
    struct Node* groupPrev = NULL;

    while (current != NULL) {
        struct Node* groupStart = current;
        struct Node* prev = NULL;
        int count = 0;

        
        while (current != NULL && count < k) {
            struct Node* next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
            count++;
        }

        // Connect previous group
        if (newHead == NULL) {
            newHead = prev;
        }

        if (groupPrev != NULL) {
            groupPrev->next = prev;
        }

        groupStart->next = current;
        if (current != NULL)
            current->prev = groupStart;

        groupPrev = groupStart;
    }

    head = newHead;
}
