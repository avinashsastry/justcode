#include "queue.h"
#include "graph.h"

template <class object>
queue<object>::queue(unsigned int max_len) {
	array = (object*) malloc(max_len * sizeof(object));
	length = 0;
	max_length = max_len;
}

template <class object>
queue<object>::~queue() {
	if (array) free(array);
}

template <class object>
void queue<object>::push(object o) {
	if (!o) return;
	
	if (length < max_length) {
		array[length] = o;
		length++;
	}
	else {
		// Do nothing
	}
}

template <class object>
object queue<object>::pop() {
	if (length > 0) {
		object o = array[0];
		length--;
		memcpy(array, array+1, length*sizeof(object));
		return o;
	}
	else {
		return NULL;
	}
	
}

template <class object>
object queue<object>::peek() {
	if (array)
		return array[0];
}

template <class object>
bool queue<object>::isEmpty() {
	if (length > 0) return false;
	else return true;
}

template class queue<graphNode*>;