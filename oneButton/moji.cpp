#include "moji.h"
#include "Game.h"
#include "input.h"

using namespace std;
using namespace DirectX::SimpleMath;

void moji::Init()
{
	m_Texture2D.Init();
	m_Texture2D.SetTexture("assets/texture/resultText.png");
	m_Texture2D.SetPosition(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetScale(200.0f, 400.0f, 0.0f);

	m_Texture2D.SetSpriteSheet(3, 1);
	m_Texture2D.AddAnimClip("0", 0, 0, 5);
	m_Texture2D.AddAnimClip("1", 1, 1, 5);
	m_Texture2D.AddAnimClip("2", 2, 2, 5);
	m_Texture2D.PlayAnim("2");
	//const int col = m_PicNum % 3;
	//const int row = m_PicNum / 3;
	//m_Texture2D.SetUV(
	//	static_cast<float>(col + 1),
	//	static_cast<float>(row + 1),
	//	3.0f,
	//	1.0f);

}

void moji::Update()
{	
	//const int col = m_PicNum % 3;
	//const int row = m_PicNum / 3;
	//m_Texture2D.SetUV(
	//	static_cast<float>(col + 1),
	//	static_cast<float>(row + 1),
	//	3.0f,
	//	1.0f);
	m_Texture2D.Update();

	//Control();
}

void moji::Draw(Camera* cam)
{
	m_Texture2D.Draw(cam);
}
void moji::Uninit()
{
	m_Texture2D.Uninit();
}

void moji::Reset()
{
	m_Texture2D.SetPosition(0.0f, 0.0f, 0.0f);
	m_Texture2D.SetScale(200.0f, 400.0f, 0.0f);

	m_Texture2D.PlayAnim("2");
}
