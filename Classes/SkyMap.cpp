#include"SkyMap.h"
#include<vector>
USING_NS_CC;
using namespace cocos2d::ui;

void SkyMap::loadPath() {

	float x, y;

	Corner = tiledmap->getObjectGroup("Corner");

	/*���������ƶ�������corner�������Ƭ��ͼ��ȡ*/
	const Vec2 begin = birthPlace->getPosition();

	ValueMap corner1 = Corner->getObject("corner1");
	x = corner1["x"].asFloat();
	y = corner1["y"].asFloat();
	auto move1 = MoveTo::create(3, Vec2(x, y));
	path.push_back(Vec2(x, y));

	ValueMap corner2 = Corner->getObject("corner2");
	x = corner2["x"].asFloat();
	y = corner2["y"].asFloat();
	auto move2 = MoveTo::create(1, Vec2(x, y));
	path.push_back(Vec2(x, y));

	ValueMap corner3 = Corner->getObject("corner3");
	x = corner3["x"].asFloat();
	y = corner3["y"].asFloat();
	auto move3 = MoveTo::create(4, Vec2(x, y));
	path.push_back(Vec2(x, y));

	ValueMap corner4 = Corner->getObject("corner4");
	x = corner4["x"].asFloat();
	y = corner4["y"].asFloat();
	auto move4 = MoveTo::create(1, Vec2(x, y));
	path.push_back(Vec2(x, y));

	const Vec2 end = Carrot->getPosition();
	auto move5 = MoveTo::create(3, end);

	/*���淭ת����*/
	auto reverse = ScaleBy::create(0.1f, -1, 1);

	/*������������*/
	movepath = Sequence::create(move1, reverse, move2, move3, reverse, move4, move5, NULL);

}

void SkyMap::loadWave() {
	std::vector<std::vector<int>> skywave = {
		{normal,normal,normal},
		{fly,fly,fly},
		{big,big,big}
	};

	for (int i = 0; i < skywave.size(); i++)
		waveMonster.push_back(skywave.at(i));

	maxWave = skywave.size();
}

SkyMap* SkyMap::createGame() {

	auto skymap = SkyMap::create();
	return skymap;

}

bool SkyMap::init() {
	if (!Scene::init())
		return false;

	tiledmap = TMXTiledMap::create("MAP/SKY/TileMap1.tmx");

	addChild(tiledmap, -1);
	if (tiledmap == nullptr)
		return false;

	Object = tiledmap->getObjectGroup("Object");

	loadWave();

	loadPath();

	InitMap();

	return true;

}