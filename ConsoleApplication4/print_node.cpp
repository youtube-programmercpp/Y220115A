#include <iostream>
#include <iomanip>
struct node {
	char name;
	node* left, * right;

	int depth() const
	{
		const int n = left  ? left ->depth() : 0;
		const int m = right ? right->depth() : 0;
		return 1 + (n > m ? n : m);
	}
	struct rasterizer {
		std::ostream& ostm        ;
		int           tree_height ;
		int           target_depth;
		int width(int current_depth) const
		{
			return 1 << (tree_height - current_depth - 1);
		}
		void print_name(char name) const
		{
			const int n = width(target_depth);
			ostm << std::setw(n) << name << std::setw(n) << ' ';
		}
		void print_spaces(int current_depth) const
		{
			ostm << std::setw(width(current_depth - 1)) << ' ';
		}
		std::ostream& print(const node& r_node)
		{
			for (; target_depth < tree_height; ++target_depth) {
				r_node.print_node(0, *this);
				ostm << '\n';
			}
			return ostm;
		}
	};
	void print_node(int current_depth, const struct rasterizer& r) const
	{
		if (current_depth < r.target_depth) {
			if (left) {
				left->print_node(current_depth + 1, r);
				if (right)
					right->print_node(current_depth + 1, r);
				else
					r.print_spaces(current_depth + 1);
			}
			else if (right) {
				r.print_spaces(current_depth + 1);
				right->print_node(current_depth + 1, r);
			}
			else
				r.print_spaces(current_depth);
		}
		else
			r.print_name(name);
	}
	friend std::ostream& operator<<(std::ostream& ostm, const node& r)
	{
		return rasterizer{ ostm, r.depth() }.print(r);
	}
};
node* ポインタを付け替え(node* A)
{
	node* const B = A->left ;
	A->left       = B->right;
	B->right      = A       ;
	B->left = nullptr;
	return B;
}
extern "C" void print_node(const char* label, const node * p)
{
	std::cout << label << *p;
}
