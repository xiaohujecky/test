#include<stdio.h>
#include<assert.h>

using namespace std;

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

typedef unsigned char BYTE;
typedef long int LONGLONG;

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

// 1.写一个单链表逆序算法
LINKNODE reverseLink2(LINKNODE head){
    LinkNode *lastnode = NULL;
    while (head->next != NULL){
        LinkNode *child = head->next;
        head->next = lastnode;
        lastnode = head;
        head = child;
    }
    head->next = lastnode;
    return head;
}


// 2.根据dynamic programming思想，实现快速排序算法
void quickSort2(int a[], int low, int high){
     if (low<high){
        int flag = a[low];
        int left = low;
        int right = high;
        while (left < right){
            if (a[right]>=flag){
                right--;
            }else{
                bool sign = true;
                while (left < right && sign){
                    if (a[left]<=flag){
                        left++;
                    }else{
                        int tmp = a[right];
                        a[right] = a[left];
                        a[left] = tmp;
                        sign = false;
                    }
                }
            }
        }
        if(a[left]<flag){
            int tmp = a[left];
            a[left] = flag;
            a[low] = tmp;
        }else if(left-1>=low && a[left-1]<flag){
            int tmp = a[left-1];
            a[left-1] = flag;
            a[low] = tmp;
        }
        quickSort2(a, low, left-1);
        quickSort2(a, left+1, high);
    }
}


/*
// 1.写一个单链表逆序算法
LINKNODE reverseLink2(LINKNODE head){
if (!head){
        return head;
    }
    LINKNODE p, c, n, fh;// initialize linknode
    fh = head;
    p = head;
    c = p->next;
    n = c->next;
    while (n){
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    c->next = p;
    fh->next = NULL;
    return c;

}


// 2.根据dynamic programming思想，实现快速排序算法
void quickSort2(int a[], int low, int high){
if (low < high)
    {
        int i = setMiddle(a, low, high);// find middle
        quickSort2(a, low, i - 1); // sort left part
        quickSort2(a, i + 1, high); // sort right part
    }

}
int setMiddle(int s[], int l, int r){
    int i = l, j = r;
    int x = s[l];
    while (i < j)
    {
        while(i < j && s[j] >= x)
            j--;
        if(i < j)
        {
            s[i] = s[j];
            i++;
        }

        while(i < j && s[i] < x)
            i++;
        if(i < j)
        {
            s[j] = s[i];
            j--;
        }
    }
    // set x to blank
    s[i] = x;
    return i;
} 

 */

void *mymemcpy0(void *dst,const void *src,size_t num)
{
    assert(dst != NULL && src != NULL && num > 0);
    assert(dst >= src + num || src >= dst + num ); //考虑内存重叠情况
    BYTE *pdst = (BYTE*)dst;
    BYTE *psrc = (BYTE*)src;
    while(num--) 
    *pdst++ = *psrc++;
    return pdst;
}

template< typename T>
T* mymemcpy1(T *dst, T *src, size_t num)
{
    if (dst == NULL || src == NULL)
        return NULL;
    if (dst == src)
        return dst;

    T *pdst = static_cast<T*>(dst);
    const T *psrc = static_cast<const T*>(src);
    //T *pdst = dst;
    //const T *psrc = (const T*)src;

    int n = static_cast<int>(num);

    if (pdst > psrc){
        // Note : the for loop index i should not be the type of size_t
        // because size_t type varible is a non-negative interger
        // for condition will always meets up and core dumps.
        for (int i = n - 1; i >= 0; --i)
            pdst[i] = psrc[i];
    }else{
        for (int i = 0; i < n; ++i)
            pdst[i] = psrc[i];
    }
    return pdst;
}

void *mymemcpy2(void *dst,const void *src,size_t num){
    assert(dst != NULL && src != NULL);
    int word_num = num/sizeof(int);
    int slice = num%sizeof(10);
    int *pdst = (int *)dst;
    int *psrc = (int *)src;
    while (word_num--) *pdst++ = *psrc++;
    while (slice--) *(char *)pdst++ = *(char *)psrc++;
    return pdst;

}

int main(int argc, char *argv[])
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int a_len=0;
   
    /*
    GET_ARRAY_LEN(a, a_len);
    //-- 单链表逆序
    LINKNODE ln = createLink(a, a_len);
    printLinkNode(ln);
    printf("Reverse the Link.\n");
    LINKNODE rln=reverseLink2(ln);
    printLinkNode(rln);

    //--快速排序
    int b[10]={9,2,3,6,5,4,7,8,1,10};
    printArry(b, 10);
    quickSort2(b, 0, 9);
    printArry(b, 10);
    */

    //-- memcpy
    int c[10]={0};
    int *str_a = a;
    int *str_c = c;
    printArry(a, 10);
    //mymemcpy0(c, a, sizeof(int)*10);
    //mymemcpy1(c, a, 10);
    mymemcpy2(c, a, sizeof(int)*10);
    printArry(c, 10);
    return 0;
}
