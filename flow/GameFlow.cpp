#include "flow/GameFlow.hpp"

#include <fstream>

#include "systems/entity/entities/EasyHorse.hpp"
#include "construct/Parser.hpp"

using fri::flow::GameFlow;
using fri::flow::IFlow;

GameFlow::GameFlow() {
  auto h = std::make_shared<fri::system::entity::entities::EasyHorse>(_ctx, 5, 1);
  _ctx.GetEntitySystem().RegisterGameObject(h);

  std::string fname = fri::GetBaseDirectory();
  fname.append("resources/levels/level0.txt");
  std::cout << "Loading level from " << fname << std::endl;
  std::ifstream in(fname);
  fri::construct::ParseLevel(in, _ctx);
}

GameFlow::~GameFlow() {
}

void GameFlow::Tick(double Step) {
  _ctx.Tick(Step);
}

bool GameFlow::ShouldSwitch() {
  return false;
}

IFlow * GameFlow::NextFlow() {
  return nullptr;
}