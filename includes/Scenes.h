#ifndef SCENES_H
# define SCENES_H

# include "Sphere.h"
# include "Light_and_Shading.h"

typedef struct  s_obj
{
    t_sp            *sp;
    struct s_obj    *next;
    struct s_obj    *prev;
}               t_obj;

typedef struct  s_lights
{
    t_pt_light      light_src;
    t_sight         sig;
    struct s_lights *next;
    struct s_lights *prev;
}               t_lights;

typedef struct  s_world
{
    t_obj       *obj_lst;
    t_lights    *lights_lst;
}               t_world;

t_world *world(void);

void    create_obj_lst(t_world *world);

#endif
