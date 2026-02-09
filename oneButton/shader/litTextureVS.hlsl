#include "common.hlsl"

PS_IN main(in VS_IN input)
{
	PS_IN output;

	//positoin=============================
	// ワールド、ビュー、プロジェクション行列を掛け合わせて座標変換を行う
	matrix wvp;
	wvp = mul(World, View);
	wvp = mul(wvp, Projection);
	output.pos = mul(input.pos, wvp);
	
	//color=============================
	output.col.xyz = input.col.xyz * Light.Diffuse.xyz; // 拡散光の影響を乗算
	output.col.xyz += input.col.xyz * Light.Ambient.xyz; // アンビエント光を加算//環境光
	output.col.xyz += Material.Emissive.xyz; // エミッシブ色を加算//自体が光を発している
	output.col.a = input.col.a * Material.Diffuse.a; // アルファ値はそのまま使用
	
	//texture=============================
	// テクスチャ座標はそのまま使用
	output.tex = input.tex;
	
	return output;
}

