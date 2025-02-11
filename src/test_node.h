#ifndef TEST_NODE
#define TEST_NODE

#include <godot_cpp/classes/node.hpp>

namespace godot {

class TestNode : public Node {
    GDCLASS(TestNode, Node)

protected:
    static void _bind_methods();
public:
    TestNode();
    ~TestNode();
    void _ready() override;
    float sum(float a, float b);
};

}

#endif
