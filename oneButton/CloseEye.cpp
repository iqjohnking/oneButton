#include "CloseEye.h"
#include "Game.h"
#include "input.h"

using namespace std;
using namespace DirectX::SimpleMath;

void CloseEye::Init()
{
	m_Texture2D.Init();
	m_Texture2D.SetTexture("assets/texture/closeYourEye.png");
	m_Texture2D.SetPosition(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetRotation(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetScale(1920.0f, 1080.0f, 1.0f);

	m_Texture2D.SetSpriteSheet(4, 4);

	const int col = m_PicNum % 4;
	const int row = m_PicNum / 4;
	m_Texture2D.SetUV(
		static_cast<float>(col + 1),
		static_cast<float>(row + 1),
		4.0f,
		4.0f);

	//m_Texture2D.AddAnimClip("open", 0, 14, 2);
	//m_Texture2D.PlayAnim("open");

}

void CloseEye::Update()
{
	const int col = m_PicNum % 4;
	const int row = m_PicNum / 4;
	m_Texture2D.SetUV(
		static_cast<float>(col + 1),
		static_cast<float>(row + 1),
		4.0f,
		4.0f);

	m_Texture2D.Update();
	Control();
}

void CloseEye::Draw(Camera* cam)
{
	//m_Texture2D.SetScale(m_Radius * 2, m_Radius * 2, 0);
	m_Texture2D.SetPosition(GetPosition());
	m_Texture2D.Draw(cam);
}
void CloseEye::Uninit()
{
	m_Texture2D.Uninit();
}

void CloseEye::Control()
{
	bool isReverse = false;
	if (Input::GetKeyPress(VK_SPACE))
	{
		if (m_PicNum > 0)
		{
			m_PicNum--;
		}
		//isReverse = true;
		//m_Texture2D.PlayAnimOnce("open", isReverse);
	}
	else
	{
		if (m_PicNum < 14)
		{
			m_PicNum++;
		}
		//m_Texture2D.PlayAnimOnce("open", isReverse);k
	}

	//if (Input::GetKeyRelease(VK_SPACE))
	//{
	//}
}
