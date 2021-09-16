/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/16 19:31:44 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>
#include "../Utils/colors.hpp"


int test = 0;
int ok = 0;
int ko = 0;
#define COUNT 10

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

template<class T>
void print2DUtil(Node<T> *root, int space)
{
	if (root == NULL)
		return;

	space += COUNT;

	print2DUtil(root->right, space);

	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout<<" ";
	std::cout<<root->value<<"\n";

	print2DUtil(root->left, space);
}

template<class T>
void print2D(Node<T> *root)
{
	print2DUtil(root, 0);
}

template<class T>
Node<T> *find_val(Node<T> *tree, T val)
{
	bool find = false;

	while (find == false)
	{
		if (val < tree->value && tree->left)
			tree = tree->left;
		else if (val > tree->value && tree->right)
			tree = tree->right;
		else if (val == tree->value)
			find = true;
		else if (!tree->right && !tree->left)
		{
			tree = NULL;
			break;
		}
	}
	return (tree);
}

template<class T>
void place(Node<T> *tmp, Node<T> *tree)
{
	Node<T> *courant = tree;
	Node<T> *precedent = NULL;

	// Si tree est vide, ça va très vite :
	if(tree == NULL)
	{
		tree = tmp;
		return;
	}

	// On se fraye un chemin jusqu'a une place vide
	while(courant)
	{
		precedent = courant;
		if(tmp->value < courant->value)
			courant = courant->left;
		else
			courant = courant->right;
	}

	// Hop, on a trouvé une place libre, et precedent pointe vers le parent de notre tmp à replacer.
	if(tmp->value < precedent->value)
		precedent->left = tmp;
	else
		precedent->right = tmp;
}

template<class T>
void erase(Node<T> *tmp, Node<T> *tree)
{
	Node<T> *droite = tmp->right;
	Node<T> *gauche = tmp->left;
	Node<T> *courant = tree;

	// Cas délicat : si on supprime la racine?
	if(tmp == tree)
	{
		*tree = *droite;
		if(gauche) place(gauche, tree);
		delete tmp;
		return;
	}

	while(courant)
	{
		if(courant->right == tmp
			|| courant->left == tmp)
			break;

		if(tmp->value >= courant->value)
			courant = courant->right;
		else
			courant = courant->left;
	}

	// Courant pointe maintenant vers le tmp précédent le tmp à supprimer.
	if(courant->right == tmp)
		courant->right = droite;
	else
		courant->left = droite;

	// Et puis on replace l'autre fils du tmp disparu
	if(gauche) place(gauche, tree);

	// Enfin, on libère l'objet tmp de ses obligations
	delete tmp;
}

int main()
{
	std::cout << YELLOW << "TEST BST\n\n" << NC;

	Node<int> *tree = new Node<int>;

	tree->value = 8;
	tree->left = NULL;
	tree->right = NULL;

	push(tree, 5);
	push(tree, 3);
	push(tree, 1);
	push(tree, 10);
	push(tree, 6);
	push(tree, 7);
	push(tree, 11);
	push(tree, 4);
	push(tree, 2);
	push(tree, 9);
	push(tree, 12);
	push(tree, 9);

	// display(tree);
	print2D(tree);
	std::cout << "\n--------------------------------------------------------\n";

	// ft_erase(tree, 3);


	Node<int> *n = find_val(tree, 8);
	erase(n, tree);

	print2D(tree);
	std::cout << "\n--------------------------------------------------------\n";
	// ft_erase(tree, n);
	return (0);
}