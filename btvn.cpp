#include <stdio.h>

struct Node {
    float heso;
    int somu;
    Node* link;
};

struct ListDT {
    Node* first, *last;
};


void initDT(ListDT *l) {
    l->first = l->last = NULL;
}


Node* callNode(float hs, int sm) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}


void addNode(ListDT* lDT, Node* p) {
    if (lDT->first == NULL) {
        lDT->first = lDT->last = p;
    } else {
        lDT->last->link = p;
        lDT->last = p;
    }
}


void attachNode(ListDT* lDT, float hs, int sm) {
    Node* p = lDT->first;
    while (p != NULL) {
        if (p->somu == sm) {  
            p->heso += hs;
            if (p->heso == 0) {  
                Node* temp = lDT->first;
                if (temp == p) {
                    lDT->first = p->link;
                } else {
                    while (temp->link != p) temp = temp->link;
                    temp->link = p->link;
                }
                if (p == lDT->last) lDT->last = temp;
                delete p;
            }
            return;
        }
        p = p->link;
    }
    
    Node* newNode = callNode(hs, sm);
    if (newNode == NULL) return;
    addNode(lDT, newNode);
}


void taoDT(ListDT* lDT) {
    float hs;
    int sm;
    int i = 0;
    printf("Bat dau nhap da thuc (nhap he so 0 de ket thuc): \n");
    do {
        i++;
        printf("Nhap so phan tu thu %d", i);
        printf("\nNhap he so = ");
        scanf("%f", &hs);
        if (hs == 0) break;  
        printf("Nhap so mu = ");
        scanf("%d", &sm);
        attachNode(lDT, hs, sm);
    } while (hs != 0);
    printf("Ket thuc nhap\n");
}


void inDT(ListDT* lDT) {
    if (lDT->first == NULL) {
        printf("0\n");
        return;
    }
    Node* p = lDT->first;
    while (p != NULL) {
        if (p->heso > 0 && p != lDT->first) printf(" + ");
        printf("%.0f * x^%d", p->heso, p->somu);
        p = p->link;
    }
    printf("\n");
}


void giaiPhongDT(ListDT* lDT) {
    Node* p = lDT->first;
    while (p != NULL) {
        Node* temp = p;
        p = p->link;
        delete temp;
    }
    lDT->first = lDT->last = NULL;
}

int main() {
    ListDT dt;
    initDT(&dt);
    taoDT(&dt);
    printf("Da thuc vua nhap: ");
    inDT(&dt);
    giaiPhongDT(&dt); 
    return 0;
}
	