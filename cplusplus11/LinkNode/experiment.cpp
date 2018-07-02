#include<stdio.h>

using namespace std;

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

typedef struct LinkNode
{
    int idx;
    LINKNODE next;
} *LINKNODE;

LINKNODE createLink(int *a, int len){
    LINKNODE head = new (LINKNODE) len*sizeof(LINKNODE);
    LINKNODE ptr=head;
    while (ptr->next){
        ptr->idx = *a++;
        ptr = ptr->next;
    }
    return head;
}

LINKNODE reverseLink(LINKNODE head){
    LINKNODE p,q,ptr;
    p = NULL;
    q = head;
    ptr = head->next;
    while(ptr){
        q->next = p;
        p = q;
        q = ptr;
        ptr=ptr->next;
    }
    
    return q;
}

int main(int argc, char *argv[])
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int a_len=0;
    GET_ARRAY_LEN(a, a_len);
    LINKNODE ln = createLink(a, a_len);
}
