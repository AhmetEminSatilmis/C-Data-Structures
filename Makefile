all:
	gcc linked_list.c circular_linked_list.c doubly_linked_list.c array_stack.c list_stack.c array_queue.c circular_array_queue.c main.c -o a
	

run:
	./a
