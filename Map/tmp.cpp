{
	Node<T> *tmp = find_val(tree, val);
	if (!tmp)
		std::cout << RED << "ERROR: Node Not Find\n" << NC;
	else
	{
		Node<T> *left = tmp->left;
		Node<T> *right = tmp->right;
		if (!right && !left)
		{
			while (tree->right->value != val && tree->left->value != val)
			{
				if (val < tree->value && tree->left)
					tree = tree->left;
				else if (val > tree->value && tree->right)
					tree = tree->right;
			}
			if (val < tree->value && tree->left)
			{
				delete tree->left;
				tree->left = NULL;
			}
			else if (val > tree->value && tree->right)
			{
				delete tree->right;
				tree->right = NULL;
			}
			return;
		}
		delete tmp;
		tmp = NULL;
		if (!right)
			*tmp = *left;
		else
		{
			*tmp = *right;
			while (tmp)
			{
				if (left->value < tmp->value && tmp->left)
					tmp = tmp->left;
				else if (left->value > tmp->value && tmp->right)
					tmp = tmp->right;
				else
					break;
			}
			Node<T> *new_node = new Node<T>;
			new_node = left;
			if (left->value < tmp->value)
				tmp->left = new_node;
			else
				tmp->right = new_node;
		}
	}
}