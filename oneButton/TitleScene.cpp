#include "TitleScene.h"
#include "Game.h"
#include "Input.h"
#include "Texture2D.h"
#include "GolfBall.h"
#include <random>

using namespace std;
using namespace DirectX::SimpleMath;
Sound* g_sound = Game::GetSound();

// コンストラクタ
TitleScene::TitleScene()
{
	Init();
}

// デストラクタ
TitleScene::~TitleScene()
{
	Uninit();
}

// 初期化
void TitleScene::Init()
{
	//背景画像オブジェクト生成
	//Texture2D* bg = Game::GetInstance()->AddObject<Texture2D>();
	//bg->SetTexture("assets/texture/background1.png");
	//bg->SetPosition(0.0f, 0.0f, 0.0f);
	//bg->SetRotation(0.0f, 0.0f, 0.0f);
	////bg->SetScale(1600.0f, 900.0f, 0.0f);
	//bg->SetScale(1920.0f, 1080.0f, 0.0f);
	//m_MySceneObjects.emplace_back(bg);

	//GolfBall* gb = Game::GetInstance()->AddObject<GolfBall>();
	//m_MySceneObjects.emplace_back(gb);

	m_bg = Game::GetInstance()->AddObject<backGround>();
	m_MySceneObjects.emplace_back(m_bg);

	m_ghostSml = Game::GetInstance()->AddObject<ghost>();
	m_MySceneObjects.emplace_back(m_ghostSml);
	m_ghostSml->m_Texture2D.SetActive(false);

	m_ghostBig = Game::GetInstance()->AddObject<ghostBig>();
	m_MySceneObjects.emplace_back(m_ghostBig);
	m_ghostBig->m_Texture2D.SetActive(false);

	m_Attack = Game::GetInstance()->AddObject<Attack>();
	m_MySceneObjects.emplace_back(m_Attack);
	m_Attack->m_Texture2D.SetActive(false);

	m_moji = Game::GetInstance()->AddObject<moji>();
	m_MySceneObjects.emplace_back(m_moji);
	m_moji->m_Texture2D.SetActive(false);

	m_CloseEye = Game::GetInstance()->AddObject<CloseEye>();
	m_MySceneObjects.emplace_back(m_CloseEye);

	Game::GetSound()->Play(SOUND_LABEL_BGM000);

}

void TitleScene::DrawImGui()
{
	const bool titleOpen = ImGui::Begin("Title Scene");
	if (titleOpen)
	{
		ImGui::Value("Range", range);
		ImGui::Value("DeadRange", DeadRange);
		//float result = range / DeadRange;
		ImGui::Value("result", result);
		//if (!testObjs.empty())
		//{
		//	const auto position = testObjs[0]->GetPosition();
		//	float pos[3] = { position.x, position.y, position.z };
		//	if (ImGui::DragFloat3("Model Position", pos, 0.1f))
		//	{
		//		testObjs[0]->SetPosition(DirectX::SimpleMath::Vector3(pos[0], pos[1], pos[2]));
		//	}
		//}
	}
	ImGui::End();

	// 他ウィンドウも同じパターン
	//const bool debugOpen = ImGui::Begin("Debug");
	//if (debugOpen)
	//{
	//	ImGui::Text("Enterキーで Stage1 へ");
	//}
	//ImGui::End();
}

// 更新
void TitleScene::Update()
{
	// spaceキーを押してステージ1へ
	if (Input::GetKeyPress(VK_SPACE))
	{
		range++;
		if (!m_IsGameOver) { m_moji->m_Texture2D.SetActive(false); }
	}
	if (m_IsGameOver && goTimer <= 240) {
		goTimer++;
		if (goTimer == 240) {
			m_moji->m_Texture2D.PlayAnim("1");
			g_sound->Play(SOUND_LABEL_SE006);
		}
	}
	if (m_IsGameOver && range == 180) {
		goTimer = 0;
		g_sound->Play(SOUND_LABEL_SE006);
		m_moji->Reset();
	}

	result = range / DeadRange;

	if (!m_IsGameOver) {

		if (result > 0.0f && result < 0.05f)
		{
			g_sound->Play(SOUND_LABEL_SE002);
		}
		if (result >= 0.05f && result < 0.10f)
		{
			g_sound->Play(SOUND_LABEL_SE005);
		}
		else if (result >= 0.30f && result < 0.40f)
		{
			g_sound->Stop(SOUND_LABEL_SE002);
			g_sound->Stop(SOUND_LABEL_SE003);
			g_sound->Play(SOUND_LABEL_SE004);
		}
		else if (result >= 0.50f && result < 0.55f)
		{
			g_sound->Play(SOUND_LABEL_SE000);
		}
		else if (result >= 0.95f && result < 1.0f)
		{
			g_sound->Play(SOUND_LABEL_SE001);
		}

		if (Input::GetKeyRelease(VK_SPACE))
		{
			g_sound->Stop(SOUND_LABEL_SE000);
			g_sound->Stop(SOUND_LABEL_SE001);
			g_sound->Stop(SOUND_LABEL_SE002);
			g_sound->Stop(SOUND_LABEL_SE003);
			g_sound->Stop(SOUND_LABEL_SE004);
			g_sound->Stop(SOUND_LABEL_SE005);

			range = 0;
			if (result >= 1) {
				m_ghostBig->m_Texture2D.SetActive(true);
				m_ghostSml->m_Texture2D.SetActive(false);
				g_sound->Play(SOUND_LABEL_SE007);

				m_moji->m_Texture2D.SetActive(true);
				m_moji->m_Texture2D.SetScale(400.f, 800.f, 0.f);
				m_moji->m_Texture2D.PlayAnim("0");

				m_IsGameOver = true;
				// ゲームオーバー
			}
			else if (result > 0.85f) {
				m_ghostSml->m_Texture2D.SetActive(false);

				m_Attack->m_Texture2D.SetActive(true);

				m_moji->m_Texture2D.SetActive(true);
				m_moji->m_Texture2D.PlayAnim("2");

				g_sound->Play(SOUND_LABEL_SE006);
				// 攻撃成功
			}
			else if (range < 0.85f) {
				m_ghostSml->m_Texture2D.SetActive(true);
				m_ghostSml->Control(result);


				// 攻撃失敗
			}

			static std::mt19937 rng{ std::random_device{}() };
			static std::uniform_int_distribution<int> dist(400, 700);
			DeadRange = static_cast<float>(dist(rng));
		}
	}
	else if (m_IsGameOver) {
		if (Input::GetKeyRelease(VK_SPACE))
		{
			if (range > 180)
			{
				static std::mt19937 rng{ std::random_device{}() };
				static std::uniform_int_distribution<int> dist(400, 700);
				m_IsGameOver = false;
				range = 0;
				DeadRange = static_cast<float>(dist(rng));
				m_ghostBig->m_Texture2D.SetActive(false);
			}
			return;
		}
	}

	// エンターキーを押してステージ1へ
	if (Input::GetKeyTrigger(VK_RETURN))
	{
	//	Game::GetInstance()->ChangeScene(SceneName::STAGE1);
	}
}

// 終了処理
void TitleScene::Uninit()
{
	// このシーンのオブジェクトを削除する
	for (auto& o : m_MySceneObjects) {
		Game::GetInstance()->DeleteObject(o);
	}
	m_MySceneObjects.clear();
}
