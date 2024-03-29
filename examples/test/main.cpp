#include "chokoballs.hpp"
#include "chokolait.hpp"

namespace CB = ChokoBalls;
namespace CE = ChokoEngine;

CB::World world;
CB::Object_Rigidbody cube;

CE::SceneObject ball_display;

bool play = true;

void reset() {
	cube->position = glm::vec3(-3, 0, 1);
	cube->rotation = glm::identity<glm::quat>();
	cube->velocity = glm::vec3(
		CE::Random::Value() * 2 - 1,
		0,//CE::Random::Value() * 3,
		CE::Random::Value() * 2 - 1
	) * 0.2f;
	cube->rotVelocity = glm::identity<glm::quat>();/* CE::Quat::FromEuler(CE::Vec3(
		0,//CE::Random::Value() * 2 - 1,
		0,//CE::Random::Value() * 2 - 1,
		1//CE::Random::Value() * 2 - 1
	).normalized() * 180.f);*/
}

void apply() {
	const auto& tr = ball_display->transform();
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

	CE::ChokoLait::Init(500, 500);

	world = CB::World::New();
	//world->timeScale = 0.1f;

	cube = CB::Object_Collider_Sphere::New(1.f);
	world->AddObject(cube);

	const auto mapmesh = CE::MeshLoader::LoadObj(CE::IO::path() + "../../resources/map1.obj");

	auto map = CB::Object_Collider_Mesh::New();
	map->vertices.resize(mapmesh->vertexCount());
	std::memcpy(map->vertices.data(), mapmesh->positions().data(), mapmesh->vertexCount() * sizeof(glm::vec3));
	map->triangles.resize(mapmesh->triangleCount());
	std::memcpy(map->triangles.data(), mapmesh->triangles().data(), mapmesh->triangleCount() * sizeof(glm::ivec3));
	map->dynamic = false;
	world->AddObject(map);

	reset();

	ball_display = CE::ChokoLait::scene->AddNewObject();
	auto rend = ball_display->AddComponent<CE::MeshRenderer>();
	auto mesh = CE::MeshLoader::LoadObj(CE::IO::path() + "../../resources/ball.obj");
	rend->mesh(mesh);
	auto tex = CE::Texture::New(CE::IO::path() + "../../resources/test.jpg");
	auto shad = CE::Shader::New(
		CE::IO::ReadFile(CE::IO::path() + "../../resources/vert.txt"),
		CE::IO::ReadFile(CE::IO::path() + "../../resources/fragd.txt"));
	shad->RegisterStandardUniforms();
	shad->AddUniform("tex", CE::ShaderVariableType::Texture);
	auto mat = CE::Material::New();
	mat->shader(shad);
	mat->SetUniform("tex", tex);
	rend->materials({ mat });

	auto map_display = CE::ChokoLait::scene->AddNewObject();
	rend = map_display->AddComponent<CE::MeshRenderer>();
	rend->mesh(mapmesh);
	rend->materials({ mat });

	auto camera = CE::ChokoLait::scene->AddNewObject();
	camera->AddComponent<CE::Camera>();
	camera->transform()->localPosition(CE::Vec3(0, 7, -15));
	camera->transform()->localRotationEuler(CE::Vec3(30, 0, 0));

	auto light = CE::ChokoLait::scene->AddNewObject();
	light->transform()->localPosition(CE::Vec3(10, 10, 10));
	auto lc = light->AddComponent<CE::Light>(CE::LightType::Point);
	lc->strength(10.f);
	lc->shadow(true);
	lc->shadowSamples(1);
	lc->distance(30.f);

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
