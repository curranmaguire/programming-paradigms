#ifndef langton_h
#define langton_h

enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct ant
{
    int x;
    int y;
    enum direction direction;
};

struct rule
{
    char *rules;
};

#define ant_is_at(x, y) (x == ant->x && y == ant->y ? 1 : 0)

enum colour
{
    WHITE,
    BLACK
};

enum colour2
{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o,
    p,
    q,
    r,
    s,
    t,
    u,
    v,
    w,
    x,
    y,
    z
};

void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);

void apply_rule(enum colour *colour, struct ant *ant);
void apply_rule_general(enum colour2 *colour, struct ant *ant, struct rule *rule);

#endif
