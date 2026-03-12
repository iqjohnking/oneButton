#include "Attack.h"
#include "Game.h"
#include "input.h"

using namespace std;
using namespace DirectX::SimpleMath;

void Attack::Init()
{
	m_Texture2D.Init();
	m_Texture2D.SetTexture("assets/texture/attack.png");
	m_Texture2D.SetPosition(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetRotation(0.0f, 0.0f, 0.0f);

	m_Texture2D.SetSpriteSheet(1, 1);


}

void Attack::Update()
{
	if (m_Texture2D.IsActive() == false) {
		return;
	}

	m_Texture2D.Update();
	timer++;
	if (timer > 200) {
		timer = 0;
		m_Texture2D.SetScale(0.f, 0.f, 0.0f);
		m_Texture2D.SetAlpha(1.f);
		m_Texture2D.SetActive(false);
	}

	//Control();
}

void Attack::Draw(Camera* cam)
{
	float progress = static_cast<float>(timer) / 200.0f;
	if (progress < 0.0f) {
		progress = 0.0f;
	}
	if (progress > 1.0f) {
		progress = 1.0f;
	}


	const float alpha = 1.0f - progress;
	const float size = timer * 3.5f;

	m_Texture2D.SetScale(size, size, 0.0f);
	m_Texture2D.SetAlpha(alpha);
	m_Texture2D.Draw(cam);
}
void Attack::Uninit()
{
	m_Texture2D.Uninit();
}

void Attack::Control()
{

}
