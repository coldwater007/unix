#include <stdio.h>
#include <malloc.h>

struct node {
    int val;
    struct node *next;
};

static void list_sort(struct node *head);

struct node *list_create(int arr[], int size)
{
    struct node *head = NULL;
    int i;
    for (i = size - 1; i >= 0; --i) {
        struct node *p = (struct node *)malloc(sizeof(struct node));

        p->val = arr[i];
        p->next = head;
        head = p;
    }
    return head;
}
static void list_print(struct node *head)
{
    for (; head; head = head->next) {
        printf("%d", head->val);
        if (head->next)
            printf(" ");
    }
    printf("\n");
}
static void list_free(struct node *head)
{
    struct node *next;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
}
static int input(int **arr, int *size)
{
    int i;
    int ret;

    ret = fscanf(stdin, "%d\n", size);
    if (ret != 1)
        return -1;
    *arr = (int *)malloc(sizeof(int) * (*size));
    for (i = 0; i < *size; ++i) {
        fscanf(stdin, "%d ", &(*arr)[i]);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct node *head;
    int *arr = NULL;
    int size = 0;

    if (input(&arr, &size) < 0) {
        fprintf(stderr, "input error\n");
        return 0;
    }
	printf("1");
    head = list_create(arr, size);
	printf("1");
    list_sort(head);
	printf("2");
    list_print(head);
    list_free(head);
    free(arr);
    return 0;
}

static void list_sort(struct node *head)
{
	return;
	printf("1");
    if(head==NULL || head->next==NULL)
        return;
    //TODO:
    int len=0;
    node* p=head;
	printf("1");
    while(p)
    {
        len++;
        p=p->next;
    }
    
    node* dump=new node;
    dump->next=head;
	printf("1");
    for(int i=0;i<len-1;i++)  //最多冒泡len-1次
    {
        node* pre=dump;
        node* p=pre->next;
        while(p->next!=NULL)  //还存在后续节点
        {
			printf("3");
            if(p->next->val>=p->val)  //后面一个节点更大
            {
                pre=p;
                p=p->next;//两者后移动
            }
            else{  //作交换   
                node* p2=p->next;
                node* p2_next=p->next;
                //四个节点重新勾连
                pre->next=p2;
                p2->next=p;
                p->next=p2_next;
                pre=p2;
              
            }
            
        }
    }
	printf("2");
    head=dump->next;
    dump->next=NULL;
    delete dump;
    
}