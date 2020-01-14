#include "src/backend.hpp"

CB_BEGIN_NAMESPACE

void Impl_Object::ApplyForces(
        _Object_Rigidbody* o,
        _World* w) {
    const auto A = o->force / o->mass;
    const auto dt = w->deltaTime * w->timeScale;
    const auto& V = o->velocity += A * dt;
    o->position += V * dt + A * dt * dt;
};

CB_END_NAMESPACE