#ifndef RENDERING_CLASS_H
#define RENDERING_CLASS_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/multi_mesh_instance3d.hpp>
#include <flecs/flecs.h>
#include <world.h>
#include <flecs_module.h>

using namespace godot;

namespace FlecsModule
{
    class Rendering : public MultiMeshInstance3D
    {
        GDCLASS(Rendering, MultiMeshInstance3D);

    protected:
        static void _bind_methods();

    public:
        Rendering();
        ~Rendering();
        void spawn_entity(Ref<World> p_world, String name, float x, float y, float z, float vel_x, float vel_y, float vel_z);
        int spawned;
    };

#endif // RENDERING_CLASS_H
}