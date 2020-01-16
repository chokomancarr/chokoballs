#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

_World::_World() : deltaTime(1.f / 20), timeScale(1), gravity(-9.81f), objects() {}

void _World::Clear() {
	objects.clear();
}

void _World::AddObject(const Object& o) {
	objects.push_back(o);
}

void _World::RemoveObject(const Object& o) {
	auto it = std::find(objects.begin(), objects.end(), o);
	if (it != objects.end()) {
		std::swap(*it, objects.back());
		objects.pop_back();
	}
}

CB_STATUS _World::BeginUpdate() {
	auto res = ChokoBalls::backend->BeginUpdate(this);
	//ensure lock here?
	return res;
}

CB_STATUS _World::FinishUpdate() {
	std::lock_guard<std::mutex> lock(update_mutex);
	return ChokoBalls::backend->FinishUpdate(this);
}

CB_END_NAMESPACE