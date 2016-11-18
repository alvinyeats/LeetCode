class ClassList{
private:
        typedef struct list{
                int item;
                struct list *nextPtr;
                //list(int x) : item(x), nextPtr(NULL) {}
        }List;
        List *headPtr, *tailPtr;
public:
        ClassList(void);
        ~ClassList(void);
        void Insert(int value);

        void Delete(int value);

        void Show(void)const;

        
};



ClassList::ClassList(void)
{
        headPtr = tailPtr = NULL;
}

void ClassList::Insert(int value)
{
        List *newPtr = NULL;

        if((newPtr = new List) == NULL){
                cerr << "new failure." << endl;
                exit(1);
        }

        newPtr->item = value;
        newPtr->nextPtr = NULL;

        if(headPtr == NULL)
                headPtr = newPtr;
        else
                tailPtr->nextPtr = newPtr;
        tailPtr = newPtr;
}

void ClassList::Delete(int value)
{
        List *tempPtr = NULL, *prePtr = NULL, *currPtr = headPtr;

        if(headPtr == NULL){
                cerr << "list is empty." << endl;
                return;
        }

        if(headPtr->item == value){
                tempPtr = headPtr;
                headPtr = headPtr->nextPtr;
                delete tempPtr;
                return;
        }

        while(currPtr != NULL){
                if(currPtr->item != value){
                        prePtr = currPtr;
                        currPtr = currPtr->nextPtr;
                }else
                        break;
        }
        
        if(currPtr == NULL && prePtr->item != value){
                cout << "Not Found delete value: " << value << endl;
                return;
        }
        else{
                tempPtr = currPtr;
                if(currPtr == tailPtr)
                        tailPtr = prePtr;
                currPtr = currPtr->nextPtr;
                prePtr->nextPtr = currPtr;
                delete tempPtr;
        }

        cout << "Delete " << value << "successful." << endl;
}

void ClassList::Show(void)const
{
        List *tempPtr = NULL;

        for(tempPtr = headPtr; tempPtr != NULL; tempPtr = tempPtr->nextPtr)
                cout << "value = " << tempPtr->item << endl;
}

ClassList::~ClassList(void)
{
        List *tempPtr = NULL;

        while(headPtr !=NULL){
                tempPtr = headPtr;
                headPtr = headPtr->nextPtr;
                delete tempPtr;
        }
        headPtr = NULL;
        tailPtr = NULL;
}