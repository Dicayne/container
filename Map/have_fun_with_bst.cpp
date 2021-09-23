/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/23 18:45:42 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>
#include "../Utils/colors.hpp"
#define COUNT 10

template<class T>
struct	Node
{
	Node*	left;
	Node*	right;
	T		value;
};

template<class T>
void	place(Node<T> *n, Node<T> **tree)
{
	Node<T> *previous;
	Node<T> *curent = *tree;

	if (!*tree)
		*tree = n;
	else
	{
		while (curent)
		{
			previous = curent;
			if (n->value < curent->value)
				curent = curent->left;
			else if (n->value > curent->value)
				curent = curent->right;
		}
		if (n->value < previous->value)
			previous->left = n;
		if (n->value > previous->value)
			previous->right = n;
	}
}

template<class T>
void	push(Node<T> **tree, T val)
{
	Node<T> *n = new Node<T>;

	n->left = NULL;
	n->right = NULL;
	n->value = val;

	place(n, tree);
}

template<class T>
void	display(Node<T> *tree)
{
	if (tree)
	{
		if (tree->left)
			display(tree->left);
		std::cout << tree->value << "  ";
		if (tree->right)
			display(tree->right);
	}
}

template<class T>
Node<T>	*find_val(Node<T> *tree, T val)
{
	Node<T> *ret = tree;

	while (ret)
	{
		if (val < ret->value)
			ret = ret->left;
		else if (val > ret->value)
			ret = ret->right;
		else
			break;
	}
	if (!ret)
		std::cout << RED << "ERROR: Node not Found\n" << NC;
	return (ret);
}

template<class T>
void erase(Node<T> **tree, T val)
{
	Node<T> *curent = *tree;
	Node<T> *tmp = find_val(*tree, val);

	if (!tmp)
		return;

	Node<T> *left = tmp->left;
	Node<T> *right = tmp->right;

	if (val == curent->value)
	{
		*tree = right;
		if (left)
			place(left, tree);
		delete (tmp);
	}
	else
	{
		while(curent != tmp)
		{
			if(curent->right == tmp || curent->left == tmp)
				break;
			if(tmp->value >= curent->value)
				curent = curent->right;
			else
				curent = curent->left;
		}

		if(curent->right == tmp)
			curent->right = right;
		else
			curent->left = right;
		if(left)
			place(left, tree);
		delete tmp;
	}
}

template<class T>
void clear(Node<T> **tree)
{
	Node<T> *tmp = *tree;
	while (tmp)
		erase(&tmp, tmp->value);
	*tree = NULL;
}

template<class T>
void	print2DUtil(Node<T> *root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	print2DUtil(root->right, space);
	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout <<root->value << "\n";

	print2DUtil(root->left, space);
}

template<class T>
void	print2D(Node<T> *root)
{
	std::cout << "--------------------------------------------------------\n";
	if (!root)
		std::cout << "BST is Empty\n";
	print2DUtil(root, 0);
	std::cout << "--------------------------------------------------------\n";
}

int main()
{
	std::cout << YELLOW << "TEST BST\n" << NC;

	Node<char> *tree = NULL;
	std::string cmd;

	std::cout << "Choose command (push, quit, display, clear, erase) :";
	while (cmd != "quit")
	{
		cmd = "";
		std::cin >> cmd;
		if (cmd == "push")
		{
			std::cout << "Enter the integer you want to store: ";
			char value;
			std::cin >> value;
			push(&tree, value);
		}
		else if (cmd == "display")
			print2D(tree);
		else if (cmd == "erase")
		{
			std::cout << "Enter the integer you want to erase: ";
			char value;
			std::cin >> value;
			erase(&tree, value);
		}
		else if (cmd == "clear")
			clear(&tree);
		else if (cmd == "quit")
			break;
		else
			std::cout << "Wrong command\n";
		std::cout << "\nChoose command (push, quit, display, clear, erase) :";
	}
	return (0);
}
