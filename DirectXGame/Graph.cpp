#include "Graph.h"

#include <algorithm>
#include <cassert>

using namespace::KamataEngine;

Graph::Graph() {}

Graph::~Graph() {
    delete backBar_;
    delete frontBar_;
}

void Graph::Initialize() {

    // 裏のグラフ
    backBar_ = new Sprite();
    backBar_->Initialize();
    backBar_->SetPosition({ 100.0f, 50.0f });        // 表示位置
    backBar_->SetSize({ 200.0f, 20.0f });            // サイズ（固定）
    backBar_->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });  // 赤

    // 表のグラフ
    frontBar_ = new Sprite();
    frontBar_->Initialize();
    frontBar_->SetPosition({ 100.0f, 50.0f });        // 表示位置（裏と同じ位置）
    frontBar_->SetSize({ 200.0f, 20.0f });            // サイズ（初期サイズ）
    frontBar_->SetColor({ 0.0f, 1.0f, 0.0f, 1.0f });  // 緑

    // 初期値を100%に設定
    value_ = 1.0f;
}

void Graph::SetValue(float rate) {
    // 0.0～1.0の範囲にクランプ
    value_ = std::clamp(rate, 0.0f, 1.0f);
}

void Graph::Update() {
    // 横幅を value_ に応じて変化させる
    frontBar_->SetSize({ 200 * value_, 20 });
}

void Graph::Draw() {
    backBar_->Draw();   // 赤
    frontBar_->Draw();  // 緑
}