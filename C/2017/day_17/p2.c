struct animator
{
	Texture *tex;
	size_t offset;
	size_t current;
	double rotation;
};
struct entity
{
	size_t status;
	Rectangle frame;
	struct animator anim;
	struct animation *a_set;
};

struct entity *init_entitiy(void)
{
	struct enity *res;
	size_t	cycle;

	res = malloc(sizeof(*res));
	//stuff;

	res->a_set = get_animate_ent1();
}

struct animation
{
	texture	**anims;
};


 animate_ent1(struct animator *dest, size_t status)
{
	static struct animation *a_set;

	if (a_set == NULL)
		init_set1(&a_set);
	//Some boudns checking here,
	dest->tex = a_set[status].anims[dest->current];
	dest->current++;
}
