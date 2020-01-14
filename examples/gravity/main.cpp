#include "chokoballs.hpp"
#include "chokolait.hpp"

namespace CB = ChokoBalls;
namespace CE = ChokoEngine;

CB::World world;
CB::Object_Rigidbody cube;

CE::SceneObject cube_display;

bool play = true;

void reset() {
    cube->position = glm::vec3();
    cube->rotation = glm::quat();
    cube->velocity = glm::vec3(
        CE::Random::Value() * 2 - 1,
        CE::Random::Value() * 3,
        CE::Random::Value() * 2 - 1
    );
    cube->rotVelocity = glm::vec3(
        CE::Random::Value() * 2 - 1,
        CE::Random::Value() * 2 - 1,
        CE::Random::Value() * 2 - 1
    ) * 3.1415f;
}

void apply() {
    const auto& tr = cube_display->transform();
    tr->localPosition(CE::Vec3(
        cube->position.x,
        cube->position.y,
        cube->position.z
    ));
    tr->localRotation(CE::Quat(
        cube->rotation.w,
        cube->rotation.x,
        cube->rotation.y,
        cube->rotation.z
    ));
}

int main() {
    CB::ChokoBalls::Init();

    world = CB::World::New();

    cube = CB::Object_Rigidbody::New();
    
    reset();

    CE::ChokoLait::Init(500, 500);

    cube_display = CE::ChokoLait::scene->AddNewObject();

    apply();

    while (CE::ChokoLait::alive()) {
        CE::ChokoLait::Update([]() {
            if (CE::Input::KeyDown(CE::InputKey::Enter)) {
                reset();
            }
            else if (CE::Input::KeyDown(CE::InputKey::Space)) {
                play = !play;
                world->FinishUpdate();
            }
            else {
                if (play) {
                    world->FinishUpdate();
                    apply();
                    world->BeginUpdate();
                }
            }
        });
        CE::ChokoLait::Paint();
    }
}