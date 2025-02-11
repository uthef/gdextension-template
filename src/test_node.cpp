#include "test_node.h"
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

TestNode::TestNode() {

}

TestNode::~TestNode() {

}

void TestNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("sum", "a", "b"), &TestNode::sum);
}

float TestNode::sum(float a, float b) {
    return a + b;
}

void TestNode::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) return;

    print_line(vformat("Hello from %s!", get_name()));
}
