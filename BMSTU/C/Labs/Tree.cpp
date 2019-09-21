#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct node
{
	int key;
	struct node * l;
	struct node * r;
}node;

struct TB
{
	node * root;
};

node * generat(int a);
node * add(node * x, int a);
node * search(node * x, int a);
void del(node * x);
void print(node * x);
node * max(node * x);
node * min(node * x);
node * serchPRA(node * x, int a);
void delet(node * x, int a);

//int main(void)
//{
//	printf("\t%d\n", func(f1, 5, 'Z'));
//	
//	getchar();
//	return 0;
//}
//
//int f1(char c, int x)
//{
//	return (c - 100) * x;
//}
//
//int func(int(*f)(char, int), int x, char c)
//{
//	return f(c, x);
//}

int main(void)
{
	printf("###TREEE###\n");
	node * root = NULL;
	root = add(root, 3);

	add(root, 2);
	add(root, 4);

	print(root);
	printf("\nMAX~~~ %d", max(root)->key);
	printf("\nMIN~~~ %d", min(root)->key);

	//delet(root, 4);
	//print(root);
	//printf("\nPRA for 7 --- %d", serchPRA(root, 7)->key);
	printf("\n###########\n");
	//del(root);

	getchar();
	return 0;
}

node * generat(int a)
{
	node * n = (node *)malloc(sizeof(node));
	n->key = a;
	n->r = NULL;
	n->l = NULL;
	return n;
}

node * add(node * x, int a)
{
	if (!x)
	{
		x = generat(a);
		return x;
	}

	else
	{
		if (a > x->key)
		{
			if (x->r)
				return add(x->r, a);
			else
			{
				node * y = generat(a);
				x->r = y;
				return y;
			}
		}
		else if (a < x->key)
		{
			if (x->l)
				return add(x->l, a);
			else
			{
				node * y = generat(a);
				x->l = y;
				return y;
			}
		}
		else
			return x;
	}
}

node * search(node * x, int a)
{
	if (a > x->key)
	{
		if (x->r)
			return search(x->r, a);
		else
			return NULL;
	}
	else if (a < x->key)
	{
		if (x->l)
			return search(x->l, a);
		else
			return NULL;
	}
	else
		return x;
}

void del(node * x)
{
	if (x->l)
	{
		del(x->l);
	}
	if (x->r)
	{
		del(x->r);
	}
	free(x);
}

void print(node * x)
{
	if (x->l)
		print(x->l);
	else
	{
		printf("`%d", x->key);

		if (x->r)
			print(x->r);
		return;
	}

	printf("`%d", x->key);

	if (x->r)
		print(x->r);
}

node * max(node * x)
{
	if (x->r)
	{
		return max(x->r);
	}
	return x;
}

node * min(node * x)
{
	if (x->l)
	{
		return min(x->l);
	}
	return x;
}

void delet(node * x, int a)
{
	node * c = (node *)malloc(sizeof(node));
	c = search(x, a);

	node * n = (node *)malloc(sizeof(node));
	n = serchPRA(x, a);

	if (c->key)
	{
		if (!(c->l) && !(c->r))
		{
			if (n->l->key == a)
				n->l = NULL;

			else
				n->r = NULL;
		}
		else if (c->l || c->r)
		{
			if (c->l)
			{
				if (n->l->key == a)
					n->l = c->l;

				else
					n->r = c->l;
			}
			else
			{
				if (n->l->key == a)
					n->l = c->r;

				else
					n->r = c->r;
			}
		}
		else if (c->r && c->l)
		{
			node * q = (node *)malloc(sizeof(node));
			q = max(c->l);

			node * g = (node *)malloc(sizeof(node));
			g = min(c->r);

			if (abs(c->key - q->key) <= abs(c->key - q->key))
			{
				node * r = (node *)malloc(sizeof(node));
				r = serchPRA(x, q->key);

				if (n->l->key == a)
				{
					n->l = q;
					q->l = c->l;
					q->r = c->r;
				}
				else
				{
					n->r = q;
					q->l = c->l;
					q->r = c->r;
				}
			}
			else
			{
				if (n->l->key == a)
				{
					n->l = g;
					g->l = c->l;
					g->r = c->r;
				}
				else
				{
					n->r = g;
					g->l = c->l;
					g->r = c->r;
				}
			}
			free(q);
			free(g);
		}
		free(n);
		free(c);
	}
}

node * serchPRA(node * x, int a)
{
	if (a > x->key)
	{
		if (x->r)
		{
			if (x->r->key != a)
				return serchPRA(x->r, a);
			else
				return x;
		}
		else
			return NULL;
	}
	else if (a < x->key)
	{
		if (x->l)
		{
			if (x->l->key != a)
				return serchPRA(x->l, a);
			else
				return x;
		}
		else
			return NULL;
	}
	else
		return NULL;
}