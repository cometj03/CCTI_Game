#pragma once
#include "stdafx.h"
#include "Camera.h"
#include "RenderingManager.h"
#include "CollisionManager.h"

class Scene
{
	friend class Framework;
public:
	Scene();
	virtual ~Scene();

private:
	static Scene* currentScene;
	static Scene* nextScene;
	static void SwapScene(D2DApp* d2dApp);

public:
	static void ChangeScene(Scene* nextScene);
	static Scene* GetCurrentScene();

	static void Destroy(GameObject* gameObject);
	static GameObject* PushOnCurrentScene(GameObject* gameObject);
	static GameObject* PushUIOnCurrentScene(GameObject* gameObject);
	static AABBCollider* PushOnCurrentScene(AABBCollider* col);
	static CircleCollider* PushOnCurrentScene(CircleCollider* col);

private:
	D2DApp* d2dApp;
	Camera* camera;
	std::list<GameObject*> renderableList;
	std::list<GameObject*> gameObjectList;
	std::list<GameObject*> destroyedObjectList;
	std::list<GameObject*> uiList;
	RenderingManager* renderingManager;
	CollisionManager* collisionManager;

private:
	virtual void Initialize() = 0;
	void UpdateGameObjects();
	void UpdatePhysics();
	void DeleteDestroyedObjects();
	void Render();

public:
	GameObject* Push(GameObject* gameObject);
	GameObject* PushUI(GameObject* gameObject);
	AABBCollider* Push(AABBCollider* col);
	CircleCollider* Push(CircleCollider* col);
	//void Destroy(GameObject* o);

public:
	RenderingManager* GetRenderingManager();
	CollisionManager* GetCollisionManager();
	Camera* GetCamera();
};

