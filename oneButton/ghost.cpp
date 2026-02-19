#include "ghost.h"
#include "Game.h"
#include "input.h"
#include <random>

using namespace std;
using namespace DirectX::SimpleMath;

void ghost::Init()
{
	m_Texture2D.Init();
	m_Texture2D.SetTexture("assets/texture/ghost.png");
	m_Texture2D.SetPosition(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetRotation(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetScale(100.0f, 200.0f, 2.0f);

	m_Texture2D.SetSpriteSheet(4, 2);

	const int col = m_PicNum % 4;
	const int row = m_PicNum / 4;
	m_Texture2D.SetUV(
		static_cast<float>(col + 1),
		static_cast<float>(row + 1),
		4.0f,
		2.0f);

}

void ghost::Update()
{
	m_Texture2D.Update();
	//Control();
}

void ghost::Draw(Camera* cam)
{
	m_Texture2D.Draw(cam);
}
void ghost::Uninit()
{
	m_Texture2D.Uninit();
}

void ghost::Control(float res)
{
	static std::mt19937 rng{ std::random_device{}() };
	static std::uniform_int_distribution<int> dist(0, 7);
	m_PicNum = dist(rng);

	const int col = m_PicNum % 4;
	const int row = m_PicNum / 4;
	m_Texture2D.SetUV(
		static_cast<float>(col + 1),
		static_cast<float>(row + 1),
		4.0f,
		2.0f);

	float x = static_cast<float>(rand() % 200 - 200); // -200.0f ~ 0.0f 
	float y = res * -300; // -100.0f ~ 100.0f
	m_Texture2D.SetPosition(x, y, 0.0f);

	const Vector3 baseScale(100.0f, 200.0f, 2.0f);
	const float minScale = 1.0f;
	const float scaleFactor = (std::max)(res * 5.0f, minScale);
	m_Texture2D.SetScale(
		baseScale.x * scaleFactor,
		baseScale.y * scaleFactor,
		baseScale.z);
}
