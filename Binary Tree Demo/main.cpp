#include <iostream>
#include <sstream>
#include <string>
#include "binary-tree.hpp"

template <typename T>
void print_tree(const std::string &prefix, tree_node<T> *node, bool is_left)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << "|--";
		std::cout << node->m_key << std::endl;

		print_tree(prefix + (is_left ? "|   " : "    "), node->m_left, true);
		print_tree(prefix + (is_left ? "|   " : "    "), node->m_right, false);
	}
}

template <typename T>
void print_tree(binary_tree<T> &tree)
{
	print_tree("", tree.root(), false);
}

int main()
{
	std::string input = "bomba, akrobata, pies, egzamin, kot, zebra, kot, ametyst, beczka, albinos";
	std::istringstream ss(input);
	std::string token;

	binary_tree<std::string> tree;

	while (std::getline(ss, token, ',')) {
		tree.insert(token);
	}

	print_tree(tree);
}