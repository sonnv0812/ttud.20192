#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *pnext;
} node;

typedef struct _list{
    node *head;
    node *tail;
} list;

void Init(list *l);
node *makeNode(int value);
void addNodeTail(list *l, node *p);
void outputList(list l);
void inputList(list *l);
void freeList(list &l);
void insertNode(list *l);
void editNode(list *l);
void deleteHead(list &l);
void deleteNode(list &l);
int maxList(list l);
void innguoc(node *p);

int main(){
    list l, l1;
    inputList(&l);
    printf("\n");

    outputList(l);

    node *p = l.head;
    innguoc(p);

    /*editNode(&l);

    outputList(l);

    deleteNode(l);

    outputList(l);*/

    freeList(l);

    return 0;
}

//Cac ham khoi tao
void Init(list *l){
    l->head = l->tail = NULL;
}

node *makeNode(int value){
    node *p = (node *)malloc(sizeof(node));
    p->value = value;
    p->pnext = NULL;
    return p;
}

//Them node vao Tail
void addNodeTail(list *l, node *p){
    if(l->head==NULL)
        l->head=l->tail=p;
    else{
        l->tail->pnext = p;
        l->tail = p;
    }
}

//in list 
void outputList(list l){
    for(node *p= l.head; p != NULL; p = p->pnext){
        printf("%d ", p->value);
    }
    printf("\n");
}

//Nhap list
void inputList(list *l){
    int size;
    printf("Nhap so node: ");
    scanf("%d", &size);
    Init(l);
    for(int i = 0; i < size; i++){
        int data;
        printf("\nNhap data cho node %d: ", i+1);
        scanf("%d", &data);
        node *p = makeNode(data);
        addNodeTail(l, p);
    }
}

//Giai phong list
void freeList(list &l){
    node *p;
    while(l.head != NULL){
        p = l.head;
        l.head = l.head->pnext;
        free(p);
    }   
}

//Chen node vao sau 1 vi tri bat ky
void insertNode(list *l){
    int data;
    scanf("%d", &data);
    node *p = makeNode(data);
    int position;
    scanf("%d", &position);
    if(position == 1){
        if(l->head==NULL){
            l->head = l->tail = p;
        }
        else{
            p->pnext = l->head;
            l->head = p;
        }
        return;        
    }
    
    int i = 2;
    for(node *k = l->head; k != NULL; k = k->pnext){
        if(i == position){
            node *temp = k->pnext;
            k->pnext = p;
            p->pnext = temp;
            return;
        }
        i++;
    }
}

//Sua node bat ky
void editNode(list *l){
    printf("\nBan muon sua node thu: ");
    int position;
    scanf("%d", &position);
    printf("\nBan muon sua nhung cai gi (chon so thu tu)?\n");
    printf("\n1. Value"); int value;
    int j; scanf("%d", &j);

    int i = 0;
    for(node *k = l->head; k != NULL; k = k->pnext){
        i++;
        if(i == position){
            switch (j){
                case 1:
                    printf("\nNhap du lieu sua? ");
                    scanf("%d", &value);
                    break;
    
                default:
                    break;
            }
            k->value = value;
            return;
        }
    }
}

int maxList(list l){
    int max = l.head->value;
    for(node *p = l.head; p != NULL; p = p->pnext)
        if(max < p->value)
            max = p->value;
    return max;
}

void deleteHead(list &l){
    if(l.head == NULL)
        return;
    else{
        node *p;
        p = l.head->pnext;
        l.head = p;
    }
}

void deleteNode(list &l){
    printf("\nNhap vi tri xoa: ");
    int pos; 
    scanf("%d", &pos);
    int i = 0;
    node *p = l.head;
    for(node *k = l.head; k->pnext != NULL; k = k->pnext){
        i++;
        if(pos == i){
            p->pnext = k->pnext;
            free(k);
            return;
        }
        p = k;
    }
}

void innguoc(node *p){
    if(p == NULL) return;
    innguoc(p->pnext);
    printf("%d ", p->value);
}