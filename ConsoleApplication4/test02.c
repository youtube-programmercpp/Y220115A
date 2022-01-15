#include <stdio.h>
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
//プログラム例２
struct node* ポインタを付け替え(struct node* A)
{
	struct node* B = A->left ;
	A->left        = B->right;
	B->right       = A       ;
	return B;
}
int main()
{
	struct node a = { 'a'         }
	,           b = { 'b'         }
	,           c = { 'c'         }
	,           B = { 'B', &a, &b }
	,           A = { 'A', &B, &c }
	, * t = &A;
	printf("【処理前】\n"); print_tree(t);
	t = ポインタを付け替え(t);
	printf("【処理後】\n"); print_tree(t);
}
