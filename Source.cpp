#include <iostream>
#include <ctime>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList list;

	// Push initial values to top
	list.push_top(10);
	list.push_top(15);
	list.push_top(20);

	// Output header
	std::cout << "Output:" << '\n';

	// Push value to bottom
	list.push_bottom(5);

	// Remove value from bottom
	list.remove_bottom();

	// Insert before node
	list.insert_before(list.top(), 69);

	// Print list
	list.print_list();
	std::cout << '\n';

	// Search for value starting from head
	const int val = 20;
	Node* result = list.search(val);
	std::cout << "Searching for " << val;
	std::cout << " < " << (result ? "FOUND" : "NOT FOUND") << " >" << '\n';

	// Subscripting operator
	Node* test = list[3];
	if (test)
		std::cout << "Result: " << test->val << '\n';

	return 0;
}