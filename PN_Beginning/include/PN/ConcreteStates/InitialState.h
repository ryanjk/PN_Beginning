#ifndef INITIAL_STATE_H
#define INITIAL_STATE_H

#include "PN/Window/WindowManager.h"

#include "PN/ECS/Component/LightComponent.h"

#include "PN/GameState/GameState.h"

#include "PN/Render/Image.h"
#include "PN/Render/Mesh.h"
#include "PN/Render/Renderable.h"

#include "LodePNG/lodepng.h"

#include "PN/Util/MatrixStack.h"

#include <map>

namespace pn {

	struct DrawCall;
	using DrawCallContainer = std::multimap < int, DrawCall > ;

	class InitialState : public pn::GameState {
	public:
		InitialState(const pn::PString& stateFilename);

		void update(double dt) override;
		void render() override;

	protected:
		void startUpAssist() override;

	private:
		std::map<EntityID, pn::Renderable> m_renderables;

		std::vector<EntityID> m_lights;

		pn::Entity* m_activeCamera;

		void buildDrawCalls(EntityID start, pn::MatrixStack& matrixStack, DrawCallContainer& m_drawCalls);
		void renderDrawCalls(DrawCallContainer& drawCalls);
	};
}

#endif