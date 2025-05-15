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