/*
09. Program for Implementation of Single Linked List Part-1
Single linked list operations
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data; // data field
    struct node* link; //As one node holds the address of another node then the name of pointer is link
    // this pointer is of data type node.
};
struct node* root = NULL; // root declared globally with default value NULL.
int len; // Global declaration of length used in len function to find number of nodes in LL.
void append(void);
void add_at_begin(void);
void add_at_after(void);
int length();
void display(void);
// void delete(void);
int main()
{
    int ch;
    while(1) // To continuously perform the operations.
    {
        printf("Single Linked List Operations : \n");
        printf("1. Append \n");
        printf("2. Add at beginnign \n");
        printf("3. Add at after \n");
        printf("4. Length \n");
        printf("5. Display \n");
        printf("6. Delete\n");
        printf("7. Quit \n");

        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: append();
            break;

            case 2: add_at_begin();
            break;

            case 3: add_at_after();
            break;

            case 4: len = length();
                    printf("Length : %d\n\n",len);
            break;

            case 5: display();
            break;

            // case 6: delete();
            // break;

            case 7 : exit(1);
            break;



            default:
            printf("Invalid Input.\n\n");

        }

    }
    return 0;
}
//--------------------------APPEND--------------------------------------------------
/* Now root is created at a particular location and now we need to define a way to make new node
 and add to list, we do so inside the append function. Whenever append is called first we need to
 declare the temp variable (a local variable which gets deleted after completion of append).*/
void append()
{
    struct node* temp;
    temp =(struct node*)malloc(sizeof(struct node));
    // malloc first creates a node with 2 fields data and link
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    /* Node is ready now we have to check where to connect this node, either to root or somewhere else.
    If list already has some elements then we need to add the node at the end of the list.
    As when beginning there are no nodes in the list so root will be temp
    */
//Checking
    if(root==NULL) //list is empty
    {
        temp = root; //starts pointing to the first node in the list.

    }
    //for remaining nodes we make use of else block
    else
    {
        /*Again consider our 4 node LL of addresses 1k-4k and data 10-40 link of 4th node = NULL*/
        //This runs when root != NULL
        struct node * p;
        /*We travel from first location to last location, as root stores the first address
        so we store the root inside p (temp)
        */
       p = root;//Now we have to check continuously if next->link = NULL or not.
       while(p->link != NULL) //if p to link not equal to null means there is other node.
       {
           p = p->link; // As this starts to point to the final node of the existing list.
       }
       // Put in the address of temp in the link of existing LL at the end instead of NULL.
       p->link = temp; // Final node of previous LL connected to the new node.
        // This is how you add node at the end of the single linked list.
    }
}
//--------------------------------LENGTH of LINKED-LIST-------------------------------------------
//  Pt. 2
/*
    Here we write the function to find length of a linked list. Length function is always of int type.
    Returns number of nodes in the LL.
    int len declared globally so we can access it from anywhere.
*/

//-----------------------------------------------------------------------------------
int length()
{
    struct node *temp;
    int count = 0;
    // No need to disturb the root variable in a single LL operation, perform operations using temp.
    temp = root; // To start counting nodes from root.
    // temp stored with memory address 1000.
    //If root==NULL means there are no nodes in the list. Continue if nodes exist
    if(temp==NULL)
    {
        printf("List is empty\n\n");
    }
    while(temp!=NULL)
    {
        count++;//Increase count value if temp != NULL
        //Send control to next node by temp to link i.e. temp->link value updation as following:
        temp = temp->link;
        // temp becomes 2000 from 1000. 2000->3000. 3000->4000. 4000->NULL . END LOOP!
        //count becomes 4 now. And condition fails at 4000->link. So 4 nodes present.


    }
    return count;
}

//--------------------------------DISPLAY ELEMENTS IN LINKED-LIST----------------------------------

void display()
{
    struct node* temp;
    temp = root;
    // Logic same as length of the LL. First we check if temp != NULL and then proceed with loop.
    if(temp==NULL)
    {
        printf("List is empty\n\n");
    }
    else{
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);//temp->data to print information of node.
            temp = temp->link;  // Sending control to next node.
        }
        printf("\n\n"); // 2 lines gap after printing the list.
    }
}

// void delete(void)
// {

// }

void add_at_begin(void)
{

}

void add_at_after(void)
{

}
