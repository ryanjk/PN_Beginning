#ifndef PN_DRAW_CALL_H
#define PN_DRAW_CALL_H

#include "PN/Util/Math.h"

#include "PN/ECS/Component/RenderComponent.h"

#include "PN/Render/Renderable.h"
#include "PN/Render/Material.h"

namespace pn {
	
	struct DrawCall {
		mat4 world_transform;
		pn::Renderable gl_objects;
		pn::Material material;
		unsigned int num_vertices;
		std::shared_ptr<pn::RenderComponent> renderComponent;
	};
}

#endif 