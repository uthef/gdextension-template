#include "register_types.h"
#include "test_node.h"

void initialize_module(ModuleInitializationLevel level) {
    if (level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    GDREGISTER_CLASS(TestNode)
}

void terminate_module(ModuleInitializationLevel level) {
    if (level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
    GDExtensionBool GDE_EXPORT gdextension_library_init(
        GDExtensionInterfaceGetProcAddress proc_address, 
        const GDExtensionClassLibraryPtr p_library, 
        GDExtensionInitialization* r_init) {
            godot::GDExtensionBinding::InitObject init_obj(proc_address, p_library, r_init);

            init_obj.register_initializer(initialize_module);
            init_obj.register_terminator(terminate_module);
            init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

            return init_obj.init();
    }
}
