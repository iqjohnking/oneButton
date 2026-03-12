#pragma once
#include "Texture2D.h"

class CloseEye : public Object
{
public:
	Texture2D m_Texture2D;
	bool isOpening = false; // –Ú‚ªŠJ‚¢‚Ä‚¢‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO
	int m_PicNum = 0;
public:
	void Init() override;
	void Update() override;
	void Draw(Camera* cam) override;
	void Uninit() override;

	void Control();

};