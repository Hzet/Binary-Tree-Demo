#pragma once
#include <cstdint>

template <typename T>
struct tree_node
{
	tree_node *m_left;
	tree_node *m_right;
	T m_key;
};

template <typename T>
class binary_tree
{
public:
	binary_tree();
	~binary_tree();

	tree_node<T>* root();
	void insert(T key);
	std::size_t size() const;
	bool is_empty() const;

private:
	static void delete_node(tree_node<T> *node);

	tree_node<T> *m_root;
	std::size_t m_size;
};

template <typename T>
void binary_tree<T>::delete_node(tree_node<T> *node)
{
	if (node == nullptr)
		return;

	if (node->m_left != nullptr)
		delete_node(node->m_left);
	else
	{
		delete node->m_left;
		node->m_left = nullptr;
	}

	if (node->m_right != nullptr)
		delete_node(node->m_right);
	else
	{
		delete node->m_right;
		node->m_right = nullptr;
	}

	delete node;
	node = nullptr;
}

template <typename T>
binary_tree<T>::binary_tree()
	: m_root(nullptr)
	, m_size(0)
{
}

template <typename T>
binary_tree<T>::~binary_tree()
{
	delete_node(m_root);
	m_size = 0;
}

template <typename T>
tree_node<T>* binary_tree<T>::root()
{
	return m_root;
}

template <typename T>
void binary_tree<T>::insert(T key)
{
	m_size++;

	tree_node<T> *node = new tree_node<T>{ nullptr, nullptr, key };
	tree_node<T> *y = nullptr;
	tree_node<T> *x = m_root;

	while (x != nullptr)
	{
		y = x;
		if (node->m_key < x->m_key)
			x = x->m_left;
		else
			x = x->m_right;
	}

	if (y == nullptr)
		m_root = node;
	else
	{
		if (node->m_key < y->m_key)
			y->m_left = node;
		else
			y->m_right = node;
	}
}

template <typename T>
std::size_t binary_tree<T>::size() const
{
	return m_size;
}

template <typename T>
bool binary_tree<T>::is_empty() const
{
	return m_size == 0;
}