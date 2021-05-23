build:
	cc src/*.c src/object/*.c -framework IOKit -framework Cocoa -framework OpenGL `pkg-config --libs --cflags raylib` -o ./bin/PhysicsSimulator
run:
	./bin/PhysicsSimulator
