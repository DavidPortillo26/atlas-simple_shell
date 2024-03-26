#ifndef LISTS_H
#define LISTS_H
/**
 * struct node - node to traverse the PATH
 * @dir: directories in the shell
 * @next: next node
 * Return: PATH
*/
struct node
{
	char *dir;
	struct node *next;
};
int main(int argc, char *argv[]);


#endif
