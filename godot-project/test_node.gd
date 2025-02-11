extends TestNode


func _enter_tree() -> void:
    var a = 10
    var b = 15
    print("%d + %d = %d" % [a, b, sum(a, b)])
