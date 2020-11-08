#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SaveMode1 1 //apend data in file
#define SaveMode2 2 //Clear all file data

typedef struct node
{
    char name[30];
    int age;
    char sex[10];
    struct node *next;

} node;

static node *createNode(char *name, int age, char *sex);
static void printALL(node *);
static node *addNode(node *, char *name, int age, char *sex);
void deleteNode(node *, char *name);
node *LoadFromFile();
void SaveInFile(node *, int savemode);

int main(void)
{
    node *first = NULL;
    first = LoadFromFile();
    printALL(first);
    deleteNode(first, "Richard");

    SaveInFile(first, SaveMode2);

    system("PAUSE");
    return 0;
}

static node *createNode(char *name, int age, char *sex)
{
    node *newNode;
    //create first person
    newNode = (node *)malloc(sizeof(node));

    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->sex, sex);
    newNode->next = NULL;
    return newNode;
}

static void printALL(node *inNode)
{

    node *n = inNode;

    while (n != NULL)
    {

        printf("name = %s\n", n->name);
        printf("age = %d\n", n->age);
        printf("sex=%s\n", n->sex);
        n = n->next;
    }
}
void SaveInFile(node *input, int savemode)
{
    FILE *f;

    if (savemode == SaveMode1)
    {
        f = fopen("data.txt", "a+");
    }
    else
    {

        f = fopen("data.txt", "w+");
    }

    if (f == NULL)
    {
        printf("Cant open file and Saving");
        exit(1);
    }

    while (input != NULL)
    {

        fprintf(f, "%s ", input->name);
        fprintf(f, "%d ", input->age);
        fprintf(f, "%s ", input->sex);
        fprintf(f, "\n");
        input = input->next;
    }

    fclose(f);
}

node *addNode(node *orginal, char *name, int age, char *sex)
{
    //create new node
    node *newNode = createNode(name, age, sex);
    //link orginal and new node
    orginal->next = newNode;

    return newNode;
}

void deleteNode(node *input, char *name)
{

    //use name to find node and delete it
    node *current = input;
    node *previous = NULL;

    //LinKList當中是否有該姓名 找出該前後二個Node
    while ( (current != NULL) &&  (strcmp(name, current->name) != 0) )
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        //List中沒有該Node
        printf("LinkList do not contain the name can't delete");
    }
    else if (current == input)
    {
        //is first node
        input = current->next;
        //free(current);
        //current = NULL;
    }
    else
    {
        //需要刪除
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

node *LoadFromFile()
{

    node *first = NULL;
    node *tmp = NULL;

    FILE *f = fopen("data.txt", "r");

    if (f == NULL)
    {

        printf("Cant open file Loading");
        exit(1);
    }

    char name[30], sex[10];
    int age = 0;
    int counter = 0;

    while (fscanf(f, "%s %d %s\n", name, &age, sex) != EOF)
    {
        if (counter == 0)
        {

            first = createNode(name, age, sex);
            tmp = first;
        }
        else
        {
            tmp = addNode(tmp, name, age, sex);
        }
        counter++;
    }
    fclose(f);
    return first;
}
