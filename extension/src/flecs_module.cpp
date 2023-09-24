#include <flecs_module.h>
#include <godot_cpp/classes/resource_loader.hpp>

using namespace godot;

namespace FlecsModule
{
    godot_flecs::godot_flecs(flecs::world &ecs)
    {
        ecs.module<godot_flecs>();
        ecs.component<Position>();
        ecs.component<Velocity>();
        ecs.component<Color>();

        ecs.system<Position, const Velocity>("Move")
            .each([](Position &p, const Velocity &v)
                  {    
            p.x += v.x;
            p.y += v.y;
            p.z += v.z; });

        ecs.system<Velocity>("Gravity")
            .each([](Velocity &v)
                  { v.y -= 0.01; });

        ecs.system<Velocity, const Position>("Bounce")
            .each([](Velocity &v, const Position &p)
                  { 
            if(p.x < 100 && p.x > -100 && p.z < 100 && p.z > -100 && p.y < 0){
                v.y = -v.y;
            } });

        ecs.system<Velocity>("Damping")
            .each([](Velocity &v)
                  {    
            v.x = v.x * 0.99;
            v.y = v.y * 0.99;
            v.z = v.z * 0.99; });

        ecs.system<const Color, const MultiMeshInstance>("RenderColor")
            .each([](flecs::iter &it, size_t index, const Color &c, const MultiMeshInstance &i)
                  { RenderingServer::get_singleton()->multimesh_instance_set_color(i.id, index, godot::Color(c.r, c.g, c.b)); });

        ecs.system<Color, const Position>("ColorIsPosition")
            .each([](flecs::iter &it, size_t index, Color &c, const Position &p)
                  {    
            Vector3 myVector(p.x, p.y, p.z);
            myVector.normalize();
            c.r = myVector.x;
            c.g = myVector.y;
            c.b = myVector.z; });

        ecs.system<const Position, const MultiMeshInstance>("Render")
            .each([](flecs::iter &it, size_t index, const Position &p, const MultiMeshInstance &i)
                  { RenderingServer::get_singleton()->multimesh_instance_set_transform(i.id, index, Transform3D(Basis(), Vector3(p.x, p.y, p.z))); });
    }

}