run:
	./build/PhysicsSimulator
compile:
	cmake --build ./build
test:
	cmake --build ./build
	./build/PhysicsSimulator
