#include<stdio.h>

using namespace std;

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

typedef struct LinkNode
{
    int idx;
    LinkNode *next;
} *LINKNODE;

LINKNODE createLink(const int *a, const int len){
    LINKNODE head = new LinkNode;
    LINKNODE ptr=head;
    for (int i=0; i < len - 1; ++i){
        ptr->idx = *a++;
        ptr->next = new LinkNode;
        ptr = ptr->next;
    }
    ptr->idx=*a++;
    ptr->next=NULL;
    return head;
}

void printLinkNode(const LINKNODE head){
    if (head == NULL){
        printf("The Link is NULL.");
    }
    printf("The Link is :");
    LINKNODE ptr=head;
    while (ptr){
        printf(" %d", ptr->idx);
        ptr=ptr->next;
    }
    printf(".\n\n");
    return ;
}

void printArry(const int *a, int len){
    if (len <=0){
        printf("The Arry is NULL.");
    }
    printf("The Arry is :");
    int idx=len;
    while (idx){
        printf(" %d", *a++);
        idx--;
    }
    printf(".\n\n");
    return ;
}

void releaseLink(LINKNODE head){
    if (head == NULL){
        printf("The Link is NULL.\n");
    }
    LINKNODE ptr=head;
    while(head){
        head=head->next;
        delete ptr;
        ptr=head;
    }
    return ;
}

LINKNODE reverseLink(LINKNODE head){
    LINKNODE p,q,ptr;
    p = NULL;
    ptr = NULL;
    q = head;
    while(q->next){
        ptr = q->next;
        q->next = p;
        p = q;
        q = ptr;
    }
    q->next = p;
    
    return q;
}

void quickSort(int a[], int low, int high){
    if (low >= high)
        return ; 
   int i = low;
   int j = high;
   int key=a[i];
   while (i < j){
       while (i < j && key < a[j]) 
           j--;
       a[i]=a[j];
       while (i < j && a[i] < key)
           i++;
       a[j]=a[i];
   }
   a[i] = key;
   quickSort(a,low, i-1);
   quickSort(a,i+1, high);
   return ;
}


int main(int argc, char *argv[])
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int a_len=0;
    GET_ARRAY_LEN(a, a_len);
    //-- 单链表逆序
    LINKNODE ln = createLink(a, a_len);
    printLinkNode(ln);
    printf("Reverse the Link.\n");
    LINKNODE rln=reverseLink(ln);
    printLinkNode(rln);

    //--快速排序
    int b[10]={9,2,3,6,5,4,7,8,1,10};
    printArry(b, 10);
    quickSort(b, 0, 9);
    printArry(b, 10);
}
