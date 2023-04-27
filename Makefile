all:
	cc src/collision/collision.c src/object/object.c src/main.c -lraylib -o build/PhysicsSim
	./build/PhysicsSim
compile:
	cc src/collision/collision.c src/object/object.c src/main.c -lraylib -o build/PhysicsSim
test:
	cc src/collision/collision.c src/object/object.c src/main.c -lraylib -o build/PhysicsSim
	./build/PhysicsSim
