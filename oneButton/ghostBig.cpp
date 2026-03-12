#include "ghostBig.h"
#include "Game.h"
#include "input.h"

using namespace std;
using namespace DirectX::SimpleMath;

void ghostBig::Init()
{
	m_Texture2D.Init();
	m_Texture2D.SetTexture("assets/texture/ghost_Big.png");
	m_Texture2D.SetPosition(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetRotation(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetScale(1920.f, 1080.f, 0.0f);

	m_Texture2D.SetSpriteSheet(1, 1);
	//m_Texture2D.AddAnimClip("open", 0, 3, 5);
	//m_Texture2D.PlayAnim("open");

}

void ghostBig::Update()
{
	m_Texture2D.Update();
	//Control();
}

void ghostBig::Draw(Camera* cam)
{
	//m_Texture2D.SetScale(m_Radius * 2, m_Radius * 2, 0);
	//m_Texture2D.SetPosition(GetPosition());
	m_Texture2D.Draw(cam);
}
void ghostBig::Uninit()
{
	m_Texture2D.Uninit();
}

void ghostBig::Control()
{

}
