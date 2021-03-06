#include <stdio.h>
#include <stdlib.h>

#define Red 3
#define Black 2
#define Empty_Red 1
#define Empty_Black 0

struct RBTree{
    struct RBTree *parent;
    struct RBTree *left;
    struct RBTree *right;
    int value;
    char color; // 0 - black; 1 - red (0 bit);; 0 - is empty; 1 - '0' is value (2 bit);;
} typedef RB_Tree;

int is_red ( RB_Tree *node )
{
    return node != NULL && node->color & 1;
}

/* функция для однократного поворота узла */
RB_Tree *rb_single ( RB_Tree *root, int dir )
{
    RB_Tree *save;
    if (!dir) {
        save = root->right;
        root->right = save->left;
        save->left = root;
    } else {
        save = root->left;
        root->left = save->right;
        save->right = root;
    }

    root->color = Red;
    save->color = Black;

    return save;
}

/* функция для двукратного поворота узла */
RB_Tree *rb_double ( RB_Tree *root, int dir )
{
    if (!dir) {
        root->right = rb_single ( root->right, !dir );
    } else {
        root->left = rb_single ( root->left, !dir );
    }
    return rb_single ( root, dir );
}

RB_Tree *make_node (RB_Tree *parent,  int data )
{
    RB_Tree *node = (RB_Tree *) malloc(sizeof(RB_Tree));
    if (!node) {
        printf("Could`t allocate memory!\n");
        return NULL;
    }
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->value = data;
    node->color = Red;
    return node;
}

RB_Tree *insert (RB_Tree *root, int input){


    RB_Tree head = {0}; /* временный корень дерева*/
    RB_Tree *g, *t;     /* дедушка и родитель */
    RB_Tree *p, *q;     /* родитель и итератор */
    int dir = 0, last;

    /* вспомогательные переменные */
    t = &head;
    g = p = NULL;
    q = t->right = root;

    if (!(root->color & 2)){
        root->value = input;
        root->color = Black;
    } else {
        for ( ; ; ){
            if ( q == NULL ) {
                /* вставка ноды */
                if (dir) {
                    p->right = q = make_node ( p, input );
                } else {
                    p->left = q = make_node ( p, input );
                }
                if ( q == NULL )
                    return root;
            } else if ( is_red ( q->left ) && is_red ( q->right ) ) {
                /* смена цвета */
                q->color = Red;
                q->left->color = Black;
                q->right->color = Black;
            }
            /* совпадение 2-х красных цветов */
            if ( is_red ( q ) && is_red ( p ) ) {
                int dir2 = t->right == g;

                if (last){
                    if ( q == p->right ) {
                        if (dir2) {
                            t->right = rb_single(g, !last);
                        } else {
                            t->left = rb_single(g, !last);
                        }
                    } else {
                        if (dir2) {
                            t->right = rb_double(g, !last);
                        } else {
                            t->left = rb_double(g, !last);
                        }
                    }
                } else {
                    if ( q == p->left ) {
                        if (dir2) {
                            t->right = rb_single(g, !last);
                        } else {
                            t->left = rb_single(g, !last);
                        }
                    } else {
                        if (dir2) {
                            t->right = rb_double(g, !last);
                        } else {
                            t->left = rb_double(g, !last);
                        }
                    }
                }
            }

            /* такой узел в дереве уже есть  - выход из функции*/
            if ( q->value == input ) {
                break;
            }

            last = dir;
            dir = q->value < input;

            if ( g != NULL )
                t = g;
            g = p, p = q;
            if (dir) {
                q = q->right;
            } else {
                q = q->left;
            }
        }
        /* обновить указатель на корень дерева*/
        root = head.right;
    }
    /* сделать корень дерева черным */
    root->color = Black;
    return root;
}

void draw(RB_Tree *baobab_leaf, int depth){
    if (baobab_leaf->color & 1) { // if red
        if (baobab_leaf->color >> 1) { //if red`s not null
            for (int i = 0; i < depth; ++i)
                printf("    ");
            printf("<%d>\n", baobab_leaf->value);
        }
    } else if (baobab_leaf->color >> 1) {
        for (int i = 0; i < depth; ++i)
            printf("    ");
        printf("%d\n", baobab_leaf->value);
    }
}

void printing (RB_Tree *baobab_leaf, int depth)
{
    if (baobab_leaf->right)
        printing(baobab_leaf->right, depth+1); //THANKS TO DIMON
    draw(baobab_leaf, depth) ;
    if (baobab_leaf->left)
        printing(baobab_leaf->left, depth+1);
}

void show (RB_Tree *baobab){
    if (!(baobab->color >> 1)){
        printf("<Is Empty>\n");
        return;
    }
    int depth = 0;
    printing(baobab, depth);
}

RB_Tree *delete( RB_Tree *tree, int input )
{
    if ( tree != NULL )
    {
        RB_Tree head = {0}; /* временный указатель на корень дерева */
        RB_Tree *q, *p, *g; /* вспомогательные переменные */
        RB_Tree *f = NULL;  /* узел, подлежащий удалению */
        int dir = 1;

        /* инициализация вспомогательных переменных */
        q = &head;
        g = p = NULL;
        q->right = tree;

        /* поиск и удаление */
        while ( dir ? (q->right != NULL) : (q->left != NULL)) {
            int last = dir;

            /* сохранение иерархии узлов во временные переменные */
            g = p, p = q;
            q = dir ? q->right : q->left;
            dir = q->value < input;

            /* сохранение найденного узла */
            if ( q->value == input )
                f = q;

            if ( !is_red ( q ) && !is_red ( dir ? q->right : q->left ) ) {
                if ( is_red ( dir ? q->left : q->right ) ) {
                    p = rb_single(q, dir);
                    if (last) {
                        p->right = rb_single(q, dir);
                    } else {
                        p->left = rb_single(q, dir);
                    }
                } else if ( !is_red ( dir ? q->left : q->right ) ) {
                    RB_Tree *s = (!last ? p->right : p->left);


                    if ( s != NULL ) {
                        if ( !is_red ( !last ? s->right : s->left ) && !is_red ( last ? s->right : s->left ) ) {
                            /* смена цвета узлов */
                            p->color = Black;
                            s->color = Red;
                            q->color = Red;
                        }
                        else {
                            int dir2 = g->right == p;

                            if ( is_red ( last ? s->right : s->left ) ) {
                                if (dir2) {
                                    g->right = rb_double(p, last);
                                } else {
                                    g->left = rb_double(p, last);
                                }

                            } else if ( is_red ( !last ? s->right : s->left ) ){
                                if (dir2) {
                                    g->right = rb_single ( p, last );
                                } else {
                                    g->left = rb_single ( p, last );
                                }
                            }

                            /* корректировка цвета узлов */
                            q->color = Red;
                            if (dir2) {
                                g->right->color = Red;
                                g->right->left->color = Black;
                                g->right->right->color = Black;
                            } else {
                                g->left->color = Red;
                                g->left->left->color = Black;
                                g->left->right->color = Black;
                            }
                        }
                    }
                }
            }
        }

        /* удаление найденного узла */
        if ( f != NULL ) {
            f->value = q->value;
            if (p->right == q) {
                p->right =
                        ((q->left == NULL) ? q->right : q->left);
            } else {
                p->left =
                        ((q->left == NULL) ? q->right : q->left);
            }
            free ( q );
        }

        /* обновление указателя на корень дерева */
        tree = head.right;
        if ( tree != NULL )
            tree->color = Black;
    }

    return tree;
}

void inorder(RB_Tree *tree){
    if (tree->left)
        inorder(tree->left);
    printf("%d -> ", tree->value);
    if (tree->right)
        inorder(tree->right);
}

void preorder(RB_Tree *tree){
    printf("%d -> ", tree->value);
    if (tree->left) {
        preorder(tree->left);
    } else {
        printf(" Is empty");
    }
    if (tree->right)
        preorder(tree->right);
}

void postorder(RB_Tree *tree){

    if (tree->left)
        postorder(tree->left);
    if (tree->right)
        postorder(tree->right);
    if (!( tree->right)) //tree->left ||
        printf("Is empty");
    printf("%d -> ", tree->value);
}

int main() {
    printf("Hello, World!\n");

    RB_Tree *baobab = (RB_Tree *)malloc(sizeof(RB_Tree));
    if (!baobab){
        printf("Could`t allocate memory!\n");
        return -1;
    }
    baobab->parent = NULL;
    baobab->left = NULL;
    baobab->right = NULL;
    baobab->color = Empty_Red;
    baobab->value = 0;

    int choice = 0;
    int input = 0;
    do
    {
        printf("\nWhat do you want to do?\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Show\n");
        printf("4.Inorder\n");
        printf("5.Preorder\n");
        printf("6.Postorder\n");
        printf("7.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch ( choice )
        {
            case 1:
                printf("\nEnter The Data for Inserting:");
                scanf("%d", &input);
                printf("\nInserting!\n\n");
                baobab = insert(baobab, input);
                break;
            case 2:
                printf("\nEnter The Data for Deleting:");
                scanf("%d", &input);
                baobab = delete(baobab, input);
                break;
            case 3:
                show(baobab);
                break;
            case 4:
                printf("\n");
                if (baobab->color & 2)
                    inorder(baobab);
                printf("\n");
                break;
            case 5:
                printf("\n");
                if (baobab->color & 2)
                    preorder(baobab);
                printf("\n");
                break;
            case 6:
                printf("\n");
                if ( baobab->color & 2 )
                {
                    if (baobab->left)
                        postorder(baobab->left);
                    if (baobab->right)
                        postorder(baobab->right);
                    printf("%d -> ", baobab->value);
                }
                else
                {
                    printf("Is empty");
                }
                printf("\n");
                break;
            case 7:
                printf("\nExiting......");
                exit(1);
                return 0;
            default:
                printf("Please Enter a valid number!!\n");
                break;
        }
    }
    while ( 1 );

    return 0;
}
