#include <stdio.h>
//ß(ƒm[ƒh)
struct node {
	char name;
	struct node* left, * right;
};
int depth(const struct node* p)
{
	if (p) {
		const int n = depth(p->left );
		const int m = depth(p->right);
		return 1 + (n > m ? n : m);
	}
	else
		return 0;
}
void print_node(const struct node* p, int target_depth, int current_depth, int tree_height)
{
	if (current_depth < target_depth) {
		++current_depth;
		print_node(p ? p->left  : NULL, target_depth, current_depth, tree_height);
		print_node(p ? p->right : NULL, target_depth, current_depth, tree_height);
	}
	else {
		const int n = (1 << (tree_height - target_depth - 1));
		printf("%*c%*s", n, p ? p->name : ' ', n, "");
	}
}
void print_tree(const struct node* p)
{
	const int tree_height = depth(p);
	for (int i = 0; i < tree_height; ++i) {
		print_node(p, i, 0, tree_height);
		putchar('\n');
	}
}
//ƒvƒƒOƒ‰ƒ€—á‚P
int main()
{
	struct node a = { 'a'         }
	,           b = { 'b'         }
	,           c = { 'c'         }
	,           B = { 'B', &a, &b }
	,           A = { 'A', &B, &c }
	, * t = &A;
	printf("yˆ—‘Oz\n"); print_tree(t);
	A.left  = &b;
	B.right = &A;
	t       = &B;
	printf("yˆ—Œãz\n"); print_tree(t);
}
