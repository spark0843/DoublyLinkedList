#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node
{
	int val;
	Node *next;
	Node *prev;

	Node() : val(NULL), next(nullptr), prev(nullptr) { }

	Node(int val) : next(nullptr), prev(nullptr)
	{
		this->val = val;
	}
};

class DoublyLinkedList
{
	Node *head;
	Node *tail;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) { }

	Node* top() const
	{
		return this->head;
	}

	Node* bottom() const
	{
		return this->tail;
	}

	bool isEmpty() const // O(1)
	{
		return this->head == NULL;
	}

	Node* operator[](int ind) // O(N)
	{
		unsigned int count = 0u;
		Node *ptr = this->head;

		while (ptr != nullptr)
		{
			if (count++ == ind)
			{
				return ptr;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		return nullptr;
	}

	Node* search(int val) const // O(N)
	{
		Node *node = this->head;
		while (node != nullptr)
		{
			if (node->val == val)
			{
				return node;
			}
			else
			{
				node = node->next;
			}
		}
		return nullptr;
	}

	void insert_before(Node *node, int val) // O(N)
	{
		if (node == this->head)
		{
			push_top(val);
		}
		else if (node == this->tail)
		{
			push_bottom(val);
		}
		else
		{
			Node* ptr = this->head;
			while (ptr != nullptr)
			{
				if (ptr == node) // if found
				{
					Node* newNode = new Node(val);

					newNode->next = ptr;
					newNode->prev = ptr->prev;
					newNode->prev->next = newNode;
					ptr->prev = newNode;

					break;
				}
				ptr = ptr->next;
			}
		}
	}

	void remove_top() // O(1)
	{
		Node *node = this->head;
		this->head = node->next;
		this->head->prev = nullptr;
		node = nullptr;
		delete node;
	}

	void remove_bottom() // O(1)
	{
		Node* node = this->tail;
		this->tail = node->prev;
		this->tail->next = nullptr;
		node = nullptr;
		delete node;
	}

	void push_top(int val) // O(1)
	{
		Node *newNode = new Node(val);
		if (isEmpty())
		{
			this->tail = newNode;
		}
		else
		{
			newNode->next = this->head;
			this->head->prev = newNode;
		}
		this->head = newNode;
	}

	void push_bottom(int val) // O(1)
	{
		Node* newNode = new Node(val);
		if (isEmpty())
		{
			this->head = newNode;
		}
		else
		{
			newNode->prev = this->tail;
			this->tail->next = newNode;
		}
		this->tail = newNode;
	}

	void print_list() const // O(N)
	{
		Node *node = head;
		while (node != nullptr)
		{
			std::cout << node->val << " ";
			node = node->next;
		}
	}
};

#endif