#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	static CCScene* scene(bool p0) {
		auto scene = MenuLayer::scene(p0);

		std::string msg = "== Installed Mods ==\n";
		for (auto& mod : Loader::get()->getAllMods()) {
			msg += mod->isEnabled() ? "x | " : "  | ";
			msg += "[" + mod->getVersion().toString() + "] ";
			msg += mod->getID() + " (" + mod->getName() + ")\n";
		}

		log::info("{}", msg);

		return scene;
	}
};
