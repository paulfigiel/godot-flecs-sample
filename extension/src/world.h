#ifndef WORLD_CLASS_H
#define WORLD_CLASS_H

#include <godot_cpp/classes/ref.hpp>
#include <flecs/flecs.h>
#include <flecs_module.h>

namespace FlecsModule
{
    class World : public godot::RefCounted
    {
        GDCLASS(World, godot::RefCounted);

    protected:
        static void _bind_methods();
        flecs::world world;

    public:
        World();
        ~World();
        void progress();
        flecs::world *get_world();
        godot::String to_json();
    };
}
#endif // WORLD_CLASS_H