#ifndef GODOT_FLECS_MODULE_H
#define GODOT_FLECS_MODULE_H

#include <godot_cpp/core/class_db.hpp>
#include <flecs/flecs.h>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/classes/mesh.hpp>

namespace FlecsModule
{
    struct Position
    {
        float x, y, z;
    };

    struct Velocity
    {
        float x, y, z;
    };

    struct Color
    {
        float r, g, b;
    };

    struct MultiMeshInstance
    {
        godot::RID id;
    };

    struct godot_flecs
    {
        godot_flecs(flecs::world &world); // Ctor that loads the module
    };

}

#endif