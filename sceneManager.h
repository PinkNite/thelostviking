#pragma once
#include "singletonBase.h"
#include <map>

//���� ���� ���ӳ�� ���漱��
class gameNode;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>			 mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode*	_currentScene;	//���� ��
	mapSceneList		_mSceneList;

public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �߰� �Ծ�
	gameNode* addScene(string sceneName, gameNode* scene);

	//�� ���� �Ծ�
	HRESULT changeScene(string sceneName);


};

