// Struct for a generic stack of some specified sized type
typedef struct {
	void* elems;
	int elemSize;
	int logicallength;
	int allocatedlength;
	void (*freefn)(void* x);
} stack;

// Constructor
void stackNew(stack* s, int elemSize, void (*freefn)(void*)) ;

// Destructor
void stackDispose(stack* s);

// Methods
void stackPush(stack* s, void* elemAddr);
void stackPop (stack* s, void* elemAddr);

