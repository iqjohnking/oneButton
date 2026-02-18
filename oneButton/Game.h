#pragma once
#include <iostream>

#include "Renderer.h"
#include "TitleScene.h"
#include "Stage1Scene.h"
#include "ResultScene.h"

//#include "TestPlane.h"
//#include "TestModel.h"
//#include "GolfBall.h"

enum class SceneName {
	TITLE,
	STAGE1,
	RESULT
};


class Game
{
private:

	static Game* m_Instance; // ゲームクラスのインスタンス
	Scene* m_Scene; // シーン

	// カメラ
	Camera  m_Camera;

	std::vector<std::unique_ptr<Object>> m_Objects; // オブジェクトのリスト

		//====================================================================
	// テストオブジェクト
	//TestPlane m_Plane;
	//TestModel m_Model;
	//GolfBall m_Ball;
	//====================================================================

public:
	Game(); // コンストラクタ
	~Game(); // デストラクタ

	static void Init(); // 初期化
	static void Update(); // 更新
	static void Draw(); // 描画
	static void Uninit(); // 終了処理

	static Game* GetInstance(); // インスタンスの取得
	void ChangeScene(SceneName sceneName); // シーンの切り替え
	void DeleteObject(Object* obj); // オブジェクトの削除
	void DeleteAllObjects(); // 全てのオブジェクトの削除

	template <typename T> T* AddObject()
	{
		T* pt = new T();
		m_Instance->m_Objects.emplace_back(pt);
		pt->Init();
		return pt;
	}
	template <typename T> std::vector<T*> GetObject()
	{
		std::vector<T*> result;
		for (const auto& obj : m_Instance->m_Objects)
		{
			if (T* derivedObj = dynamic_cast<T*>(obj.get()))
			{
				result.emplace_back(derivedObj); // derivedObjは派生オブジェクトの意味です
			}
		}
		return result;
	}



};
