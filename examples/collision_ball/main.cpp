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
    cube->rotation = glm::identity<glm::quat>();
    cube->velocity = glm::vec3(
        CE::Random::Value() * 2 - 1,
        0,//CE::Random::Value() * 3,
        CE::Random::Value() * 2 - 1
    ) * 0.1f;
    cube->rotVelocity = glm::identity<glm::quat>();/* CE::Quat::FromEuler(CE::Vec3(
        0,//CE::Random::Value() * 2 - 1,
        0,//CE::Random::Value() * 2 - 1,
        1//CE::Random::Value() * 2 - 1
    ).normalized() * 180.f);*/
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
    CB::ChokoBalls::SetBackend(CB::BACKEND_TYPE::CPU);
    CB::ChokoBalls::Init();

    world = CB::World::New();
    //world->timeScale = 0.1f;

    cube = CB::Object_Collider_Sphere::New(1.f);
    world->AddObject(cube);

    auto ball = CB::Object_Collider_Sphere::New(1.f);
    ball->position = glm::vec3(0, -5, 0);
    ball->dynamic = false;
    world->AddObject(ball);

    reset();

    CE::ChokoLait::Init(500, 500);

    cube_display = CE::ChokoLait::scene->AddNewObject();
	auto rend = cube_display->AddComponent<CE::MeshRenderer>();
	auto mesh = CE::MeshLoader::LoadObj(CE::IO::path() + "../../resources/ball.obj");
	rend->mesh(mesh);
	auto tex = CE::Texture::New(CE::IO::path() + "../../resources/test.jpg");
	auto shad = CE::Shader::New(
		CE::IO::ReadFile(CE::IO::path() + "../../resources/vert.txt"),
		CE::IO::ReadFile(CE::IO::path() + "../../resources/frag.txt"));
	shad->RegisterStandardUniforms();
	shad->AddUniform("tex", CE::ShaderVariableType::Texture);
	auto mat = CE::Material::New();
	mat->shader(shad);
	mat->SetUniform("tex", tex);
	rend->materials({ mat });

    auto ball_display = CE::ChokoLait::scene->AddNewObject();
    ball_display->transform()->localPosition(CE::Vec3(0, -5, 0));
	rend = ball_display->AddComponent<CE::MeshRenderer>();
	rend->mesh(mesh);
	rend->materials({ mat });

	auto camera = CE::ChokoLait::scene->AddNewObject();
	camera->AddComponent<CE::Camera>();
	camera->transform()->localPosition(CE::Vec3(0, 0, -15));

    apply();

    while (CE::ChokoLait::alive()) {
        CE::ChokoLait::Update([]() {
            world->FinishUpdate();
            world->deltaTime = CE::Time::delta();
            if (CE::Input::KeyDown(CE::InputKey::Enter)) {
                reset();
                apply();
            }
            else if (CE::Input::KeyDown(CE::InputKey::Space)) {
                play = !play;
            }
            else {
                if (play) {
                    apply();
                    world->BeginUpdate();
                }
            }
        });
        CE::ChokoLait::Paint(0, []() {
            cube->bounce = CE::UI::I::Slider(CE::Rect(10, 10, 150, 20), CE::Vec2(0, 1), cube->bounce, CE::Color::green());
        });
        glfwSetWindowTitle(glfwGetCurrentContext(), std::to_string(int(1 / CE::Time::delta())).c_str());
    }
}
