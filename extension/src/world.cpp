#include "world.h"
#include <godot_cpp/core/class_db.hpp>
#include <flecs/flecs.h>
#include <godot_cpp/variant/utility_functions.hpp>
#include <flecs_module.h>

namespace FlecsModule
{
    World::World()
    {
        world = flecs::world();
        world.import<godot_flecs>();
        world.set<flecs::Rest>({});
        world.import <flecs::monitor>();
    }

    World::~World()
    {
    }

    flecs::world *World::get_world()
    {
        return &world;
    }

    void World::progress()
    {
        world.progress();
    }

    godot::String World::to_json()
    {
        return godot::String(world.to_json());
    }

    void World::_bind_methods()
    {
        godot::ClassDB::bind_method(godot::D_METHOD("progress"), &World::progress);
        godot::ClassDB::bind_method(godot::D_METHOD("to_json"), &World::to_json);
    }
}