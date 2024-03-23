#include <stdbool.h>

typedef struct room_s room_t;

typedef struct link_s {
    room_t *link;
    struct link_s *next;
} link_t;

struct room_s {
    char *name;
    int nb;
    int visited;

    link_t *links;

    bool (*validator)();
    void (*happen)();
};

typedef struct rooms_t {
    room_t *current;
    struct rooms_t *next;
} rooms_t;

typedef struct {
    room_t *current;
    rooms_t *rooms;
    int nb_rooms;
} graph_t;
