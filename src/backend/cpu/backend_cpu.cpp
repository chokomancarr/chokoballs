#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

void Backend_CPU::Dispatch(Backend_CPU& b) {

}

Backend_CPU::Backend_CPU() {}

CB_STATUS Backend_CPU::BeginUpdate(World* const world) {
	objects = world->objects;
	tree = BVHBuilder::Generate(objects);
	computeThread = std::thread(Dispatch, *this);
	return CB_STATUS::OK;
}

CB_STATUS Backend_CPU::FinishUpdate(World& world) {
	computeThread.join();
}

CB_END_NAMESPACE