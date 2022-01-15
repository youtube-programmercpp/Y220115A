struct node {
	char name;
	struct node* left, * right;
};
void print_node(const char* label, const struct node* p);
int main()
{
	struct node * t = &(struct node)
	{ 'A'
	, &(struct node)
		{ 'B'
		,& (struct node){'a'}
		,& (struct node){'b'}
		}
	, &(struct node){'c'}
	};
	print_node("yˆ—‘Oz\n", t);
	struct node* B = t->left;
	t->left  = B->right;
	B->right = t       ;
	t = B;
	print_node("yˆ—Œãz\n", t);
}
