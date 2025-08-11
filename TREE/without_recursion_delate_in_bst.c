void delete(int x) {
    struct node *parent = NULL;
    struct node *current = root;

    while (current != NULL && current->data != x) {
        parent = current;
        if (x < current->data)
            current = current->lptr;
        else
            current = current->rptr;
    }

    if (current == NULL) {
        printf("Value %d not found in the tree!\n", x);
        return;
    }

    if (current->lptr == NULL && current->rptr == NULL) {
        if (current == root)
            root = NULL;
        else if (parent->lptr == current)
            parent->lptr = NULL;
        else
            parent->rptr = NULL;
        free(current);
    }

    else if (current->lptr == NULL || current->rptr == NULL) {
        struct node *child = (current->lptr) ? current->lptr : current->rptr;
        if (current == root)
            root = child;
        else if (parent->lptr == current)
            parent->lptr = child;
        else
            parent->rptr = child;
        free(current);
    }

    else {
        struct node *lsub=current->lptr;
        current->lptr=NULL;
        struct node *temp=current->rptr;

        if(parent==NULL) {
            root=current->rptr;
        }
        else if(parent->rptr==current) {
            parent->rptr=current->rptr;
        }
        else{
            parent->lptr=current->rptr;
        }
        while (temp->lptr!=NULL)
        {
            temp=temp->lptr;
        }
        temp->lptr=lsub;
        free(current);
    }
}