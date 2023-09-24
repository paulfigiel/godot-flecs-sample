#include "register_types.h"
#include "world.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <flecs/flecs.h>
#include <rendering.h>

using namespace godot;

namespace FlecsModule
{
	void initialize(ModuleInitializationLevel p_level)
	{
		if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		{
			return;
		}
		ClassDB::register_class<World>();
		ClassDB::register_class<Rendering>();
	}

	void uninitialize(ModuleInitializationLevel p_level)
	{
		if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		{
			return;
		}
	}

	extern "C"
	{
		GDExtensionBool GDE_EXPORT flecs_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
		{
			GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

			init_obj.register_initializer(initialize);
			init_obj.register_terminator(uninitialize);
			init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

			return init_obj.init();
		}
	}
}