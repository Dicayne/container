/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/15 18:16:54 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>
#include "../Utils/colors.hpp"


int test = 0;
int ok = 0;
int ko = 0;

template<class T>
struct Node
{
	Node*	left;
	Node*	right;
	T		value;
};
template<class T>
void	push(Node<T> *tree, T val)
{
	if (val < tree->value)
	{
		if (tree->left != NULL)
			push(tree->left, val);
		else
		{
			Node<T> *new_node = new Node<T>;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->value = val;
			tree->left = new_node;
		}
	}
	else if (val > tree->value)
	{
		if (tree->right != NULL)
			push(tree->right, val);
		else
		{
			Node<T> *new_node = new Node<T>;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->value = val;
			tree->right = new_node;
		}
	}
}

template<class T>
void display(Node<T> *tree)
{
	if (tree->left)
		display(tree->left);
	std::cout << tree->value << std::endl;
	if (tree->right)
		display(tree->right);
}

int main()
{
	std::cout << YELLOW << "TEST BST\n\n" << NC;

	Node<int> tree;

	tree.value = 8;
	tree.left = NULL;
	tree.right = NULL;

	push(&tree, 3);
	push(&tree, 1);
	push(&tree, 5);
	push(&tree, 10);
	push(&tree, 6);
	push(&tree, 11);
	push(&tree, 7);
	push(&tree, 4);
	push(&tree, 2);
	push(&tree, 9);
	push(&tree, 12);

	display(&tree);
	return (0);
}