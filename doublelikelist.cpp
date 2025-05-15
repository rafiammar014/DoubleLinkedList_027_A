#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public
        int nomMhs;
        Node *next;
        Node *prev;
};

class doubleLinkedList
{
    private:
        Node *START;

    public:
        DoubleLinkedList()
        {
            START = NULL;
        }

        void ddNode ()
        {
            int nim;
            string nm;
            cout << "\nEnter the roll number og the student: ";
            cin >> nim;

            // Step 1: Allcate memory for new node
            Node *newNode = new Node();

            // Step 2:Assign value to the data fields
            newNode->nomMhs = nim;

            // Step 3: Insert at beginning if list is empty or nim is smallest 
            if (START == NULL || nim < START->nomMhs)
            {
                if (START != NULL && nim == START->nomMhs)
                {
                    cout << "\nDuplicate nim not allowed" << endl;
                    return;
                }
                // Step 4: newNode.Next = START;
                newNode->next = START;

                // Step 5: start.prev = newNode; (if start exists)
                if (START != NULL)
                    START->prev = newNode;

                // Step 6: newNode.prev = NULL
                newNode->prev = NULL;

                // Step 7: START = newNode
                START = newNode;
                return;
            }
        }
        // insert in between node 
        // Step 8 : locate potition for insertion 
        Node *current = START;
        while (current->next != NULL && current->next->nomMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->nomMhs)
        {
            cout << "\nDuplicate nim not allowed" << endl;
            return;
        }

        // Step 9 : Insertion between current and current->next
        newNode->next = current->next;// step 9a
        newNode->prev = current;// step 9b

        //insertion last node 
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c

        current->next = newNode; // step 9d
}

void hapus()
{
    if (START == NULL)
    {
        cout << "\nList is empty" << endl;
        return;
    }
    
    cout << "\nEnter the roll of the student whose record is to be deleted: ";
    int rollNo;
    cin >> rollNo;

    Node *current = START;

    // Step 1: Traverse the list to find the node 
    while (current != NULL && current->nomMhs != rollNo)
        current = current->next;

        if (current == NULL)
        {
            cout << "\nRecord not found" << endl;
            return;
        }

        // Step 2 : If node is at the beginning
        if (current == START)
        {
            START = current->next; // Step 2a: START = START.next 
            if (START != NULL)
                START->prev = NULL; // Step 2b: START.prev = NULL
        }
        else
        {
            // Step 3: link preveious node to next of current 
            current->prev->next = current->next;

            // Step 4: If current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // Step 5: Delete the node 
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
}

void traverse ()
{
    if (START == NULL)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    // Step 1: Mark first node as currentNode 
    Node *currentNode = START;

    // Step 2: Repeat until currentNode == NULL
    cout << "\nRecords in asecending order of roll number are:\n";
    int i = 0 ;
    while (currentNode != NULL)
    {

      cout << i + 1 << ". " << currentNode->nomMhs << " " << endl;

      // Step 3: Move to next node
      currentNode = currentNode->next;
      i ++;
    }
}

void revtraverse ()
{
    if (START == NULL)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    // Step 1: Move to last node
    Node *currentNode = START;
    int i + 1;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        i++;
    }

    // Step 2: Traverse backward
    cout << "\nRecords in descending order of roll number are:\n";
    while (currentNode != NULL)
    {
        cout << i << ". " << currentNode->nomMhs << " " << endl;

        // Step 3: Move to previous node
        currentNode = currentNode->prev;
        i--;
    }
}

void searchData()
{
    If (START == NULL)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    int rollNo;
    cout << "\nEnter the roll number of the student to search: ";
    cin >> rollNo;  

    Node *current = START;
    
    // Step 1: Traverse to find matching roll number 
    while (Current != NULL && current->nomMhs != rollNo)
        current = current->next;
}
