extends Node


var world:World
var entityCount:int
var rng
@export var r:Rendering

func _ready() -> void:
	world = World.new()
	rng = RandomNumberGenerator.new()

func _process(_delta):
	spawnEntity(10)
	world.progress()

func spawnEntity(count):
	for i in count:
		r.spawn_entity(world,str("Entity",entityCount),
		rng.randf_range(-50.0, 50.0),
		rng.randf_range(0.0, 10.0),
		rng.randf_range(-50.0, 50.0),
		rng.randf_range(-1, 1),
		rng.randf_range(-0.1, 0.1),
		rng.randf_range(-1, 1))
		entityCount+=1
