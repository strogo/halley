#pragma once
#include "create_functions.h"
#include "halley/core/game/scene_editor_interface.h"

namespace Halley {
    class SceneEditor : public ISceneEditor {
    public:
		void init(SceneEditorContext& context) override;
		void update(Time t) override;
		void render(RenderContext& rc) override;

		World& getWorld() override;
		void spawnPending() override;

		EntityId getCameraId() override;
		void dragCamera(Vector2f amount) override;
		void changeZoom(int amount, Vector2f cursorPosRelToCamera) override;

		void setSelectedEntity(EntityId id) override;
		void showEntity(EntityId id) override;

		std::vector<std::unique_ptr<IComponentEditorFieldFactory>> getComponentEditorFieldFactories() override;

    protected:
		virtual void createServices(World& world, SceneEditorContext& context);
		virtual void createEntities(World& world, SceneEditorContext& context);

		virtual CreateComponentFunction getCreateComponentFunction() const = 0;
		virtual CreateSystemFunction getCreateSystemFunction() const = 0;
		virtual String getSceneEditorStageName() = 0;

    	virtual EntityId createCamera();

    private:
		std::unique_ptr<World> world;
		EntityId cameraEntityId;

		std::unique_ptr<World> createWorld(SceneEditorContext& context);
	};
}
