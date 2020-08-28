#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

void Impl_Object::ApplyForces(
        pObject o,
        _World* w) {
    const auto& A = o->rigidbody.accel;
    const auto dt = w->deltaTime * w->timeScale;
    const auto& V = o->rigidbody.velocity += A * dt;
    o->position += V * dt + A * dt * dt;
    /*
    const auto& T = o->torque;
    const auto W = o->rotVelocity *=
        glm::slerp(glm::identity<glm::quat>(), T, dt);
    o->rotation = glm::normalize(
        o->rotation *
        glm::slerp(glm::identity<glm::quat>(), W, dt) *
        glm::slerp(glm::identity<glm::quat>(), T, dt * dt));
    */
}

void Impl_Object::AddForceAt(
        pObject o,
        float f,
        const glm::vec3& p,
        const glm::vec3& d) {
    o->rigidbody.accel += d * f * o->rigidbody.inverseMass;
    /*
    const auto rv = p - o->position;
    const auto r = glm::length(rv);
    const auto cth = glm::dot(d, rv / r);
    const auto sth = std::sqrt(std::max(1 - cth * cth, 0.f));
    if (sth > 0) {
        o->torque += glm::angleAxis(f * r * sth,
            glm::normalize(glm::cross(d, rv))) * o->inverseMoment;
    }
    */
}

void Impl_Object::AddImpulseAt(
        pObject o,
        float a,
        const glm::vec3& p,
        const glm::vec3& d) {
    //o->accel += d * a;
    o->rigidbody.velocity += d * a;
    /*
    const auto rv = p - o->position;
    const auto r = glm::length(rv);
    const auto cth = glm::dot(d, rv / r);
    const auto sth = std::sqrt(std::max(1 - cth * cth, 0.f));
    if (sth > 0) {
        o->rotVelocity += glm::angleAxis(a * r * sth,
            glm::normalize(glm::cross(d, rv)));
    }
    */
}

void Impl_Object::AddOffsetAt(
        pObject o,
        float s,
        const glm::vec3& p,
        const glm::vec3& d,
        float idt) {
    //o->accel += d * a;
    const auto v = s * idt;
    o->position += d * s;



    //o->velocity += d * v;
    /*
    const auto rv = p - o->position;
    const auto r = glm::length(rv);
    const auto cth = glm::dot(d, rv / r);
    const auto sth = std::sqrt(std::max(1 - cth * cth, 0.f));
    if (sth > 0) {
        o->rotVelocity += glm::angleAxis(a * r * sth,
            glm::normalize(glm::cross(d, rv)));
    }
    */
}

CB_END_NAMESPACE