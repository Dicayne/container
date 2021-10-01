// {
// 	Node<T> *tmp = find_val(tree, val);
// 	if (!tmp)
// 		std::cout << RED << "ERROR: Node Not Find\n" << NC;
// 	else
// 	{
// 		Node<T> *left = tmp->left;
// 		Node<T> *right = tmp->right;
// 		if (!right && !left)
// 		{
// 			while (tree->right->value != val && tree->left->value != val)
// 			{
// 				if (val < tree->value && tree->left)
// 					tree = tree->left;
// 				else if (val > tree->value && tree->right)
// 					tree = tree->right;
// 			}
// 			if (val < tree->value && tree->left)
// 			{
// 				delete tree->left;
// 				tree->left = NULL;
// 			}
// 			else if (val > tree->value && tree->right)
// 			{
// 				delete tree->right;
// 				tree->right = NULL;
// 			}
// 			return;
// 		}
// 		delete tmp;
// 		tmp = NULL;
// 		if (!right)
// 			*tmp = *left;
// 		else
// 		{
// 			*tmp = *right;
// 			while (tmp)
// 			{
// 				if (left->value < tmp->value && tmp->left)
// 					tmp = tmp->left;
// 				else if (left->value > tmp->value && tmp->right)
// 					tmp = tmp->right;
// 				else
// 					break;
// 			}
// 			Node<T> *new_node = new Node<T>;
// 			new_node = left;
// 			if (left->value < tmp->value)
// 				tmp->left = new_node;
// 			else
// 				tmp->right = new_node;
// 		}
// 	}
// }

#include <iostream>
using namespace std;
struct Noeud
{
	int valeur;
	Noeud* fils_droite;
	Noeud* fils_gauche;
};
Noeud* arbre = NULL;

void Placer(Noeud* noeud)
{
	Noeud* courant = arbre;
	Noeud* precedent = NULL;

	// Si l'arbre est vide, ça va très vite :
	if(arbre == NULL)
	{
		arbre = noeud;
		return;
	}

	// On se fraye un chemin jusqu'a une place vide
	while(courant)
	{
		precedent = courant;
		if(noeud->valeur < courant->valeur)
			courant = courant->fils_gauche;
		else
			courant = courant->fils_droite;
	}

	// Hop, on a trouvé une place libre, et
	// precedent pointe vers le parent de notre
	// noeud à replacer.
	if(noeud->valeur < precedent->valeur)
		precedent->fils_gauche = noeud;
	else
		precedent->fils_droite = noeud;
}

void Ajouter(int valeur)
{
	// Création de notre nouveau noeud en mémoire
	Noeud* nouveau = new Noeud;
	nouveau->valeur = valeur;
	nouveau->fils_droite = NULL;
	nouveau->fils_gauche = NULL;

	// Puis on laisse Placer() le mettre à la bonne place
	Placer(nouveau);
}

Noeud* Rechercher(int valeur)
{
	Noeud* courant = arbre;
	while(courant)
	{
		if(valeur == courant->valeur)
			return courant;
		else if(valeur < courant->valeur)
			courant = courant->fils_gauche;
		else
			courant = courant->fils_droite;
	}

	return NULL;
}

void Supprimer(Noeud* noeud)
{
	Noeud* droite = noeud->fils_droite;
	Noeud* gauche = noeud->fils_gauche;
	Noeud* courant = arbre;

	// Cas délicat : si on supprime la racine?
	if(noeud == arbre)
	{
		arbre = droite;
		if(gauche) Placer(gauche);
		delete noeud;
		return;
	}

	while(courant)
	{
		if(courant->fils_droite == noeud || courant->fils_gauche == noeud)
			break;

		if(noeud->valeur >= courant->valeur)
			courant = courant->fils_droite;
		else
			courant = courant->fils_gauche;
	}

	// Courant pointe maintenant vers le noeud précédent le
	// noeud à supprimer.
	if(courant->fils_droite == noeud)
		courant->fils_droite = droite;
	else
		courant->fils_gauche = droite;

	// Et puis on replace l'autre fils du noeud disparu
	if(gauche) Placer(gauche);

	// Enfin, on libère l'objet noeud de ses obligations
	delete noeud;
}

void Afficher(Noeud* racine)
{
	if(racine->fils_gauche)
		Afficher(racine->fils_gauche);
	cout << racine->valeur << "\t";
	if(racine->fils_droite)
		Afficher(racine->fils_droite);
}

void print2DUtil(Noeud *root, int space)
{
	if (root == NULL)
		return;

	space += 10;

	print2DUtil(root->fils_droite, space);

	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout<<" ";
	std::cout<<root->valeur <<"\n";

	print2DUtil(root->fils_gauche, space);
}

void print2D(Noeud *root)
{
	print2DUtil(root, 0);
}

int main(void)
{
	Ajouter(10);
	Ajouter(4);
	Ajouter(15);
	Ajouter(2);
	Ajouter(16);
	Ajouter(1);
	Ajouter(9);
	Ajouter(14);

	Afficher(arbre);
	cout << "\n------------------------------------\n\n";

	Noeud* n = Rechercher(arbre->valeur);

	while (arbre)
	{
		n = Rechercher(arbre->valeur);
		Supprimer(n);
		print2D(arbre);
		cout << "\n------------------------------------\n\n";
	}
	return 0;
}
