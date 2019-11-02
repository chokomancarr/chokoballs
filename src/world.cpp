#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

World::World() : deltaTime(1.f / 20), timeScale(1), objects() {}

void World::Clear() {
	objects.clear();
}

void World::AddObject(const pObject& o) {
	objects.push_back(o);
}

void World::RemoveObject(const pObject& o) {
	auto it = std::find(objects.begin(), objects.end(), o);
	if (it != objects.end()) {
		std::swap(*it, objects.back());
		objects.pop_back();
	}
}

CB_STATUS World::BeginUpdate() {
	return ChokoBalls::backend->BeginUpdate(this);
}

CB_STATUS World::FinishUpdate() {
	return ChokoBalls::backend->FinishUpdate(*this);
}

CB_END_NAMESPACE